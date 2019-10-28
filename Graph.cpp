#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2


int G[100][100]/*={0}*/,color[100],d[100],prev[100],q[100];
int front = 0 , rear =0;
void print_path(int s, int v){
    if(s==v){
        cout<<s<<"->";
    }
    else if(prev[v]==-1){
        cout<<"No Path";
    }

    else{
        print_path(s,prev[v]);
        cout<<v<<"->";
    }
}
void  BFS(int s , int n){
int u;
    for(int i =0;i<n;i++){

        color[i]=WHITE;
        d[i]=99999;
        prev[i]=-1;

    }
    color[s]=GRAY;
    d[s]=0;
    prev[s]=0;

    q[rear++]=s;
    while(front!=rear){
        u=q[front++];
        for(int v= 0;v<n;v++){
            if(G[u][v]==1){
                if(color[v]==WHITE){
                    color[v]=GRAY;
                    d[v]=d[u]+1;
                    prev[v]=u;
                    q[rear++]=v;

                }
            }
        }
    }
}

int main(){
int n,e,s,u,v,i,j;
cout<<"Enter Number of nodes: ";
cin>>n;
cout<<"Enter Number of edges: ";
cin>>e;
//cout<<"Enter Number of sources: ";
//cin>>s;
s=0;
//for(i=0;i<n;i++){
//    for(j=0;j<n;j++){
//        G[i][j]=0;
//    }
//}
for(i=0;i<e;i++){
    cout<<"Enter edges :";
    cin>>u>>v;
    G[u][v]=1;
    G[v][u]=1;
}

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        cout<<G[i][j]<<"\t";
    }
    cout<<endl;
}

BFS(s,n);
for(i=0;i<n;i++){
        cout<<color[i]<<" ";
}

    cout<<endl;
for(i=0;i<n;i++){
        cout<<d[i]<<" ";
}

    cout<<endl;
for(i=0;i<n;i++){
        cout<<prev[i]<<" ";
}

    cout<<endl;
print_path(2,7);

return 0;

}

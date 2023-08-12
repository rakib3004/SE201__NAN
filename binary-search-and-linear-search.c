#include<stdio.h>

int main()
{
    int i;
    int n;
    printf("Input the size of your array>>>>");
    scanf("%d",&n);
    int a[n];

    for(i=0; i<n; i++)
    {
        printf("Item no %d >>>",i+1);
        scanf("%d",&a[i]);
    }

   int f=0;
    for(i=0; i<n-1; i++)
    {
        if(a[i]<=a[i+1])
        {
            f=1;
        }
        else
        {
            f=0;
            break;
        }
    }
    printf("\n\nEnter Your Desired item>>>>>");
    int item;
    scanf("%d",&item);
    if(f==1)
    {
        printf("\n\n******Your Array is sorted****** \n");
        printf("\n\nNow Start Binary Search...............\n");
    }

    else
    {
        printf("\n\n******Your Array is not  sorted****** \n");
        printf("\n\nNow Start Linear Search...............\n");
    }

    if(f==1)
    {
        int left_index=0;
        int right_index=n-1;

        int mid=(left_index+right_index)/2;
        while(left_index<=right_index)
        {

            if(a[mid]==item)

            {
                printf("\n\nThe item is found!!!\n");
                printf("\n\nThe item is at %d th index in this array.\n\n",mid);
                return 0;
            }

            else if(item<a[mid])
            {

                right_index=mid-1;
            }
            else
            {
                left_index=mid+1;

            }
            mid=(left_index+right_index)/2;

        }
        printf("\n\nThe item is not found in this array.!!!!!\n\n");
    }

    else
    {
        for(i=0; i<n; i++)
        {
            if(a[i]==item)
            {
                printf("\n\nThe item is found!!!\n");
                printf("\n\nThe item is at %d th index in this array.\n\n",i);
                return 0;
            }
        }
        printf("\n\nThe item is not found in this array!!!!!\n\n");

    }
    return 0;
}

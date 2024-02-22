#include<stdio.h>
void main()
{
    int a[20],i,n,f=0,l=0,h=0,num;
    printf("enter limit of array");
    scanf("%d",&n);
    
    printf("enter elements");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("enter no to search");
    scanf("%d",&num);
    
    for(l=0,h=n-1;l<=h;)
    {
        int mid=(l+h)/2;
        
        if(a[mid]>num)
            h=mid-1;
        else if(a[mid]<num)
            l=mid+1;
        else
        {
            printf("%d",mid);
            f=1;
             break;
        }
    }
    
    if(f==1)
        printf("\nNumber Found ");
    else 
        printf("\nNumber not Found ");
}


#include <stdio.h>

void main()
{
    int a[20],n2,n1,l,i,f,num;
    printf("enter ist and 2nd no :");
    scanf("%d%d",&n1,&n2);
    printf("enter no to found");
    scanf("%d",&num);
    l=n2-n1;
    for(i=0;i<l;i++)
    {
        if(n1<n2)
        {
          a[i]=n1+1;
          n1++;
        }
    }
    for(i=0; i<l-1; i++)
    printf("%d",a[i]);
    
   for(i=0; i<l-1; i++)
   {
       if(a[i]==num)
        f=1;
   }
    if(f==1)
    printf("\n no found");
    else
    printf("\n not found");

    
}


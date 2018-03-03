#include<stdio.h>
int main()
{
    int m,n,p,i,j;

    for(i=3,j=0;i<4;i++,j++)
    {
        p=1;
        j=i;
        while(j!=1)
        {
            p++;
            if(j%2==0)
                j=j/2;
            else
                j=3*j+1;
        }
    }
    printf("%d\n",p);

    return 0;
}

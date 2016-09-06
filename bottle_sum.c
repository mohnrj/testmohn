#include<stdio.h>
#define MAX_NUM 100
int main()
{
    int no_of_beverage,Quantity_X,i,j,k,sum,flag;
    int value[MAX_NUM];
    scanf("%d",&no_of_beverage);
    for(i=0;i<no_of_beverage;i++)
    {
        scanf("%d",&value[i]);
    }
    scanf("%d",&Quantity_X);
    for(i=0;i<no_of_beverage;i++)
    {
        for(j=0;j<no_of_beverage;j++)
        {
            if(i==j)
            {
                continue;
            }

            for(k=0;k<no_of_beverage;k++)
            {
                if((i==k)||(j==k))
                {
                    continue;
                }

                sum=value[i]+value[j]+value[k];
                printf("%d   %d   %d    %d\n",value[i],value[j],value[k],sum);
                if(Quantity_X==sum)
                {
                    flag=1;
                    break;

                }

            }
            if(flag==1)
            {
                break;
            }
        }
        if(flag==1)
            {
                break;
            }
    }

    if(flag==1)
    {
        printf("true");

    }else{
        printf("False");
    }

}

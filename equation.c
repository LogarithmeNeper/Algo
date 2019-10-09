#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int carre(int n)
{
    return n*n;
}

int cube(int n)
{
    return n*n*n;
}

int m(int a,int b)
{
    if (a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int verite=0;

    int i=1;
    int j=1;

    int c=ceil(sqrt(m(a,b)));
    //printf("%d\r\n",c);

    for (i=1; i<=c; i++)
    {
        for (j=1; j<=c; j++)
        {
            if ((carre(i)+carre(j)==a)&&(cube(i)+cube(j)==b))
            {
                printf("%d %d\r\n",i,j);
                verite=1;
            }
        }
    }

    if (verite==0)
    {
        printf("-\r\n");
    }

    return 0;
}

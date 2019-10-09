#include <stdio.h>
#include <stdlib.h>

unsigned long fact(int n)
{
        if ((n==0)||(n==1))
        {
            return 1;
        }
        else
        {
            return n*fact(n-1);
        }
}
int main()
{
    int valeur;
    scanf("%d",&valeur);
    int result=fact(valeur);
    printf("%d\r\n",result);
    return 0;
}

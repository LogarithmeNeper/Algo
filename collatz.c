#include <stdio.h>
#include <stdlib.h>

int collatz(int n)
{
    if (n%2==0)
    {
        return n/2;
    }
    else
    {
        return 3*n+1;
    }
}

int main()
{
    int valeur;
    scanf("%d",&valeur);

    while (valeur!=1)
    {
        printf("%d\r\n",valeur);
        valeur=collatz(valeur);
    }

    printf("1\r\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    char a[100];
    char b[100];
    int i,k;
    printf("enter string-1:");
    gets(a);
    printf("\nenter string-2:");
    gets(b);
    i=strlen(a);
    k=0;
    while(b[k]!='\0')
    {
        a[i]=b[k];
        i++;
        k++;
    }
    puts(a);
}

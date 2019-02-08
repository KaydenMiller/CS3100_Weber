#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argc = %d\n",argc);
    printf("argv[0] = %s\n",argv[0]);
    if (argc != 2)
    {
        printf("Incorrect number of arguments, you must pass in a number.\n");
        return -1;
    }
    else
    {
        printf("%s\n",argv[1]);
    }

    int i;
    int max = atoi(argv[1]);
    for(i = 0; i < max; i++)
    {
        printf("%i \t",i);
    }
    
    printf("\n");

    return 5;
}
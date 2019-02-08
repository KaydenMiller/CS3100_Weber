#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    printf("Arguments Count: %d\n", argc);
    printf("Arguments: ");
    for (int i = 0; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");

    if (argc != 3)
    {
        printf("Must be in format \"./HW3 {numForks} {fileName}\"\n");
        return -1;
    }

    int forks = atoi(argv[1]);
    int bufferSize = 256;
    char* fileName = argv[2];

    printf("File Name: \"%s\"\n", fileName);

    if (forks < 1 || forks > 4)
    {
        printf("Incorrect number of forks! (1-4)\n");
        return -1;
    }

    // If it makes it to this point we should be good on args

    execl("minmax.exe", "minmax.exe", fileName, (char*)0);

    printf("Kayden Miller\n");
    return 0;
}
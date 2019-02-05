#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    const char* fileName = "test.txt";
    FILE* ft = fopen(fileName, "rb");

    if (ft)
    {
        int pid = getpid();
        fseek(ft, 0, SEEK_END);
        long size = ftell(ft);
        fseek(ft, 0, SEEK_SET);
        int num = (int)size / (int)sizeof(int);
        printf("size of the file: %li , sizeof(int) = %i\n, the number of numbers = %i\n\n", size, (int)sizeof(int), num);

        int i;
        for (i = 0; i < num; i++)
        {
            int temp = 0;
            fread(&temp, sizeof(int), 1, ft);
            printf("%i: %i\t", pid, temp);
        }
        fclose(ft);
    }
    printf("\n");

    return 0;
}
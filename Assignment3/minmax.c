#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

// This will determine the min and max values inside of a binary file
int main(int argc, char* argv[])
{
    char* fileName = argv[1];

    FILE* ft = fopen(fileName, "rb");

    if (ft)
    {
        int pid = getpid();
        fseek(ft, 0, SEEK_END);
        long size = ftell(ft);
        fseek(ft, 0, SEEK_SET);
        int numOfNums = (int)size / (int)sizeof(int);
        
        int max = INT_MIN;
        int min = INT_MAX;

        for (int i = 0; i < numOfNums; i++)
        {
            int temp = 0;
            fread (&temp, sizeof(int), 1, ft);

            if (temp > max)
            {
                max = temp;
            }

            if (temp < min)
            {
                min = temp;
            }
        }

        fclose(ft);

        printf("Max: %i, Min: %i\n", max, min);
    }

    return 0;
}
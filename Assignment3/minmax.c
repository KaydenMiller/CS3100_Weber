#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

int FindMin(FILE* ft, int startIndex, int divisionSize, int maxSize)
{
    fseek(ft, startIndex * sizeof(int), SEEK_SET);
    int min = INT_MAX;

    for (int i = 0; i < divisionSize; i++)
    {
        int cur = (int)ftell(ft) / (int)sizeof(int);
        if (cur >= maxSize)
            break;

        int temp = 0;
        fread (&temp, sizeof(int), 1, ft);

        if (temp < min)
        {
            min = temp;
        }
    }

    return min;
}

int FindMax(FILE* ft, int startIndex, int divisionSize, int maxSize)
{
    fseek(ft, startIndex * sizeof(int), SEEK_SET);
    int max = INT_MIN;

    for (int i = 0; i < divisionSize; i++)
    {
        int cur = (int)ftell(ft) / (int)sizeof(int);
        if (cur >= maxSize)
            break;

        int temp = 0;
        fread (&temp, sizeof(int), 1, ft);

        if (temp > max)
        {
            max = temp;
        }
    }

    return max;
}

// This will determine the min and max values inside of a binary file
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Invalid command format!\n");
        printf("Must be in format: \"minmax.exe {fileName} {sectionNum}\"\n");
        return -1;
    }

    char* fileName = argv[1];
    char* section = argv[2];
    // sectionNum 0 = full file; 1 = s1; 2 = s2; 3 = s3; 4 = s4;
    int sectionNum = atoi(section);

    FILE* ft = fopen(fileName, "rb");
    if (ft)
    {
        int pid = getpid();
        fseek(ft, 0, SEEK_END);
        long size = ftell(ft);
        fseek(ft, 0, SEEK_SET);
        int numOfNums = (int)size / (int)sizeof(int);
        
        int numOfNumsInSection = numOfNums / 4;
        int max, min;
        int startIndex = numOfNumsInSection * (sectionNum - 1);

        if (sectionNum == 0)
        {
            min = FindMin(ft, 0, numOfNums, numOfNums);
            max = FindMax(ft, 0, numOfNums, numOfNums);
            printf("%i,%i,", min, max);
           //printf("Section #: %i | Start @: %i; End @: %i | Max: %i, Min: %i\n", sectionNum, 0, numOfNums, max, min);
        }
        else 
        {
            min = FindMin(ft, startIndex, numOfNumsInSection, numOfNums);
            max = FindMax(ft, startIndex, numOfNumsInSection, numOfNums);
            printf("%i,%i,", min, max);
            //printf("Section #: %i | Start @: %i; End @: %i | Max: %i, Min: %i\n", sectionNum, startIndex, endIndex - 1, max, min);
        }
        fclose(ft);
    }
    else
    {
        printf("No file found!");
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    const char* fileName = "test.txt";
    FILE* ft = fopen(fileName, "wb");
    srand(time(NULL));
    if (ft)
    {
        int i;
        for (i = 0; i < 40; i++)
        {
            int randomNum = (rand() % 10);
            fwrite(&randomNum, sizeof(int), 1, ft);
        }

        fclose(ft);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
    const char* fileName = "text.txt";
    FILE* ft = fopen(fileName, "wb");
    srand(time(NULL));
    if (ft)
    {
        int i;
        for (i = 0; i < 1000; i++)
        {
            int randomNum = rand() % 1000;
            fwrite(&randomNum, sizeof(int), 1, ft);
        }

        fclose(ft);
    }

    return 0;
}
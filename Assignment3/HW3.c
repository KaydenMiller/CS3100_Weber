#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    printf("Kayden Miller\n");

    if (argc != 3)
    {
        printf("Must be in format \"./HW3 {numForks} {fileName}\"\n");
        return -1;
    }

    int forks = atoi(argv[1]);
    char* fileName = argv[2];

    if (forks != 1 && forks != 4)
    {
        printf("Incorrect number of forks! (1,4)\n");
        return -1;
    }

    // If it makes it to this point we should be good on args
    // Now Set up pipes
    int cp[2];
    if (pipe(cp) < 0)
    {
        printf("Pipe did not work!\n");
        return -1;
    }


    if (forks == 1)
    {
        int pid = fork();
        if (pid == 0)
        {
            close(1); //close stdout
	        dup2(cp[1],1); //move stdout to pipe of cp[1]
	        close(0); //close stdin
	        close(cp[0]); //close pipe in

            execl("minmax.exe", "minmax.exe", fileName, "0", (char*)0);
        }
        else
        {
            // parent
            close(cp[1]);
            char ch;
            char buff[12];
            int min = INT_MAX;
            int max = INT_MIN;
            int current;

            for (int j = 0; j < 12; j++)
            {
                buff[j] = 0;
            }

            int m = 0;
            int k = 0;
            while (read(cp[0], &ch, 1) == 1)
            {
                if (ch != ',')
                {
                    buff[m] = ch;
                    m++;
                }
                else
                {
                    current = atoi(buff);
                    if (max < current)
                    {
                        max = current;
                    }
                    if (min > current)
                    {
                        min = current;
                    }
                }
            }

            printf("Min: %i, Max: %i\n", min, max);
        }
    }
    else if (forks == 4)
    {
        int pid = fork();
        if (pid == 0)
        {
            close(1); //close stdout
	        dup2(cp[1],1); //move stdout to pipe of cp[1]
	        close(0); //close stdin
	        close(cp[0]); //close pipe in

            pid = fork();
            if (pid == 0)
            {
                execl("minmax.exe", "minmax.exe", fileName, "1", (char*)0);
            }
            else
            {
                // parent
                pid = fork();
                if (pid == 0)
                {
                    execl("minmax.exe", "minmax.exe", fileName, "2", (char*)0);
                }
                else
                {
                    // parent
                    pid = fork();
                    if (pid == 0)
                    {
                        execl("minmax.exe", "minmax.exe", fileName, "3", (char*)0);
                    }
                    else
                    {
                        // Parent
                        execl("minmax.exe", "minmax.exe", fileName, "4", (char*)0);
                    }
                }
            }
        }
        else
        {
            // parent
            close(cp[1]);
            char ch;
            char buff[50];
            int min = INT_MAX;
            int max = INT_MIN;
            int current;

            for (int j = 0; j < 12; j++)
            {
                buff[j] = 0;
            }

            int m = 0;
            int k = 0;
            while (read(cp[0], &ch, 1) == 1)
            {
                if (ch != ',')
                {
                    buff[m] = ch;
                    m++;
                }
                else
                {
                    current = atoi(buff);
                    if (max < current)
                    {
                        max = current;
                    }
                    if (min > current)
                    {
                        min = current;
                    }
                }
            }

            printf("Min: %i, Max: %i\n", min, max);
        }
    }

    return 0;
}
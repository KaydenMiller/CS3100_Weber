#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("This is before the fork.\n");
    int cp[2];

    if (pipe(cp) < 0)
    {
        printf("didn't work, couldn't not establish pipe.\n");
        return -1;
    }

    int pid = fork();
    if (pid == 0)
    {
        printf("this is the child. not the original\n");
        close(1); //close stdout
        dup2(cp[1], 1); //move stdout to pipe of cp[1]
        close(0); //close stdin
        close(cp[0]); //close pipe in
        execl("printStuff","printStuff", "5",(char *) 0);  //note: All the arguments in exec have to be strings.
    }
    else
    {
        close(cp[1]); //if you don't close this part of the pipe then the while loop (three lines down) will never return
        
        printf("this is the parent. the 'original.'\n");
        
        char ch;
        while( read(cp[0], &ch, 1) == 1)
        {
            printf("%c",ch);
            //write(1, &ch, 1);
            //outcount++;
        }
        printf("all done.\n");
        //execl("printStuff","printStuff", "10",(char *) 0);
    }

    printf("This is after the fork.\n");

    return 0;
}
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "syscall.h"
#include "param.h"
#include "fcntl.h"
#include "traps.h"
#include "memlayout.h"

//TODO: DEFAULT mycpu->magic to 0
//TODO: Fix getMagic() incrementMagic()
//TODO: Fix modifyCurrentProcessName(char* newName) it thinks it is getting 30 chars
int main(int argc, char *argv[])
{
    int magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    incrementMagic(3);

    magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    printf(1, "current process name:");
    getCurrentProcessName();
    printf(1, "\n");

    modifyCurrentProcessName("newName");

    printf(1, "current process new name:");
    getCurrentProcessName();
    printf(1, "\n");

    magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    incrementMagic(3);

    magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    exit();
}
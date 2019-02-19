#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "syscall.h"
#include "param.h"
#include "fcntl.h"
#include "traps.h"
#include "memlayout.h"

int main(int argc, char *argv[])
{
    int magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    //incrementMagic(3);

    magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    printf(1, "current process name:");

    getCurrentProcessName();

    printf(1, "\n");

    //modifyCurrentProcessName("newName");

    getCurrentProcessName();

    magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    //incrementMagic(3);

    magic = getMagic();
    printf(1, "current magic number is the following: %d\n", magic);

    exit();
}
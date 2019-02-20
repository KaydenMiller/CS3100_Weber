#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int magic = 0;
// This will increment the value of "magic" in the cpu struct by value
int
sys_incrementMagic(void)
{
  //8.5 x 11 sheet is allowed on test double sided
  int value;
  argint(0, &value);
  magic += value;
  // cli?
  return 0;
}

// This will return the value of "magic" in the cpu struct
int
sys_getMagic(void)
{
  // the following line has an error in it mycpu()->magic
  int magicOutput = magic;
  return magicOutput;
}

// This will print the value of the current processes name
int
sys_getCurrentProcessName(void)
{
  char* name = myproc()->name;
  cprintf("%s", name);
  return 0;
}

// This will set the current processes name
int
sys_modifyCurrentProcessName(void)
{
  char* newName;
  argstr(0, &newName);

  int lengthOfString = strlen(newName);
  if (lengthOfString >= 16)
    return -1;

  for (int i = 0; i < lengthOfString; i++)
  {
    myproc()->name[i] = newName[i];
  }
  
  return 0;
}
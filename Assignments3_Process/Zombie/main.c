#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void func(int signum)
{
    wait(NULL);
}

int main (int argc, char const *argv[])
{
pid_t child;
int status, ret;

child = fork();
if ( 0==child)
{
    printf("Im the child process, ");
    printf("My ID is: %d, My parent ID is: %d\n", getpid(),getppid());
    //printf("Child process will be close in 3s\n");
    //sleep(3);
    //exit(0);
    while(1);
}
else 
{
    signal (SIGCHLD,func);
    printf("I'm the parent process, ");
    printf ("My ID is: %d \n", getpid());
    while(1);

}
}
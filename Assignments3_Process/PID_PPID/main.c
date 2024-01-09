#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char const *argv[])
{
pid_t child;
int status, ret;

child = fork();
if ( 0==child)
{
    printf("Im the child process, ");
    printf("My ID is: %d, My parent ID is: %d\n", getpid(),getppid());
    printf("Child process will be close in 3s\n");
    sleep(3);
    exit(0);
    //while(1);
}
else 
{
    ret=wait(&status);

    printf("I'm the parent process, ");
    printf ("My ID is: %d \n", getpid());
    printf("My child ID is: %d\n", ret);
    while(1);

}
}
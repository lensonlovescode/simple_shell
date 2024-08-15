#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/**
 * main - PID
 * Return: Always 0.
 */
int main()
{
	pid_t pid, ppid;

	pid = getpid();
	ppid = getppid();

	printf("Process ID: %u\n", pid);
	printf("Parent Process ID: %u\n", ppid);
	return (0);
}


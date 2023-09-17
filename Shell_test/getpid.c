#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, ppid, c_pid;

	pid = getpid();
	ppid = getppid();

	printf("Process ID is: %d\n", pid);
	printf("Parent process ID: %d\n", ppid);

	c_pid = fork();

	if (c_pid == 0)
	{
		printf("Child process ID\n");
		printf("Parent process ID (PPID): %d\n", getppid());
		printf("Current process ID (PID): %d\n", getpid ());
	}
	else if (c_pid > 0)
	{
		printf("This is a parent process;\n");
		printf("Child process ID (PPID): %d\n", c_pid);
	}
	else
	{
		printf("failed");
			return (-1);
	}


	return (0);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

 int main(int argc, char *argv[])
 {
 		if(argc !=3)
		{
			printf("Use only two arguments.\n");
			printf("Usage: shot <program_name> <times>");
			return 1;
		}

		const char *program_path = argv[1];
		int n = atoi(argv[2]);

		 for(int i=0;i < n;i++)
		 {
		 	pid_t pid = fork();
			if(pid == 0)
		 		execl(program_path,program_path,NULL);
			
			waitpid( pid, NULL , WEXITSTATUS(NULL));
		
		 }

		 return 0;
 }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimelo-d <mimelo-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:16:09 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 22:42:21 by mimelo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

int compile_test(char *testfile, char *tester_path, char *project_path)
{
	int compile_status;
	int stderr_fd[2];
	pid_t pid;
	char compilation_error[4048];
	int nbytes;

	(void) testfile;
	(void) project_path;
	if ( pipe(stderr_fd) ==-1)
    	die("pipe");

	if ((pid = fork()) == -1)
		die("fork");

	 if(pid == 0) {
		// printf("Child\n");
		dup2 (stderr_fd[1], STDERR_FILENO);
		close(stderr_fd[0]);
		close(stderr_fd[1]);
		chdir(tester_path);
		execl("/bin/bash", "bash", "./compile_test.sh", (char *)0);
		chdir(project_path);
	} else {
		
		close(stderr_fd[1]);
		wait(&compile_status); // N.B.: wait until the child process completes, else we could read a partial or empty output
		
		if (compile_status != 0)
		{
			nbytes = read(stderr_fd[0], compilation_error, sizeof(compilation_error)); // read the output once the child has completed
			printf("\nCompilation Error:\n\n%.*s\n", nbytes, compilation_error);
		}
	}
	return (0);
}


int run_test(char *runner_path, char *project_path, char *testfile_binary)
{
	int status_code;
	int stdout_fd[2];
	int stderr_fd[2];
	pid_t pid;
	char compilation_result[4048];
	char compilation_error[4048];
	int nbytes;

	(void) testfile_binary;

	if (pipe(stdout_fd) ==-1 || pipe(stderr_fd) ==-1)
    	die("pipe");

	if ((pid = fork()) == -1)
		die("fork");

	 if(pid == 0) {
		// printf("Child\n");
		dup2 (stdout_fd[1], STDOUT_FILENO);
		close(stdout_fd[0]);
		close(stdout_fd[1]);

		dup2 (stderr_fd[1], STDERR_FILENO);
		close(stderr_fd[0]);
		close(stderr_fd[1]);
		chdir(runner_path);
		execl("./testfile", "", (char *)0);
		chdir(project_path);
	} else {
		
		close(stdout_fd[1]);
		close(stderr_fd[1]);
		wait(&status_code); // N.B.: wait until the child process completes, else we could read a partial or empty output
		
		if (status_code != 0)
		{
			printf("%s", " - Fail \n");
			nbytes = read(stdout_fd[0], compilation_result, sizeof(compilation_result)); // read the output once the child has completed
			printf("Console:-------\n%.*s\n", nbytes, compilation_result);
		
			nbytes = read(stderr_fd[0], compilation_error, sizeof(compilation_error)); // read the output once the child has completed
			printf("Error:--------\n%.*s\n", nbytes, compilation_error);

			printf("%s", "\n");
		}
		else
		{
			printf("%s", " - Pass\n");
		}
	}
	return (0);
}

void run_file(char *filename, char *runner_path, char *project_path)
{
	char binary[1024];

	sprintf(binary, "%s.test", filename);
	compile_test(filename, runner_path, project_path);
	run_test(runner_path, project_path, binary);
}

int main(int argc, char *argv[])
{
	char project_path[2024];
	getcwd(project_path, 2024);
	if (argc < 2)
		return (1);
	for (int i = 2; i < argc; i++)
	{
		printf("Running File <%s>", argv[i]);
		run_file(argv[i], argv[1], project_path);
	}
	return (0);
}
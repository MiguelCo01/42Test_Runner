/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:16:09 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 17:03:58 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);

int compile_test(char *testfile, char *testfile_binary)
{
	int stdout_fd[2];
	int stderr_fd[2];
	pid_t pid;
	char compilation_result[4048];
	char compilation_error[4048];
	int nbytes;

	printf("Compiling %s\n", testfile);

	if (pipe(stdout_fd) ==-1 || pipe(stderr_fd) ==-1)
    	die("pipe");

	if ((pid = fork()) == -1)
		die("fork");

	 if(pid == 0) {
		printf("Child\n");
		dup2 (stdout_fd[1], STDOUT_FILENO);
		close(stdout_fd[0]);
		close(stdout_fd[1]);

		dup2 (stderr_fd[1], STDERR_FILENO);
		close(stderr_fd[0]);
		close(stderr_fd[1]);
		
		//execl("cc", "-Wall -Wextra -Werror", testfile, "-o", testfile_binary, (char *)0);
		printf("%s -> %s\n", testfile, testfile_binary);
		//execl("/bin/ls", "ls", "-1", (char *)0);
		execl("/bin/bash", "bash", "/archive/Projects/42Lisboa/Core/tester/compile_test.sh", (char *)0);
		die("something")
		printf("Done -\n");
	} else {
		
		printf("Parent\n");
		close(stdout_fd[1]);
		close(stderr_fd[1]);
		wait(NULL); // N.B.: wait until the child process completes, else we could read a partial or empty output
		
		printf("Waited\n");
		// Handle Stdout
		nbytes = read(stdout_fd[0], compilation_result, sizeof(compilation_result)); // read the output once the child has completed
		printf("Console:-------\n%.*s\n", nbytes, compilation_result);
		
		// Handle Stderr
		nbytes = read(stderr_fd[0], compilation_error, sizeof(compilation_error)); // read the output once the child has completed
		printf("Error:--------\n%.*s\n", nbytes, compilation_error);
		printf("Done\n");
		//close(stdout_fd[0]);
		//close(stderr_fd[0]);

	}
	return (0);
}


int run_test(char *testfile_binary)
{
	int stdout_fd[2];
	int stderr_fd[2];
	pid_t pid;
	char compilation_result[4048];
	char compilation_error[4048];
	int nbytes;

	printf("Running%s\n", testfile_binary);



	if (pipe(stdout_fd) ==-1 || pipe(stderr_fd) ==-1)
    	die("pipe");

	if ((pid = fork()) == -1)
		die("fork");

	 if(pid == 0) {
		printf("Child\n");
		dup2 (stdout_fd[1], STDOUT_FILENO);
		close(stdout_fd[0]);
		close(stdout_fd[1]);

		dup2 (stderr_fd[1], STDERR_FILENO);
		close(stderr_fd[0]);
		close(stderr_fd[1]);
		
		execl("/archive/Projects/42Lisboa/Core/tester/testfile", "", (char *)0);
		printf("Done -\n");
	} else {
		
		printf("Parent\n");
		close(stdout_fd[1]);
		close(stderr_fd[1]);
		wait(NULL); // N.B.: wait until the child process completes, else we could read a partial or empty output
		
		printf("Waited\n");
		// Handle Stdout
		nbytes = read(stdout_fd[0], compilation_result, sizeof(compilation_result)); // read the output once the child has completed
		printf("Console:-------\n%.*s\n", nbytes, compilation_result);
		
		// Handle Stderr
		nbytes = read(stderr_fd[0], compilation_error, sizeof(compilation_error)); // read the output once the child has completed
		printf("Error:--------\n%.*s\n", nbytes, compilation_error);
		printf("Done\n");
		//close(stdout_fd[0]);
		//close(stderr_fd[0]);

	}
	return (0);
}

void run_file(char *filename)
{
	char binary[1024];

	sprintf(binary, "%s.test", filename);
	printf("Compiling and executing %s\n", binary);

	compile_test(filename, binary);
	run_test(binary);
	// Compile Test File
	// 1.1 - Fork and Execv gcc with all the arguments
	// 1.2 - Get the results check if no errors
	// Execute Test File Binary
	// 1.1 - Fork and Execv gcc with all the arguments
	// 1.2 - Get the results check if no errors
}

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		printf("Running File <%s>\n", argv[i]);
		run_file(argv[i]);
	}
	return (0);
}
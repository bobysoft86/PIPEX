/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:13:50 by roberodr          #+#    #+#             */
/*   Updated: 2023/03/15 17:12:19 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>


int main (int argc, char **argv)
{


	int infile;
	char **ls;
	char **wc;
	
	infile = open(argv[1], O_RDONLY);

	if (!infile)
		return(-1);

	
	wc = malloc(3 * sizeof(char *));
	wc[0] = strdup("/usr/bin/wc");
	wc[1] = strdup("-l");
	wc[2] = NULL;

	ls = malloc(3 * sizeof(char *));
	ls[0] = strdup("/bin/ls");
	ls[1] = strdup("-l");
	//ls[2] = strdup("text.txt");
	// ls[2] = strdup(argv[1]);
	ls[2] = NULL;

	int fd[2];
	if  (pipe(fd) == -1)
		return (1);
		
	int pid1 = fork();
	if (pid1 < 0)
		return(0);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		dup2(infile, STDIN_FILENO);
		close(infile);
		execve(ls[0], ls, NULL);
	}

		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve(wc[0], wc, NULL);
	
			waitpid(pid1, NULL, 0);
		return 0;

}


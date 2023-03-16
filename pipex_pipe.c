/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:13:50 by roberodr          #+#    #+#             */
/*   Updated: 2023/03/16 14:31:10 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int ft_checkdir(*s1)
{
	char line[62] = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki"
	
	strlcpy
	strchr 
}

void ft_strcpy (char *src, char *dst)
{

	int i;

	i = 0;
	while(src[i])
		{
			dst[i] = src[i];
			i++;
		}
}


int main (int argc, char **argv)
{
	
	int outfile;
	int infile;
	char **ls;
	char **wc;
	 char s1[7];

	if (argc < 3 )
	{
		write(1, "error", 5);
		return(-1);
	}	
	

	ft_strcpy(argv[2], s1);
	outfile = open(s1 , O_WRONLY | O_CREAT, 0777);
	infile = open(argv[1], O_RDONLY);
	if (!infile)
		return(-1);
													// comprobar accesos de ruta para comandos
		
	wc = malloc(3 * sizeof(char *));
	wc[0] = strdup("/usr/bin/wc");
	wc[1] = strdup("-c");
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
		dup2(outfile, STDOUT_FILENO);
		close(infile);
		execve(wc[0], wc, NULL);
	
			waitpid(pid1, NULL, 0);
		return 0;

}


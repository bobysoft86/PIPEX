/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:57 by roberodr          #+#    #+#             */
/*   Updated: 2023/03/15 11:34:17 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while ( s1[i] !='\0')
		{
			if(s1[i] != s2[i]) 			
				return(0);
			i++;
		}
	return(1);
}


int main (int argc, char **argv, char *env[])
{
	char *ls;
	char *s2;
//printf("esto es argv2 %d", &argv[2]);
	s2 = "ls";

	if(ft_strcmp(argv[1],s2) == 1)
		ls = "/bin/ls";
	
	char	**test;
	test = malloc(3 * sizeof(char *));
	test[0] = ls;
	test[1] = argv[2];
	// strcpy(test[0], ls);
	// strcpy(test[1], argv[3]);
	test[2] = NULL;
	
	if(argc == 3)
	{
		pid_t pid;


		pid = fork();

		if (pid == -1)
			return (-1);

		if (pid == 0)
		{
			int val = execve(test[0],test,NULL);
			
				if (val == -1)
					return(printf("error"));
		}
		else 
		{
			wait(NULL);
			printf("done");
		}
	return(0);
	
	}
}
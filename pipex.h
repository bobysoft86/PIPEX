/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roberodr <roberodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:07:55 by roberodr          #+#    #+#             */
/*   Updated: 2023/04/14 18:11:20 by roberodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct index
{
	char	*path;
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	int		pid1;
	int		outfile;
	int		infile;
}	t_index;

typedef struct union1
{
	char	**result;
	char	*tmp;
	int		i;
	int		j;
}	t_union1;

static char	*mini_path(char *envp[]);
size_t		ft_sizeword(const char *str, char del, int pos);
size_t		ft_countto(const char *a, char c);
size_t		ft_strlen(const char *c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		ft_get_path(char *cmd, char **envp, char **f_path);
void		ft_strcpy(char *src, char *dst);
void		ft_strcpy(char *src, char *dst);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ftfree(char **s, size_t contador1);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		**ft_split_cmd_arg(char *argv);
char		**ft_unioncmd(char **str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_child(t_index index, char **envp);
void		ft_father(t_index index, char **envp);
void		ft_error(char *s);

#endif

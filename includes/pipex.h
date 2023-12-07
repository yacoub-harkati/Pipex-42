#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

typedef struct s_pipex
{
	int in_fd;
	int out_fd;
	int cmd_count;
	int cmd_offset;
	char **cmd_paths;
	char **env_paths;
	char ***cmd_args;
} t_pipex;

void ft_init_pipex(int ac, char **av, char **envp, t_pipex *pipe_d);
char **ft_parse_paths(int ac, t_pipex *pipe_d);
char ***ft_parse_args(int ac, char **av, t_pipex *pipe_d);
char **ft_parse_env_paths(int ac, char **envp);
char *ft_get_correct_cmd_path(char *cmd, char **env_paths);

#endif
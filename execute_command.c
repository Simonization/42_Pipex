/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:57:57 by slangero          #+#    #+#             */
/*   Updated: 2024/10/02 22:00:39 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_executable_path(char *cmd, char **env)
{
	char	**split_cmd;
	char	**env_path;
	char	*exec_path;

	split_cmd = ft_extract_cmd(cmd);
	env_path = ft_extract_env_path(env);
	exec_path = ft_search_env_path(split_cmd[0], env_path);
	verify(exec_path);
	ft_free(split_cmd);
	free(env_path);
	return (exec_path);
}

void	execute_command(char *cmd, char **env)
{
	char	**split_cmd;
	char	*exec_path;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
	{
		perror("Error splitting command");
		exit(1);
	}
	if (access(split_cmd[0], X_OK) == 0)
		execve(split_cmd[0], split_cmd, env);
	exec_path = find_executable_path(cmd, env);
	if (!exec_path)
	{
		exit(1);
	}
	execve(exec_path, split_cmd, env);
	perror("Error executing command");
	free(exec_path);
	ft_free(split_cmd);
	exit(1);
}

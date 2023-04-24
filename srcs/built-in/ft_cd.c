/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:25:33 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:25:37 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_handle_tild_hyphen(t_parsing *parse, char c)
{
	char	*ret;

	ret = NULL;
	ret = ft_loop_tild_hyphen(parse, c);
	if (c == '~' && !ret)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (ft_strlen(ret) == 0)
	{
		free(ret);
		return (0);
	}
	if (chdir(ret) != 0)
	{
		ft_printf("minishell: cd: %s: No such file or directory\n", ret);
		free(ret);
		return (1);
	}
	free(ret);
	return (0);
}

char	*ft_get_current_position(void)
{
	char	*cwd;
	char	buffer[4096];

	cwd = getcwd(buffer, sizeof(buffer));
	if (!cwd)
	{
		perror("cd: error retrieving current directory");
		return (NULL);
	}
	return (cwd);
}

int	ft_cd(t_parsing *parse)
{
	t_list	*tmp;
	char	*cwd;
	int		ret;

	ret = 0;
	tmp = parse->lst_cmdline;
	cwd = ft_get_current_position();
	if (tmp->next == NULL || ft_strcmp(tmp->next->str, "~") == 0)
		ret = ft_handle_tild_hyphen(parse, '~');
	else if (tmp->next == NULL || ft_strcmp(tmp->next->str, "-") == 0)
		ret = ft_handle_tild_hyphen(parse, '-');
	else if (chdir(tmp->next->str) != 0)
	{
		write (2, "cd: ", 4);
		perror(tmp->next->str);
		return (1);
	}
	if (!cwd)
		return (0);
	ft_update_oldpwd(parse, cwd);
	cwd = ft_get_current_position();
	ft_update_pwd(parse, cwd);
	return (ret);
}

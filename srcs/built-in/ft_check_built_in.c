/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_built_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:15:39 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:16:49 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_built_in(t_parsing *parse)
{
	if (parse->built_in_cmd == 1)
		g_sig.return_value = ft_env(parse);
	else if (parse->built_in_cmd == 3)
		g_sig.return_value = ft_pwd();
	else if (parse->built_in_cmd == 4)
		ft_echo(parse->lst_cmdline, parse);
	else if (parse->built_in_cmd == 5)
		ft_unset(parse);
	else if (parse->built_in_cmd == 6)
		g_sig.return_value = ft_cd(parse);
	else if (parse->built_in_cmd == 7)
		ft_exit(parse);
	else if (parse->built_in_cmd == 8)
		ft_print_history(parse);
	exit(g_sig.return_value);
}

static void	command_length(t_parsing *parse)
{
	t_list	*tmp;

	tmp = parse->lst_cmdline;
	parse->lst_target = 0;
	while (tmp && ft_strchr(tmp->str, '|') == NULL)
	{
		parse->lst_target++;
		tmp = tmp->next;
	}
}

int	parsing_built_in(t_parsing *parse)
{
	t_list	*tmp;

	command_length(parse);
	tmp = parse->lst_cmdline;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, "env") == 0 || ft_strcmp(tmp->str, "ENV") == 0)
			return (1);
		if (ft_strcmp(tmp->str, "pwd") == 0 || ft_strcmp(tmp->str, "PWD") == 0)
			return (3);
		if (ft_strcmp(tmp->str, "echo") == 0)
			return (4);
		if (ft_strcmp(tmp->str, "unset") == 0)
			return (5);
		if ((ft_strcmp(tmp->str, "cd") == 0) || (ft_strcmp(tmp->str, "cd") == 0
				&& (ft_strcmp(tmp->next->str, "~") == 0)))
			return (6);
		if (ft_strcmp(tmp->str, "exit") == 0)
			return (7);
		if (ft_strcmp(tmp->str, "history") == 0)
			return (8);
		tmp = tmp->next;
	}
	return (0);
}

void	execute_built_in_alone(t_parsing *parse)
{
	if (ft_strcmp(parse->lst_cmdline->str, "export") == 0
		&& ft_lst_strchr_pipe(parse->lst_cmdline) == 1)
			g_sig.return_value = ft_export(parse);
	else if (ft_strcmp(parse->lst_cmdline->str, "unset") == 0)
		ft_unset(parse);
	else if (ft_strcmp(parse->lst_cmdline->str, "exit") == 0)
		ft_exit(parse);
	else if ((ft_strcmp(parse->lst_cmdline->str, "cd") == 0)
		|| (ft_strcmp(parse->lst_cmdline->str, "cd") == 0
			&& (ft_strcmp(parse->lst_cmdline->next->str, "~") == 0)))
	{
		check_herringbone(parse);
		g_sig.return_value = ft_cd(parse);
	}
	ft_lstdel_all(&parse->lst_cmdline);
	return ;
}

void	built_in_used_alone(t_parsing *parse)
{
	int		built_in_found;

	built_in_found = 0;
	if (ft_lst_strchr_pipe(parse->lst_cmdline) == 0)
		return ;
	if (ft_strcmp(parse->lst_cmdline->str, "export") == 0
		|| ft_strcmp(parse->lst_cmdline->str, "unset") == 0
		|| ft_strcmp(parse->lst_cmdline->str, "cd") == 0
		|| ft_strcmp(parse->lst_cmdline->str, "exit") == 0)
		built_in_found = 1;
	if (built_in_found == 1)
		execute_built_in_alone(parse);
}

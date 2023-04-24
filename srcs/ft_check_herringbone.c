/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_herringbone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:18:08 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:18:10 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_heredoc(t_parsing *parse)
{
	if (!parse->lst_cmdline)
		return ;
	parse->redirection_in = 0;
	parse->heredoc_pfd = 0;
	while (check_herringbones_input(parse) == 0
		&& parse->lst_cmdline->str[0] != '|' && parse->lst_cmdline != NULL)
	{
		if (ft_strcmp(parse->lst_cmdline->str, "<<") == 0)
		{
			parse->redirection_in = 1;
			ft_heredoc(parse, &parse->lst_cmdline);
			if (!parse->lst_cmdline)
				return ;
		}
		if (!parse->lst_cmdline || !parse->lst_cmdline->next
			|| parse->lst_cmdline->str[0] == '|')
			break ;
		if (ft_strcmp(parse->lst_cmdline->str, "<<") != 0)
			parse->lst_cmdline = parse->lst_cmdline->next;
	}
	while (parse->lst_cmdline->prev != NULL)
		parse->lst_cmdline = parse->lst_cmdline->prev;
}

int	check_herringbones_input(t_parsing *parse)
{
	t_list	*tmp;

	tmp = parse->lst_cmdline;
	while (tmp)
	{
		if (ft_strcmp(tmp->str, "<") == 0 || ft_strcmp(tmp->str, "<<") == 0
			|| ft_strcmp(tmp->str, ">") == 0 || ft_strcmp(tmp->str, ">>") == 0)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

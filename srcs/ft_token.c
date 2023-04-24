/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:20:40 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:20:43 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_close_herringbone(t_parsing *parse)
{
	if (parse->input[parse->i] == '>' && parse->input[parse->i +1] == '>')
	{
		parse->len = 2;
		ft_fill_lst(&parse->lst_cmdline, parse, parse->i);
		parse->i++;
	}
	else if (parse->input[parse->i] == '>' && parse->input[parse->i +1] != '>')
	{
		parse->len = 1;
		ft_fill_lst(&parse->lst_cmdline, parse, parse->i);
	}
	parse->len = 0;
	return (1);
}

int	is_open_herringbone(t_parsing *parse)
{
	if (parse->input[parse->i] == '<' && parse->input[parse->i +1] == '<')
	{
		parse->len = 2;
		ft_fill_lst(&parse->lst_cmdline, parse, parse->i);
		parse->i++;
	}
	else if (parse->input[parse->i] == '<' && parse->input[parse->i +1] != '<')
	{
		parse->len = 1;
		ft_fill_lst(&parse->lst_cmdline, parse, parse->i);
	}
	parse->len = 0;
	return (1);
}

int	is_pipe(t_parsing *parse)
{
	if (parse->input[parse->i] == '|')
	{
		parse->len = 1;
		ft_fill_lst(&parse->lst_cmdline, parse, parse->i);
	}
	parse->len = 0;
	return (1);
}

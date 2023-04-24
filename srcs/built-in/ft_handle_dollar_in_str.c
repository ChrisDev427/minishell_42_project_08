/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dollar_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:25:05 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:25:06 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void	ft_handle_dollar_in_str(t_parsing *parse)
{
	t_list	*tmplst;
	t_list	*new;

	if (parse->lst_cmdline && ft_strcmp(parse->lst_cmdline->str, "echo") == 0)
		parse->is_in_str = 1;
	parse->len_b = 0;
	parse->i_b = 0;
	parse->str_tmp = ft_substr(parse->input, parse->i - parse->len,
			parse->len);
	tmplst = NULL;
	ft_loop_dollar(parse, &tmplst);
	ft_replace_value(parse, &tmplst);
	free(parse->str_tmp);
	parse->str_tmp = NULL;
	if (ft_lstsize(tmplst) > 1)
	{
		parse->str_tmp = ft_lst_to_str(tmplst);
		ft_strdel_quotes(parse, parse->str_tmp);
		new = ft_lstnew(ft_strdup(parse->str_tmp));
		ft_lstadd_back(&parse->lst_cmdline, new);
	}
	free(parse->str_tmp);
	parse->str_tmp = NULL;
	ft_lstdel_all(&tmplst);
	parse->is_dollar = 0;
}

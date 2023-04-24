/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dollar_in_heredoc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:17:24 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:17:29 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_handle_dollar_in_heredoc(t_parsing *parse, char *src)
{
	t_list	*tmplst;
	char	*dst;

	parse->len_b = 0;
	parse->i_b = 0;
	parse->str_tmp = ft_strdup(src);
	free(src);
	tmplst = NULL;
	ft_loop_dollar(parse, &tmplst);
	ft_replace_value(parse, &tmplst);
	free(parse->str_tmp);
	parse->str_tmp = NULL;
	dst = ft_lst_to_str(tmplst);
	ft_lstdel_all(&tmplst);
	return (dst);
}

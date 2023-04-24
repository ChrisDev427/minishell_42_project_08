/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:17:04 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:17:06 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int	ft_env(t_parsing *parse)
{
	t_list	*tmp;

	tmp = parse->lst_env;
	if (parse->lst_cmdline->next == NULL
		|| ft_strcmp(parse->lst_cmdline->next->str, "|") == 0)
	{
		while (tmp)
		{
			if (ft_strnstr(tmp->str, "=", ft_strlen(tmp->str)))
				ft_printf("%s\n", tmp->str);
			tmp = tmp->next;
		}
	}
	else
	{
		ft_printf("env: options & arguments are not permited\n");
		return (127);
	}
	return (0);
}

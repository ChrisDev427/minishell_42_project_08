/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_shlvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chmassa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:18:48 by chmassa           #+#    #+#             */
/*   Updated: 2023/04/24 10:23:30 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_increment_shlvl(char *s)
{
	int		lvl;
	int		i;
	char	*ret;
	char	*ret_itoa;

	lvl = ft_atoi(s +6);
	lvl++;
	ret_itoa = ft_itoa(lvl);
	i = 0;
	while (s[i++])
		if (s[i] == '=')
			s[i +1] = '\0';
	ret = ft_strdup(s);
	ret = ft_strjoin_free_s1(ret, ret_itoa);
	free(ret_itoa);
	return (ret);
}

void	ft_handle_shlvl(t_parsing *parse)
{
	t_list	*tmp;
	char	*lvl;

	tmp = parse->lst_env;
	while (tmp)
	{
		if (ft_strnstr(tmp->str, "SHLVL=", 6))
		{
			lvl = ft_increment_shlvl(tmp->str);
			free(tmp->str);
			tmp->str = ft_strdup(lvl);
			free(lvl);
		}
		tmp = tmp->next;
	}
}

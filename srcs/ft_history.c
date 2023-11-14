/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:19:08 by chmassa           #+#    #+#             */
/*   Updated: 2023/11/14 12:13:14 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_clear_history(t_parsing *parse)
{
	if (unlink(".history") != 0)
		perror("Error: deleting history file\n");
	parse->fd_history[1] = open(".history",
			O_RDWR | O_CREAT | O_APPEND, 0644);
	if (parse->fd_history[1] < 0)
		perror(".history");
}

void	ft_check_history_size(t_parsing *parse)
{
	int		nb_line;
	char	*s;

	nb_line = 0;
	parse->fd_history[0] = open(".history", O_RDONLY);
	
	if (parse->fd_history[0] < 0)
		perror(".history");
	
	while (1)
	{
		s = get_next_line(parse->fd_history[0]);
		if (!s)
		{
			free(s);
			break ;
		}
		free(s);
		nb_line++;
	}
	if (nb_line > 10000)
		ft_clear_history(parse);
	close(parse->fd_history[0]);
}

void	ft_print_history(t_parsing *parse)
{
	char	*ret;
	int		nb_line;

	nb_line = 1;
	parse->fd_history[0] = open(".history", O_RDONLY);
	if (parse->fd_history[0] < 0)
		perror(".history");
	while (1)
	{
		ret = get_next_line(parse->fd_history[0]);
		if (!ret)
		{
			free(ret);
			break ;
		}
		ft_printf("  %d\t%s", nb_line, ret);
		free(ret);
		nb_line++;
	}
	close(parse->fd_history[0]);
}

void	ft_add_history(t_parsing *parse)
{
	if (ft_strcmp(parse->tmp_input, parse->input) != 0)
	{
		add_history(parse->input);
		parse->tmp_input[0] = '\0';
	}
	ft_strcpy(parse->tmp_input, parse->input);
}

void	ft_history(t_parsing *parse)
{
	ft_putstr_fd(parse->input, parse->fd_history[1]);
	write (parse->fd_history[1], "\n", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:14:47 by cyildiri          #+#    #+#             */
/*   Updated: 2017/05/04 20:22:54 by cyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static	t_args	str_to_args(char *str, char delim)
{
	t_args args;

	args.count = ft_cntwords(str, delim);
	args.args = ft_strsplit(str, delim);
	return (args);
}

t_args			command_prompt(char *msg)
{
	char	*line;
	size_t	linelen;
	size_t	linecap;
	t_args	args;

	line = NULL;
	write(1, msg, strlen(msg));
	if ((linelen = getline(&line, &linecap, stdin)) > 0)
	{
		*strchr(line, '\n') = '\0';
		args = str_to_args(line, ' ');
	}
	else
	{
		args.args = NULL;
		args.count = 0;
	}
	free(line);
	return (args);
}

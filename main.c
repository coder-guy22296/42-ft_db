/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:50 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 15:46:51 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		main(void)
{
	t_db	db;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;

	load_db(&db);
	while ((linelen = getline(&line, &linecap, stdin)) > 0)
	{
		if (strncmp(line, "ADD ", 4) == 0)
			// add entry
		else if (strncmp(line, "SELECT ", 7) == 0)
			// select entry
		else if (strncmp(line, "UPDATE ", 7) == 0)
			// update entry
		else if (strncmp(line, "DELETE ", 7) == 0)
			// delete entry
		else if (strncmp(line, "EXIT", 4) == 0)
			return (0);
		else
			// invalid command
	}
	return (0);
}

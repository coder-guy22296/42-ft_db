/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:50 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 16:25:54 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		main(void)
{
	t_db	db;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	char	*command;

	load_db(&db);
	while ((linelen = getline(&line, &linecap, stdin)) > 0)
	{
		command = strtok(line, " ");
		if (strcmp(command, "ADD") == 0)
			add_table_entry(&db, strtok(NULL, " "), strtok(NULL, " "));
		else if (strcmp(command, "SELECT") == 0)
			printf("%s\n", get_table_entry(&db, strtok(NULL, " ")));
		else if (strcmp(command, "UPDATE") == 0)
			update_table_entry(&db, strtok(NULL, " "), strtok(NULL, " "));
		else if (strcmp(command, "DELETE") == 0)
			remove_table_entry(&db, strtok(NULL, " "));
		else if (strcmp(command, "EXIT") == 0)
			return (0);
		else
			printf("Invalid command\n");
	}
	return (0);
}

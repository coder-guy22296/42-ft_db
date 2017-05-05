/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:56:50 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 18:56:41 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		main(void)
{
	t_table	table;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	char	*command;

	load_table(&table);
	while ((linelen = getline(&line, &linecap, stdin)) > 0)
	{
		*strchr(line, '\n') = '\0';
		command = strtok(line, " ");
		if (strcmp(command, "INSERT") == 0)
			insert_table_entry(&table, strtok(NULL, " "), strtok(NULL, " "));
		else if (strcmp(command, "SELECT") == 0)
			select_table_entry(&table, strtok(NULL, " "));
		else if (strcmp(command, "UPDATE") == 0)
			update_table_entry(&table, strtok(NULL, " "), strtok(NULL, " "));
		else if (strcmp(command, "DELETE") == 0)
			delete_table_entry(&table, strtok(NULL, " "));
		else if (strcmp(command, "EXIT") == 0)
			return (0);
		else
			printf("Invalid command\n");
	}
	return (0);
}

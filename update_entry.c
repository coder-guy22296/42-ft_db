/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:58:39 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 16:01:38 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	update_table_entry(t_db *database, char *key, char *new_value)
{
	t_row	*cur;

	cur = database->row;
	while (cur)
		if (strcmp(cur->key, key) == 0)
			break;
	if (!cur)
	{
		// key not found
		return;
	}
	free(cur->value);
	cur->value = strdup(new_value);
	write_table_to_file(database);
}

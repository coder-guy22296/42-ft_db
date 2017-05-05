/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_table_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:58:39 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 19:11:19 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	update_table_entry(t_table *table, char *key, char *new_value)
{
	t_row	*cur;

	if (!key || !new_value)
	{
		// key or new_value is NULL
		return;
	}
	cur = table->row;
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
	write_table_to_file(table);
}
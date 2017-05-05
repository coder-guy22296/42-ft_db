/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_table_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:58:39 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 20:15:42 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	update_table_entry(t_table *table, char *key, char *new_value)
{
	t_row	*cur;

	if (!key || !new_value || strchr(key, ',') || strchr(new_value, ','))
	{
		return ;
	}
	cur = table->row;
	while (cur)
		if (strcmp(cur->key, key) == 0)
			break ;
	if (!cur)
	{
		printf("Key not found\n");
		return ;
	}
	free(cur->value);
	cur->value = strdup(new_value);
	write_table_to_file(table);
}

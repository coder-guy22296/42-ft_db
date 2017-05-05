/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_table_entry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:02:29 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 18:43:56 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	delete_table_entry(t_table *table, char *key)
{
	t_row	**cur;
	t_row	*to_delete;

	cur = &table->row;
	while (*cur && strcmp((*cur)->key, key))
		cur = &(*cur)->next;
	if (!*cur)
	{
		// key not found
		return;
	}
	to_delete = *cur;
	*cur = (*cur)->next;
	free(to_delete);
	write_table_to_file(table);
}

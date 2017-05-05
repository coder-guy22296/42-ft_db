/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:12:09 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 23:15:50 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	free_table(t_table *table)
{
	t_row	*cur;
	t_row	*next;

	cur = table->row;
	while (cur)
	{
		next = cur->next;
		free(cur->key);
		free(cur->value);
		free(cur);
		cur = next;
	}
}

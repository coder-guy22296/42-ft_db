/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_table_to_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:51:37 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 18:41:10 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	write_table_to_file(t_table *table)
{
	FILE	*fp;
	t_row	*cur;

	if (!(fp = fopen(FN, "w")))
		return ;
	cur = table->row;
	while (cur)
	{
		fprintf(fp, "%s,%s\n", cur->key, cur->value);
		cur = cur->next;
	}
	fclose(fp);
}

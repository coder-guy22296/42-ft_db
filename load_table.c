/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:17:51 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 19:10:19 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

// alloation errors should be handled here and freed properly

void	load_table(t_table *table)
{
	FILE	*fp;
	t_row	**cur;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;

	table->row = NULL;
	if (!(fp = fopen(FN, "r")))
	{
		// error: can't open file
		return;
	}
	cur = &table->row;
	line = NULL;
	linecap = 0;
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		*strchr(line, '\n') = '\0';
		*cur = (t_row*)malloc(sizeof(**cur));
		(*cur)->key = strdup(strtok(line, ","));
		(*cur)->value = strdup(strtok(NULL, ","));
		(*cur)->next = NULL;
		cur = &(*cur)->next;
	}
	fclose(fp);
}

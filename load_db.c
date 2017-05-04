/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:17:51 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 15:38:06 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	load_db(t_db *db)
{
	FILE	*fp;
	t_row	**cur;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;
	
	if (!(fp = fopen("database", "r")))
	{
		// error: can't open file
		return;
	}
	db->row = NULL;
	cur = &db->row;
	line = NULL;
	linecap = 0;
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		*cur = (t_row*)malloc(sizeof(**cur));
		(*cur)->key = strdup(strtok(line, ","));
		(*cur)->value = strdup(strtok(NULL, ","));
		(*cur)->next = NULL;
		cur = &(*cur)->next;
	}
}

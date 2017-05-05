/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:17:51 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 23:32:41 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static void	init_row(t_row *cur, char *line)
{
	char	*tok;

	cur->key = strdup(strtok(line, ","));
	tok = strtok(NULL, ",");
	cur->value = (tok) ? strdup(tok) : strdup("");
	cur->next = NULL;
}

void		load_table(t_table *table)
{
	FILE	*fp;
	t_row	*cur;
	char	*line;
	size_t	linecap;
	ssize_t	linelen;

	table->row = NULL;
	if (!(fp = fopen(FN, "r")))
		return ;
	line = NULL;
	linecap = 0;
	while ((linelen = getline(&line, &linecap, fp)) > 0)
	{
		if (!strchr(line, ',') || strchr(line, ',') != strrchr(line, ','))
			return ;
		*strchr(line, '\n') = '\0';
		cur = (t_row*)malloc(sizeof(*cur));
		init_row(cur, line);
		cur->next = table->row;
		table->row = cur;
	}
	free(line);
	fclose(fp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:06:54 by jshi              #+#    #+#             */
/*   Updated: 2017/05/04 15:10:54 by jshi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_row
{
	char			*key;
	char			*value;
	struct s_row	*next;
}					t_row;

typedef struct		s_db
{
	t_row			*row;
}					t_db;
#endif

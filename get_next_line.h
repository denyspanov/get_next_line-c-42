/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:02:06 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/16 16:02:08 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_GET_NEXT_LINE_FT_
#define _FT_GET_NEXT_LINE_FT_
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 20
typedef struct node {
	char *str;
	char *buff;
	char *rez;
	long readed;
	int flag;
}   node_t;
int get_next_line(const int fd, char **line);
#endif
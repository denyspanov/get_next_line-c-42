/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:02:06 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/22 19:38:21 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 100

typedef	struct			s_node
{
	char				*stock;
	int					fd;
	struct s_node		*next;
}						t_node;
int						get_next_line(int const fd, char **line);
#endif

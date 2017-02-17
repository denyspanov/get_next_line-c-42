/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpanov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:01:53 by dpanov            #+#    #+#             */
/*   Updated: 2017/02/16 16:01:56 by dpanov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void d_m(node_t **head)
{
	(*head)->str = ft_strjoin((*head)->str,(*head)->buff);
}

int	chec_enter(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void rezz(node_t **head)
{
	int i;
	int j;

	i = 0;
	while((*head)->str[i] != '\0')
	{
		if ('\n' == (*head)->str[i])
			break;
		i++;
	}
	j = 0;
	i++;
	while((*head)->str[i] != '\0')
	{
		(*head)->str[j] = (*head)->str[i];
		j++;
		i++;
	}
	(*head)->str[j] = '\0';
}

int get_next_line(const int fd, char **line)
{
	static node_t *head = NULL;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (head == NULL)
	{
		head = (node_t *) malloc(sizeof(node_t));
		head->rez = ft_strnew(1);
		head->str = ft_strnew(1);
		head->flag = 0;
	}
	if (!(head->buff = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (chec_enter(head->str))
	{
		*line = ft_strncpy(head->rez, head->str, chec_enter(head->str));
		rezz(&head);
		return (1);
	}
	while ((head->readed = read(fd,head->buff,BUFF_SIZE)) > 0)
	{
		d_m(&head);
		if (chec_enter(head->str))
		{
			*line = ft_strncpy(head->rez,head->str, chec_enter(head->str));
			rezz(&head);
			return (1);
		}
	}
	if (head->readed == 0 && head->flag == 0 && (chec_enter(head->str)))
	{
		*line = head->str;
		head->flag++;
		free(head->str);
		return (1);
	}
	return (1);
}
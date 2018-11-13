/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:59:43 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/12 11:59:45 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static char		*ft_strconcat(char *s1, char *s2)
{
	int		i;
	char	*ptr;

	i = -1;
	if (!(ptr = (char *)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

static int		add_line(char **str, char **line, char *newline)
{
	char	*tmp;

	if (newline || **str)
	{
		tmp = *str;
		*line = (newline ? ft_strsub(*str, 0, newline - *str) :
			ft_strdup(*str));
		*str = (newline ? ft_strdup(newline + 1) : ft_strdup("\0"));
		free(tmp);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*str[4864];
	char		*newline;

	if (fd < 0 || fd > 4864 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] && (newline = ft_strchr(str[fd], '\n')))
		return (add_line(&str[fd], line, newline));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str[fd] = (!str[fd] ? ft_strdup(buf) : ft_strconcat(str[fd], buf));
		if ((newline = ft_strchr(str[fd], '\n')))
			break ;
	}
	return (ret < 0 ? (-1) : (add_line(&str[fd], line, newline)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabid <moabid@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:04:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/12 23:05:29 by moabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_read
{
	int				fd;
	char			*str;
	struct s_read	*next;
}				t_read;

size_t	ft_strlen(char *s);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*get_next_line(int fd);
int		new_line_checker(char *s);
t_read	*init_struct(int fd);
t_read	*check_fd(t_read *read, int fd);
t_read	*clear_head(t_read *read, int fd);
char	*free_and_cpy_reminder(char *str);
char	*return_line(char *str);
char	*read_file(int fd, char *str);

#endif

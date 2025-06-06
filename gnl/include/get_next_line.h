/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvon-de <fvon-der@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:25:11 by fvon-de           #+#    #+#             */
/*   Updated: 2024/10/22 22:25:11 by fvon-de          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 100
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

char	*get_next_line(int fd);
char	*eof_residue(int fd, char *line, char *buffer, int *eol_posi);
char	*copy_full_line(char *buffer, int *eol_posi);
size_t	find_eol(char *line);

char	*ft_partstrjoin(char *s1, char *s2, int *eol_loc);
void	shift_buffer(char *dst, const char *src, size_t dstsize);
void	cleanup_get_next_line(void);

#endif
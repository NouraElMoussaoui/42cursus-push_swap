/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-mous <nel-mous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:43:50 by nel-mous          #+#    #+#             */
/*   Updated: 2023/03/18 12:04:35 by nel-mous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

int				ft_isdigit(int c);
void			ft_putstr(char *str);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *a);
long long		ft_atoi(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_stack			*ft_lstnew(int content);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
int				ft_lstsize(t_stack *lst);
char			**ft_split(char const *s, char c);
int				ft_strcmp(const char *S1, const char *S2);
char			*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
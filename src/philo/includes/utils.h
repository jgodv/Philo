/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:33:47 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 21:20:05 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* time.c */
uint64_t	get_ms_time(void);
void		take_a_nap_during_that_time(uint64_t that_time);

/* utils.c */
int	char_to_uint64(const char *str);
void	*ft_calloc(size_t count, size_t size);
void    output(t_report *report);
void	*unlock_and_return(pthread_mutex_t *mutex, void *val);

void	clear_all_asset(t_meta *meta);

#endif
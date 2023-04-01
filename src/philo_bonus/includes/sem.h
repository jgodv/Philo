/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:19:24 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:29:30 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEM_H
# define SEM_H

void	close_and_unlink_sem(sem_t *sem, const char *name);
void	*post_and_return(sem_t *sem, void *val);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/26 21:10:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "queue.h"

void	philo_take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork[L]);
	enqueue(philo->box, write_report(philo, PHILO_FORK));
}

void	philo_take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork[R]);
	enqueue(philo->box, write_report(philo, PHILO_FORK));
}
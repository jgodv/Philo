/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/04/01 19:23:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "utils.h"
#include "life.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->last_meal_sem);
	philo->last_meal = get_micro_time();
	sem_post(philo->last_meal_sem);
	output(philo->print_sem, write_report(philo, PHILO_EAT));
	take_a_nap_during_that_time(philo->args->time_to_eat);
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
	philo->eat_cnt++;
}

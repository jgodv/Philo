/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   be_born_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:15 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 15:55:58 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "life.h"
#include "error.h"
#include "utils.h"

bool be_born_philo(t_meta *meta)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&meta->mutex.start_mt);
	while (i < meta->args.num_of_philo)
	{
		if (i == meta->args.num_of_philo - 1)
			meta->start_time = get_ms_time();
		if(pthread_create(meta->table.tids + i, NULL, begin_life, meta->table.philos + i))
			return (prt_err(ERR_THD_CREATE, THD_ERROR));
		i++;
	}
	pthread_mutex_unlock(&meta->mutex.start_mt);
	return (true);
}
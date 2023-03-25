/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:48:28 by jgo               #+#    #+#             */
/*   Updated: 2023/03/25 14:24:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "def.h"
#include "error.h"

// 1 초(second) = 1,000 밀리초(millisecond) = 1,000,000 마이크로초(microsecond)
//  마이크로초와 밀리초는 1,000배 관계이며, 밀리초와 초는 1,000배 관계입니다. 
uint64_t get_ms_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	take_a_nap_during_that_time(uint64_t start_time, uint64_t that_time)
{
	uint64_t	current_time;
	uint64_t	end_time;

	end_time = start_time + that_time;
	while (true)
	{
		current_time = get_ms_time();
		if (current_time > end_time)
			break ;
		if (current_time < start_time + (that_time * 0.9))
			usleep(300);
	}
}

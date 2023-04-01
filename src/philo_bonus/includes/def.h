/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:43:05 by jgo               #+#    #+#             */
/*   Updated: 2023/03/21 11:35:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

/*-------------- INCLUDE --------------*/
# include "enum.h"
# include "const.h"

/*-------------- TYPEDEF --------------*/
typedef struct s_meta		t_meta;
typedef struct s_philo		t_philo;
typedef struct s_state		t_state;
typedef struct s_args		t_args;
typedef struct s_table		t_table;
typedef struct s_report		t_report;
typedef struct s_terminate	t_terminate;
typedef struct s_meta_sem	t_meta_sem;
typedef struct s_sem		t_sem;

typedef union u_sem_val	t_u_sem_val;

/*-------------- UNION --------------*/
union u_sem_val
{
	int			i;
	bool		b;
	uint64_t	u;
};

/*-------------- STRUCT --------------*/
struct s_state
{
	t_proc_state	state;
};

struct s_report
{
	uint64_t		time_stamp;
	int				num;
	t_philo_state	state;
};

struct s_sem
{
	t_u_sem_val	val;
	sem_t		*sem;
};

struct s_philo
{
	int				idx;
	t_args			*args;
	t_report		report;
	int				eat_cnt;
	uint64_t		last_meal;
	sem_t			*fork_sem;
	sem_t			*print_sem;
	pthread_t		moniter_thd;
	sem_t			*counter_sem;
	sem_t			*life_sem;
	sem_t			*terminate_sem;
	pid_t			*pids;

};

struct s_args
{
	int				num_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				num_of_must_eat;
	uint64_t		start_time_of_sim;
};

struct s_table
{
	t_philo			philo;
	pid_t			*pids;
	sem_t			*fork_sem;
};

struct s_meta_sem
{
	sem_t	*counter_sem; // bi
	sem_t	*print_sem; // bi //한번에 한명씩 순서대로 출력해야하기 때문에. 여러명이 출력할 수 있다면 순서가 꼬일 수 있다. 
	sem_t	*terminate_sem;
};

struct s_meta
{
	t_args			args;
	t_table			table;
	t_meta_sem		sem;
	pthread_t		meal_counter;
};

#endif
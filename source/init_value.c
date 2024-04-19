/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:48:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/19 14:29:59 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Init struct with initial data
 * @return A struct with data filled.
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->argc_qt = argc;
	data->philoandfork_qt = ft_atoi(argv[1]);
	data->die_timeto = ft_atoi(argv[2]);
	data->eat_timeto = ft_atoi(argv[3]);
	data->sleep_timeto = ft_atoi(argv[4]);
	if (argc > 5)
		data->musteat_times = ft_atoi(argv[5]);
	else
		data->musteat_times = 0;
	data->thr_arr = alloc_thread(data->philoandfork_qt);
	data->mtx_arr = alloc_mutex(data->philoandfork_qt);
	data->ph = malloc(sizeof(t_philo) * data->philoandfork_qt);
	if (!data->ph)
		return ;
	data->ph->id = 0;
	
}
pthread_t	*alloc_thread(int qt)
{
	pthread_t *thread;

	thread = malloc(sizeof(pthread_t) * qt);
	if (!thread)
		return (NULL);
	return (thread);
}

void    init_threads(t_data *data)
{
    int i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		data->ph[i].id = i;
		if (pthread_create(&data->thr_arr[i], NULL,
			&start_routine, &data->ph[i]) != 0)
			errormsg_and_exit("Error\nError creating threads", EXIT_FAILURE);
		i ++;
	}
	i = 0;
	while (i < data->philoandfork_qt)
		if (pthread_join(data->thr_arr[i ++], NULL) != 0)
			errormsg_and_exit("Error\nError thread join", EXIT_FAILURE);
}
/**
 * @brief Alloc space for mutexes
 * @param qt 
 * @return 
*/
pthread_mutex_t	*alloc_mutex(int qt)
{
	pthread_mutex_t *mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * qt);
	if (!mutex)
		return (NULL);
	return (mutex);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philoandfork_qt)
		pthread_mutex_init(&data->mtx_arr[i ++], NULL);
}
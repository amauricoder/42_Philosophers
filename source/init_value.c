/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:48:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/20 17:36:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Init struct  and philo struct with initial data,
 * init mutexes and atributes the left/right fork ptr to the equivalent mutex.
 * @return A struct with data filled.
*/
void	init_data(int argc, char **argv, t_data *data)
{
	data->argc_qt = argc;
	data->philoandfork_qt = ft_atoi(argv[1]);
	data->die_timeto = ft_atoi(argv[2]);
	data->eat_timeto = ft_atoi(argv[3]);
	data->sleep_timeto = ft_atoi(argv[4]);
	data->musteat_times = 0;
	if (argc > 5)
		data->musteat_times = ft_atoi(argv[5]);
	data->start_time = get_time();
	alloc_and_init_mutex(data->philoandfork_qt, data);
	data->ph = malloc(sizeof(t_philo) * data->philoandfork_qt);
	if (!data->ph)
		return ;
	init_philo(data);
}
/**
* @brief Allocate memory for the treaton the main struct.
* @param qt Quantity of space necessary to alloc.
*/
pthread_t	*alloc_thread(int qt)
{
	pthread_t *thread;

	thread = malloc(sizeof(pthread_t) * qt);
	if (!thread)
		return (NULL);
	return (thread);
}

/**
 * @brief Alloc space for mutexes and init every mutex individually.
 * @param qt Quantity of space necessary to alloc.
*/
void	alloc_and_init_mutex(int qt, t_data *data)
{
	int i;

	data->all_forks = malloc(sizeof(pthread_mutex_t) * qt);
	if (!data->all_forks)
		return ;	
	i = 0;
	while (i < qt)
		pthread_mutex_init(&data->all_forks[i ++], NULL);
}
/**
 * @brief Gives the pointers of the left and right fork of the philo struct
 * to the corresponding mutex
 * @param data Main struct.
*/
void	attribute_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philoandfork_qt)
	{
		data->ph[i].left_fork = &data->all_forks[i];
		if (i == 0)
			data->ph[i].right_fork = &data->all_forks[data->philoandfork_qt - 1];			
		else
			data->ph[i].right_fork = &data->all_forks[i - 1];
		if (!data->ph[i].right_fork || !data->ph[i].left_fork)
				errormsg_and_exit("Error\nAtr Forks!", 1);
		i ++;
	}
}

void	init_philo(t_data *data)
{
	int i;

	i = -1;
	while (++ i < data->philoandfork_qt)
	{
		data->ph[i].main = data;
		data->ph[i].left_fork = NULL;
		data->ph[i].right_fork = NULL;
		data->ph[i].id = 0;
		data->ph[i].thread = malloc(sizeof(pthread_t));
		if (!data->ph[i].thread)
			return ;		
	}
}
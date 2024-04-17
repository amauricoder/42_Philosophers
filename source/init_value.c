/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:48:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/17 13:26:07 by aconceic         ###   ########.fr       */
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
	data->threads_arr = alloc_thread(data->philoandfork_qt);
	//data->mtx_arr = alloc_mutex(data->philoandfork_qt);
}
pthread_t	**alloc_thread(int qt)
{
	int	i;
	pthread_t **threads_arr;
	pthread_t *thread;

	threads_arr = malloc(sizeof(pthread_t) * qt);
	i = 0;
	while (i < qt)
	{
		thread = malloc(sizeof(thread));
		if (!thread)
			return (NULL);
		threads_arr[i] = thread;
		i ++;
	}
	return (threads_arr);
}

void    init_threads(t_data data)
{
    int i;

	i = 0;
	while (i < data.philoandfork_qt)
	{
		if (pthread_create(data.threads_arr[i], NULL,
			&start_routine, &data) != 0)
			errormsg_and_exit("Error\nError creating threads", EXIT_FAILURE);
		i ++;
	}
	i = 0;
	while (i < data.philoandfork_qt)
		if (pthread_join(*(data.threads_arr[i ++]), NULL) != 0)
			errormsg_and_exit("Error\nError thread join", EXIT_FAILURE);
}

/* pthread_mutex_t	**alloc_mutex(int qt)
{
	int i;

	i = 0;
	while (i < qt)
	{
		
	}
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:48:28 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/16 17:47:29 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Init struct with initial data
 * @return A struct with data filled.
*/
void	init_struct(int argc, char **argv, t_data *values)
{
	values->argc_qt = argc;
	values->philoandfork_qt = ft_atoi(argv[1]);
	values->die_timeto = ft_atoi(argv[2]);
	values->eat_timeto = ft_atoi(argv[3]);
	values->sleep_timeto = ft_atoi(argv[4]);
	if (argc > 5)
		values->musteat_times = ft_atoi(argv[5]);
	else
		values->musteat_times = 0;
	values->threads_arr = alloc_thread(values->philoandfork_qt);

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
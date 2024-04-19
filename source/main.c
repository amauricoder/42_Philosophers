/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/19 14:26:26 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//number_of_philosophers[1] time_to_die[2] time_to_eat[3] time_to_sleep[4]
//[number_of_times_each_philosopher_must_eat[5]
//./philo 5 200 50 50 5


int	main(int argc, char **argv)
{
	t_data		d;

	memset(&d, 0, sizeof(t_data));
	if (!argument_isvalid(argc, argv))
		errormsg_and_exit("Error\nInvalid Arguments", EXIT_FAILURE);
	init_data(argc, argv, &d);
	init_mutex(&d);
	init_threads(&d);
	
	//printf("main() data->number value %i\n", d.number);
	//-----------------------------------------------
	//printf("main philo->id %i\n", d.ph[3].id);

	//-----------------------------------------------
	free_struct(&d);
}

//int gettimeofday ( struct timeval *tp ,  struct timezone *tz );

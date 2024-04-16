/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/16 17:46:50 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//number_of_philosophers[1] time_to_die[2] time_to_eat[3] time_to_sleep[4]
//[number_of_times_each_philosopher_must_eat[5]
//./philo 5 200 50 50 5
int	main(int argc, char **argv)
{
	t_data	philo;

	memset(&philo, 0, sizeof(t_data));
	if (!argument_isvalid(argc, argv))
		errormsg_and_exit("Error\nInvalid Arguments", EXIT_FAILURE);
	init_struct(argc, argv, &philo);
	//-----------------------------------------------
	int i = 0;
	printf("quantity of philo from main => %i\n", philo.philoandfork_qt);
	while (i < philo.philoandfork_qt)
	{
		//printf("i from main => %i\n", i);
		if (pthread_create(philo.threads_arr[i], NULL, &printf_runningthr, NULL) != 0)
			errormsg_and_exit("Error\nError creating threads", EXIT_FAILURE);
		i ++;
	}
	i = 0;
	while (i < philo.philoandfork_qt)
		if (pthread_join(*(philo.threads_arr[i ++]), NULL) != 0)
			errormsg_and_exit("Error\nError thread join", EXIT_FAILURE);
	
	//-----------------------------------------------
	//free_struct(philo);
}

//int gettimeofday ( struct timeval *tp ,  struct timezone *tz );

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_sessions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:04:08 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/03 13:57:31 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//https://linuxhint.com/gettimeofday_c_language/

void get_time_test(void)
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds %li\n", current_time.tv_sec);
    printf("microseconds %li\n", current_time.tv_usec);
}

void get_time_usleep(void)
{
	struct timeval 	start_time;
	struct timeval 	end_time;
	long			request_sleep_time;
	long			actual_sleep_time;

	request_sleep_time = 200 * 1000;
	gettimeofday(&start_time, NULL);
	usleep(request_sleep_time);
	gettimeofday(&end_time, NULL);
	actual_sleep_time = (end_time.tv_sec - start_time.tv_sec) * 1000000
		+ (end_time.tv_usec + end_time.tv_usec);
	
	printf("Requested sleep time %ld\n", request_sleep_time);
	printf("Actual sleep time %ld\n", actual_sleep_time);
}
void *printf_runningthr(void *arg)
{
 /*    t_data	*philo;
	philo = (t_data *)arg;
	pthread_mutex_lock(mtx);
	printf("%d\n", philo->n);
	philo->n++;
	pthread_mutex_unlock(mtx); */
	printf("Thread is running\n");
    usleep(500);
    printf("Ending thread\n");
	(void)arg;
    return NULL;
}

//------------------------------------------------------------------
//Learning Threads, more information on notes.
/* int i = 0;
	printf("quantity of philo from main => %i\n", philo->philoandfork_qt);
	while (i < philo->philoandfork_qt)
	{
		//printf("i from main => %i\n", i);
		if (pthread_create(philo->thr_arr[i], NULL, &printf_runningthr, NULL) != 0)
			return (1);
		i ++;
	}
	i = 0;
	while (i < philo->philoandfork_qt)
		if (pthread_join(*(philo->thr_arr[i ++]), NULL) != 0)
			return (1);
	 */
//-------------------------------------------------------------------



/* 

TEST THIS ./philo 2 500 300 200


Do not test with more than 200 philosophers.
Do not test with time_to_die or time_to_eat or time_to_sleep set to values lower than 60 ms.
Test 1 800 200 200. The philosopher should not eat and should die.
Test 5 800 200 200. No philosopher should die.
Test 5 800 200 200 7. No philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times.
Test 4 410 200 200. No philosopher should die.
Test 4 310 200 100. One philosopher should die.
Test with 2 philosophers and check the different times: a death delayed by more than 10 ms is unacceptable.
Test with any values of your choice to verify all the requirements. Ensure philosophers die at the right time, that they don't steal forks, and so forth.
 */
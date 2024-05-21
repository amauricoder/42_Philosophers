/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:49 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/07 11:13:05 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/******************************/
/*    COLORS ANSI ESCAPE      */
/******************************/
# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[33m"
# define ORANGE "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MGT "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

/**************************************/
/*             External Libs          */
/**************************************/
//
# include <stdlib.h> //malloc
# include <sys/types.h> //fork
# include <unistd.h> //write, fork, usleep
# include <stdio.h> //ft_printf
# include <string.h> //memset
# include <sys/time.h> // gettimeofday
# include <sys/wait.h> // wait, waitpid, waitid
# include <pthread.h> // thread_create
# include <limits.h> //int_max int_min

/**************************************/
/*             Structs                */
/**************************************/
typedef struct s_forks
{
	int				fork_id;
	pthread_mutex_t	*fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				meals_qt;
	int				is_full;
	size_t			last_meal_time;
	pthread_t		*thread;
	t_fork			*left_fork;
	t_fork			*right_fork;
	struct s_data	*main;
}	t_philo;

//main struct
typedef struct s_data
{
	int				argc_qt;
	int				philoandfork_qt;
	int				die_timeto;
	int				eat_timeto;
	int				sleep_timeto;
	int				musteat_times;
	int				is_someone_dead;
	int				qt_philo_full;
	int				table_is_ready;
	int				stop_simulation;
	pthread_mutex_t	*table_mutex;
	pthread_mutex_t	*full_mutex;
	size_t			start_time;
	t_fork			*all_forks;
	t_philo			*ph;
}	t_data;

/**************************************/
/*       MAIN -> source/main.c        */
/**************************************/
//
int					main(int argc, char **argv);

/**************************************/
/*   FT_UTILS -> source/ft_utils.c    */
/**************************************/
//
int					ft_strlen(char *str);
int					ft_strcmp(char *str1, char *str2);
int					ft_atoi(char *number);
size_t				get_time(void);
void				ft_usleep(size_t time, t_philo *philo);

/**************************************/
/*   FT_UTILS2 -> source/ft_utils2.c    */
/**************************************/
//
size_t				convert_sizet(int number);
int					is_simulation_stoped(t_philo *philo);

/**************************************/
/* INPUT_VALID -> source/input_valid.c */
/**************************************/
//
int					argument_isvalid(int argc, char **argv);
int					is_digit(char **argv);
int					is_null(char **argv);
int					is_intvalid(char **argv);
/**************************************/
/*     error -> source/error.c        */
/**************************************/
//
int					errormsg_and_exit(char *msg, int exit_code);

/**************************************/
/*     frees -> source/fress.c        */
/**************************************/
//
void				free_struct(t_data *data);
void				destroy_mutex(t_data *data);

/**************************************/
/*INIT VALUES -> source/init_values.c */
/**************************************/
//
void				init_data(int argc, char **argv, t_data *values);
pthread_t			*alloc_thread(int qt);
void				alloc_and_init_mutex(int qt, t_data *data);
int					attribute_forks(t_data *data);
void				init_philo(t_data *data);

/**************************************/
/*   diner -> source/dinner_table.c   */
/**************************************/
//
void				*dinner_routine(void *arg);

/**************************************/
/*   threads -> source/threads.c      */
/**************************************/
//
int					start_threads(t_data *data);
void				preparing_table(t_philo *philo);

/*******************************************/
/*  dinner utils-> source/dinner_utils.c */
/*******************************************/
//
void				*lonely_dinner(void *arg);
int					stop_sim(t_philo *philo);
int					even_philo_take_fork(t_philo *philo, size_t current_time);
int					odd_philo_take_fork(t_philo *philo, size_t current_time);
#endif
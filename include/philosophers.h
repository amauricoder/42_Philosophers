/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:49 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 17:23:10 by aconceic         ###   ########.fr       */
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
# include <fcntl.h> //sem_open
# include <sys/stat.h> //sem_open
# include <semaphore.h> //sem_open
# include <pthread.h> // thread_create

/**************************************/
/*             Structs                */
/**************************************/
typedef	struct s_forks
{
	int				fork_id;
	pthread_mutex_t *fork;
}	t_fork;

typedef	struct s_philo
{
	int				id;
	int				meals_qt;
	int				is_full;
	int				is_dead;
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
	int				table_is_ready;
	pthread_mutex_t	*table_mutex;
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
size_t				get_time();

/**************************************/
/* INPUT_VALID -> source/input_valid.c */
/**************************************/
//
int					argument_isvalid(int argc, char **argv);
int					is_digit(char **argv);
int					is_null(char **argv);

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
int    				start_threads(t_data *data);
void				preparing_table(t_philo *philo);
/**************************************/
/*                DEBUG               */
/**************************************/
//
void				get_time_test(void);
void 				*printf_runningthr(void *arg);
void				get_time_usleep(void);

#endif
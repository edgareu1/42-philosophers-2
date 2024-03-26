#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}					t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mutex_state;
	pthread_mutex_t	mutex_nb_meals_had;
	pthread_mutex_t	mutex_last_eat_time;
	u_int64_t		last_eat_time;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	mutex_eat_t;
	pthread_mutex_t	mutex_die_t;
	pthread_mutex_t	mutex_sleep_t;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_nb_philos;
	pthread_mutex_t	mutex_keep_iter;
	pthread_mutex_t	mutex_start_time;
	pthread_t		monitor_alive;
	pthread_t		monitor_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

// eat.c
void		return_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_forks(t_philo *philo);
void		update_last_meal_time(t_philo *philo);
int			eat(t_philo *philo);

// getters.c
uint64_t	get_time_die(t_data *data);
uint64_t	get_time_sleep(t_data *data);
uint64_t	get_time_eat(t_data *data);
uint64_t	get_time_last_eat(t_philo *philo);
bool		get_keep_iter(t_data *data);
int			get_nb_philos(t_data *data);
t_state		get_philo_state(t_philo *philo);
int			get_nb_meals_philo_had(t_philo *philo);
uint64_t	get_time_start(t_data *data);

// init_data.c
int			init_forks(t_data *data);
int			init_philos(t_data *data);
int			init_data(t_data *data, int argc, char **argv);

// monitoring.c
bool		is_philo_dead(t_philo *philo);
void		*routine_full(void *data_p);
void		*routine_alive(void *data_p);

// parse.c
int			check_input_values(int argc, char **argv);
int			check_input(int argc, char **argv);

// routine.c
void		*routine(void *philo_p);

// setters.c
void		set_keep_iterating(t_data *data, bool set_to);
void		set_philo_state(t_philo *philo, t_state state);

// sleep.c
int			ft_sleep(t_philo *philo);

// think.c
int			think(t_philo *philo);

// time.c
void		ft_usleep(uint64_t time);
u_int64_t	get_time(void);

// utils.c
int			ft_atoi(char *str);
bool		has_nb_meals(t_data *data);
void		free_data(t_data *data);
void		print_message(t_data *data, int id, char *msg);

#endif

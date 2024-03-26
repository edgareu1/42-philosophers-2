#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <semaphore.h>

# include <sys/wait.h>
# include <fcntl.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2
# define FORK_ERROR 3
# define SEM_ERROR 4
# define THREAD_ERROR 4

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING,
	DEAD,
	FULL,
	IDLE,
	FINISH,
	SLEEPING
}					t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	u_int64_t		last_eat_time;
	sem_t			*sem_philo;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	pthread_t		monitor;
	t_philo			philo;
}					t_data;

// eat.c
int			eat(t_data *data);

// getter.c
uint64_t	get_time_last_eat(t_data *data);
t_state		get_philo_state(t_data *data);
uint64_t	get_time_start(t_data *data);

// init_data.c
int			init_data(t_data *data, int argc, char **argv);

// monitor.c
bool		did_someone_die(void);
void		announce_dead(void);
void		*monitor_death(void *data_p);

// parse.c
int			check_input(int argc, char **argv);

// print_message.c
int			print_message(t_data *data, char *msg);
void		print_sem(t_data *data, char *str);

// routine.c
char		*create_sem_name(int id);
bool		should_stop(t_state	state);
int			start_routine(t_data *data, int id);

// setters.c
void		set_philo_state(t_data *data, t_state state);
void		update_last_meal_time(t_data *data);

// sleep.c
void		elapse_time_eat(t_data *data);
int			ft_sleep(t_data *data);

// think.c
int			think(t_data *data);

// time.c
void		ft_usleep(uint64_t time);
u_int64_t	get_time(void);

// utils.c
size_t		ft_strlen(const char *s);
char		*ft_itoa(int n);
int			ft_atoi(char *str);
char		*ft_strjoin(char *s1, char *s2);

#endif

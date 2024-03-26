#include "../include/philo.h"

uint64_t	get_time_die(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mutex_die_t);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mutex_die_t);
	return (die_time);
}

uint64_t	get_time_sleep(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&data->mutex_sleep_t);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mutex_sleep_t);
	return (sleep_time);
}

uint64_t	get_time_eat(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->mutex_eat_t);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mutex_eat_t);
	return (eat_time);
}

uint64_t	get_time_last_eat(t_philo *philo)
{
	uint64_t	last_eat_time;

	pthread_mutex_lock(&philo->mutex_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mutex_last_eat_time);
	return (last_eat_time);
}

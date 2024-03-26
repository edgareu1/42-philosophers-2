#include "../include/philo.h"

bool	get_keep_iter(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mutex_keep_iter);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mutex_keep_iter);
	return (keep_iterating);
}

int	get_nb_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&data->mutex_nb_philos);
	nb_philos = data->nb_philos;
	pthread_mutex_unlock(&data->mutex_nb_philos);
	return (nb_philos);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mutex_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mutex_state);
	return (state);
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mutex_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mutex_nb_meals_had);
	return (nb_meals_had);
}

uint64_t	get_time_start(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mutex_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mutex_start_time);
	return (time);
}

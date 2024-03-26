#include "../include/philo_bonus.h"

int	drop_forks(t_data *data)
{
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	return (0);
}

bool	has_nb_meals(t_data *data)
{
	return (data->nb_meals > 0);
}

bool	philo_is_full(t_data *data)
{
	if (has_nb_meals(data) == false)
		return (false);
	if (data->nb_meals <= data->philo.nb_meals_had)
	{
		set_philo_state(data, FULL);
		return (true);
	}
	return (false);
}

int	take_forks(t_data *data)
{
	sem_wait(data->sem_forks);
	if (print_message(data, TAKE_FORKS))
	{
		sem_post(data->sem_forks);
		return (1);
	}
	if (data->nb_philos == 1)
		return (1);
	sem_wait(data->sem_forks);
	if (should_stop(get_philo_state(data)))
	{
		drop_forks(data);
		return (1);
	}
	if (print_message(data, TAKE_FORKS))
	{
		drop_forks(data);
		return (1);
	}
	return (0);
}

int	eat(t_data *data)
{
	if (take_forks(data))
		return (1);
	update_last_meal_time(data);
	set_philo_state(data, EATING);
	if (print_message(data, EAT))
	{
		drop_forks(data);
		return (1);
	}
	elapse_time_eat(data);
	drop_forks(data);
	data->philo.nb_meals_had++;
	if (philo_is_full(data))
		return (1);
	return (0);
}

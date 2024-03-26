#include "../include/philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mutex_last_eat_time);
}

void	update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_nb_meals_had);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->mutex_nb_meals_had);
}

void	elapse_time_eat(t_philo *philo)
{
	ft_usleep(get_time_eat(philo->data));
}

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	print_message(philo->data, philo->id, EAT);
	update_last_meal_time(philo);
	elapse_time_eat(philo);
	update_nb_meals_had(philo);
	drop_forks(philo);
	return (0);
}

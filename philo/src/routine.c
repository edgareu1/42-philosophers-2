#include "../include/philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}

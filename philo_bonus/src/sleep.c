#include "../include/philo_bonus.h"

void	elapse_time_eat(t_data *data)
{
	ft_usleep(data->eat_time);
}

int	ft_sleep(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_message(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}

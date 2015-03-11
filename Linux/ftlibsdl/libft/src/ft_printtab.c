#include "libft.h"
#include "ft_printf.h"

void	ft_printtab(int *tab, int max)
{
	int i;

	i = 0;
	while (i < max)
		ft_printf("tab [%d][%d]\n", i, tab[i]), i++;
}

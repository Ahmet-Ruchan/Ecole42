#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	q;

	q = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		arr = (int *) malloc((max - min) * sizeof(int));
		while (min != max)
		{
			arr[q] = min;
			min++;
			q++;
		}
		*range = arr;
		if (q == 0)
			return (-1);
		return (q);
	}
}	

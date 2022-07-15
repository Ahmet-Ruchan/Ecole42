#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	q;

	q = 0;
	if (min >= max)
		return (0);
	arr = (int *) malloc((max - min) * sizeof(int));
	while (min != max)
	{
		arr[q] = min;
		min++;
		q++;
	}
	return (arr);
}

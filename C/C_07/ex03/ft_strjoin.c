#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		index;
	char	*array;

	array = malloc(sizeof(strs));
	index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			array[index++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			array[index++] = sep[j++];
		i++;
	}
	array[index] = '\0';
	return (array);
}

#include <stdlib.h>

int		ft_atoi_base(char *str, char *charset);

int		len(char *str);

_Bool	is_valid(char *charset, int len);

int		find_num(char str, char *base);

char	*rec_func(int nbr, char *charset, int len, char *str)
{
	unsigned int	val;

	if (nbr < 0)
	{
		*str = '-';
		str++;
		val = -nbr;
	}
	else
	{
		val = nbr;
	}
	if (val >= (unsigned int) len)
		str = rec_func(val / len, charset, len, str);
	*str = charset[val % len];
	*(str + 1) = 0;
	return (str + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *charset)
{
	char	*str;
	int		val;

	str = (char *)malloc(sizeof(char) * 34);
	if (!is_valid(charset, len(charset)))
		return (0);
	if (!is_valid(base_from, len(base_from)))
		return (0);
	val = ft_atoi_base(nbr, base_from);
	rec_func(val, charset, len(charset), str);
	str[34] = 0;
	return (str);
}

int	new_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != 0 && find_num(str[i], charset) != -1)
		i++;
	return (i);
}

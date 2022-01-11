#include <stdlib.h>

int	is_a_err(char ch, char *base)
{
	while (*base != 0)
	{
		if (*base == ch)
			return (1);
		base++;
	}
	return (0);
}

int	strl(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i] != 0 && !is_a_err(str[i], base))
		i++;
	return (i);
}

int	find_str(char *str, char *base)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (*str != 0)
	{
		while (is_a_err(*str, base) && *str != 0)
			str++;
		if (*str == 0)
			return (c);
		c++;
		while (!is_a_err(*str, base) && *str != 0)
			str++;
	}
	return (c);
}

char	*strcopy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (*src != 0 && i < n)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_m;
	int		c;
	int		i;

	i = 0;
	c = find_str(str, charset);
	str_m = malloc(sizeof(char *) * c + 1);
	while (i < c)
	{
		while (is_a_err(*str, charset) && *str != 0)
			str++;
		if (*str == 0)
			return (str_m);
		str_m[i] = malloc(strl(str, charset) + 1);
		strcopy(str_m[i], str, strl(str, charset));
		while (!is_a_err(*str, charset) && *str != 0)
			str++;
		i++;
	}
	str_m[c] = 0;
	return (str_m);
}

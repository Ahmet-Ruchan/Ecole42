void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	c;
	int	aux[20];

	c = 0;
	index = size - 1;
	while (index >= 0)
	{
		aux[c] = tab[index];
		index--;
		c++;
	}
	c = 0;
	while (c < size)
	{
		tab[c] = aux[c];
		c++;
	}
}

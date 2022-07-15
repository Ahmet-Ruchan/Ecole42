#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int    ft_isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        printf("dogru\n"); //ascii 65-90 ve 97-122
    else
        printf("yanlis\n");
}

int    ft_isdigit(int c)
{
    if (c >= '0' && c <= '9') //ascii 48-57
        printf("dogru\n");
	else
        printf("yanlis\n");
}

int    ft_isalnum(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9'))
        printf("dogru\n"); //ascii 65-90 ve 97-122 ve 48-57
    else
        printf("yanlis\n");
}

int    ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        printf("dogru\n");
    else
        printf("yanlis\n");
}

int    ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        printf("dogru\n");
    else
        printf("yanlis\n");
}

size_t    ft_strlen(const char *s)
{
    size_t    l;

    l = 0;
    while (s[l] != 0)
        l++;
    return (l);
}

void    *ft_memset(void *b, int c, size_t    len)
{
    size_t    i;

    i = 0;
    while (i < len)
    {
        ((unsigned char *)b)[i] = c;
        i++;
    }
    return (b);
}

void    ft_bzero(void *s, size_t    n)
{
    ft_memset(s, '\0', n);
}

void    *ft_memcpy(void *dst, const void *src, size_t    n)
{
    size_t    i;

    if (!dst && !src)
        return (0);
    i = 0;
    while (i < n)
    {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        i++;
    }
    return (dst);
}

void    *ft_memmove(void *dst, const void *src, size_t    len)
{
    size_t    i;

    if (!dst && !src)
        return (0);
    i = 0;
    if ((size_t)dst - (size_t)src < len)
    {
        i = len - 1;
        while (i < len)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i--;
        }
    }
    else
    {
        while (i < len)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dst);
}

size_t    ft_strlcpy(char *dst, const char *src, size_t    dstsize)
{
    size_t    srcsize;
    size_t    i;

    if (!dst || !src)
        return (0);
    srcsize = ft_strlen(src);
    i = 0;
    if (dstsize != 0)
    {
        while (src[i] != '\0' && i < (dstsize - 1))
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (srcsize);
}

size_t    ft_strlcat(char *dst, const char *src, size_t    dstsize)
{
    size_t    c;
    size_t    d;

    if (dstsize <= ft_strlen(dst))
        return (dstsize + ft_strlen(src));
    c = ft_strlen(dst);
    d = 0;
    while (src[d] != '\0' && c + 1 < dstsize)
    {
        dst[c] = src[d];
        c++;
        d++;
    }
    dst[c] = '\0';
    return (ft_strlen(dst) + ft_strlen(&src[d]));
}

int    ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    return (c);
}

int    ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    return (c);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0' && c != *s)
        s++;
    if (c == *s)
        return ((char *)s);
    return (0);
}

char    *ft_strrchr(const char *s, int c)
{
    int                i;
    const char        *ini;

    ini = s;
    i = ft_strlen(s);
    s = (s + i);
    while (*s != *ini && c != *s)
        s--;
    if (c == *s)
        return ((char *)s);
    return (0);
}

int    ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t    i;

    if (n == 0)
        return (0);
    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        if (i < (n - 1))
            i++;
        else
            return (0);
    }
    return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s)[i] == (unsigned char)c)
            return ((void *)(s + i));
        i++;
    }
    return (0);
}

int    ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t    i;

    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
            return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
        i++;
    }
    return (0);
}

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t    h;
    size_t    n;

    h = 0;
    if (needle[0] == '\0')
        return ((char *)haystack);
    while (haystack[h] != '\0')
    {
        n = 0;
        while (haystack[h + n] == needle[n] && (h + n) < len)
        {
            if (haystack[h + n] == '\0' && needle[n] == '\0')
                return ((char *)&haystack[h]);
            n++;
        }
        if (needle[n] == '\0')
            return ((char *)haystack + h);
        h++;
    }
    return (0);
}

int ft_atoi(const char *str)
{
    int i;
    int c;
    int last;
    last = 0;
    i = 0;
    c = 1;
    while (str [i] == 32 || (str[i] >= 9 && str [i] <= 13))
        i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str [i] == '-')
            c *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57)
    {
            last = (str[i] - 48) + (last * 10);
        i++;
    }
    return (last * c);
}


char    *ft_strdup(const char *s)
{
    size_t    len;
    void    *new;

    len = ft_strlen(s) + 1;
    new = malloc(len);
    if (new == NULL)
        return (NULL);
    return ((char *)ft_memcpy(new, s, len));
}


void
	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*final;

	if (s)
	{		
		if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
			return (ft_strdup(""));
		i = 0;
		while (i < len && s[i + start] != '\0')
			i++;
		final = (char *) malloc((sizeof(char) * i) + 1);
		if (!(final))
			return (NULL);
		j = 0;
		while (j < i)
		{
			final[j] = s[start + j];
			j++;
		}
		final[j] = '\0';
		return (final);
	}
	return (NULL);
}


char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, len + 1);
	return (str);
}



static int	ft_checkset(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	index;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_checkset(s1[start], set))
		start++;
	while (end > start && ft_checkset(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (start < end)
		str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}


unsigned int	str_in_array(const char *s, char delimiter)
{
	unsigned int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a -1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a -1], s - j, j + 1);
		}
	}
	return (arr);
}


int	get_len(int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 0)
		nbr_len++;
	while (nbr)
	{
		nbr /= 10;
		nbr_len++;
	}
	return (nbr_len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;

	digit = get_len(n);
	str = (char *) ft_calloc(digit + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(str, "-2147483648", digit + 1);
			return (str);
		}
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		*(str + --digit) = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

//************************
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
char	ft_change(unsigned int i, char b){
	b += i;
	return (b);
}
//***********************

//***********************
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

void	ft_ft(unsigned int g, char *b)
{
	*b = *b + g;
}
//*************************

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}


void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}


void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}


int main() {
    
    //ft_isalpha.c #OK
    /*
    char	text;
	text = 'y';
	printf ("%d\n", ft_isalpha(text));
    */
    
    //ft_isdigit.c #OK
    /*
    char	a;
	char	b;
	char	x;
	char	y;
	char	z;

	a = '9';
	b = '6';
	x = 'a';
	y = 'q';
	z = '!';
	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(b));
	printf("%d\n", ft_isdigit(x));
	printf("%d\n", ft_isdigit(y));
	printf("%d\n", ft_isdigit(z));
    */
    
    //ft_isalnum.c #OK
    /*
    char deger;
    printf("Bir deger giriniz:\n");
    scanf("%c",&deger);
    ft_isalnum(deger);
    */
    
    //ft_isascii.c #OK
    /*
    char deger;
    printf("Bir deger giriniz:\n");
    scanf("%c",&deger);
    ft_isascii(deger);
    */
    
    //ft_isprint.c #OK
    /*
    char deger;
    printf("Bir deger giriniz:\n");
    scanf("%c",&deger);
    ft_isprint(deger);
    */
    
    //ft_strlen.c #OK
    /*
	char    str[100];
    printf("Bir sey yaziniz\n");
	gets(str);
    printf("%d\n",ft_strlen(str));
    */
    
    //ft_memset.c #OK
    /*
    char dizi[] = "Bilgisayar";
    printf("dizi bellek içeriği: %s\n", dizi);
    memset(dizi, 'x', 5);
    printf("dizi bellek içeriği: %s\n", dizi);
    */
    
    //ft_bzero.c #OK
    /*
    char name[] = "yavuzahmet";
    ft_bzero(name,2);
    puts(name + 2);
    */
    
    //ft_memcpy.c #OK
    /*
    const char *cp = "Bilgisayar&Programlama";
    char dest[40];

    ft_memset(dest, '\0', 40);
    ft_memcpy(dest, cp, 40);
    printf("%s\n", dest);
    */
    
    //ft_memmove.c #OK
    /*
    char a[] = "start";
    //printf(a+2);
	printf("%s\n", ft_memmove(a+2,a,3)); //"art","start",3 --> "sta"

    printf("\n");

    char	d[] = "Farklı";
	char	b[] = "bir fonksiyon";
	printf("%s\n", ft_memcpy(d, b, 3)); //"Farklı","bir fonksiyon",3 --> "birklı"
    */
    
    //ft_strlcpy.c #OK
    /*
    char string1[] = "hello there, Venus";
	char buffer1[19];
	size_t x;
	
	x = ft_strlcpy(buffer1,string1,10);
	printf("%lu\n",x);
	printf("%s\n",buffer1);
    */
   
    //ft_strlcat.c #OK
    /*
    char	kelime[] = "yavuz";
	char	kelime2[] = "islam";

	printf("%lu\n",ft_strlcat(kelime,kelime2,3));
    */
    
    //ft_toupper.c #OK
    /*
    char c1 = 'g', c2 = 'b';
    printf("%c %c\n", c1, ft_toupper(c1));
    printf("%c %c\n", c2, ft_toupper(c2));
    */
    
    //ft_tolower.c #OK
    /*
    char c1 = 'G', c2 = 'B';
    printf("%c %c\n", c1, ft_tolower(c1));
    printf("%c %c\n", c2, ft_tolower(c2));
    */
    
    //ft_strchr.c #OK
    /*
    const char cdizi[] = "Bilgisayar";
    char *ret;

    ret = ft_strchr(cdizi, 's');
    printf("İstenilen karakterden itibaren dizi içeriği: %s\n", ret);
    */
    
    //ft_strrchr.c #OK
    /*
    const char cdizi[] = "Bilgisayar";
    char cd = 'i';
    char *ret;

    ret = ft_strrchr(cdizi, cd);
    printf("Bulunan son %c karakterinden itibaren dizi içeriği: %s\n", cd, ret);
    /*/
    
    //ft_strncmp.c #OK
    /*
    char	*s1 = "yavuztalhaislam";
	char	*s2 = "yavuztalha";
	char	i = 'i';

	printf("%d\n",ft_strncmp(s1,s2,12));
	printf("%d\n",i);
    */
    
    //ft_memchr.c #OK
    /*
    char *yavuz = "yavuz talha islam";
	char a = 'z';
	printf("%s",ft_memchr(yavuz,a,5));
    */
    
    //ft_memcmp.c #OK
    /*
    char	*yavuz = "yavuztalhaislam";
	char	*yavuz1 = "yavuzislam";
	char 	a;
	char 	b;

	a = 't';
	b = 'i';
	printf("%d\n",ft_memcmp(yavuz, yavuz1, 14));
	printf("%d\n", a - b);
    */
    
    //ft_strnstr.c #OK
    /*
    char *yavuz = "yavuz talha islam";
	char *talha = "talha";

	printf("%s\n",ft_strnstr(yavuz,talha,14));
    */
    
    //ft_atoi.c #OK
    /*
    char ahmet [] = "     -----++1453sybsdh";
    printf("%d\n",ft_atoi(ahmet));
    */
    
    //ft_strdup.c #OK
    /*
    const char *cp1 = "Bilgisayar";
    char *cp2 = ft_strdup(cp1);

    printf("İlk karakter dizisi: %s\n", cp1);
    printf("Benzer olarak oluşturulan karakter dizisi: %s\n", cp2);
    */
    
    //ft_calloc.c #OK
    /*
    char	*x;

	x = ft_calloc(5, sizeof(char)); //char 1 byte, 5 * 1 = 5 byte yer ayrıldı
	printf("%p\n",&x);
    */
    
    //ft_substr.c
    //2. indisten başlar 4 uzunluğunda string oluşturur
    /*
    char    a[] = "abcdef";
    printf("%s\n", ft_substr(a, 2, 4)); //"cdef"
    */

   //ft_strjoin.c #OK
   //hafızada yer ayırarak s1 ve s2 stringlerini birleştirir
   /*
   char	a[] = "ah";
   char	b[] = "met";
   printf("%s\n", ft_strjoin(a, b));
   */

  //ft_strtrim.c #OK
  //hafızada yer ayırır, başta ve sonda çıkartılmak istenen değerler çıkartılır
  /*
  char	a[] = "aaaaaaaaaabcaaaaaaaaa";
  char	b[] = "a";
  printf("%s\n", ft_strtrim(a, b)); //bc"
  */

  //ft_split.c #OK
  //hafızada yer ayırır ve s stringini c ayıracı ile bölerek yeni bir string oluşturur
  /*
  char *a ="ahmet av,mane,ronaldo, ";
  char **mystr = ft_split(a, ',');
  int i = 0;
  while (mystr[i])
	{
		printf("%s\n",mystr[i]);
		i++;
	}
  */

  //ft_itoa.c
  //hafızada yer ayırır ve integer değerleri stringe dönüştütrür negatif değerlerde dikkate alınmalıdır
  /*
    printf("%s\n", ft_itoa(-128967264));
  */

  //ft_strmapi. 
  /*
    char	*a;
	a = "aaaaaa";
	printf("%s", ft_strmapi(a, &ft_change));
  */

   //ft_striteri.c
   /*
    char	a[] = "aaaaaa";
	ft_striteri(a, &ft_ft);
	printf("%s\n", a);
   */

  //ft_putchar_fd.c
  /*
    int a = open("abc.txt",O_WRONLY);
	ft_putchar_fd('a',a);
  */

   //ft_putstr_fd.c
   /*
    int	a = open("abc.txt",O_WRONLY);	
	printf("%d\n", a);
	ft_putstr_fd("asahkjdh", a);
    */

   //ft_putendl_fd.c
   /*
   int a = open("abc.txt",O_WRONLY);
   ft_putendl_fd("sdlajaslkdjald",a);
    */

   //ft_putnbr_fd.c
    /*
    int a = open("abc.txt",O_WRONLY);
	ft_putnbr_fd(-2147483648,a);
    */

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    











    return 0;
}

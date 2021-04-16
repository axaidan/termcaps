#include "editor.h"

void	prompt(void)
{
	*(global.buffer) = '\0';
	write(2, "$> ", 3); 
}

/*
void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	ft_putnbr_fd(int x, int fd)
{
	long    n;
	char    c;

	if (fd < 0)
		return ;
	n = x;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

int		ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/

char	ctrl_key(char c)
{
	return ((c) & 0x1f);
}

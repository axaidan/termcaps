#include "editor.h"

char	read_key(void)
{
	int		bytes_read;
	char	c;

	while ((bytes_read = read(STDIN_FILENO, &c, 1)) != 1)
	{
		if (bytes_read == -1 && errno != EAGAIN)
		{
			ft_putstr_fd("error -- read(2)\r\n", STDERR_FILENO);
			exit(1);
		}
	}
	return (c);
}

char	process_key(int *stop)
{
	char	c;

	c = read_key();
	if (c == ctrl_key('q'))
		*stop = 1;
	else if (ft_isprint(c))
		write(STDIN_FILENO, &c, 1);
	return (c);
}

void	write_buffer(char *buffer, int *stop)
{
	int		i;
	char	c;

	i = 0;
	c = '\0';
	while (c != '\r' && *stop == 0)
	{
		c = process_key(stop);
		if (ft_isprint(c))
			buffer[i++] = c;
	}
	write(STDIN_FILENO, "\r\n", 2);
	buffer[i] = '\0';
}

void	print_buffer(char *buffer)
{
	if (*buffer)
	{
		ft_putstr_fd(buffer, STDIN_FILENO);
		write(STDIN_FILENO, "\r\n", 2);
	}
}

int		main(void)
{
	char	buffer[INPUT_MAX];
	int		stop;

	orig_termios = enable_raw_mode();
	stop = 0;
	while (stop == 0)
	{
		prompt();
		write_buffer(buffer, &stop);
		print_buffer(buffer);
	}
	disable_raw_mode();
	return (0);
}

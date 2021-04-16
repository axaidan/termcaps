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

char	process_key(void)
{
	char	c;

	c = read_key();
	return (c);
}

void	write_buffer(char *buffer, int *stop)
{
}

int		main(void)
{
	char	buffer[INPUT_MAX];
	char	c;
	int		stop;
	int		i;

	orig_termios = enable_raw_mode();
	stop = 0;
	while (stop == 0)
	{
		i = 0;
		prompt();
		c = '\0';
		while (c != '\r' && stop == 0)
		{
			c = process_key();
			if (c == ctrl_key('q'))
				stop = 1;
			else if (ft_isprint(c))
			{
				write(STDIN_FILENO, &c, 1);
				buffer[i++] = c;
			}
		}
		buffer[i] = '\0';
		write(STDIN_FILENO, "\r\n", 2);
		if (*buffer)
		{
			ft_putstr_fd(buffer, STDIN_FILENO);
			write(STDIN_FILENO, "\r\n", 2);
		}
	}
	disable_raw_mode();
	return (0);
}
/*
   int main(void)
   {
   char			c;
   char			buffer[INPUT_MAX];
   int				i;
   int				stop;

   orig_termios = enable_raw_mode();
   stop = 0;
   while (stop == 0)
   {
   prompt();
   i = 0;
   while (read(STDIN_FILENO, &c, 1) == 1 && stop == 0 && c != '\r')
   {
   if (c == ctrl_key('q'))
   {
   stop = 1;
   break ;
   }
   else if (ft_isprint(c))
   {
   write(STDIN_FILENO, &c, 1);
   buffer[i++] = c; 
   }
   else
   ft_putnbr_fd(c, STDIN_FILENO);
   }
   write(1, "\r\n", 2);
   buffer[i] = '\0';
   if (*buffer)
   {
   ft_putstr(buffer);
   write(1, "\r\n", 2);
   }
   }
   atexit(disable_raw_mode);
   return (0);	

   }
 */

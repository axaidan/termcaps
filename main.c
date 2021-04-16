#include "editor.h"

void	prompt(void)
{
	write(2, "$> ", 3);
}

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
			{
				ft_putnbr_fd(c, STDIN_FILENO);
			}
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

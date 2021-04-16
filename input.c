#include "editor.h"

char    read_key(void)
{
    int     bytes_read;
    char    c;

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

char    process_key(int *stop)
{
    char    c;

    c = read_key();
    if (c == ctrl_key('q'))
        *stop = 1;
	else if (c == ctrl_key('u'))
	{
		exec_termcap("dl");
		prompt();
	}
	else if (c == 127)
		delete();
    else if (ft_isprint(c))
        write(STDIN_FILENO, &c, 1);
    return (c);
}

void    write_buffer(int *stop)
{
    int     i;
    char    c;

    i = 0;
    c = '\0';
    while (c != '\r' && *stop == 0 && i < INPUT_MAX - 1)
    {
        c = process_key(stop);
        if (ft_isprint(c))
		{
            global.buffer[i++] = c;
			global.buffer[i] = '\0';
		}
    }
    write(STDIN_FILENO, "\r\n", 2);
    global.buffer[i] = '\0';
}

void    print_buffer(void)
{
    if (*global.buffer)
    {
        ft_putstr_fd(global.buffer, STDIN_FILENO);
        write(STDIN_FILENO, "\r\n", 2);
    }
}

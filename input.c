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

int    process_key(int *stop, t_buff *buff)
{
    char    c;

    c = read_key();
	if (is_ctrl_keys(c, stop, buff))
		;
	else if (c == ESCAPE)
		return (arrow_value());
	else if (c == DELETE)
		delete_char(buff);
    else if (ft_isprint(c))
        write(STDIN_FILENO, &c, 1);
    return (c);
}

void    write_buffer(int *stop, t_buff *buff)
{
    int		c;

    buff->i = 0;
    c = '\0';
    while (c != ENTER && *stop == 0 && buff->i < INPUT_MAX - 1)
    {
        c = process_key(stop, buff);
        if (ft_isprint(c))
		{
            buff->buffer[buff->i++] = c;
			buff->buffer[buff->i] = '\0';
		}
		else if (c == UP_ARROW || c == DN_ARROW)
			change_input_str(c, buff);
    }
    write(STDIN_FILENO, "\r\n", 2);
}

void    print_buffer(t_buff *buff)
{
    if (*buff->buffer)
    {
        ft_putstr_fd(buff->buffer, STDIN_FILENO);
        write(STDIN_FILENO, "\r\n", 2);
    }
}

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

int    process_key(int *stop, t_list *history)
{
    char    c;

    c = read_key();
	if (is_ctrl_keys(c, stop, history))
		;
	else if (c == ESCAPE)
		return (arrow_value());
	else if (c == DELETE)
		delete_char();
    else if (ft_isprint(c))
        write(STDIN_FILENO, &c, 1);
    return (c);
}

void    write_buffer(int *stop, t_list *history)
{
    int		c;

    glb.i = 0;
    c = '\0';
    while (c != ENTER && *stop == 0 && glb.i < INPUT_MAX - 1)
    {
        c = process_key(stop,history);
        if (ft_isprint(c))
		{
            glb.buffer[glb.i++] = c;
			glb.buffer[glb.i] = '\0';
		}
		else if (c == UP_ARROW || c == DN_ARROW)
			change_input_str(c);
    }
    write(STDIN_FILENO, "\r\n", 2);
}

void    print_buffer(void)
{
    if (*glb.buffer)
    {
        ft_putstr_fd(glb.buffer, STDIN_FILENO);
        write(STDIN_FILENO, "\r\n", 2);
    }
}

#include "editor.h"

t_buff	init_buff_struct(void)
{
	t_buff	buff;

	ft_bzero(buff.buffer, INPUT_MAX);
	ft_bzero(buff.backup, INPUT_MAX);
	buff.pos = NULL;
	buff.history = NULL;
	buff.i = 0;
	return (buff);
}

int		main(void)
{
	int			stop;
	t_buff		buff;
	t_list		*history;
	t_termios	orig_termios;

	buff = init_buff_struct();
	orig_termios = enable_raw_mode();
	if (init_termcaps() == 0)
		return (-1);
	stop = 0;
	history = NULL;
	while (stop == 0)
	{
		prompt(&buff);
		write_buffer(&stop, &buff);
		if (stop == 0)
		{
			stop = add_to_history(&buff);
			print_buffer(&buff);
		}
	}
	ft_lstclear(&buff.history, free);
	disable_raw_mode(orig_termios);
	return (0);
}

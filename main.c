#include "editor.h"

int		main(void)
{
	int			stop;
	t_buff		buff;
	t_list		*history;
	t_termios	orig_termios;

	init_buff_and_history(&buff, &history);
	orig_termios = enable_raw_mode();
	if (init_termcaps() == 0)
		return (-1);
	stop = 0;
	while (stop == 0)
	{
		prompt(&buff);
		write_buffer(&stop, &buff, history);
		if (stop == 0)
		{
			stop = add_to_history(&buff, &history);
			print_buffer(&buff);
		}
	}
	ft_lstclear(&history, free);
	disable_raw_mode(orig_termios);
	return (0);
}

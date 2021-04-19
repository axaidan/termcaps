#include "editor.h"

int		main(void)
{
	int		stop;
	t_list	*history;

	history = NULL;
	glb.orig_termios = enable_raw_mode();
	if (init_termcaps() == 0)
		return (-1);
	exec_termcap("cl");
	stop = 0;
	while (stop == 0)
	{
		prompt();
		write_buffer(&stop, history);
		if (stop == 0)
		{
			stop = add_to_history(&history);
			print_buffer();
		}
	}
	ft_lstclear(&history, free);
	disable_raw_mode();
	return (0);
}

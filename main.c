#include "editor.h"

int		main(void)
{
	int		stop;

	glb.history = NULL;
	glb.orig_termios = enable_raw_mode();
	if (init_termcaps() == 0)
		return (-1);
	exec_termcap("cl");
	stop = 0;
	while (stop == 0)
	{
		prompt();
		write_buffer(&stop, glb.history);
		if (stop == 0)
		{
			stop = add_to_history(&glb.history);
			print_buffer();
		}
	}
	ft_lstclear(&glb.history, free);
	disable_raw_mode();
	return (0);
}

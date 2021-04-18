#include "editor.h"

int		main(void)
{
	int		stop;
	t_list	*start;
	//t_list	*new_node;

	start = NULL;
	glb.orig_termios = enable_raw_mode();
	if (init_termcaps() == 0)
		return (-1);
	exec_termcap("cl");
	stop = 0;
	while (stop == 0)
	{
		prompt();
		write_buffer(&stop, start);
		if (stop == 0)
		{
			stop = add_to_history(&start);
			print_buffer();
		}
	}
	ft_lstclear(&start, free);
	disable_raw_mode();
	return (0);
}

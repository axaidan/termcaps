#include "editor.h"

int		main(void)
{
	int		stop;

	glb.orig_termios = enable_raw_mode();
	if (init_termcaps() == 0)
		return (-1);
	exec_termcap("cl");
	stop = 0;
	while (stop == 0)
	{
		prompt();
		write_buffer(&stop);
		print_buffer();
	}
	disable_raw_mode();
	return (0);
}

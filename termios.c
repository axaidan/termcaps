#include "editor.h"

void			disable_raw_mode(void) 
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &global.orig_termios);
}

struct termios	enable_raw_mode(void)
{
	struct termios	new_termios;

	tcgetattr(STDIN_FILENO, &global.orig_termios);
	new_termios = global.orig_termios;
	new_termios.c_lflag &= ~(ICANON | ECHO | ISIG);
	new_termios.c_iflag &= ~(ICRNL | IXON);
	new_termios.c_oflag &= ~(OPOST);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
	return (global.orig_termios);
}

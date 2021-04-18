#include "editor.h"

void			disable_raw_mode(void) 
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &glb.orig_termios);
}

struct termios	enable_raw_mode(void)
{
	struct termios	new_termios;

	tcgetattr(STDIN_FILENO, &glb.orig_termios);
	new_termios = glb.orig_termios;
	new_termios.c_lflag &= ~(ICANON | ECHO | ISIG);
	new_termios.c_iflag &= ~(ICRNL | IXON);
	new_termios.c_oflag &= ~(OPOST);
	new_termios.c_cc[VMIN] = 0;
	new_termios.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
	return (glb.orig_termios);
}

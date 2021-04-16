#include "editor.h"

void			disable_raw_mode(void) 
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

struct termios	enable_raw_mode(void)
{
	struct termios	new_termios;

	tcgetattr(STDIN_FILENO, &orig_termios);
	new_termios = orig_termios;
	new_termios.c_lflag &= ~(ICANON | ECHO | ISIG);
	new_termios.c_iflag &= ~(ICRNL);
	new_termios.c_oflag &= ~(OPOST);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
	return (orig_termios);
}

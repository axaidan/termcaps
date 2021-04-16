#ifndef EDITOR_H
# define EDITOR_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include "libft.h"

# define INPUT_MAX 10
# define CTRL_KEY(k) ((k) & 0x1f)

void				prompt(void);
struct termios		enable_raw_mode(void);
void				disable_raw_mode(void);
char				ctrl_key(char c);
char				read_key(void);
char				process_key(int *stop);
void				write_buffer(int *stop);
void				print_buffer(void);
int					init_termcaps(void);
int					put_termcap(int c);
void				exec_termcap(char *termcap_name);
void				delete(void);

typedef struct				s_global
{
	struct termios		orig_termios;
	char				buffer[INPUT_MAX];
}							t_global;

t_global	global;

#endif

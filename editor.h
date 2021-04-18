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

# define INPUT_MAX 1024

void				prompt(void);
struct termios		enable_raw_mode(void);
void				disable_raw_mode(void);
char				ctrl_value(char c);
char				read_key(void);
char				process_key(int *stop);
void				write_buffer(int *stop);
void				print_buffer(void);
int					init_termcaps(void);
int					put_termcap(int c);
void				exec_termcap(char *termcap_name);
void				delete_char(void);
int					is_ctrl_keys(char c, int *stop);
void				clear_line(void);

typedef struct				s_global
{
	struct termios		orig_termios;
	char				buffer[INPUT_MAX];
	int					i;
}							t_global;

t_global					glb;

#endif

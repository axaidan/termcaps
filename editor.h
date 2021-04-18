#ifndef EDITOR_H
# define EDITOR_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include <limits.h>
# include "libft.h"

# define INPUT_MAX 1024
# define ENTER '\r'
# define DELETE 127
# define ESCAPE 27

# define UP_ARROW 12938712
# define DN_ARROW 1290837

void				prompt(void);
struct termios		enable_raw_mode(void);
void				disable_raw_mode(void);
char				ctrl_value(char c);
char				read_key(void);
int					process_key(int *stop, t_list *history);
void				write_buffer(int *stop, t_list *history);
void				print_buffer(void);
int					init_termcaps(void);
int					put_termcap(int c);
void				exec_termcap(char *termcap_name);
void				delete_char(void);
int					is_ctrl_keys(char c, int *stop, t_list *history);
void				clear_line(void);
int					add_to_history(t_list **history);
void				print_history(t_list *history);
void				change_input_str(int arrow);

typedef struct				s_global
{
	struct termios		orig_termios;
	char				buffer[INPUT_MAX];
	char				*buffer_bckp;
//	t_list				*history;
	int					i;
}							t_global;

t_global					glb;

#endif

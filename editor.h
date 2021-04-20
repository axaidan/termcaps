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

typedef struct termios t_termios;

typedef struct				s_buff
{
	char				buffer[INPUT_MAX];
	char				backup[INPUT_MAX];
	t_list				*pos;
	t_list				*history;
	int					i;
}							t_buff;

void				prompt(t_buff *buff);
struct termios		enable_raw_mode(void);
void				disable_raw_mode(t_termios orig_termios);
char				ctrl_value(char c);
char				read_key(void);
int					process_key(int *stop, t_buff *buff);
void				write_buffer(int *stop, t_buff *buff);
void				print_buffer(t_buff *buff);
int					init_termcaps(void);
int					put_termcap(int c);
void				exec_termcap(char *termcap_name);
void				delete_char(t_buff *buff);
int					is_ctrl_keys(char c, int *stop, t_buff *buff);
void				clear_line(t_buff *buff);
int					add_to_history(t_buff *buff);
void				display_history(t_buff *buff);
void				change_input_str(int arrow, t_buff *buff);
int					arrow_value(void);

#endif

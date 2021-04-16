#ifndef EDITOR_H
# define EDITOR_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <termios.h>
# include <curses.h>

# define INPUT_MAX 1024
# define CTRL_KEY(k) ((k) & 0x1f)

void				prompt(void);
struct termios		enable_raw_mode(void);
void				disable_raw_mode(void);
void				ft_putnbr_fd(int x, int fd);
void				ft_putstr(char *s);
int					ft_isprint(int c);
char				ctrl_key(char c);

struct termios	orig_termios;

#endif

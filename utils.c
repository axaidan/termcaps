#include "editor.h"

void	prompt(t_buff *buff)
{
	buff->pos = NULL;
	*(buff->buffer) = '\0';
	write(STDERR_FILENO, "$> ", 3); 
}

int		is_ctrl_keys(char c, int *stop, t_buff *buff)
{
    if (c == ctrl_value('d'))
        *stop = 1;
    else if (c == ctrl_value('u'))
		clear_line(buff);
	else if (c == ctrl_value('h'))
		display_history(buff);
	else if (c == ctrl_value('s'))
		printf("history size = %d\r\n", ft_lstsize(buff->history));
	else
		return (0);
	return (1);
}

char	ctrl_value(char c)
{
	return ((c) & 0x1f);
}

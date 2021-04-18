#include "editor.h"

void	prompt(void)
{
	*(glb.buffer) = '\0';
	write(STDERR_FILENO, "$> ", 3); 
}

int		is_ctrl_keys(char c, int *stop, t_list *history)
{
    if (c == ctrl_value('d'))
        *stop = 1;
    else if (c == ctrl_value('u'))
		clear_line();
	else if (c == ctrl_value('h'))
		print_history(history);
	else if (c == ctrl_value('s'))
		printf("history size = %d\r\n", ft_lstsize(history));
	else
		return (0);
	return (1);
}

char	ctrl_value(char c)
{
	return ((c) & 0x1f);
}

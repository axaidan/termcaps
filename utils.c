#include "editor.h"

void	prompt(t_buff *buff)
{
	buff->pos = NULL;
	*(buff->buffer) = '\0';
	write(STDERR_FILENO, "$> ", 3); 
}

int		is_ctrl_keys(char c, int *stop, t_buff *buff, t_list *history)
{
	if (c == ctrl_value('d'))
		*stop = 1;
	else if (c == ctrl_value('u'))
		clear_line(buff);
	else if (c == ctrl_value('h'))
	{
		display_history(history);
		prompt(buff);
	}
	else if (c == ctrl_value('s'))
	{
		printf("history size = %d\r\n", ft_lstsize(history));
		prompt(buff);
	}
	else
		return (0);
	return (1);
}

int     arrow_value(void)
{
	char    seq[3];

	if (read(STDIN_FILENO, &seq[0], 1) != 1)
		return (ESCAPE);
	if (read(STDIN_FILENO, &seq[1], 1) != 1)
		return (ESCAPE);
	if (seq[0] == '[' && seq[1] == 'A')
		return (UP_ARROW);
	else if (seq[0] == '[' && seq[1] == 'B')
		return (DN_ARROW);
	return (ESCAPE);
}

char	ctrl_value(char c)
{
	return ((c) & 0x1f);
}

int    init_buff_and_history(t_buff *buff, t_list **history)
{
	buff->buffer = malloc(INPUT_MAX);
	if (buff->buffer == NULL)
		return (1);
	ft_bzero(buff->buffer, INPUT_MAX);
	buff->backup = malloc(INPUT_MAX);
	if (buff->buffer == NULL)
	{
		free(buff->buffer);
		return (1);
	}
	ft_bzero(buff->backup, INPUT_MAX);
	buff->pos = NULL;
	buff->i = 0;
	buff->factor = 1;
	*history = NULL;
	return (0);
}

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(old_ptr);
		return (NULL);
	}
	ft_bzero(new_ptr, new_size);	
	ft_memcpy(new_ptr, old_ptr, old_size);
	free(old_ptr);
	return (new_ptr);
}

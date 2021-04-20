#include "editor.h"

void	display_history(t_buff *buff)
{
	int		i;
	t_list	*hist;

	printf("\r\n");
	i = 0;
	hist = buff->history;
	while (hist)
	{
		printf("%d\tcur: %p\t\"%10.10s\"\tprv: %p\tnxt: %p\r\n", i++, hist, hist->content, hist->previous, hist->next);
		hist = hist->next;
	}
	prompt(buff);
}

//int		add_to_history(t_list **history)
int		add_to_history(t_buff *buff)
{
	char	*line;
	t_list	*new_node;

	line = ft_strdup(buff->buffer);
	if (line == NULL)
		return (1);
	new_node = ft_lstnew(line);
	if (new_node == NULL)
	{
		free(line);
		return (1);
	}
	ft_lstadd_front(&(buff->history), new_node);
	return (0);
}

void	change_input_str(int arrow, t_buff *buff)
{
	exec_termcap("dl");
	write(STDERR_FILENO, "$> ", 3);
	if (arrow == UP_ARROW && buff->history)
	{
		if (buff->pos == NULL)
		{
			ft_memcpy(buff->backup, buff->buffer, ft_strlen(buff->buffer) + 1);
			buff->pos = buff->history;
		}
		else if (buff->pos->next != NULL)
			buff->pos = buff->pos->next;
		ft_memcpy(buff->buffer, buff->pos->content, ft_strlen(buff->pos->content) + 1);
	}
	else if (arrow == DN_ARROW && buff->pos != NULL)
	{
		if (buff->pos->previous != NULL)
		{
			buff->pos = buff->pos->previous;
			ft_memcpy(buff->buffer, buff->pos->content, ft_strlen(buff->pos->content) + 1);
		}
		else if (buff->pos->previous == NULL)
		{
			ft_memcpy(buff->buffer, buff->backup, ft_strlen(buff->backup) + 1);
			buff->pos = NULL;
		}
	}
	ft_putstr_fd(buff->buffer, 1);
	buff->i = ft_strlen(buff->buffer);
}

int		arrow_value(void)
{
	char	seq[3];

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

#include "editor.h"

void	print_history(t_list *history)
{
	//	t_list	*tmp;
	int		i;

	printf("\r\n");
	//	tmp = history;
	i = 0;
	while (history)
	{
		printf("%d\tcur: %p\t\"%10.10s\"\tnxt: %p\tprv: %p\r\n", i++, history, history->content, history->next, history->previous);
		history = history->next;
	}
	prompt();
}

int		add_to_history(t_list **history)
{
	char	*line;
	t_list	*new_node;

	line = ft_strdup(glb.buffer);
	if (line == NULL)
		return (1);
	new_node = ft_lstnew(line);
	if (new_node == NULL)
	{
		free(line);
		return (1);
	}
	ft_lstadd_front(history, new_node);
	return (0);
}

void	change_input_str(int arrow)
{
	exec_termcap("dl");
	write(STDERR_FILENO, "$> ", 3);
	if (arrow == UP_ARROW)
	{
		if (glb.history_pos == NULL)
		{
			ft_memcpy(glb.backup, glb.buffer, ft_strlen(glb.buffer) + 1);
			glb.history_pos = glb.history;
		}
		else if (glb.history_pos->next != NULL)
			glb.history_pos = glb.history_pos->next;
		ft_memcpy(glb.buffer, glb.history_pos->content, ft_strlen(glb.history_pos->content) + 1);
	}
	else if (arrow == DN_ARROW && glb.history != NULL)
	{
		if (glb.history_pos->previous != NULL)
		{
			glb.history_pos = glb.history_pos->previous;
			ft_memcpy(glb.buffer, glb.history_pos->content, ft_strlen(glb.history_pos->content) + 1);
		}
		else if (glb.history_pos->previous == NULL)
		{
			ft_memcpy(glb.buffer, glb.backup, ft_strlen(glb.backup) + 1);
			glb.history_pos = NULL;
		}
	}
	ft_putstr_fd(glb.buffer, 1);
	glb.i = ft_strlen(glb.buffer);
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

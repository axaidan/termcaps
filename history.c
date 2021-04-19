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
		printf("%d\tcur: %p\t\"%10.10s\"\tnxt: %p\r\n", i++, history, history->content, history->next);
		history = history->next;
	}
	prompt();
}

int		add_to_history(t_list **history)
{
	char	*line;
	t_list	*new_node;

	//	printf("add_to_history() - ADDING \"%s\" to history %p\r\n", glb.buffer, *history);
	line = ft_strdup(glb.buffer);
	if (line == NULL)
		return (1);
	new_node = ft_lstnew(line);
	if (new_node == NULL)
	{
		free(line);
		return (1);
	}
	new_node->next = *history;
	*history = new_node;
	//ft_lstadd_front(history, new_node);
	//	printf("add_to_history() - ADDED, lst_size is now %d\r\n", ft_lstsize(*history));
	//	printf("add_to_history() - ADDED, (*history)->content = \"%10s\"\t(*history)->next = %p\r\n", (*history)->content, (*history)->next);
	return (0);
}

void	change_input_str(int arrow)
{
	exec_termcap("dl");
	write(STDERR_FILENO, "$> ", 3);
	if (arrow == UP_ARROW)
		write(STDIN_FILENO, "going up in history", 19);
	else if (arrow == DN_ARROW)
		write(STDIN_FILENO, "going down in history", 21);
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

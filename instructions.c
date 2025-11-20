#include "push_swap.h"

void	instruction(t_list **stack_a, t_list **stack_b, size_t len)
{
	// on va en push tous sauf 2 dans la stack_b

	int len_a;
	int len_b;
	while (len_a-- > 2)
	{
		push(stack_a, stack_b, 'b');
		len_b++;
	}
	// si les 2 restant dans la stack a ils sont dans l'ordre alors on fait rien, sinon on les swap
	if (stack_a->content > stack_a->next->content)
		swap(stack_a, 'a');
	// on va boucler sur la len de b
		// pour chaucn des elements dans a on cherche celui qui a le moindre cout pour mettre lui et son buddy au top
		// on le fait
		// on push le top b dans a
	while (len_b--)
	{

	}
}

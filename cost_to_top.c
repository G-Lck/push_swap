#include "push_swap.h"

static int cost_ra_rb(int nb, int buddy, t_list *stack_a, t_list *stack_b)
{
	int len_a;
	int len_b;

	len_a = lst_size(stack_a);
	len_b = lst_size(stack_b);
	return (max(len_a - get_position(nb, stack_a), len_b - get_position(buddy, stack_b)));
}

static int cost_ra_rrb(int nb, int buddy, t_list *stack_a, t_list *stack_b)
{
	int len_a;
	int len_b;

	len_a = lst_size(stack_a);
	len_b = lst_size(stack_b);
	return (len_a - get_position(nb, stack_a) - (get_position(buddy, stack_b) - len_b));
}

static int cost_rra_rb(int nb, int buddy, t_list *stack_a, t_list *stack_b)
{
	int len_a;
	int len_b;

	len_a = lst_size(stack_a);
	len_b = lst_size(stack_b);
	return (- (get_position(nb, stack_a) - len_a) + len_b - get_position(buddy, stack_b));
}

static int cost_rra_rrb(int nb, int buddy, t_list *stack_a, t_list *stack_b)
{
	int len_a;
	int len_b;

	len_a = lst_size(stack_a);
	len_b = lst_size(stack_b);
	return (max(-(get_position(nb, stack_a)-len_a, - (get_position(buddy, stack_b) - len_b))));
}

char *cost_to_top(int nb, t_list *stack_a, t_list *stack_b)
{
	int buddy;
	int len_a;
	int len_b;
	int min_moves;

	len_a = lst_size(stack_a);
	len_b = lst_size(stack_b);
	buddy = get_buddy(nb, stack_b);
	min_moves = min_of_4(cost_ra_rb(nb, buddy, stack_a, stack_b),
					cost_ra_rrb(nb, buddy, stack_a, stack_b),
					cost_rra_rb(nb, buddy, stack_a, stack_b),
					cost_rra_rrb(nb, buddy, stack_a, stack_b));

	return (min_moves);
}

less_cost_in_stack_a(t_list *stack_a, t_list *stack_b)
{
	int len_a;
	int min_cost;
	int min_nb;

	min_cost = INT_MAX;
	len_a = lst_size(stack_a);
	while (len_a--)
	{
		if (cost_to_top(stack_a->content, stack_a, stack_b) < min_cost)
		{
			min_cost = cost_to_top(stack_a->content, stack_a, stack_b);
			min_nb = stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (min_nb);
}

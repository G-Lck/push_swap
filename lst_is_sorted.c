#include "push_swap.h"

int lst_is_sorted(t_list *lst, char c)
{
    if (!lst)
        return 1;
    while (lst && lst->next)
    {
        if (!lst->content || !lst->next->content)
            return 0;
        int a = *(int *)(lst->content);
        int b = *(int *)(lst->next->content);
        if (c == 'i' && a != b - 1)
            return 0;
        if (c == 'd' && a != b + 1)
            return 0;
        lst = lst->next;
    }
    return 1;
}

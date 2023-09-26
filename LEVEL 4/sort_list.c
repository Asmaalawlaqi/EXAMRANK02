// Assignment name  : sort_list
// Expected files   : sort_list.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write the following functions:

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

// This function must sort the list given as a parameter, using the function 
// pointer cmp to select the order to apply, and returns a pointer to the 
// first element of the sorted list.

// Duplications must remain.

// Inputs will always be consistent.

// You must use the type t_list described in the file list.h 
// that is provided to you. You must include that file 
// (#include "list.h"), but you must not turn it in. We will use our own 
// to compile your assignment.

// typedef struct s_list t_list;

// struct s_list
// {
// 	int     data;
// 	t_list  *next;
// };

// Functions passed as cmp will always return a value different from 
// 0 if a and b are in the right order, 0 otherwise.

// For example, the following function used as cmp will sort the list 
// in ascending order:

// int ascending(int a, int b)
// {
// 	return (a <= b);
// }

#include "list.h"
#include <stddef.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int swap;
    t_list *tmp;

    tmp = lst;
    while (lst->next != NULL)
    {
        if((*cmp) (lst->data, lst->next->data) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return (lst);
}

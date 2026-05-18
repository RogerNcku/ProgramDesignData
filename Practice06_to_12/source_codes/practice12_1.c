#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->value = n;
    new_node->next = list;

    return new_node;
}

struct node *find_last(struct node *list, int n)
{
    struct node *p;
    struct node *last = NULL;

    for (p = list; p != NULL; p = p->next)
    {
        if (p->value == n)
        {
            last = p;
        }
    }

    return last;
}

int main(void)
{
    struct node *list = NULL;
    struct node *result;

    list = add_to_list(list, 5);
    list = add_to_list(list, 3);
    list = add_to_list(list, 5);
    list = add_to_list(list, 1);

    result = find_last(list, 5);

    if (result != NULL)
    {
        printf("Last node value: %d\n", result->value);
    }
    else
    {
        printf("Value not found.\n");
    }

    return 0;
}

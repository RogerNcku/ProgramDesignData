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

int count_occurrences(struct node *list, int n)
{
    int count = 0;
    struct node *p;

    for (p = list; p != NULL; p = p->next)
    {
        if (p->value == n)
        {
            count++;
        }
    }

    return count;
}

int main(void)
{
    struct node *list = NULL;

    list = add_to_list(list, 5);
    list = add_to_list(list, 3);
    list = add_to_list(list, 5);
    list = add_to_list(list, 5);
    list = add_to_list(list, 1);

    printf("Occurrences of 5: %d\n", count_occurrences(list, 5));

    return 0;
}

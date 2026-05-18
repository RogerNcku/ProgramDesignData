#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
{
    struct node *cur;
    struct node *prev = NULL;

    for (cur = list; cur != NULL && cur->value < new_node->value; cur = cur->next)
    {
        prev = cur;
    }

    new_node->next = cur;

    if (prev == NULL)
    {
        return new_node;
    }
    else
    {
        prev->next = new_node;
        return list;
    }
}

void print_list(struct node *list)
{
    struct node *p;

    for (p = list; p != NULL; p = p->next)
    {
        printf("%d -> ", p->value);
    }

    printf("NULL\n");
}

int main(void)
{
    struct node *list = NULL;
    struct node *n1;
    struct node *n2;
    struct node *n3;

    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));

    n1->value = 10;
    n1->next = NULL;

    n2->value = 30;
    n2->next = NULL;

    n3->value = 20;
    n3->next = NULL;

    list = insert_into_ordered_list(list, n1);
    list = insert_into_ordered_list(list, n2);
    list = insert_into_ordered_list(list, n3);

    print_list(list);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link_node {
    int data;
    struct link_node *next;
} link_node, link_list;

struct link_list * create_link_list()
{
    struct link_list *list = (struct link_list *) malloc(sizeof(struct link_node));
    if (list == NULL) {
        return NULL;
    }
    return list;
}

int insert_link_node_by_data(struct link_list *list, int data)
{
    if (list == NULL) {
        return -1;
    }

    struct link_node *head = (struct link_node *)list;
    struct link_node *node = (struct link_node *)malloc(sizeof(struct link_node));
    if (node == NULL) {
        return -1;
    }

    node->data = data;
    node->next = NULL;

    if (head->next == NULL) {
        head->next = node;
    } else {
        struct link_node *pnode = head->next;
        node->next = pnode;
        head->next = node;
    }
    return 0;
}

void display_link_list(struct link_list *list) 
{
    if (list == NULL) {
        return ;
    }

    struct link_node *head = (struct link_node *)list;
    struct link_node *pnode = head->next;

    while (pnode) {
        printf("%d->", pnode->data);
        pnode = pnode->next;
    }
    printf("NULL\n");
}

int reverse_link_list(struct link_list *list) 
{
    if (list == NULL) {
        return -1;
    }

    struct link_node *head = (struct link_node *)list;
    if (head->next == NULL) {
        return -1;
    }

    //the first node
    struct link_node *cur = head->next;
    if (cur == NULL) {
        return 0;
    }

    //the second node
    struct link_node *pnode = cur->next;
    cur->next = NULL;

    while(pnode) {
        /*依次改变指针的位置*/
        struct link_node *qnode = pnode->next;
        pnode->next = cur;
        cur = pnode;
        pnode = qnode;
    }

    /*cur指向了最后一个节点*/
    head->next = cur;

    return 0;
}

void free_link_list(struct link_list *list)
{
    if (list == NULL) {
        return;
    }

    struct link_node *head = (struct link_node *)list;
    struct link_node *pnode = head->next;
    while(pnode) {
        struct link_node *qnode = pnode->next;
        free(pnode);
        pnode = qnode;
    }
    free(list);
    list = NULL;
}

int main()
{
    struct link_list *list = create_link_list();
    if (list == NULL) {
        return -1;
    }

    insert_link_node_by_data(list, 10);
    insert_link_node_by_data(list, 11);
    insert_link_node_by_data(list, 12);
    insert_link_node_by_data(list, 13);
    insert_link_node_by_data(list, 14);

    display_link_list(list);

    reverse_link_list(list);
    display_link_list(list);

    free_link_list(list);

    return 0;
}

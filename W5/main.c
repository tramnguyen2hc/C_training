#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
} node_t;

typedef node_t* head_t;

void add_node(head_t *head, node_t* new_node);
int delete_node(head_t *head);
void display(head_t head);
void add_node_head(head_t *head, node_t* new_node);
int delete_node_tail(head_t *head);

head_t g_head = NULL;
node_t* con_node;

void main(void)
{
    int temp;
    node_t nodeA = {4,NULL};
    node_t nodeB = {5,NULL};
    node_t nodeC = {6,NULL};
    node_t nodeD = {7,NULL};
    node_t nodeNew = {90,NULL};

    add_node(&g_head, &nodeA);
    add_node(&g_head, &nodeB);
    add_node(&g_head, &nodeC);
    add_node(&g_head, &nodeD);
    add_node_head(&g_head, &nodeNew);

    display(g_head);

    temp = delete_node(&g_head);
    display(g_head);
    temp = delete_node_tail(&g_head);
    display(g_head);
    return;
}

void add_node(head_t *head, node_t* new_node)
{
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        con_node=*head;

        while (1)
        {
            if(con_node->next!=NULL)
            {
                con_node = con_node->next;
            }
            else
            {
                break;
            }
        }
        con_node->next = new_node;
    }
}

void add_node_head(head_t *head, node_t* new_node)
{
    new_node->next = *head;
    *head = new_node;
}

int delete_node(head_t *head)
{
    if((*head) != NULL)
    {
        (*head) = (*head)->next;
        return 0;
    }
    else
    {
        return -1;
    }
}

int delete_node_tail(head_t *head)
{
    node_t* t_head = *head;
    node_t* t_pre_last_node = *head;
    while (1)
    {
        if((t_head)->next!=NULL)
        {
            t_head = (t_head)->next;
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        if((t_pre_last_node)->next!=t_head)
        {
            t_pre_last_node = (t_pre_last_node)->next;
        }
        else
        {
            break;
        }
    }
    (t_pre_last_node)->next=NULL;
    return 0;
}

void display(head_t head)
{
    printf("Element of each node:\n");
    node_t* temp=head;
    while (temp !=NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
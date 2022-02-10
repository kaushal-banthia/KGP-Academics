#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *add;
};

void add_data(struct node **head, int new_num);
struct node* traverse_from_front_to_end(struct node *head);
void traverse_from_end_to_front(struct node *tail);
void reverse(struct node **head, struct node **tail);
//void alternate(struct node **head, struct node **tail);

void main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    int num_arr[n];
    printf("Enter the %d integers between -100 to 100: ", n);
    for (int i = 0; i < n; i++)
    {
        int new_num;
        scanf("%d", &new_num);
        num_arr[n-i-1] = new_num;
    }
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        add_data(&head, num_arr[i]);
    }
    printf("Doubly linked list traversed from front to end: ");
    struct node *tail = traverse_from_front_to_end(head);
    printf("\n");
    printf("Doubly linked list traversed from end to front: ");
    traverse_from_end_to_front(tail);
    printf("\n");
    printf("Reversed doubly linked list traversed from front to end: ");
    reverse(&head, &tail);
    printf("\n");
    //printf("Alternated doubly linked list traversed from front to end: ");
    //alternate(&head, &tail);
    printf("\n");
}

void add_data(struct node **head, int new_num)
{
    struct node *trav = (struct node *) malloc (sizeof (struct node) ); 
    trav->num = new_num; 
    trav->add = *head; 
    if (*head != NULL) 
    {
        (*head)->add = (unsigned long long)trav^(unsigned long long)(*head)->add; 
    }
    *head = trav; 
}

struct node* traverse_from_front_to_end(struct node *head)
{
    struct node *trav = head;
    struct node *back = NULL;
    struct node *next;
    
    while (trav != NULL)
    {
        printf("%d ", trav->num);
        next = (unsigned long long)back^(unsigned long long)(trav)->add;
        back = trav; 
        trav = next;
    }
    return back;
}

void traverse_from_end_to_front(struct node *tail)
{
    struct node *trav = tail;
    struct node *front = NULL;
    struct node *prev;
    
    while (trav != NULL)
    {
        printf("%d ", trav->num);
        prev = (unsigned long long)front^(unsigned long long)(trav)->add;
        front = trav; 
        trav = prev;
    }
}

void reverse(struct node **head, struct node **tail)
{
    struct node *temp = NULL;
    temp = *head;
    *head = *tail;
    *tail = temp;
    traverse_from_front_to_end(*head);
}

/*void alternate(struct node **head, struct node **tail)
{
    struct node *back = *head;
    struct node *trav = (unsigned long long)back^(unsigned long long)(trav)->add;
    while ((unsigned long long)back^(unsigned long long)(trav)->add != NULL)
    {
        struct node *temp;
        struct node *trav_again = *tail->add;
        struct node *back_again = *tail;
        node *tail_again = trav;
        
        temp = back->add;
        temp = (unsigned long long)temp^(unsigned long long)trav;
        temp = (unsigned long long)temp^(unsigned long long)back_again;
        back->add = temp;
        
        temp = trav->add;
        temp = (unsigned long long)temp^(unsigned long long)back;
        trav->add = temp;
        
        temp = *tail->add;
        temp = (unsigned long long)temp^(unsigned long long)back;
        *tail->add = temp;
        
        trav = trav_again;
        back = back_again;
        *tail = tail_again;
    }
    traverse_from_front_to_end(*head);
}*/
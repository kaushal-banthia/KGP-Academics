#include <stdio.h>
#include <stdlib.h>

typedef struct _hashing
{
    int key;
    struct _hashing *next;//stores for actual collision
    struct _hashing *next_next;//stores all the values of this key
    int size;
}
hash;

void del(hash *counterparties_by_portfolio, hash *portfolio_by_counterparties, int counterparty_id, int size);
void insert(hash *arr, int key, int value, int size);
void print_table(hash *arr, char name, int size);

int hashed_key(int key, int size)
{
    return (key%size);
}

void main()
{
    FILE *f = fopen("input_for_10.txt", "r");
    int transaction, size;
    fscanf(f, "%d", &size);
    fscanf(f, "%d", &transaction);

    hash *counterparties_by_portfolio = (hash *) malloc(size * sizeof(hash));
    hash *portfolio_by_counterparties = (hash *) malloc(size * sizeof(hash));
    for (int i = 0; i < size; i++)
    {
        counterparties_by_portfolio[i].key = 0;
        counterparties_by_portfolio[i].next = NULL;
        counterparties_by_portfolio[i].next_next = NULL;
        counterparties_by_portfolio[i].size = 0;

        portfolio_by_counterparties[i].key = 0;
        portfolio_by_counterparties[i].next = NULL;
        portfolio_by_counterparties[i].next_next = NULL;
        portfolio_by_counterparties[i].size = 0;
    }

    for (int i = 0; i < transaction; i++)
    {
        char symbol;
        int counterparty_id = 0, portfolio_num = 0;
        while (1)
        {
            fscanf(f, "%c", &symbol);
            if (symbol != '\n')
                break;
        }

        if (symbol == '+')
        {
            fscanf(f, " %d %d", &counterparty_id, &portfolio_num);
            insert(portfolio_by_counterparties, counterparty_id, portfolio_num, size);
            insert(counterparties_by_portfolio, portfolio_num, counterparty_id, size);
        }
        else if (symbol == '-')
        {
            fscanf(f, "%d", &counterparty_id);
            del(counterparties_by_portfolio, portfolio_by_counterparties, counterparty_id, size);
        }
    }

    print_table(counterparties_by_portfolio, 'p', size);
    print_table(portfolio_by_counterparties, 'c', size);


}

void insert(hash *arr, int key, int value, int size)
{
    int index = hashed_key(key, size);
    hash *trav = (arr+index);
    hash *newnode = (hash *) malloc(sizeof(hash));
    hash *new_new_node = (hash *) malloc(sizeof(hash));

    new_new_node->key = value;
    new_new_node->next = NULL;
    new_new_node->next_next = NULL;
    new_new_node->size = 0;


    newnode->key = key;
    newnode->next = NULL;
    newnode->next_next = new_new_node;
    newnode->size = 1;

    while(trav->next != NULL && trav->key != key)
    {
        trav = trav->next;
    }

    if (trav->key == key)
    {
        hash *temp = trav;
        while(trav->next_next != NULL)
        {
            trav = trav->next_next;
        }
        trav->next_next = new_new_node;
        (temp->size)++;
    }

    else if (trav->next == NULL)
    {
        trav->next = newnode;
    }
}

void del(hash *counterparties_by_portfolio, hash *portfolio_by_counterparties, int counterparty_id, int size)
{
    int index = hashed_key(counterparty_id, size);
    hash *trav = (portfolio_by_counterparties+index);
    hash *prev = trav;
    while(trav->next != NULL && trav->key != counterparty_id)
    {
        prev = trav;
        trav = trav->next;
    }

    int length;
    if (trav->key == counterparty_id)
    {
        prev->next = trav->next;
        length = trav->size;
        int array_of_portfolios[length];//from the other hash table, all these values need to be deleted, having the same counterparty_id
        for (int i = 0; i < length; i++)
        {
            array_of_portfolios[i] = trav->next_next->key;
            trav = trav->next_next;
        }
        for (int i = 0; i < length; i++)
        {
            int index = hashed_key(array_of_portfolios[i], size);
            hash *trav = (counterparties_by_portfolio+index);
            trav = trav->next;
            while (trav->next != NULL || trav->key != array_of_portfolios[i])
            {
                trav = trav->next;
            }
            if (trav->key == array_of_portfolios[i])
            {
                while (trav->next_next != NULL)
                {
                    if (trav->next_next->key == counterparty_id)
                        trav->next_next = trav->next_next->next_next;
                    trav = trav->next_next;
                }
            }

        }

    }

    else
        printf("No such element found and thus nothing deleted");
}

void print_table(hash *arr, char name, int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        hash *trav = &(arr[i]);
        while (trav->next != NULL)
        {
            trav = trav->next;
            hash *temp = trav;
            int key = trav->key;
            while (trav->next_next != NULL)
            {
                trav = trav->next_next;
                int value = trav->key;
                printf("%c %d %d %d\n", name, i, key, value);
                count++;
            }
            trav = temp;
        }
        if (count == 0)
        {
            printf("%c %d -1 -1\n", name, i);
        }
    }
}

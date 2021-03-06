/*
 * C Program to Count Number of Non Leaf Nodes of a given Tree
 */
#include <stdio.h>
#include <stdlib.h>

struct btnode
{
    int value;
    struct btnode *r,*l;
} *root = NULL, *temp = NULL;

void create();
void insert();
void add(struct btnode *t);
void inorder(struct btnode *t);

int count = 0;

void main()
{
    int ch;
    printf("\nOPERATIONS ---");
    printf("\n1] Insert ");
    printf("\n2] Display");
    printf("\n3] Exit ");
    while (1)
        {
            printf("\nEnter your choice : ");
            scanf("%d", &ch);
            switch (ch)
                {
                case 1:
                    insert();
                    break;
                case 2:
                    inorder(root);
                    printf("\nNumber of non leaf nodes: %d", count);
                    break;
                case 3:
                    exit(0);
                default :
                    printf("Wrong choice, Please enter correct choice  ");
                    break;
                }
        }
}


void create()
{
    int data;
    printf("Enter the data of node : ");
    scanf("%d", &data);
    temp = (struct btnode* ) malloc(1*(sizeof(struct btnode)));
    temp->value = data;
    temp->l = temp->r = NULL;
}


void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        add(root);
}


void add(struct btnode *t)
{
    if ((temp->value > t->value) && (t->r != NULL))        
        add(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))       
        add(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

/* To display and count the sum of non leaf nodes */
void inorder(struct btnode *t)
{
    if (t->l != NULL)
        inorder(t->l);
    if ((t->l != NULL) ||  (t->r != NULL))
        {
            count++;                           
            printf("%d ->",t->value);
        }
    if (t->r != NULL)
        inorder(t->r);
}



#include <stdio.h>
#include <stdlib.h>
struct node
{
    // for containing data of char type
    char data;
    // next for containing the address of  next node
    struct node *next;
    // head for pointing to the first node of linked list
} *head;
// function initialize list
void init()
{
    head = NULL;
    printf("list innitialized.\n");
}
void showlist()
{
    if (head != NULL)
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("list is empty.\n");
    }
}
void insertatend(char data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("ERROR : could not allocate the memory.\n");
        return;
    }
    new->data = data;
    new->next = NULL;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}
void removefromend()
{
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *temp = head;
            struct node *temp1;
            while (temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            free(temp1->next);
            temp1->next = NULL;
        }
    }
    else
    {
        printf("list is empty.\n");
    }
}
void insertatbegining(char data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head = new;
}
void removefrombegining()
{
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
void inseratposition(char data,int pos)
{
    if(head==NULL && pos!=0)
    {
        printf("\nlist is empty.");
    }
    else
    {
        if(pos==0)
        {
            insertatbegining(data);
        }
        else
        {
            struct node *new=malloc(sizeof(struct node));
            new->data=data;
            struct node *temp=head;
            int count=0;
            while(count!=pos-1)
            {
                count++;
                temp=temp->next;
            }
            new->next=temp->next;
            temp->next=new;
        }
    }
}
void removefromposition(int pos)
{
    if(head==NULL && pos==0)
    {
        printf("\nlist is empty.");
    }
    else
    {
        if(pos==0)
        {
            removefrombegining();
        }
        else
        {
            struct node *temp=head;
            int count=0;
            while(count!=pos-1)
            {
                count++;
                temp=temp->next;
            }
            struct node *temp1=temp->next;
            temp->next=temp->next->next;
            free(temp1);
        }
    }
}
int main()
{
    char data;
    int ch = 0, pos = 0;
    do
    {
        printf("\n1.init the list.");
        printf("\n2.show list.");
        printf("\n3.add data to begining.");
        printf("\n4.add data to specific position.");
        printf("\n5.add data to end.");
        printf("\n6.remove data from begining.");
        printf("\n7.remove data from specific position.");
        printf("\n8.remove data from end.");
        printf("\n0.Exit.");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            init();
            break;
        case 2:
            showlist();
            break;
        case 3:
            printf("Enter data : ");
            scanf(" %c", &data);
            insertatbegining(data);
            break;
        case 4:
            printf("Enter data : ");
            scanf(" %c", &data);
            printf("Enter position : ");
            scanf(" %d", &pos);
            inseratposition(data,pos);
            break;
        case 5:
            printf("Enter data : ");
            scanf(" %c", &data);
            insertatend(data);
            break;
        case 6:
            removefrombegining();
            break;
        case 7:
            printf("Enter position : ");
            scanf(" %d", &pos);
            removefromposition(pos);
            break;
        case 8:
            removefromend();
            break;
        default:
            if (ch != 0)
                printf("Invalid choice.\n");
        }
    } while (ch != 0);
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
  PNODE temp = NULL;
  temp = first;
  while(temp != NULL)
  {
    printf("| %d | -",temp->data);
    temp = temp -> next;
  }
  printf("\n");
}

int Count(PNODE first)
{
  int iCount = 0;
  PNODE temp = NULL;
  temp = first;
  while(temp != NULL)
  {
    iCount++;
    temp = temp->next;
  }
  return iCount;
}

void Enqueue(PPNODE first,int no)
{
  PNODE newn =(PNODE)malloc(sizeof(NODE));
  newn -> data = no;
  newn -> next = NULL;
  PNODE temp = NULL;
  if(*first == NULL)
  {
    *first = newn;
  }
  else
  {
    temp = *first;
    while(temp -> next != NULL)
    {
      temp = temp ->next;
    }
    temp -> next = newn;
  }
}

int Dequeue(PPNODE first)
{
  PNODE temp = NULL;
  int iValue = 0;
  temp = *first;
  if(*first == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }
  else
  {
    iValue =temp ->data;
    *first = (*first) -> next;
    free(temp);
    return iValue;
  }
}
int main()
{
  PNODE head = NULL;
  Enqueue(&head,11);
  Enqueue(&head,21);
  Enqueue(&head,31);
  Enqueue(&head,41);
  Display(head);
  Dequeue(&head);
  Display(head);
  return 0;
}
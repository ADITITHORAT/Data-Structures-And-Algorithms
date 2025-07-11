#include <stdio.h>
#include<stdlib.h>

struct node 
{
  int data ;
  struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,PPNODE last , int no)
{
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn -> data = no;
  newn -> next = NULL;

  if((*first) == NULL && (*last) == NULL )
  {
    *first = newn;
    *last = newn;
    (*last)->next = newn;
  }
  else
  {
    newn ->next = *first;
    *first = newn;
    (*last)->next = *first;
  }
}
int Count(PNODE first,PNODE last)
{
  PNODE temp = NULL;
  temp = first;
  int iCount = 0;
  do
  {
    iCount++;
    temp = temp->next;
  } while (temp != first);
  printf("\n");
  return iCount;
}
void InsertLast(PPNODE first,PPNODE last, int no)
{
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn ->data = no;
  newn ->next = NULL;
  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;
    (*last)->next = newn;
  }
  else
  {
    (*last) -> next = newn;
    *last = newn;
    (*last)->next = *first;
  }
}

void InsertAtPos(PPNODE first , PPNODE last , int no, int pos)
{
  int iCount = Count(*first,*last);
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  PNODE temp = NULL;
  newn -> data = no;
  newn -> next = NULL;
  if((pos < 1) || pos>iCount +1)
  {
    printf("Invalid Position\n");
    return;
  }

  if(pos == 1)
  {
    InsertFirst(first,last,no);
  }
  else if (pos == iCount+1)
  {
    InsertLast(first,last,no);
  }
  else
  {
    temp = *first;
    for(int iCnt = 1; iCnt < pos -1 ; iCnt++)
    {
      temp = temp -> next;
    }
    newn -> next = temp ->next ;
    temp ->next = newn;
  }
}
void Display(PNODE first,PNODE last)
{
  PNODE temp = NULL;
  temp = first;
  do
  {
    printf("| %d | -> ",temp->data);
    temp = temp->next;
  } while (temp != first);
  printf("\n");
  
}

void DeleteFirst(PPNODE first , PPNODE last)
{
  PNODE temp = NULL;
  if(*first == NULL && *last == NULL)
  {
    return;
  }
  else if ((*first)==(*last))
  {
    free(*first);
    *first = NULL;
    *last = NULL;
  }
  else 
  {
    temp = *first;
    *first = (*first)->next;
    (*last)->next = *first;
    free(temp);
  }
}

void DeleteLast(PPNODE first,PPNODE last )
{
  PNODE temp = NULL;
  if(*first == NULL && *last == NULL)
  {
    return;
  }
  else if (*last == *first)
  {
    free(*last);
    *last = NULL;
    *first = NULL;
  }
  else
  {
    temp = *first;
    while(temp ->next != *last)
    {
      temp = temp -> next;
    }
    free(*last);
    *last = temp;
    (*last)->next = *first;

  }
}

void DeleteAtPos(PPNODE first, PPNODE last,int pos)
{
  int iCount = Count(*first,*last);
  PNODE temp = NULL;
  PNODE target = NULL;
  if(pos < 1 || pos> iCount)
  {
    printf("Invalid Position\n");
    return;
  }
  if (pos == 1)
  {
    DeleteFirst(first,last);
  }
  else if (pos == iCount)
  {
    DeleteLast(first,last);
  }
  else
  {
    temp = *first;
    for(int iCnt = 1; iCnt < pos -1 ; iCnt ++)
    {
      temp = temp-> next;
    }
    target = temp -> next;
    temp -> next = target -> next;
    free(target);
  }
}
int main()
{
  PNODE head = NULL;
  PNODE tail = NULL;
  InsertFirst(&head,&tail,10);
  InsertFirst(&head,&tail,20);
  InsertFirst(&head,&tail,30);
  Display(head,tail);
  InsertLast(&head,&tail,21);
  Display(head,tail);
  InsertAtPos(&head,&tail,5,2);

  Display(head,tail);
  DeleteFirst(&head,&tail);
  Display(head,tail);
  DeleteLast(&head,&tail);
  Display(head,tail);
  DeleteAtPos(&head,&tail,2);
  Display(head,tail);
  return 0;
}
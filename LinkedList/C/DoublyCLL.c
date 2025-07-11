#include<stdio.h>
#include<stdlib.h>


struct node 
{
  int data;
  struct node * next;
  struct node * prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node ** PPNODE;


void Display(PNODE first , PNODE last)
{
  PNODE temp = NULL;
  temp =  first;
  do
  {
    printf("| %d | <=> ",temp ->data);
    temp = temp -> next;
  } while (temp != first);
  printf("NULL\n");

}
int Count(PNODE first , PNODE last)
{
  PNODE temp = NULL;
  int iCount = 0;
  temp = first;
  do
  {
    iCount++;
    temp = temp->next;
  } while (temp != first);
  return iCount;
  
}
void InsertFirst(PPNODE first , PPNODE last , int no)
{

  PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn -> data = no;
  newn -> next = NULL;

  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;
  }
  else
  {
    newn -> next = *first;
    (*first) -> prev = newn;
    *first = newn;
    (*last) -> next = *first;
    (*first)->prev = *last;
  }
}
void InsertLast(PPNODE first , PPNODE last , int no)
{
 
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn -> data = no;
  newn -> next = NULL;
  if(*first == NULL && *last == NULL)
  {
    *first = newn;
    *last = newn;
  }
  else
  {
    (*last) ->next = newn;
    newn -> prev = (*last);
    *last = newn;
    (*last)->next = *first ;
    (*first)->prev = *last;
  }
  
  
}
void InsertAtPos(PPNODE first , PPNODE last , int no,int pos)
{
  PNODE newn = (PNODE)malloc(sizeof(NODE));
  newn -> next = NULL;
  newn -> data = no;
  PNODE temp = NULL;
  int iCount = Count(*first,*last);
  if(pos < 1 || pos > iCount+1)
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
    for(int iCnt = 1; iCnt < pos -1;iCnt++)
    {
     temp = temp -> next; 
    }
    newn -> next =temp -> next;
    newn ->prev = temp;
    
    temp -> next -> prev = newn;
    temp -> next = newn;
  }
}

void DeleteFirst(PPNODE first , PPNODE last)
{
  if(*first == NULL && *last == NULL)
  {
    return;
  }
  else if (*last == *first)
  {
    free(*first);
    *first = NULL;
    *last = NULL;
  }
  else
  {
    *first = (*first) -> next;
    free((*last) -> next);
    (*last)->next = *first;
    (*first)->prev = *last;
    
  }
}
void DeleteLast(PPNODE first , PPNODE last)
{
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
    *last = (*last) -> prev;
    free((*last) -> next);
    (*first )->prev = *last;
    (*last) -> next = (*first);

  }

}
void DeleteAtPos(PPNODE first , PPNODE last , int pos)
{
  int iCount = Count(*first,*last);
  PNODE temp = NULL;
  if(pos < 1 || pos > iCount)
  {
    printf("Invalid Positon \n");
    return;
  }

  if(pos == 1)
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
    for(int iCnt = 1; iCnt < pos -1;iCnt++)
    {
      temp = temp -> next;
    }
    temp->next = temp -> next ->next;
    free(temp ->next -> prev);
    temp ->next ->prev = temp;
  }
}
int main()
{
  PNODE head = NULL;
  PNODE tail = NULL;
  InsertFirst(&head, &tail,105);
  InsertLast(&head, &tail,15);

  InsertFirst(&head, &tail,125);
  InsertLast(&head, &tail,145);
  InsertAtPos(&head,&tail,123,3);
  Display(head,tail);
  // DeleteFirst(&head,&tail);
  // DeleteLast(&head,&tail);
   DeleteAtPos(&head,&tail,3);
  Display(head,tail);
  return 0;
}
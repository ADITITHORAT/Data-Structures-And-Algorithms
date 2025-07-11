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


void InsertFirst(PPNODE first, int no)
{
  PNODE newn = NULL;
  newn = (PNODE)malloc(sizeof(NODE));
  newn ->data = no;
  newn -> next = NULL;
  if(*first == NULL)
  {
    *first = newn;  // first->head->newn
  }
  else
  {
    newn -> next = *first;
    *first = newn;
  }
}

void InsertLast(PPNODE first , int no)
{
  PNODE newn = NULL;
  PNODE temp = NULL;
  newn = (PNODE)malloc(sizeof(NODE));
  newn -> data = no;
  newn -> next = NULL;

  if(*first == NULL)
  {
    *first = newn;
  }
  else
  {
    temp = *first;
    while(temp -> next != NULL)
    {
      temp = temp -> next;
    }
    temp -> next = newn;


  }
}


void DeleteFirst(PPNODE first)
{
  PNODE temp = NULL;

  if(first == NULL)
  {
    return;
  }
  else if ((*first)->next == NULL)
  {
    *first = NULL;
    free(first);
  }
  else
  {
    temp = *first;
    (*first)  =  (*first)->next;
    free(temp);
  }
}

void DeleteLast(PPNODE first)
{
  PNODE temp = NULL;
 
  if(*first == NULL)
  {
    return;
  }
  else if ( (*first)->next == NULL)
  {
    *first = NULL;
    free(first);
  }
  else
  {
    temp = *first;
    while(temp -> next -> next != NULL)
    {
      temp = temp -> next;
    }
 
    
    temp -> next = NULL;
    free(temp->next);

  }
}
void Display(PNODE first)
{
  PNODE temp = NULL;
  temp = first;
  while(temp != NULL)
  {
    printf("| %d | -> ",temp->data);
    temp = temp -> next;
  }
  printf("NULL\n");
}

int Count(PNODE first)
{
  int iCount = 0;
  PNODE temp = first;
  while(temp != NULL)
  {
    iCount++;
    temp = temp -> next;
  }
  return iCount;
}

void InsertAtPos(PPNODE first , int no,int pos)
{
  int iCount = 0;
  PNODE temp = NULL;
  PNODE newn = NULL;
  int iCnt = 0 ;
  iCount = Count(*first);

  if((pos < 1) || (pos > iCount + 1) )
  {
    printf("Invalid position \n");
    return ;
  }

  if(pos == 1)
  {
    InsertFirst(first,no);
  }
  else if (pos == iCount + 1)
  {
    InsertLast(first,no);
  }
  else
  {
    temp = *first;
    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;
    for(iCnt = 1 ; iCnt < pos - 1 ;iCnt ++)
    {
      temp = temp -> next;
    }
    newn -> next = temp -> next;
    temp -> next = newn;
    
  }
}

void DeleteAtPos(PPNODE first,int pos)
{
  int iCount = 0 ,iCnt = 0;
  PNODE temp = NULL;
  PNODE target = NULL;
  iCount = Count(*first);
  
  if((pos < 1) || (pos > iCount))
  {
    printf("Invalid Position\n");
    return;
  }

  if(pos == 1 )
  {
    DeleteFirst(first);
  }
  else if (pos == iCount)
  {
    DeleteLast(first);
  }
  else
  {
    temp = *first;
    for(iCnt = 1 ; iCnt < pos - 1 ; iCnt ++)
    {
      temp = temp -> next;
    }
    target = temp -> next;
    temp -> next = target -> next;
    free(target);
  }
}
int main()
{
  PNODE head = NULL;
  int iRet = 0;
  InsertFirst(&head,121);
  InsertFirst(&head,111);
  InsertFirst(&head,101);
  InsertLast(&head,51);
  InsertLast(&head,21);
  InsertLast(&head,11);
  Display(head);
  iRet = Count(head);
  printf("Elements in LL are : %d\n",iRet);

  DeleteFirst(&head);
  Display(head);
  iRet = Count(head);
  printf("Elements in LL are : %d\n",iRet); 

  InsertAtPos(&head,105,5);
  Display(head);
  iRet = Count(head);
  printf("Elements in LL are : %d\n",iRet); 

  DeleteAtPos(&head,5);
  Display(head);
  iRet = Count(head);
  printf("Elements in LL are : %d\n",iRet);  
  return 0;
}
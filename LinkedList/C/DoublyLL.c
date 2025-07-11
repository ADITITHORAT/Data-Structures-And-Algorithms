#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node * next;
  struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first)
{
  PNODE temp = NULL;
  temp = first;
  printf("NULL <=> ");
  while(temp != NULL)
  {
    printf("| %d | <=> ",temp->data);
    temp = temp ->next;
  }
  printf("NULL\n");
}

int Count(PNODE first)
{
  PNODE temp = first;
  int iCount = 0;
  while(temp != NULL)
  {
    iCount++;
    temp = temp ->next;
  }
  
  return iCount;
}
void InsertFirst (PPNODE first , int no)  
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn ->data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((*first) == NULL)
    {
      *first = newn;
    }
    else
    {
      newn -> next = *first;
      (*first) -> prev = newn ;
      *first = newn ;
    }
}
void InsertLast(PPNODE first,int no )
{
  PNODE newn = NULL;
  PNODE temp = NULL;
  newn = (PNODE) malloc(sizeof(NODE));
  newn -> data = no;
  newn -> next = NULL;
  newn -> prev = NULL;
  if(*first == NULL)
  {
    *first = newn;
  }
  else
  {
    temp = *first;
    while(temp -> next != NULL)
    {
      temp = temp->next;
    }
    temp -> next = newn;
    newn -> prev = temp;
  }
}

void DeleteFirst(PPNODE first)
{
  PNODE temp = NULL;
  if(*first == NULL)
  {
    return;
  }
  else if ((*first )-> next == NULL)
  {
    free(*first);
    (*first) = NULL;
  }
  else 
  {
    // temp = * first;
    // (*first) = (*first) -> next;
    // free(temp);
    // (*first) -> prev = NULL;

    //OR Without Temp 
    *first = (*first)->next;
    free((*first)->prev);
    (*first) ->prev = NULL;
  }
}
void DeleteLast(PPNODE first)
{
  PNODE temp = NULL;
  if(*first == NULL)
  {
    return;
  }
  else if ((*first) -> next == NULL)
  {
    free(*first);
    (*first)= NULL;
  }
  else
  {
    temp = * first;
    while(temp ->next != NULL)
    {
      temp = temp -> next;
    }
    temp ->prev -> next = NULL;
    free(temp);

    /* OR while(temp -> next -> next != NULL)
    {
      temp = temp -> next;
    }
      free(temp -> next);
      temp -> next = NULL;
    */
  }
}
void InsertAtPos(PPNODE first , int no, int pos )
{
  int iCount = 0,iCnt = 0;
  PNODE newn = NULL;
  PNODE temp = NULL;
  iCount = Count(*first);
  if((pos < 1) || (pos > iCount + 1))
  {
    printf("Ivalid Position\n");
    return;
  }

  if(pos == 1)
  {
    InsertFirst(first,no);
  }
  else if ( pos == iCount +1)
  {
    InsertLast(first,no);
  }
  else
  {
    newn = (PNODE)malloc(sizeof(NODE));
    temp = *first;
    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;
    for(iCnt = 1; iCnt < pos - 1; iCnt++)
    {
      temp = temp -> next;
    }
    newn -> next = temp -> next;
    temp -> next -> prev = newn;
    newn -> prev = temp ;
    temp -> next = newn;
  }
}

void DeleteAtPos(PPNODE first , int pos)
{
    int iCount = 0 , iCnt = 0; 
    PNODE temp = NULL; 
    PNODE target = NULL;  
    iCount  = Count(*first);
    if((pos < 1) || (pos > iCount + 1))
    {
      printf("Invalid Position ");
      return;
    }  

    if(pos == 1)
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
      for(iCnt = 0 ; iCnt < pos - 1 ; iCnt++)
      {
        temp = temp -> next;
      }
      // temp -> next = temp -> next -> next;
      // free(temp -> next -> prev);
      // temp -> next ->prev = temp;

      target = temp -> next;
      temp -> next = target -> next;
      target -> next ->prev = target ->prev;
      free(target);
    }
}

int main()
{
  PNODE head = NULL;
  int iRet = 0;
  InsertFirst(&head,51);
  InsertFirst(&head,21);
  InsertFirst(&head,11);
  Display(head);
  InsertLast(&head,101);
  InsertLast(&head,121);
  InsertLast(&head,151);
  Display(head);
  iRet = Count(head);
  printf("Elements in the LL are : %d\n",iRet);
  // DeleteFirst(&head);
  // Display(head);
  // iRet = Count(head);
  // printf("Elements in the LL are : %d\n",iRet);
  // DeleteLast(&head);
  // Display(head);
  // iRet = Count(head);
  // printf("Elements in the LL are : %d\n",iRet); 

  InsertAtPos(&head,105,5);
  Display(head);
  iRet = Count(head);
  printf("Elements in the LL are : %d\n",iRet); 

  DeleteAtPos(&head,5);
  Display(head);
  iRet = Count(head);
  printf("Elements in the LL are : %d\n",iRet); 
  return 0;
}
#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node * next;
};



void Push(struct node ** first,int no)
{
  struct node * newn = NULL;
  newn = (struct node *)malloc(sizeof(struct node));
  newn ->data = no;
  newn -> next = NULL;

  if(*first == NULL)
  {
    *first = newn;
  }
  else
  {
    newn ->next = *first;
    *first = newn;
  }
}
int Pop(struct node ** first)
{
  struct node * temp = *first;
  int iValue = 0;
  if(*first == NULL)
  {
    printf("Stack is empty\n");
    return -1;
  }
  else
  {
    iValue = temp ->data;
    *first = (*first)->next;
    free(temp);
    return iValue;
  }
}

void Display(struct node * first)
{
  struct node * temp = first;
  while(temp != NULL)
  {
    printf("| %d |\n",temp ->data);
    temp = temp ->next;
  }
}

int Count(struct node * first)
{
  struct node * temp = first;
  int iCount = 0;
  while(temp != NULL)
  {
    iCount++;
    temp = temp ->next;
  }
  return iCount;
}
int main()
{
  struct node * head = NULL;
  int iRet = 0;
  int iCnt = 0;
  Push(&head,11);
  Push(&head,21);
  Push(&head,31);
  Push(&head,41);
  Push(&head,51);
  Display(head);
  iCnt = Count(head);
  printf("Element in the stack are %d \n",iCnt);
  iRet = Pop(&head);
  Display(head);
  printf("Poped element is : %d\n",iRet);
  iCnt = Count(head);
  printf("Element in the stack are %d \n",iCnt);
  return 0;
}
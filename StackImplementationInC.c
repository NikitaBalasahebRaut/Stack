//Dynamic Implementation of stack  using linked list

//push -->InsertFirst
//pop -->DeleteFirst
//Peep -->DisplayFirstElement

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

void Push(PPNODE Head,int no)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
}

int Pop(PPNODE Head)
{
	PNODE temp = *Head;
	int no = 0;
	
	if(*Head == NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		no = (*Head)->data;
		*Head = (*Head)->next;
		free(temp);
	}
	return no;
}

int Peep(PNODE Head)
{
	int no = 0;
	
	if(Head == NULL)
	{
		printf("stack is empty\n");
		return -1;
	}
	else
	{
		no = Head->data;
		return no;
	}
}

void Display(PNODE Head)
{
   if(Head == NULL)
   {
      printf("stack is empty \n");
      return;
   }
   else
   {
      while(Head != NULL)
	  {
		  printf("%d\t", Head->data);
		  Head = Head->next;
	  }
   }	
printf("\n");   
}

int Count(PNODE Head)
{
	int iCnt = 0;
   if(Head == NULL)
   {
      printf("stack is empty \n");
      return -1;
   }
   else
   {
      while(Head != NULL)
	  {
		  iCnt++;
		  Head = Head->next;
	  }
   }	
return iCnt;   
  printf("\n");
}
int main()
{
	PNODE First = NULL;
	int no = 0;
	int iRet = 0;
	
	printf("Enter The Element to push into the stack \n");
	scanf("%d",&no);
	Push(&First,no);
	
	printf("Enter The Element to push into the stack \n");
	scanf("%d",&no);
	Push(&First,no);
	
	printf("Enter The Element to push into the stack \n");
	scanf("%d",&no);
	Push(&First,no);
	
	printf("\nElements of linked list are\n");
	Display(First);
	
	iRet = Peep(First);
	printf("\npeeped element is :  %d", iRet);
	
	iRet = Pop(&First);
	printf("\n poped element is :  %d", iRet);
	
	printf("\nElements of linked list are\n");
	Display(First);
	
	iRet = Count(First);
	printf("No of elements in li ked list are : %d", iRet);
	return 0;
}

/*
Enter The Element to push into the stack
10
Enter The Element to push into the stack
20
Enter The Element to push into the stack
30

Elements of linked list are
30      20      10
peeped element is :  30
 poped element is :  30
Elements of linked list are
20      10    
 No of elements in li ked list are : 2
*/
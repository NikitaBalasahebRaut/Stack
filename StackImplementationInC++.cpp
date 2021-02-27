//stack implementation in c++

#include<iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

typedef Node NODE;
typedef Node * PNODE;

class Stack
{
	public:
	      PNODE Head;
		  
		  Stack()
		  {
			  Head = NULL;
		  }
		  
		  void Push(int value)
		  {
			  PNODE newn = NULL;
			  newn = new NODE;
			  newn->data = value;
			  newn->next = NULL;
			  
			  if(Head == NULL)
			  {
				  Head = newn;
			  }
			  else
			  {
				  newn->next = Head;
				  Head = newn;
			  }
		  }
		  
		  int Pop()
		  {
			  PNODE temp = NULL;
			  temp = Head;
			  int no = 0;
			  
			  if(Head == NULL)
			  {
				  cout<<"stack is empty\n";
				  return -1;
			  }
			  else
			  {  
		          no = Head->data;
				  Head = Head->next;
				  delete temp;
				  return no;
			  }
		  }
		  
		  void Display()
		  {
			  PNODE temp = Head;
			  
			  while(temp != NULL)
			  {
				  cout<<temp->data<<"\n";
				  temp = temp->next;
			  }
			  cout<<"\n";
		  }
		  
		  int Count()
		  {
			  PNODE temp = Head;
			  int iCnt = 0;
			  
			  while(temp != NULL)
			  {
				  iCnt++;
				  temp = temp->next;
			  }
			  return iCnt;
		  }
				  
};

int main()
{
	int no = 0;
	int iRet = 0;
	Stack obj;
	
	cout<<"Enter The Element \n";
	cin>>no;
	obj.Push(no);
	
	cout<<"Enter The Element \n";
	cin>>no;
	obj.Push(no);
	
	cout<<"Enter The Element \n";
	cin>>no;
	obj.Push(no);
	
	cout<<"linked list are:"<<"\n";
	obj.Display();
	
	no = obj.Pop();
	cout<<"Poped element\t"<<no<<"\n";
	
	 cout<<"linked list are:"<<"\n";
	obj.Display();
	
	iRet = obj.Count();
	cout<<"No of Element In Linked List are : \t"<<iRet;
	return 0;
}
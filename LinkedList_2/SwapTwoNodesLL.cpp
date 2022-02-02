/*
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' 
Swap the nodes that are present at the 'i-th' and 'j-th' positions.


Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 

*/
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/


Node *swapNodes(Node *head, int i, int j)
{
	if(head==NULL) return NULL;
	
	//swap two nodes
	//declare variables 
	Node* prevI=head, *prevJ=head, *currentI=head, *currentJ=head;
	//traverse through nodes until prevI-1
	int count=0;
	if(i>0)
	{
	    while(count!=i-1)
	    {
	        prevI=prevI->next;
	        count++;
	    }
	}
	count=0;
	//traverse through the nodes until prevJ-1
	if(j>0)
	{
	    while(count != j-1)
	    {
	        prevJ = prevJ->next;
	        count++;
	    }
	}
	
	if(i==0)
	{
	    Node* temp = head->next;
	    currentJ=prevJ->next;
	    head->next = prevJ->next->next;
	    prevJ->next->next = temp;
	    prevJ->next = head;
	    head=currentJ;
	    return head;
	}
	else if(j==0)
	{
	    Node* temp = head->next;
	    currentI = prevI->next;
	    head->next = currentI->next;
	    currentI->next = temp;
	    prevI->next = head;
	    head=currentI;
	    return head;
	}
	currentI=prevI->next;
	currentJ=prevJ->next;
	
	//check if i and j are present at alternate positions or not
	if(i-j == -1)
	{
	    Node* temp = currentJ->next;
	    prevI->next = currentJ;
	    currentJ->next = currentI;
	    currentI->next = temp;
	    return head;
	}
	else if(i-j==1)
	{
	    Node* temp = currentI->next;
	    prevJ->next = currentI;
	    currentI->next = currentJ;
	    currentJ->next = temp;
	    return head;
	}
	
	Node *temp = currentI->next;
	prevI->next = currentJ;
	currentI->next = currentJ->next;
	currentJ->next = temp;
	prevJ->next = currentI;
	return head;
}



int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
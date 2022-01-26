#include <iostream>
using namespace std;

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


//recursive solution
Node *DeleteIthPos(Node *head, int pos)
{
    //base case
    if(head==NULL)
    {
        return NULL;
    }

    //recursive call
    Node *smallAns = DeleteIthPos(head->next, pos-1);
    //small calculation
    if(pos==1)
    {
        head->next = NULL;
        return smallAns;
    }
    head->next = smallAns;
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void printLinkedList(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = takeinput();
    int pos;
    cin>>pos;
    head = DeleteIthPos(head, pos);
    printLinkedList(head);
}
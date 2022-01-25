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


Node* insertAtIthPos(Node* head, int data, int pos)
{
    Node *newNode = new Node(data);
    if(pos==1)
    {
        newNode->next = head;
        head=newNode;
        return head;
    }
    int c=1;
    Node *temp=NULL;
    Node *temp_head = head;
    while(temp_head!=NULL)
    {
        if(c==pos-1)
        {
            temp=temp_head;
        break;
        }
        c++;
        temp_head=temp_head->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
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
    int data, pos;
    Node *head = takeinput();
    cin>>data>>pos;
    head = insertAtIthPos(head, data, pos);
    printLinkedList(head);
}
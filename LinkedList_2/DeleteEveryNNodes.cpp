/*
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. 
Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list

Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6


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

Node* skipMdeleteN(Node* head, int m, int n)
{
    if(!head) return head;
    if(m==0 && n>0) return NULL;
    int c1=1, c2=1;
    Node* temp1 = head, *temp2=NULL;

    while(temp1)
    {
        while(c1!=m && temp1)
        {
            temp1=temp1->next;
            c1++;
        }

        if(temp1)
        {
            temp2=temp1->next;
            c2=1;
            while(temp2 && c2!=n)
            {
                Node* temp = temp2;
                temp2=temp2->next;
                temp->next = NULL;
                delete temp;
                c2++;
            }
        }
        if(temp1) {
            if(temp2)
            {
                temp1->next = temp2->next;
                temp1=temp2->next;
            }
            else{
                temp1->next=NULL;
                temp1=NULL;
            }
        }
        c1=1;
        c2=1;
    }
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
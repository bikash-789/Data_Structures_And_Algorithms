/*
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
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

Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2)
{
    //base cases
    if(!head1 && !head2) return NULL;
    else if(!head1) return head2;
    else if(!head2) return head1;

    //solution
    Node *finalHead =NULL, *finalTail = NULL;

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(finalHead==NULL)
            {
                finalHead=head1;
                finalTail=head1;
            }
            else {
                finalTail->next = head1;
                finalTail=finalTail->next;
            }
            head1=head1->next;
        }

        else{
            if(finalHead==NULL)
            {
                finalHead=head2;
                finalTail=head2;
            }
            else {
                finalTail->next = head2;
                finalTail=finalTail->next;
            }
            head2=head2->next;
        }
    }

    if(head1!=NULL)
    {
        finalTail->next = head1;
        finalTail=finalTail->next;
        head1=head1->next;
    }

    if(head2!=NULL)
    {
        finalTail->next = head2;
        finalTail=finalTail->next;
        head2=head2->next;
    }

    return finalHead;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
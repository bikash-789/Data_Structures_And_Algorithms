/*
Given a singly linked list of integers, sort it using 'Merge Sort.'
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

Node *mergeLL(Node *head1, Node *head2)
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

Node *midPoint(Node *head)
{
    Node *fast=head->next, *slow=head;
    while(fast!=NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}
int length(Node *head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}


Node *mergeSort(Node *head)
{
    //base case
    if(length(head) == 0 || length(head)==1) return head;

    //find mid node
    Node *midNode = midPoint(head);
    //recursive call
    Node *leftLL = head;
    Node *rightLL = midNode->next;
    midNode->next = NULL;

    Node *firstHalf = mergeSort(leftLL);
    Node *secondHalf = mergeSort(rightLL);

    //finally merge two sorted LL
    return mergeLL(firstHalf, secondHalf);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
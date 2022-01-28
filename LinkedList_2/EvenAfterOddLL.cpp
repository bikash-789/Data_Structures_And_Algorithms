/*
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers.
The relative order of the odd and even terms should remain unchanged.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

Sample Input 1 :
1
1 4 5 2 -1

sample output 1:
1 5 4 2 

Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1

Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
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

Node* evenAfterOdd(Node* head)
{
    //base case
    if(!head || !head->next) return head;

    //recursive call
    Node* smallAns = evenAfterOdd(head->next);

    //smallCalculation
    if(head->data % 2 == 0 && smallAns->data%2 != 0)
    {
        //search for first node where the even number begins
        Node* temp = smallAns;
        while(temp->next!= NULL && temp->next->data % 2 != 0)
        {
            temp=temp->next;
        }
        head->next = temp->next;
        temp->next = head;
        return smallAns;
    }
    head->next = smallAns;
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
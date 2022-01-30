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

int findLength(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head==NULL){
        return head;
    }
    
    int len=findLength(head);
    if(i==j){
        return head;
    }
    if(i<=len-1 && j<=len-1){
        Node *tempI = head, *tempJ = head, *tempM = head, *tempN=head;
        
        int count=0;
        if(i>0){
            while(count!=i-1){
                tempI = tempI->next;
                count++;
             }     
        }
        
        count=0;
        if(j>0){
            while(count!=j-1){
                tempJ = tempJ->next;
                count++;
            }
        }
        if(i==0){
            Node *t = head->next;
            head->next = tempJ->next->next;
            tempJ->next->next = t;
            head = tempJ->next;
            return head;
        }
        else if(j==0){
            Node *t = head->next;
            head->next = tempI->next->next;
            tempI->next->next = t;
            head=tempI->next;
            return head;
        }
        tempM = tempI->next;
        tempN = tempJ->next;
        if(i-j==-1){
            Node *t = tempN->next;
            tempI->next = tempN;
            tempN->next = tempM;
            tempM->next = t;
            return head;
        }
        else if(i-j == 1){
            Node *t = tempM->next;
            tempJ->next = tempM;
            tempM->next = tempN;
            tempN->next = t;
            return head;
        }
        
        Node *t = tempM->next;
        tempM->next = tempN->next;
        tempN->next = t;
        tempI->next = tempN;
        tempJ->next = tempM;
        
        return head;
    }
    
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
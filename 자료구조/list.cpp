#include "list.h"

void LinkedList::Append(int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
		head = newNode;
	else {
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void LinkedList::Prepend(int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
		head = newNode;
	else {
		Node *temp = new Node;
		temp = head;
		head = newNode;
		head->next = temp;
	}
}

int LinkedList::Length()
{
	int count = 0;
	Node *temp = new Node;
	temp = head;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void LinkedList::Print()
{
	Node *temp = new Node;
	temp = head;

	for (int i = 1; i <= Length(); i++)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
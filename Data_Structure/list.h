#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

class Node {
public:
	int data;	
	Node *next;	
};

class LinkedList {
public:
	Node* head = NULL;
	void Append(int data);
	int Length();
	void Print();

};
#endif
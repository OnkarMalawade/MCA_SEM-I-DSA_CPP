#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int i = 0;

struct node {
	int key;
	struct node* prev;
	struct node* next;
} ;
node* head = NULL;
node* first = NULL;
node* temp = NULL;
node* tail = NULL;

void addnode(int k)
{
	node* ptr
		= (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		head = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		first->next = temp;
		temp->prev = first;
		first = temp;
		tail = temp;
	}
	i++;
}
void traverse()
{
	node* ptr = head;
	while (ptr != NULL) {
		cout <<" " << ptr->key;
		ptr = ptr->next;
	}

	cout <<"\n";
}
void insertatbegin(int k)
{
	node* ptr
		= (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		first = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	i++;
}

void insertatend(int k)
{
	node* ptr
		= (node*)malloc(sizeof(node));
	ptr->key = k;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (head == NULL) {
		first = ptr;
		first = head;
		tail = head;
	}
	else {
		temp = ptr;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	i++;
}

void insertatpos(int k, int pos)
{
	if (pos < 1 || pos > i + 1) {
		cout <<"Please enter a"
			" valid position\n";
	}
	else if (pos == 1) {
		insertatbegin(k);
	}
	else if (pos == i + 1) {
		insertatend(k);
	}
	else {
		node* src = head;

		while (pos--) {
			src = src->next;
		}

		node **da, **ba;
		node* ptr
			= (node*)malloc(
				sizeof(node));
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->key = k;
		ba = &src;
		da = &(src->prev);
		ptr->next = (*ba);
		ptr->prev = (*da);
		(*da)->next = ptr;
		(*ba)->prev = ptr;
		i++;
	}
}

void delatbegin()
{
	head = head->next;
	i--;
}

void delatend()
{
	tail = tail->prev;
	tail->next = NULL;
	i--;
}

void delatpos(int pos)
{
	if (pos < 1 || pos > i + 1) {
		cout <<"Please enter a"
			" valid position\n";
	}
	else if (pos == 1) {
		delatbegin();
	}
	else if (pos == i) {
		delatend();
	}
	else {
		node* src = head;
		pos--;

		while (pos--) {
			src = src->next;
		}

		node **pre, **aft;
		pre = &(src->prev);
		aft = &(src->next);

		(*pre)->next = (*aft);
		(*aft)->prev = (*pre);

		i--;
	}
}
void search(int data){
	struct node* trav = head;
	bool flag = true;
	while(trav != NULL && flag == true){
		if(trav -> key == data){
			flag = false;
			break;
		}
		else{
			trav = trav -> next;
		}
	}
	if(flag == false){
		cout << "Element Found!";
	}
	else{
		cout << "Element Not Found!";
	}
}
int main()
{
	addnode(2);
	addnode(4);
	addnode(9);
	addnode(1);
	addnode(21);
	addnode(22);

	cout <<"Linked List: ";
	traverse();

	cout <<"\n";

	insertatbegin(1);
	cout <<"Linked List after"
		" inserting 1 "
		"at beginning: ";
	traverse();

	insertatend(0);
	cout <<"Linked List after "
		"inserting 0 at end: ";
	traverse();

	insertatpos(44, 3);
	cout <<"Linked List after "
		"inserting 44 "
		"after 3rd Node: ";
	traverse();
	
	cout<<"\nSearching Element in the Linked list: ";
	int n;
	cin >> n;
	search(n);

	cout <<"\n \n";

	delatbegin();
	cout <<"Linked List after "
		"deleting node "
		"at beginning: ";
	traverse();
	
	delatend();
	cout <<"Linked List after "
		"deleting node at end: ";
	traverse();

	cout <<"Linked List after "
		"deleting node "
		"at position 5: ";
	delatpos(5);
	traverse();

	return 0;
}

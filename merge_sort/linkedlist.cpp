#include "linkedlist.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;	
}

LinkedList::~LinkedList() {

}

void LinkedList::add(int data) {
	node* new_node = new node;
	new_node->data = data;
	new_node->next = nullptr;
	if(head == nullptr && tail == nullptr) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
}

void LinkedList::print() {
	node* curr = head;
	while(curr != nullptr) {
		cout << curr->data;
		if(curr->next != nullptr) {
			cout << "->";
		}
		curr = curr->next;
	}
	cout << endl;
}

node* LinkedList::getHead() {
	return head;
}

node* LinkedList::getTail() {
	return tail;
}
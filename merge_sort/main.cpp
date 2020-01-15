#include "linkedlist.h"

using namespace std;

void merge_sort(node* start, node* end);
void merge(node* start, node* end, node* middle);

int main() {
	LinkedList ll;
	ll.add(3);
	ll.add(1);
	ll.add(2);
	ll.print();
	merge_sort(ll.getHead(), ll.getTail());
	//ll.print();
	return 0;
}

void merge_sort(node* start, node* end) {
	if(start != end) {
		node* fast = start;
		node* slow = start;
		while(fast != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
		}
		merge_sort(start, slow);
		merge_sort(slow->next, end);
		merge(start, end, slow);
	}
}

void merge(node* start, node* end, node* middle) {
	LinkedList temp;
	node* i = start;
	node* j = middle->next;
	int k = 0;

	while(i != middle->next || j != end->next) {
		if(i != middle->next && (j == end->next || i->data <= j->data)) 
			{temp.add(i->data); i = i->next; k++;}
		else {temp.add(j->data); j=j->next; k++;}
	}

	node* curr = start->next;
	node* temp_curr = temp.getHead();
	for(int y=0; y<k+1; y++) {
		curr->data = temp_curr->data;
		curr = curr->next;
		temp_curr = temp_curr->next;
	}
}
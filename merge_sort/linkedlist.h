struct node {
	int data;
	node* next;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void add(int data);
	void print();
	void replace(node* replacement);
	node* getHead();
	node* getTail();
private:
	node* head;
	node* tail;
};
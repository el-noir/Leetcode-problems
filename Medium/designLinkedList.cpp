#include <iostream>
using namespace std;

class MyLinkedList {
private:
	int val;
	MyLinkedList* next;
	MyLinkedList* prev;

public:
	MyLinkedList* head = NULL;
	MyLinkedList() {
		this->val = -1;
		this->next = NULL;
		this->prev = NULL;
	}
	int get(int index) {
		MyLinkedList* curr = head;
		for (int i = 0; i < index && curr != NULL; i++) {
			curr = curr->next;
		}
		if (curr == NULL) {
			return -1; // Invalid index
		}
		return curr->val;
	}

	void addAtHead(int val) {
		MyLinkedList* temp = new MyLinkedList();
		temp->val = val;
		temp->next = head;
		if (head != NULL) {
			head->prev = temp;
		}
		head = temp;
	}
	void addAtTail(int val) {
		MyLinkedList* temp = new MyLinkedList();
		temp->val = val;
		if (head == NULL) {
			head = temp; return;
		}
		MyLinkedList* curr = head;

		while (curr->next != NULL) {
			curr=curr->next;
		}
		curr->next = temp;
		temp->prev = curr;
	}
	void addAtIndex(int index, int val) {
		if (index == 0) {
			addAtHead(val); return;
		}
		MyLinkedList* temp = new MyLinkedList();
		temp->val = val;

		MyLinkedList* curr= head;
        
		for (int i = 0; i < index-1 && curr != NULL; i++) {
			curr = curr->next;
		}
		if (curr == NULL) {
			delete temp;
			return;
		}
		temp->next = curr->next;
		if (curr->next != NULL) {
			curr->next->prev = temp;
		}
		curr->next = temp;
		temp->prev = curr;
	}
	void deleteAtIndex(int index) {
		if (head == NULL) {
			return;
		}
		
		MyLinkedList* curr = head;

		for (int i = 0; i < index - 1 && curr != NULL; i++) {
			curr = curr->next;
		}

		MyLinkedList* temp;
		temp= curr->next;
		curr->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		

		//MyLinkedList* temp;
		//temp = temp->next;
		//curr->next = temp->next;
		//
	 //   curr = temp->next;
		//curr->prev = temp->prev;

		//delete temp;
	}

	void print() {
		if (head == NULL) {
			cout << "No elements found";
		}

		MyLinkedList* curr= head;
		while (curr != NULL) {
			cout << curr->val << " -> ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main() {
	MyLinkedList* obj = new MyLinkedList();

	obj->addAtHead(1);
	obj->addAtHead(2);
	obj->print();

	obj->addAtTail(3);
	obj->print();

	obj->addAtIndex(1, 4);
	obj->print();

	obj->deleteAtIndex(1);
	obj->print();
	
}
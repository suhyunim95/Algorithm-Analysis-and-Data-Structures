#include <iostream>
using namespace std;

class Node {
public:
	int number;
	Node* next;
};

void printer(Node* n) {
	while (n != NULL) {
		cout << n->number << " ";
		n = n->next;
	}
}

void swap(Node* head, int a, int b) {
	Node* pren1 = NULL;
	Node* pren2 = NULL;
	Node* n1 = head;
	Node* n2 = head;

	if (head == NULL || a == b)
		return;

	while (n1 != NULL && n1->number != a) {
		pren1 = n1;
		n1 = n1->next;
	}

	while (n2 != NULL && n2->number != b) {
		pren2 = n2;
		n2 = n2->next;
	}

	if (n1 != NULL && n2 != NULL) {
		if (pren1 != NULL) {
			pren1->next = n2;
		}
		else {
			head = n2;
		}

		if (pren2 != NULL) {
			pren2->next = n1;
		}
		else {
			head = n1;
		}

		Node* temp = n1->next;
		n1->next = n2->next;
		n2->next = temp;
	}
}

Node* selectionSort(Node* input) {
	Node* head = input;
	Node* cur = input;
	while (cur != NULL) {
		Node* temp = cur->next;
		while (temp != NULL) {
			if (cur->number > temp->number) {
				swap(head, cur->number, temp->number);
				Node* save = temp;
				temp = cur;
				cur = save; 
			}
			else {
				temp = temp->next;
			}
			
		}
		cur = cur->next;
	}
	return head;
}



int main() {
	Node* node1 = NULL;
	Node* node2 = NULL;
	Node* node3 = NULL;
	Node* node4 = NULL;
	Node* node5 = NULL;
	Node* node6 = NULL;
	Node* node7 = NULL;
	Node* node8 = NULL;
	Node* node9 = NULL;
	Node* node10 = NULL;
	Node* node11 = NULL;
	Node* node12 = NULL;
	Node* node13 = NULL;
	Node* node14 = NULL;
	Node* node15 = NULL;

	node1 = new Node();
	node2 = new Node();
	node3 = new Node();
	node4 = new Node();
	node5 = new Node();
	node6 = new Node();
	node7 = new Node();
	node8 = new Node();
	node9 = new Node();
	node10 = new Node();
	node11 = new Node();
	node12 = new Node();
	node13 = new Node();
	node14 = new Node();
	node15 = new Node();

	node1->number = 1;
	node1->next = node2;
	node2->number = 4;
	node2->next = node3;
	node3->number = 3;
	node3->next = node4;
	node4->number = 14;
	node4->next = node5;
	node5->number = 9;
	node5->next = node6;
	node6->number = 11;
	node6->next = node7;
	node7->number = 6;
	node7->next = node8;
	node8->number = 5;
	node8->next = node9;
	node9->number = 13;
	node9->next = node10;
	node10->number = 12;
	node10->next = node11;
	node11->number = 8;
	node11->next = node12;
	node12->number = 7;
	node12->next = node13;
	node13->number = 15;
	node13->next = node14;
	node14->number = 10;
	node14->next = node15;
	node15->number = 2;
	node15->next = NULL;


	cout << "before ";
	printer(node1);
	cout << "\n";
	Node* h = selectionSort(node1);
	cout << "\n";
	cout << "after ";
	printer(h);

	return 0;
}
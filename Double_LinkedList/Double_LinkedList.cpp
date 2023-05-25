#include <iostream>
#include <string> 
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* start;
public:

	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void ascending();
	void descending();
	void hapus();
	void searchdata();
};

DoubleLinkedList::DoubleLinkedList() {
	start = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nenter the roll number of student : ";
	cin >> nim;
	cout << "\nEnter the name of the student ; ";
	cin.ignore();
	getline(cin, nm);
	Node* newNode = new Node();
	newNode->noMhs = nim;
	newNode->nama = nm;

	if (start == NULL || nim <= start->noMhs) {
		if (start != NULL && nim == start->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = start;
		if (start != NULL)
			start->prev = newNode;
		newNode->prev = NULL;
		start = newNode;
		return;
	}

	Node* current = start;
	while (current->next != NULL && nim > current->next->noMhs)
		current = current->next;

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL)
		current->next->prev = newNode;
	current->next = newNode;
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = *current = start;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;

	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		start = current->next;

	delete current;
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (start == NULL);
}

void DoubleLinkedList::ascending() {
	if (listEmpty())
		cout << "\nlist empty " << endl;
	else {
		cout << "\nRecords in descending order of roll number one :" << endl;
		Node* currentNode = start;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->nama << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::descending() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nBarcode in descending order of roll number are: " << endl;
		Node* currentNode = start;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;
	}
}

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

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->nama << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty " << endl;

	}
	cout << "\n enter the roll number of student whose record is to be  deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "record not found" << endl;
	else
		cout << "record with roll number " << rollNo << "deleted" << endl;

}
void DoubleLinkedList::searchdata() {
	if (listEmpty() == true) {
		cout << "\nlist is empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nenter the roll number of the student whose record you want to search : ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nrecord not found" << endl;
	else {
		cout << "\nrecord found" << endl;
		cout << "\nroll number :" << curr->noMhs << endl;
		cout << "\nnama: " << curr->nama << endl;
		
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nmenu" << endl;
			cout << "1.add a record to the list" << endl;
			cout << "2.delete a reecord form the list" << endl;
			cout << "3.view all records" << endl;
			cout << "4.view all records in the descending order of roll numbers" << endl;
			cout << "5.search for a record in the list" << endl;
			cout << "6.exit" << endl;
			cout << "\nenter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
					obj.addNode();
					break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.ascending();
				break;
			case '4':
				obj.descending();
				break;
			case '5':
				obj.searchdata();
				break;
			case '6':
				return 0;
			default:
				cout << "\ninvalid option" << endl;
				break;
			}
		}
		catch (exception& e){
			cout << "check for the values entered." << endl;

		}
	}
}

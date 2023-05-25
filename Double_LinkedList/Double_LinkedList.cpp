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

}


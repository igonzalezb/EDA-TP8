#pragma once


template <typename Type>
class Node {

public:

	Type element; // Data del nodo

	Node * next; // Puntero al nodo siguiente
	Node * prev; // Puntero al nodo anterior

	Node(const Type& element, Node * prev, Node * next);

	Node(Node * prev = NULL, Node * next = NULL);

};



template<typename Type> class List
{
private:

	Node<Type>* firstNode;
	Node<Type>* currentNode;
	Node<Type>* lastNode;

	int listSize;

public:
	List();
	~List();
	int getListSize();
	void addElement(Type data);
	void removeElement(int pos);
	Type getElement(int pos);
	bool moveToPos(int pos);

};




template<typename Type>
inline Node<Type>::Node(const Type & element, Node * prev, Node * next)
{
	this->element = element;
	this->prev = prev;
	this->next = next;

}

template<typename Type>
inline Node<Type>::Node(Node * prev, Node * next)
{
	this->prev = prev;
	this->next = next;
}


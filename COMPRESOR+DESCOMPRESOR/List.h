#pragma once


template <typename Type> class Node {

public:

	Node() { ; }

	Type element; // Data del nodo

	Node * next; // Puntero al nodo siguiente
	Node * prev; // Puntero al nodo anterior

	Node(const Type& element, Node * prev, Node * next)
	{
		this->element = element;
		this->prev = prev;
		this->next = next;
	}

	Node(Node * prev = NULL, Node * next = NULL)
	{
		this->prev = prev;
		this->next = next;
	}
	
};

template<typename Type> class List
{
private:

	Node<Type>* firstNode;
	Node<Type>* currentNode;
	Node<Type>* lastNode;

	int listSize;

public:
	List()
	{
		currentNode = firstNode = new Node<Type>(NULL, NULL);
		lastNode = new Node<Type>(firstNode);
		firstNode->next = lastNode;

		listSize = 0;
	}


	~List()
	{
		while (firstNode == lastNode)
		{
			currentNode = firstNode;
			delete currentNode;
			firstNode = firstNode->next;
		}
	}


	int getListSize()
	{
		return listSize;
	}


	void addElement(Type element)
	{
		lastNode->prev = lastNode->prev->next = new Node<Type>(element, lastNode->prev, NULL);
		listSize++;
	}


	void removeElement(int pos)
	{
		if (moveToPos(pos) == true)
		{

			currentNode->prev->next = currentNode->next;
			currentNode->next->prev = currentNode->prev;

			listSize--;
		}
	}


	Type getElement(int pos)
	{
		if (moveToPos(pos) == true)
		{
			Type elemento = currentNode->next->element;

			return elemento;
		}

		return NULL;
	}


	bool moveToPos(int pos)
	{
		if ((pos < 0) || (pos > listSize))
		{
			printf("El elemento que se quiere acceder no existe en la lista");
			return false;
		}

		currentNode = firstNode;

		for (int i = 0; i < pos; i++)
		{
			currentNode = currentNode->next;
		}

		return true;
	}

};





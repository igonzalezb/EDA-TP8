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
		
		for (int i = 0; i < listSize; i++)
		{
			removeElement(i);
		}
		
		delete firstNode;
		delete lastNode;
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
		if (pos == 0)
		{
			firstNode = firstNode->next;
			delete firstNode->prev;
			firstNode->prev = NULL;
			listSize--;
		}

		else if (pos == (listSize-1)) {

			lastNode = lastNode->prev;
			delete lastNode->next;
			lastNode->next = NULL;
			listSize--;
		}

		else if (moveToPos(pos) == true)
		{
			Node<Type>* ToRemove = currentNode;// currentNode->next;

			//currentNode->next = currentNode->next->next;
			currentNode->prev->next = currentNode->next;

			//currentNode->next->next->prev = currentNode;
			currentNode->next->prev = currentNode->prev;
			
			delete ToRemove;
			listSize--;
		}

		
	}


	Type& getElement(int pos)
	{
		if (moveToPos(pos) == true)
		{
			return currentNode->element;//currentNode->next->element;
		}
	}


	bool moveToPos(int pos)
	{
		if ((pos < 0) || (pos >= listSize))	//cambie poslistSize
		{
			printf("El elemento que se quiere acceder no existe en la lista\n");
			return false;
		}
		
		currentNode = firstNode->next;//cambie firstNode

		for (int i = 0; i < pos; i++)
		{
			currentNode = currentNode->next;
		}

		return true;
	}

};





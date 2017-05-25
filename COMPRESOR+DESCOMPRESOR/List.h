#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////
//		NODE
//	Objeto para la lista
////////////////////////////////////////////////////////////////////////////////////////////
template <typename Type> class Node {

public:
	//Contructor de Node
	Node() { ; }

	Type element; // Data del nodo

	Node * next; // Puntero al nodo siguiente
	Node * prev; // Puntero al nodo anterior

	Node(const Type& element, Node * prev, Node * next)
	{
		this->element = element;
		this->prev = prev;	//punteros al elemento anterior y siguente
		this->next = next;
	}


	Node(Node * prev = NULL, Node * next = NULL)
	{
		this->prev = prev;
		this->next = next;
	}
	
};


/////////////////////////////////////////////////////////////////////////////////////////////
//		LIST
//	Lista doblemente enlazada
////////////////////////////////////////////////////////////////////////////////////////////
template<typename Type> class List
{
private:

	Node<Type>* firstNode; 
	Node<Type>* currentNode;
	Node<Type>* lastNode;

	int listSize;

public:
	//Contructor de la lista
	List()
	{
		currentNode = firstNode = new Node<Type>(NULL, NULL);
		lastNode = new Node<Type>(firstNode);
		firstNode->next = lastNode;

		listSize = 0;
	}

	//Destructor de la lista
	~List()
	{
		
		for (int i = 0; i < listSize; i++)
		{
			removeElement(i);
		}
		
		delete firstNode;
		delete lastNode;
	}

	//Devuelve el tamano de la lista
	int getListSize()
	{
		return listSize;
	}

	//Agrega un elemento a la ultima posicion de la lista
	void addElement(Type element)
	{
		lastNode->prev = lastNode->prev->next = new Node<Type>(element, lastNode->prev, NULL);
		listSize++;
	}

	//Elimina un elemento de la lista recibiendo la posicion que se desea eliminar
	//tiene en cuenta los casos en que la posicion es 0 o la ultima en la lista
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
			Node<Type>* ToRemove = currentNode;
			currentNode->prev->next = currentNode->next;
			currentNode->next->prev = currentNode->prev;
			delete ToRemove;
			listSize--;
		}

		
	}

	//Se mueve hasta la posicion que le llega y a la cual se desea acceder y devuelve la data del elemento
	Type& getElement(int pos)
	{
		if (moveToPos(pos) == true)
		{
			return currentNode->element;
		}
	}

	//Se mueve hasta la posicion que le llega chequeando que la posicion a la que se desea acceder exista en la lista
	bool moveToPos(int pos)
	{
		if ((pos < 0) || (pos >= listSize))
		{
			printf("El elemento que se quiere acceder no existe en la lista\n");
			return false;
		}
		
		currentNode = firstNode->next;

		for (int i = 0; i < pos; i++)
		{
			currentNode = currentNode->next;
		}

		return true;
	}

};





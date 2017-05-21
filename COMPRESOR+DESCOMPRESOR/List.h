#pragma once

/*
//posicion
0 |
| A |
1 |
| B |
2 |
| C |
3 |
*/

//doblemente enlazada
template<typename Type> class List //ADAPTAR A LO QUE NECESITAMOS
{
private:
	template<typename Type> struct nodo
	{
		Type data; 
		nodo* next_node; /
	}
	nodo<Type>* firstNode; //NULL
	nodo<Type>* lastNode; //NULL
	unsigned long size; //0

public:
	List();
	~List();
	void clear();
	void 
	void addElement(Type e, unsigned long pos);
	void removeElement(unsigned long pos);
	Type getElement(unsigned long pos);
}
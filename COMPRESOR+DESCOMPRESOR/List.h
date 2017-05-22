#pragma once

template<typename Type> class List //ADAPTAR A LO QUE NECESITAMOS
{
private:

	template<typename Type>
	struct nodo
	{
		nodo* next_node; //linita
		nodo* previous_node;
		Type data;		//cajita 
	}
	nodo<Type> firstNode;
	nodo<Type> lastNode;
	unsigned long size;
public:
	List();
	void addElement(Type e, unsigned long pos);
	Type removeElement(unsigned long pos);
	Type getElement(unsigned long pos);




	//posicion
	/*
	0 |
		| A |
		1 |
		| B |
		2 |
		| C |
		3 |
		*/


};
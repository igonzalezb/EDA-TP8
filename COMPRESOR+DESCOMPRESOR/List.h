#pragma once

template<typename Type> class List //ADAPTAR A LO QUE NECESITAMOS
{
private:

	template<typename Type>
	struct nodo
	{
		nodo* next_node; //linita
		Type data;		//cajita 
	}
	nodo<Type> firstNode;
	nodo<Type> lastNode;
	unsigned long size;
public:
	void addElement(Type e, ulong pos);
	Type removeElement(ulong pos);
	Type getElement(ulong pos);

	//posicion
	0 |
		| A |
		1 |
		| B |
		2 |
		| C |
		3 |


};
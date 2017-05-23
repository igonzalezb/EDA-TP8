//#include "List.h"
//
////template <typename Type>
////List<Type>::List()
////{
////
////	currentNode = firstNode = new Node<Type>(NULL, NULL);
////	lastNode = new Node<Type>(firstNode);
////	firstNode->next = lastNode;
////
////	listSize = 0;
////
////}
////
////
////
////template<typename Type>
////List<Type>::~List()
////{
////	while (firstNode == lastNode)
////	{
////		currentNode = firstNode;
////		delete currentNode;
////		firstNode = firstNode->next;
////	}
////}
//
//
//
//template<typename Type>
//int List<Type>::getListSize()
//{
//	return listSize;
//}
//
//
//
//template<typename Type>
//void List<Type>::addElement(Type element)
//{
//	lastNode->prev = lastNode->prev->next = new Node<Type>(element, lastNode->prev, NULL);
//	listSize++;
//}
//
//
//
//template<typename Type>
//void List<Type>::removeElement(int pos)
//{
//	if (moveToPos(pos) == true)
//	{
//
//		currentNode->prev->next = currentNode->next;
//		currentNode->next->prev = currentNode->prev;
//
//		listSize--;
//	}
//}
//
//
//
//template<typename Type>
//Type List<Type>::getElement(int pos)
//{
//	if (moveToPos(pos) == true)
//	{
//		Type elemento = currentNode->next->element;
//
//		return elemento;
//	}
//
//	return NULL;
//}
//
//
//
//template<typename Type>
//bool List<Type>::moveToPos(int pos)
//{
//	if ((pos < 0) || (pos > listSize))
//	{
//		printf("El elemento que se quiere acceder no existe en la lista");
//		return false;
//	}
//
//	currentNode = firstNode;
//
//	for (int i = 0; i < pos; i++)
//	{
//		currentNode = currentNode->next;
//	}
//
//	return true;
//}
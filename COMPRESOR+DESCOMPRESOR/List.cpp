

template <typename Type>
void EDAlist<type>::addElement(type e, ulong pos)
{
	if (pos <= size)
	{
		if (firstNode == NULL)
		{
			node<type>* tempNode = new Node;
			tempNode.data = e;
			tempNode.nextNode = NULL;
			firstNode = tempNode;
			lastNode = tempNode;
		}
		else
		{
			if (pos > 0)
			{
				nodo<type>* tempNode = lastNode;
				for (int i = 1; i < pos; i++)
					tempNode = tempNode->next;
				node<type>* tempNode = new node;
				tempNode->nextNode = currentNode->next;
				currentNode->nextNode = tempnode;
				tempNode->data = e;
				if (pos == size)
					lastNode = tempNode;
			}
			else
			{

			}

		}
		size++;
	}

}
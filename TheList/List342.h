#ifndef LIST342_H
#define LIST342_H

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Bird.h"
#include "Child.h"

using namespace std;





template <class T>
class List342
{

	 friend ostream& operator<< <>(ostream &out, const List342<T> &source);
private:
	struct Node
	{
		T *data;
		Node *next = NULL;
	};

	Node *head;
public:
	 List342();
	 List342(const List342<T> &source);
	 ~List342();

	bool  BuildList(const string &fileName);

	bool  Insert(T *obj);
	bool  Remove(T target, T &result);
	bool  Peek(T target, T &result);
	bool  isEmpty();
	void  DeleteList();
	bool  Merge(List342<T> &source);

	void  SortList();
	void  RemoveDuplicates();

	List342<T>&  operator+=(const List342<T> &source);
	List342<T>  operator+(const List342<T> &source) const;
	List342<T>&  operator=(const List342<T> &source);

	bool  operator==(const List342<T> &source) const;
	bool  operator!=(const List342<T> &source) const;

};





template <class T>
List342<T>::List342()
{
	head = NULL;
}

template <class T>
List342<T>::List342(const List342 &source)
{
	head = NULL;
	*this = source;
}

template <class T>
List342<T>::~List342()
{
	DeleteList();
}

template <class T>
bool List342<T>::BuildList(const string &fileName)
{
	ifstream inputFile(fileName.c_str());

	if (!inputFile.good())
	{
		cerr << "error reading the file";
		return false;
	}

	while (!inputFile.eof())
	{
		T input;
		inputFile >> input;
		T *ptr = &input;
		Insert(ptr);

	}
	inputFile.close();
	return true;
	
	/*ifstream inf(fileName.c_str());

	if (!inf.good())
	{
		cerr << "error reading the file";
		return false;
	}
	
	while (!inf.eof())
	{
		T *ptr = new T;
		T input;
		inf >> input;
		*ptr = input;
		Insert(ptr);
		
	}
	inf.close();
	return true;*/
}

template <class T>
bool List342<T>::Insert(T *obj)
{
	Node *insNode;
	T *insData;
	
	if (isEmpty() || *obj < *head->data) 
	{
		insNode = new Node;
		insData = new T;
		*insData = *obj;
		insNode->data = insData;

		insNode->next = head;
		head = insNode;
	}

	else if (*obj == *head->data)
	{
		return false;
	}

	else
	{
		Node* current = head->next;
		Node* previous = head;

		while (current != NULL && *current->data <= *obj) 
		{
			if (*current->data == *obj)
			{
				return false;
			}

			previous = current;
			current = current->next;
		}

		insNode = new Node;
		insData = new T;
		*insData = *obj;
		insNode->data = insData;

		insNode->next = current;
		previous->next = insNode;
	}
	return true;
	
	/*Node* insNode = new Node;
			              
	insNode->data = obj;     	

	if (isEmpty() || *insNode->data < *head->data) {
		insNode->next = head;
		head = insNode;
	}

	else if (*insNode->data == *head->data)
	{
		delete insNode;
		return false;
	}

	else 
	{
		Node* current = head->next;         
		Node* previous = head;
		
		while (current != NULL && *current->data <= *insNode->data) {
			
			if (*current->data == *insNode->data)
			{
				delete insNode;
				return false;
			}
			
			previous = current;                  
			current = current->next;
		}

		insNode->next = current;
		previous->next = insNode;
	}
	return true;	*/
}

template <class T>
bool List342<T>::Remove(T target, T &result)
{
	Node *temp, *ptr;

	if (head == NULL)
		return false;
		
	if (*head->data == target)
	{
		result = *head->data;
		temp = head;
		head = head->next;
		
		delete temp->data;
		delete temp;
		
		return true;
	}

	ptr = head;

	while (ptr->next != NULL && *ptr->next->data != target)
	{
		ptr = ptr->next;
	}

	if (ptr->next == NULL)
		return false;

	else
	{
		temp = ptr->next;
		ptr->next = ptr->next->next;
		
		delete temp->data;
		delete temp;
		
		return true;
	}
	
	//Node *removeNode;

	//if (*head->data == target)
	//{
	//	result = *head->data;
	//	removeNode = head;
	//	head = head->next;
	//	delete removeNode;
	//	return true;
	//}
	//
	//while (temp->next != NULL)
	//{
	//	if (*temp->next->data == target)
	//	{
	//		result = *temp->next->data;
	//		removeNode = temp->next;
	//		temp->next = removeNode->next;
	//		delete removeNode->data;
	//		delete removeNode;
	//		removeNode = NULL;
	//		return true;
	//	}
	//	else
	//	{
	//		temp = temp->next;
	//	}
	//}

	//return false; //target not found	
}

template <class T>
bool List342<T>::Peek(T target, T &result)
{
	
	
	if (isEmpty())
	{
		return false;
	}
	
	Node *current = head;

	while (current != NULL)
	{
		if (*current->data == target)
		{
			result = *current->data;
			return true;
		}
		
		current = current->next;
	}
	
	return false; //target not found
}

template <class T>
bool List342<T>::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

template <class T>
void List342<T>::DeleteList()
{
	if (head == NULL)
		return;

	if (head->next == NULL)
	{
		delete head->data;
		delete head;
		
		head = NULL;
		return;
	}

	Node *delNode;
	Node *ptr = head;

	while (ptr->next != NULL)
	{
		delNode = ptr;
		ptr = ptr->next;
		
		delete delNode->data;
		delete delNode;
	}	
}

template <class T>
bool List342<T>::Merge(List342<T> &source)
{
	Node *dNode, *sNode, *temp;
	dNode = head;
	sNode = source.head;
		
	if (head == NULL)
	{
		head = source.head;
		source.head = NULL;
		return true;
	}

	if (*head->data > *source.head->data)
	{
		sNode = sNode->next;
		source.head->next = head;
		head = source.head;		
	}	
	
	while (dNode->next != NULL)
	{
		if (sNode == NULL)
		{
			return true;
		}			
		
		else if (*sNode->data == *dNode->data)
		{
			temp = sNode;
			sNode = sNode->next;
			delete temp;
		}

		else if (*dNode->next->data > *sNode->data)
		{
			temp = sNode;
			sNode = sNode->next;
			temp->next = dNode->next;
			dNode->next = temp;			
		}

		dNode = dNode->next;
	}

	if (dNode->next == NULL)
	{
		dNode->next = sNode;
	}	
	
	source.head = NULL;

	return true;
}

template <class T>
List342<T>& List342<T>::operator=(const List342<T> &source)
{
	if (this == &source)
		return *this;

	if (source.head == NULL)
		return *this;

	DeleteList();

	Node *sNode, *dNode, *insNode;
	T *dataPtr;

	dNode = new Node;
	dataPtr = new T;

	*dataPtr = *source.head->data;
	
	dNode->data = dataPtr;
	head = dNode;

	sNode = source.head->next;

	while (sNode != NULL)
	{
		insNode = new Node;
		dataPtr = new T;
		
		*dataPtr = *sNode->data;
		insNode->data = dataPtr;
		dNode->next = insNode;
		sNode = sNode->next;
		dNode = dNode->next;
	}

	return *this;
}

template <class T>
List342<T>& List342<T>::operator+=(const List342<T> &source)
{
	/*if (source.head == NULL)
		return *this;
	
	if (head == NULL)
	{
		*this = source;
		return *this;
	}

	Node *current = source.head;
	T *ptr;

	while (current != NULL)
	{
		ptr = new T;
		*ptr = *current->data;
		Insert(ptr);
		current = current->next;
	}*/

	Node *dNode, *sNode, *temp;
	dNode = head;
	sNode = source.head;

	T *tempData;

	if (source.head == NULL)
		return *this;

	if (head == NULL)
	{
		*this = source;
		return *this;
	}
	
	if (*head->data > *source.head->data)
	{
		temp = new Node;
		tempData = new T;

		*tempData = *source.head->data;
		temp->data = tempData;

		temp->next = head;
		head = temp;

		sNode = sNode->next;
	}

	while (dNode->next != NULL)
	{
		if (sNode == NULL)
		{
			return *this;
		}

		else if (*sNode->data == *dNode->data)
		{
			sNode = sNode->next;			
		}

		else if (*dNode->next->data > *sNode->data)
		{
			temp = new Node;
			tempData = new T;

			*tempData = *sNode->data;
			temp->data = tempData;
			
			temp->next = dNode->next;
			dNode->next = temp;
			
			sNode = sNode->next;
			dNode = dNode->next; 			
		}

		dNode = dNode->next;
	}
	
	while (sNode != NULL)
	{
		temp = new Node;
		tempData = new T;

		*tempData = *sNode->data;
		temp->data = tempData;

		dNode->next = temp;

		sNode = sNode->next;
		dNode = dNode->next;
	}

	return *this;
}

template <class T>
List342<T> List342<T>::operator+(const List342<T> &source) const
{
	List342<T> result = *this;
	result += source;

	return result;
}

template <class T>
bool List342<T>::operator==(const List342<T> &source) const
{
	if (head == NULL && source.head == NULL)
		return true;
	else if (head == NULL && source.head != NULL)
		return false;
	else if (head != NULL && source.head == NULL)
		return false;

	Node *leftHead;
	Node *rightHead;

	leftHead = head;
	rightHead = source.head;

	while (leftHead != NULL && rightHead != NULL)
	{
		if (*leftHead->data != *rightHead->data)
		{
			return false;
		}

		leftHead = leftHead->next;
		rightHead = rightHead->next;
	}

	return true;
}

template <class T>
bool List342<T>::operator!=(const List342<T> &source) const
{
	if (*this == source)
		return false;
	else
		return true;
}

template <class T>
ostream& operator<< <>(ostream &out, const List342<T> &source)
{

	if (source.head == NULL)
	{
		out << "the list is empty";
		return out;
	}
	else
	{
		List342<T>::Node *printNode = source.head;
		while (printNode != NULL)
		{
			out << *(printNode->data);
			printNode = printNode->next;
		}
		return out;
	}
}

#endif // LIST342_H
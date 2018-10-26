#include "LinkedString.h"

LinkedString::LinkedString()
{
	strHead = nullptr;
	strTail = nullptr;
	length = 0;
}

LinkedString::LinkedString(const string & obj)
{
	node* temp;
	temp = new node;
	temp->ch = obj[0];
	temp->next = nullptr;
	length++;
	strHead = strTail = temp;

	int len = obj.length();

	for (int i = 1;i < len;i++)
	{
		node*temp2 = strTail;
		node*temp = new node;
		temp->ch = obj[i];
		temp->next = nullptr;
		temp2->next = temp;
		strTail = temp;
		length++;
	}
}

LinkedString::LinkedString(const LinkedString & obj)
{
	node*temp2 = obj.strHead;

	node* temp = new node;
	temp->ch = temp2->ch;
	temp->next = nullptr;
	temp2 = temp2->next;
	strHead = strTail = temp;
	length++;
	node* temp3;
	node* temp4;
	while (temp2 != nullptr)
	{
		temp3 = new node;
		temp3->ch = temp2->ch;
		temp3->next = nullptr;
		temp2 = temp2->next;

		temp4 = strTail;
		temp4->next = temp3;
		strTail = temp3;
		length++;
	}
}

const LinkedString & LinkedString::operator=(const LinkedString & obj)
{
	if (strHead != nullptr)		//Delete if it already contains string.
	{
		node *temp = strHead;
		node *ptr;
		node* next;
		while (temp != nullptr)
		{
			ptr = temp;
			next = temp->next;
			temp = temp->next;
			delete ptr;
			length--;
		}
	}

	node*temp2 = obj.strHead;

	node* temp = new node;
	temp->ch = temp2->ch;
	temp->next = nullptr;
	temp2 = temp2->next;
	strHead = strTail = temp;
	length++;
	node* temp3;
	node* temp4;
	while (temp2 != nullptr)
	{
		temp3 = new node;
		temp3->ch = temp2->ch;
		temp3->next = nullptr;
		temp2 = temp2->next;

		temp4 = strTail;
		temp4->next = temp3;
		strTail = temp3;
		length++;
	}
	return *this;
}

LinkedString LinkedString::operator+(const LinkedString & obj)
{
	LinkedString newList = *this;
	node *temp = newList.strTail;

	node *temp2 = obj.strHead;
	node *temp3;
	while (temp2 != nullptr)
	{
		temp3 = new node;
		temp3->ch = temp2->ch;
		temp3->next = nullptr;

		temp = newList.strTail;
		temp->next = temp3;
		newList.strTail = temp3;
		temp2 = temp2->next;
		newList.length++;
	}
	return newList;
}

bool LinkedString::find(const LinkedString & obj)		//Linked List finder in another linked list.
{
	node *temp = obj.strHead;

	node *temp2 = strHead;

	while (temp2 != nullptr)
	{
		if (temp2->ch == temp->ch)
		{
			int c = 0;
			node *temp3 = temp2;
			node *temp4 = temp;
			while (temp4 != nullptr && temp3 != nullptr)
			{
				if (temp3->ch == temp4->ch)
				{
					temp3 = temp3->next;
					temp4 = temp4->next;
					c++;
				}
				else
				{
					break;
				}
			}
			if (c == obj.length)
			{
				return true;
			}
		}
		temp2 = temp2->next;
	}
	return false;
}

bool LinkedString::find(const string & obj)
{
	int len = obj.length();
	if (len > getLength()) {
		return false;
	}
	int c = 0;
	int count = 0;
	node *temp = strHead;
	node *temp2;
	while (temp != nullptr)
	{
		c = 0;
		if (temp->ch == obj[0])
		{
			temp2 = temp;
			while (c < len)
			{
				if (temp2->ch == obj[c])
				{
					count++;
					temp2 = temp2->next;
				}
				else {
					break;
				}
				c++;
			}

			if (count == len) {
				return true;
			}
		}
		temp = temp->next;
		count = 0;
	}
	return false;
}

LinkedString LinkedString::findAndCopy(const string & obj)
{
	bool con = find(obj);
	if (con == true) {			//If the string is present in obj.
		LinkedString copiedList(obj);
		return copiedList;
	}
}

LinkedString LinkedString::findAndCut(const string & obj)
{
	int len = obj.length();

	int c = 0;
	int count = 0;
	node *temp = strHead;
	node *temp2;
	node *temp3 = temp;
	while (temp != nullptr)
	{
		c = 0;
		if (temp->ch == obj[0])
		{
			temp2 = temp;
			while (c < len)
			{
				if (temp2->ch == obj[c])
				{
					count++;
					temp2 = temp2->next;
				}
				else {
					break;
				}
				c++;
			}

			if (count == len) {
				node *temp4 = temp;
				node *temp5 = 0;
				node *temp6 = 0;

				while (temp4 != temp2)
				{
					temp5 = temp4->next;
					delete temp4;
					temp4 = temp5;
					length--;
				}
				temp6 = temp5;
				temp3->next = temp5;

				if (length == 0) {
					strHead = strTail = nullptr;
				}
				if (temp == strHead)
				{
					strHead = temp6;
				}
				if (temp2 == nullptr) {
					strTail = temp3;
				}
				LinkedString newList(obj);
				return newList;
			}
		}
		temp3 = temp;
		temp = temp->next;
		count = 0;
	}
}

void LinkedString::FindAndReplace(const string & obj, const string & rep)
{
	int len = obj.length();

	int c = 0;
	int count = 0;
	node *temp = strHead;
	node *temp2;
	node *temp3 = temp;
	while (temp != nullptr)
	{
		c = 0;
		//Find
		if (temp->ch == obj[0])
		{
			temp2 = temp;
			while (c < len)
			{
				if (temp2->ch == obj[c])
				{
					count++;
					temp2 = temp2->next;
				}
				else {
					break;
				}
				c++;
			}

			if (count == len) {
				node *temp4 = temp;
				node *temp5 = 0;
				while (temp4 != temp2)
				{
					temp5 = temp4->next;
					delete temp4;
					temp4 = temp5;
					length--;
				}
				//Replace.
				node *temp7 = new node;
				temp7->ch = rep[0];
				temp7->next = 0;
				temp3->next = temp7;
				node *temp9 = temp7;
				length++;

				for (int i = 1;i < rep.length();i++) {
					node* temp8 = new node;
					temp8->ch = rep[i];
					temp8->next = 0;
					temp9->next = temp8;
					temp9 = temp8;
					length++;
				}
				temp9->next = temp2;

				if (temp == strHead)
				{
					strHead = temp7;
				}
				if (temp2 == nullptr) {
					strTail = temp9;
				}
				return;
			}
		}
		temp3 = temp;
		temp = temp->next;
		count = 0;
	}
}

void LinkedString::FindAndInsertAfter(const string & obj, const string & obj2)
{
	int len = obj.length();
	int c = 0;
	int count = 0;
	node *temp = strHead;
	node *temp2 = temp;
	node*temp3 = 0;
	while (temp != nullptr)
	{
		c = 0;
		if (temp->ch == obj[0])
		{
			temp2 = temp;
			while (c < len)
			{
				if (temp2->ch == obj[c])
				{
					count++;
					temp3 = temp2;
					temp2 = temp2->next;
				}
				else {
					break;
				}
				c++;
			}

			if (count == len) {
				node*ptr2 = temp3;

				int cnt = 0;
				while (cnt < obj2.length()) {
					node*newptr = new node;
					newptr->ch = obj2[cnt];
					newptr->next = ptr2->next;
					ptr2->next = newptr;
					ptr2 = ptr2->next;
					cnt++;
					length++;
				}
				return;
			}
		}
		temp = temp->next;
		count = 0;
	}
}

void LinkedString::findAndInvert(const string & obj)
{
	int len = obj.length();
	int c = 0;
	int count = 0;
	node *temp = strHead;
	node *temp2;
	int check = 0;
	node*temp3 = 0;;
	while (temp != nullptr)
	{
		c = 0;
		if (temp->ch == obj[0])
		{
			temp2 = temp;
			while (c < len)
			{
				if (temp2->ch == obj[c])
				{
					count++;
					temp2 = temp2->next;
				}
				else {
					break;
				}
				c++;
			}

			if (count == len) {
				node *ptr2 = temp;

				check = 0;
				while (check < count) {
					ptr2->ch = obj[len - check - 1];
					ptr2 = ptr2->next;
					check++;
				}
				break;
			}
		}
		temp3 = temp;
		temp = temp->next;
		count = 0;
	}
}

void LinkedString::Reverse()
{
	node *temp = strHead;
	node *temp2 = temp->next;
	node *temp3 = temp2->next;
	temp->next = nullptr;
	while (temp3 != nullptr)
	{
		temp3 = temp2->next;
		temp2->next = temp;
		temp = temp2;
		temp2 = temp3;
	}
	strHead = strTail;
}

LinkedString::~LinkedString()		//Destructor.
{
	node *temp = strHead;
	node *ptr;
	node* next;
	while (temp != nullptr)
	{
		ptr = temp;
		next = temp->next;
		temp = temp->next;
		delete ptr;
		length--;
	}
}

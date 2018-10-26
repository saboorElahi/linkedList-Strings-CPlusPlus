#pragma once
#ifndef LinkedString_H
#define LinkedString_H

#include<iostream>
#include<string>
using namespace std;

class LinkedString
{
	struct node			//In private part
	{
		char ch;
		node * next;
	};
	node *strHead, *strTail;
	int length;

public:			//Functions in public part
	LinkedString();
	LinkedString(const string&);
	LinkedString(const LinkedString&);
	const LinkedString & operator=(const LinkedString&);
	LinkedString operator+ (const LinkedString&);
	bool find(const LinkedString&);
	bool find(const string&);
	LinkedString findAndCopy(const string&);
	LinkedString findAndCut(const string&);	//problem here
	void FindAndReplace(const string&, const string&);
	void FindAndInsertAfter(const string&, const string&);
	void findAndInvert(const string&);
	void Reverse();
	~LinkedString();
	friend ostream & operator << (ostream& out, const LinkedString& obj)
	{
		int c = 0;
		node *temp = obj.strHead;
		while (temp != nullptr)
		{
			out << temp->ch;
			temp = temp->next;
		}
		return out;
	}
	friend istream & operator >> (istream& in, LinkedString& obj2)
	{

		node *str = obj2.strTail;
		string obj;

		getline(in, obj);
		getline(in, obj);

		node* temp;
		temp = new node;
		temp->ch = obj[0];
		temp->next = nullptr;
		obj2.length++;
		str->next = temp;
		obj2.strTail = temp;
		if (obj2.strHead == 0) {
			obj2.strHead = temp;
		}
		int len = obj.length();

		for (int i = 1;i < len;i++)
		{
			node*temp2 = obj2.strTail;
			node*temp = new node;
			temp->ch = obj[i];
			temp->next = nullptr;
			temp2->next = temp;
			obj2.strTail = temp;
			obj2.length++;
		}

		return in;
	}
	int getLength()
	{
		return length;
	}
};

#endif

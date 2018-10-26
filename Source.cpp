#include"LinkedString.h"
#include<iostream>
#include<string>

using namespace std;

void printMenu()
{
	cout << "\n\n ----------------------------------------------------------------------\n";
	cout << " 0) Press 0 to Exit.\n";
	cout << " 1) Press 1 to copy data of Str1 into Str2.\n";
	cout << " 2) Press 2 to input data into Linked List.\n";
	cout << " 3) Press 3 to output data of Linked List.\n";
	cout << " 4) Press 4 to check Length of Linked List.\n";
	cout << " 5) Press 5 to Concatenate Str1 and Str2.\n";
	cout << " 6) Press 6 to check if Linked List Str2 is found in Str1.\n";
	cout << " 7) Press 7 to check a string in Linked List Str1.\n";
	cout << " 8) Press 8 to find And Copy string of Str1 in Str2.\n";
	cout << " 9) Press 9 to find And Cut string of Str1 in Str2.";
	cout << "\n ------------------------------------\n";
	cout << " 10) Press 10 to find And Replace string of Str1.\n";
	cout << " 11) Press 11 to find And Insert after a string in Str1.\n";
	cout << " 12) Press 12 to find And Invert a string of Str1.\n";
	cout << " 13) Press 13 to Reverse the string of Str1.\n";
	cout << " 14) Press 14 to Clear the Screen.\n";
	cout << " ----------------------------------------------------------------------\n\n ";
}

void main()
{
	int option2;
	int option = -1;
	string temp1, temp2;
	string s, s1;
	cout << "\n Enter string for Linked List Str1\t";
	getline(cin, temp1);
	cout << "\n Enter string for Linked List Str2\t";
	getline(cin, temp2);

	LinkedString str1(temp1), str2(temp2);
	cout << "\n Str1 contains : " << str1;
	cout << "\n Str2 contains : " << str2;

	while (option != 0)			
	{
		printMenu();		//Menu prints again and again until user wants to exit.
		cout << "\n What do you want to do ?\t";
		cin >> option;
		if (option == 0)
		{
			break;			//Program finishes.
		}
		else if (option == 1)
		{
			if (str1.getLength() > 0) {
				str2 = str1;
			}
			else {
				cout << "\n There is nothing present in str1\n";
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 2)
		{
			int option2;
			cout << "\n\n For which linked list do you want to input data\n\n 1) Str1\t 2) Str2\t";
			cin >> option2;
			if (option2 == 1) {
				cout << "\n Enter String\t";
				cin >> str1;
			}
			else if (option2 == 2) {
				cout << "\n Enter String\t";
				cin >> str2;
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 3) {
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 4) {
			cout << "\n Length of Str1 is : " << str1.getLength();
			cout << "\n Length of Str2 is : " << str2.getLength();
		}
		else if (option == 5) {
			if (str1.getLength() > 0) {
				str1 = str1 + str2;
			}
			else {
				str1 = str2;
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 6) {
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
			if (str1.find(str2) == true)
			{
				cout << "\n Str2 is present in Str1\n";
			}
			else {
				cout << "\n Str2 is not present in Str1\n";
			}
		}
		else if (option == 7) {
			cout << "\n What string do you want to find ? \t";
			getline(cin, s);
			getline(cin, s);

			cout << "\n\n In which linked list do you want to find the string\n\n 1) Str1\t 2) Str2\t";
			cin >> option2;
			if (option2 == 1) {
				cout << "\n Str1 contains : " << str1;
				if (str1.find(s) == true) {
					cout << "\n String Found\n";
				}
				else {
					cout << "\n String not found\n";
				}
			}
			else if (option2 == 2) {
				cout << "\n Str2 contains : " << str2;
				if (str2.find(s) == true) {
					cout << "\n String Found\n";
				}
				else {
					cout << "\n String not found\n";
				}
			}
		}
		else if (option == 8) {
			cout << "\n What string do you find and copy ? \t";
			getline(cin, s);
			getline(cin, s);

			if (str1.find(s)) {
				str2 = str1.findAndCopy(s);
			}
			else {
				cout << "\n String you entered is not present in str1.\n";
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 9) {
			cout << "\n What string do you find and cut ? \t";
			getline(cin, s);
			getline(cin, s);
			if (str1.find(s)) {
				str2 = str1.findAndCut(s);
			}
			else {
				cout << "\n String you entered is not present in str1.\n";
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 10) {
			cout << "\n What string do you want to find and replace ? \t";
			getline(cin, s);
			getline(cin, s);

			cout << "\n From What string do you want to replace ? \t";
			getline(cin, s1);

			if (str1.find(s)) {
				str1.FindAndReplace(s, s1);
			}
			else {
				cout << "\n String you entered is not present in str1.\n";
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 11) {
			cout << "\n After what string do you want to Insert ? \t";
			getline(cin, s);
			getline(cin, s);

			cout << "\n What string do you want to Insert ? \t";
			getline(cin, s1);

			if (str1.find(s)) {
				str1.FindAndInsertAfter(s, s1);
			}
			else {
				cout << "\n String you entered is not present in str1.\n";
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 12) {
			cout << "\n What string do you want to invert ? \t";
			getline(cin, s);
			getline(cin, s);

			if (str1.find(s)) {
				str1.findAndInvert(s);
			}
			else {
				cout << "\n String you entered is not present in str1.\n";
			}
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
		}
		else if (option == 13) {
			str1.Reverse();
			cout << "\n Str1 contains : " << str1;
			cout << "\n Str2 contains : " << str2;
			cout << "\n Length of Str1 is : " << str1.getLength();
			cout << "\n Length of Str2 is : " << str2.getLength();
		}
		else if (option == 14) {
			system("CLS");
		}
		else {		//If user press number other then 0-14
			cout << "\n INVALID NO!!\n";
		}
	}
	cout << "\n ";
	system("pause");
}

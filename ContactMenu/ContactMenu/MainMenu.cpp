#include "contacts.h"

string fname, lname, phonenumber;
int arr[]{ 1,2,3,4 };

#pragma region Clean Array

void cleanArr(char arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = ' ';
	}
}
#pragma endregion

#pragma region Check Number

bool CheckNumbers(string x) {//nomrede reqemleri yoxluyur
	bool check = true;
	int len = x.length();
	for (int i = 0; i < len; i++)
	{
		if (!(int(x[i]) >= 48 && int(x[i]) <= 57 ||int(x[i]) == 43))
		{
			check = false;
			break;
		}
	}
	if (check == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	system("pause");
	system("cls");
}
#pragma endregion

#pragma region Add Contact
void AddContact() {
	ofstream phone("number.txt", ios::app);
	system("cls");
	system("color 0E");

	cout << "\n\t\t\t\t\t\t<========================================>";
	cout << "\n\t\t\t\t\t\t | Enter First Name : ";
	cin >> fname;
	cout << "\t\t\t\t\t\t<---------------------------------------->";
	cout << "\n\t\t\t\t\t\t | Enter Last Name : ";
	cin >> lname;
	cout << "\t\t\t\t\t\t<---------------------------------------->";
	cout << "\n\t\t\t\t\t\t | Enter Phone Number : ";
	cin >> phonenumber;
	cout << "\t\t\t\t\t\t ________________________________________";
	cout << "\n\t\t\t\t\t\t<========================================>";

	bool chk = CheckNumbers(phonenumber);
	if (chk == true) 
	{
		if (phone.is_open()) 
		{
			phone << fname << " " << lname << " " << phonenumber << endl;
			cout << "\n\t\t\t\t\t\t |     Contact saved successfully!      |";
			cout << "\n\t\t\t\t\t\t<========================================>";

		}
		else 
		{
			system("color 0C");
			cout << "\n\t\t\t\t\t\t |       Error in opening record!       |";
			cout << "\n\t\t\t\t\t\t<========================================>";
		}
	}
	else {
		system("color 0C");
		cout << "\n\t\t\t\t\t\t |       Only numbers are allowed!      |";
		cout << "\n\t\t\t\t\t\t<========================================>";
	}

	phone.close();
	cout << "\n\t\t\t\t\t\t\t";
	system("pause");
	system("color 0B");
	system("cls");
}
#pragma endregion

#pragma region Search
void SearchContact() {
	bool found = false;
	system("color 0E");
	ifstream myfile("number.txt");
	string keyword;

	cout << "\n\t\t\t\t\t\t|============================================|";
	cout << "\n\t\t\t\t\t\t| Enter fname, lname or number to search :   |";
	cout << "\n\t\t\t\t\t\t|>>>>>>>";
	cin >> keyword;
	cout << "\t\t\t\t\t\t|\\==========================================/|";
	cout << "\n\t\t\t\t\t\t||             CONTACT DETAILS              ||";
	cout << "\n\t\t\t\t\t\t||==========================================||";
	int i = 0;
	if (myfile.is_open()) 
	{
		while (myfile >> fname >> lname >> phonenumber)
		{
			if (keyword == fname || keyword == lname || keyword == phonenumber) 
			{
				cout << "\n\t\t\t\t\t\t   - First Name : " << fname;
				cout << "\n\t\t\t\t\t\t   - Last Name : " << lname;
				cout << "\n\t\t\t\t\t\t   - Phone Number : " << phonenumber;
				cout << "\n\t\t\t\t\t\t||==========================================||";
				found = true;
			}
			i++;
		}
		myfile.close();
	}
	if (found == false) 
	{
		system("color 0C");
		cout << "\n\n\n\t\t\t\t\t\t/============================================\\";
		cout << "\n\t\t\t\t\t      <|           No such contact is found!          |>";
		cout << "\n\t\t\t\t\t\t\\============================================/";
	}
	cout << "\n\t\t\t\t\t\t     ";
	system("pause");
	system("color 0B");
	system("cls");
}
#pragma endregion

#pragma region Delete
void Delete(string fn, string ln, string pn, int secim) {
	int c = 1;
	ifstream myfile("number.txt");
	if (myfile.is_open()) {
		while (myfile >> fname >> lname >> phonenumber)
		{
			ofstream newtext("number1.txt", ios::app);
			if (newtext.is_open())
			{
				if (c != secim)
				{
					newtext << fname << " " << lname << " " << phonenumber << "\n";
				}
			}
			c++;
			newtext.close();
		}
	}
	myfile.close();
	remove("number.txt");
	ofstream mfile("number.txt", ios::app);
	ifstream newtext("number1.txt");
	if (newtext.is_open()) {
		while (newtext >> fname >> lname >> phonenumber)
		{
			if (mfile.is_open())
			{
				mfile << fname << " " << lname << " " << phonenumber << "\n";
			}
		}
		newtext.close();
		remove("number1.txt");
	}
	mfile.close();
}
#pragma endregion

#pragma region Edit
void Edit(string fn, string ln, string pn, int secim) {
	char secim1;
	string newf = fn, newl = ln, newp = pn; //edit olunacaq parametrler
	Delete(fn, ln, pn, secim);
	system("cls");
	cout << "\n\t\t\t\t\t\t||======================================||";
	cout << "\n\t\t\t\t\t\t||  Firstname :: " << fn;
	cout << "\n\t\t\t\t\t\t||--------------------------------------||";
	cout << "\n\t\t\t\t\t\t||  Do you want to change?              ||";
	cout << "\n\t\t\t\t\t\t||______________________________________||";
	cout << "\n\t\t\t\t\t\t||      1. Yes      |       2. No       ||";
	cout << "\n\t\t\t\t\t\t||--------------------------------------||";
	cout << "\n\t\t\t\t\t\t||>>>>>  ";
	while (true)
	{
		cin >> secim1;
		if (secim1 == '1' || secim1 == '2')
		{
			break;
		}
		else
		{
			system("color 0C");
			Sleep(1000);
			cout << "\n\t\t\t\t\t\t|| Wrong choice! |>>>>>";
			system("color 0B");
		}
	}
	switch (secim1)
	{
	case '1': cout << "\n\t\t\t\t\t\t||-->>  New firstname :: ";
		cin >> newf;
		break;
	default: break;
	}
	system("cls");
	cout << "\n\t\t\t\t\t\t||======================================||";
	cout << "\n\t\t\t\t\t\t||  Lastname :: " << ln;
	cout << "\n\t\t\t\t\t\t||--------------------------------------||";
	cout << "\n\t\t\t\t\t\t||  Do you want to change?              ||";
	cout << "\n\t\t\t\t\t\t||______________________________________||";
	cout << "\n\t\t\t\t\t\t||      1. Yes      |       2. No       ||";
	cout << "\n\t\t\t\t\t\t||--------------------------------------||";
	cout << "\n\t\t\t\t\t\t||>>>>>  ";
	while (true)
	{
		cin >> secim1;
		if (secim1 == '1' || secim1 == '2')
		{
			break;
		}
		else
		{
			system("color 0C");
			Sleep(1000);
			cout << "\n\t\t\t\t\t\t|| Wrong choice! |>>>>>";
			system("color 0B");
		}
	}
	switch (secim1) {
	case '1': cout << "\n\t\t\t\t\t\t||-->>  New lastname :: ";
		cin >> newl;
		break;
	default: break;
	}
	system("cls");
	cout << "\n\t\t\t\t\t\t||======================================||";
	cout << "\n\t\t\t\t\t\t||  Phone number :: " << pn;
	cout << "\n\t\t\t\t\t\t||--------------------------------------||";
	cout << "\n\t\t\t\t\t\t||  Do you want to change?              ||";
	cout << "\n\t\t\t\t\t\t||______________________________________||";
	cout << "\n\t\t\t\t\t\t||      1. Yes      |       2. No       ||";
	cout << "\n\t\t\t\t\t\t||--------------------------------------||";
	cout << "\n\t\t\t\t\t\t||>>>>>  ";
	while (true)
	{
		cin >> secim1;
		if (secim1 == '1' || secim1 == '2')
		{
			break;
		}
		else
		{
			system("color 0C");
			Sleep(1000);
			cout << "\n\t\t\t\t\t\t|| Wrong choice! |>>>>>";
			system("color 0B");
		}
	}
	switch (secim1) {
	case '1': while (true)
	{
		cout << "\n\t\t\t\t\t\t||-->>  New number :: ";
		cin >> newp;
		if (CheckNumbers(newp) == false)
		{
			cout << "\n\t\t\t\t\t\t||--------------------------------------||";
			cout << "\n\t\t\t\t\t\t||   Only numbers are allowed!          ||";
			cout << "\n\t\t\t\t\t\t||--------------------------------------||";
		}
		else
		{
			system("cls");
			break;
		}
	}
	default:
		system("cls");
		break;
	}

	ofstream myfile("number.txt", ios::app);
	if (myfile.is_open())
	{
		myfile << newf << " " << newl << " " << newp << "\n";
		myfile.close();
	}
	system("cls");
}
#pragma endregion

#pragma region Choice in AllContact

void Choice(int secim) {
	int count = 3;
	enum key
	{
		UP = 72,
		DOWN = 80,
		ENTER = 13
	};
	char arr2[3]{ ' ',' ',' ' };
	char input = '_';
	int index = 0;
	system("cls");
	ifstream myfile("number.txt");
	int c = 1;
	string fn, ln, pn; //secilmis parametrler
	if (myfile.is_open()) 
	{
		while (myfile >> fname >> lname >> phonenumber && c <= secim) 
		{
			if (c == secim) 
			{
				fn = fname;
				ln = lname;
				pn = phonenumber;
			}
			c++;
		}
		myfile.close();
	}
	while (true) {
		int ar[] = { 1,2,3 };
		int j = 0; //arr index
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t<<======================================>>";
		cout << "\n\t\t\t\t\t\t  ||        Contact information       ||";
		cout << "\n\t\t\t\t\t\t<<======================================>>";
		cout << "\n\t\t\t\t\t\t   ---->>>>  Firstname : " << fn;
		cout << "\n\t\t\t\t\t\t   ---->>>>  Lastname : " << ln;
		cout << "\n\t\t\t\t\t\t   ---->>>>  Phone number : " << pn;
		cout << "\n\t\t\t\t\t\t||______________________________________||";
		cout << "\n\t\t\t\t\t\t||||||||||||||||||||||||||||||||||||||||||";
		cout << "\n\t\t\t\t\t\t||======================================||";
		for (int i = 0; i < 3; i++) {
			switch (ar[i]) 
			{
			case 1:cout << "\n\t\t\t\t\t\t|| ~ Delete Contact. \t" << arr2[j] << "\t\t||";
				cout << "\n\t\t\t\t\t\t||--------------------------------------||";
				j++;
				break;
			case 2:cout << "\n\t\t\t\t\t\t|| ~ Edit Contact.           " << arr2[j] << "\t\t||";
				cout << "\n\t\t\t\t\t\t||--------------------------------------||";
				j++;
				break;
			case 3:cout << "\n\t\t\t\t\t\t|| ~ Back.           \t" << arr2[j] << "\t\t||";
				cout << "\n\t\t\t\t\t\t||======================================||";
				j++;
				break;
			}
		}
		input = _getch();
		if (int(input) == -32) 
		{
			input = _getch();
			if (int(input) == UP) {
				index--;
				if (index == -1) {
					index = count - 1;
				}
			}
			else if (int(input) == DOWN) {
				index++;
				if (index == count) {
					index = 0;
				}
			}
			cleanArr(arr2, 3);
			arr2[index] = '<';
			system("cls");
		}
		else if (int(input) == ENTER) 
		{
			system("cls");
			if (index == 0) {
				Delete(fn, ln, pn, secim);
				system("color 0C");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  ======================================";
				cout << "\n\t\t\t\t\t                Deleting...";
				cout << "\n\t\t\t\t\t  ======================================";
				Sleep(1000);
				system("cls");
				break;
			}
			else if (index == 1) {
				Edit(fn, ln, pn, secim);
				break;
			}
			else {
				system("cls");
				break;
			}
		}
	}
}
#pragma endregion

#pragma region AllContact
void AllContacts() {
	system("color 0E");
	ifstream myfile("number.txt");
	system("cls");
	if (myfile.is_open()) 
	{
		int say = 1; //contactin sirasi
		cout << "\n\t\t\t\t\t\t <======================================>";
		cout << "\n\t\t\t\t\t\t /              ALL CONTACTS            \\";
		cout << "\n\t\t\t\t\t\t|========================================|";
		cout << "\n\t\t\t\t\t\t|     NAMES                              |";
		cout << "\n\t\t\t\t\t\t|========================================|";
		while (myfile >> fname >> lname >> phonenumber)
		{
			cout << "\n\t\t\t\t\t\t    " << say << ". " << fname;
			cout << "\n\t\t\t\t\t\t|----------------------------------------|";
			say++;
		}
		int b = say; // backin sirasi
		cout << "\n\t\t\t\t\t\t    " << b << ". " << "BACK.";
		cout << "\n\t\t\t\t\t\t|========================================|";
		int k;
		cout << "\n\t\t\t\t\t\t\\   Which order do you want to choose?   /";
		cout << "\n\t\t\t\t\t\t         Enter the line number ::";
		cin >> k;
		myfile.close();
		if (k == b) {
			system("color 0B");
			system("cls");
			return;
		}
		else if (k > say || k <= 0) 
		{
			system("color 0C");
			cout << "\n\t\t\t\t\t        /========================================\\";
			cout << "\n\t\t\t\t\t       <|          Wrong  line number!!!         |>";
			cout << "\n\t\t\t\t\t        \\========================================/";
			Sleep(2000);
			system("cls");
		}
		else {
			Choice(k);
		}
		system("color 0B");
	}
}
#pragma endregion

#pragma region MainMenu
void MainMenu(int count) {
	enum key
	{
		UP = 72,
		DOWN = 80,
		ENTER = 13
	};
	char arr2[4]{ ' ',' ',' ',' ' };
	char input = '_';
	int index = 0;
	while (true) {
		int j = 0;//arr index
		cout << "\n\t\t\t\t\t\t|================================|";
		cout << "\n\t\t\t\t\t\t||\t   CONTACT MENU \t||";
		cout << "\n\t\t\t\t\t\t||==============================||";
		for (int i = 0; i < 4; i++)
		{
			switch (arr[i]) {
			case 1:cout << "\n\t\t\t\t\t\t|| 1. All contacts. " << arr2[j] << "\t\t||";
				cout << "\n\t\t\t\t\t\t||------------------------------||";
				j++;
				break;
			case 2:cout << "\n\t\t\t\t\t\t|| 2. Add contact. " << arr2[j] << "\t\t||";
				cout << "\n\t\t\t\t\t\t||------------------------------||";
				j++;
				break;
			case 3:cout << "\n\t\t\t\t\t\t|| 3. Search. " << arr2[j] << "\t\t\t||";
				cout << "\n\t\t\t\t\t\t||------------------------------||";
				j++;
				break;
			case 4:cout << "\n\t\t\t\t\t\t|| 4. Exit. " << arr2[j] << "\t\t\t||";
				cout << "\n\t\t\t\t\t\t|================================|";
				j++;
				break;
			}
		}
		input = _getch();
		if (int(input) == -32)
		{
			input = _getch();
			if (int(input) == UP) {
				index--;
				if (index == -1) {
					index = count - 1;
				}
			}
			else if (int(input) == DOWN) {
				index++;
				if (index == count) {
					index = 0;
				}
			}
			cleanArr(arr2, 4);
			arr2[index] = '<';
			system("cls");
		}
		else if (int(input) == ENTER)
		{
			system("cls");
			if (index == 0) {
				AllContacts();
			}
			else if (index == 1) {
				AddContact();
			}
			else if (index == 2) {
				SearchContact();
			}
			else {
				break;
			}
		}
	}
}
#pragma endregion

// Bala gore tesekkurler)
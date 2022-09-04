#pragma once

#include<iostream>
#include <conio.h>
#include <Windows.h>
#include<string>
#include<fstream>

using namespace std;

void cleanArr(char arr[], int size);
bool CheckNumbers(string x);
void AddContact();
void SearchContact();
void Delete(string fn, string ln, string pn, int secim);
void Edit(string fn, string ln, string pn, int secim);
void Choice(int secim);
void AllContacts();
void MainMenu(int count);
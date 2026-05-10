#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<Windows.h>
#include<cstdlib>
#include <fstream>
using namespace std;
struct member
{
	char name[10];
	char tele[30];
	char livetele[30];
	char worktele[30];
	char email[30];
	char web[30];
	char work[30];
	char live[30];
};
class connect1
{
public:
	member* data;
	connect1* last;
	connect1* next;
};
class list
{
	
public:
	int length;
	connect1 * head;
	list()
	{
		head = new connect1;
		head->data = NULL;
		head->last = NULL;
		head->next = NULL;
		length = 0;
	};
};
struct back
{
	member* arr[100];
	int number[100];
	int max;
};
struct temp
{
	member* arr[100];
	int number[100];
};
void ADDmember(list* );
void show(list* );
void check(list*);
void Deleteall(list*);
void Search(list*);
void sort(list*);
void help();
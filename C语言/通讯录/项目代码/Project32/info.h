#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define Max 100
struct Peoinfo
{
	char name[20];
	char sex[10];
	int age;
	char tele[20];
	char live[20];

};
typedef struct Peoinfo Peoinfo;
struct telebook
{
	Peoinfo num[Max];
	int count;

};
struct back
{
	int arr[Max];
	int m1;
};
typedef struct back back;
typedef struct telebook telebook;
void init(telebook*);
void Addmember(telebook*);
void show(telebook*);
back Serach(telebook*);
void retele(telebook*);
void Deletele(telebook*);
void sortpeo(telebook*);
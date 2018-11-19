#ifndef _STUDENT
#define _STUDENT
#include"iostream"
#include"string"
#include "windows.h"
using namespace std;
#define  size 80
class student
{
public:
	student();
	student(char *na, char *id, char *num, char *spec, int ag);
	student(const student &per);
	~student();
	char*getname()const;
	char *getid();
	char *getnumber();
	char *getspec();
	int getage()const;
	void display()const;
	void input();
	void insert();
	void Delete();
	static int getcount();


private:
	char *name;
	char ID[19];
	char number[10];
	char specialty[20];
	int age;
	static int counts;

};


#endif
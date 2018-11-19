#include"iostream"
#include"string"
#include "windows.h"
using namespace std;
class student
{
public:
	static int totoal;
	student(){ totoal++; }
	~student(){ totoal--; }
	student(int n, char *p = "wang");
	void getname();
	int getnum();
private:
	
	int num;
	char name[20];

};
int student::totoal = 0;

student::student(int n,char *p)
{
	num = n;
	strcpy_s(name, strlen(p) + 1, p);
	totoal++;
}

void student::getname()
{
	cout << name << endl;
}
int student::getnum()
{
	return num;
}
int main()
{
	cout << "the number of all students:" << student::totoal << endl;
	student *p = new student(13);
	cout << "the number of all students:" << student::totoal << endl;
	cout << "the number of all students:" << p->totoal << endl;
	delete p;
	cout << "the number of all students:" << student::totoal << endl;
	student s[2];
	cout << "the number of all students:" << s[0].totoal << endl; 
	cout << "the number of all students:" << s[1].totoal << endl;
    system("pause");
    return 0;
}
#include "_student.h"
int student::counts = 0;
student::student()
{
	name = NULL;
	age = 0;
}
student::student(char *na, char *id, char *num, char *spec, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];
		strcpy_s(name, strlen(na) + 1, na);

	}
	strcpy_s(ID, strlen(id) + 1, id);
	strcpy_s(number,strlen(num)+1, num);
	strcpy_s(specialty, strlen(spec) + 1, spec);
	age = ag;
	counts++;

}
student::student(const student &per)
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy_s(name, strlen(per.name) + 1, per.name);

	}
	strcpy_s(ID, strlen(per.ID) + 1, ID);
	strcpy_s(number, strlen(per.number) + 1, per.number);
	strcpy_s(specialty, strlen(per.specialty) + 1, per.specialty);
	age = per.age;
	counts++;
}
student::~student()
{
	cout << "disCon" << endl;
	if (name)
	{
		delete[]name;
		counts--;
	}
}
char *student::getname()const
{
	return name;
}
char *student::getid()
{
	return ID;
}
int student::getage()const
{
	return age;
}
char *student::getspec()
{
	return specialty;
}
char *student::getnumber()
{
	return number;
}
VOID student::display()CONST
{
	cout << "����" << name << endl;
	cout << "���֤" << ID << endl;
	cout << "ѧ��" << number << endl;
	cout << "רҵ" << specialty << endl;
	cout << "����" << age << endl<<endl;
}
VOID student::input()
{
	char na[10];
	cout << "��������";
	cin >> na;
	if (name)
	{
		delete[]name;
	}
	name = new char[strlen(na) + 1];
	strcpy_s(name, strlen(na) + 1, na);
	cout << "�������֤��";
	cin >> ID;
	cout << "��������";
	cin >> age;
	cout << "����רҵ";
	cin >> specialty;
	cout << "����ѧ��";
	cin >> number;
	counts++;
}

void student::insert()
{
	if (!age)
	{
		input();
	}
}
void student::Delete()
{
	age = 0;
	counts--;
}
int student::getcount()
{
	return counts;
}

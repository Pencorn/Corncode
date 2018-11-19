#include"iostream"
#include"string"
#include "windows.h"
using namespace std;
#include "_student.h"
const int N = 10;
void  menu();
void outputstu(const student *array);
void inputstu(student *array);
int searchstu(const student *array, char *na);
bool insertstu(student *array);
bool deletestu(student *array, char *na);
int main()
{
	student array[N];
	int choice;
	char na[20];
	do 
	{
		menu();
		cout << "please input your choice";
		cin >> choice;
		if (choice>=0&&choice<=5)
		{
			switch (choice)
			{
			    case  1:inputstu(array); break;
				case  2:
						cout << "input the name seached" << endl;
						cin >> na;
						int  i;
						i = searchstu(array, na);
						if (i==N)
						{
							cout << "查无此人\n";
						}
						else
						{
							array[i].display();
						}
						break;
				case 3:outputstu(array);break;
				case 4:
					if (insertstu(array))
				{
						   cout << "成功插入一条记录\n";

				}
					   else
						   cout << "插入失败\n";
					break;
				case  5:
					cout << "input the name delete" << endl;
					cin >> na;
					if (deletestu(array, na))
					{
						cout << "成功删除一条记录\n";
					}
					else
						cout << "删除失败\n";
					break;

			default:
				break;
			}
		}


	} while (choice);
system("pause");
return 0;
}
void menu()
{
	cout << "*******1.录入信息*******" << endl;
	cout << "*******2.浏览信息*******" << endl;
	cout << "*******3.查询信息*******" << endl;
	cout << "*******4.插入信息*******" << endl;
	cout << "*******5.删除信息*******" << endl;
	cout << "*******0.退    出*******" << endl;
}

void outputstu(const student *array)
{
	cout << "学生总人数" << student::getcount() << endl;
	for (int i = 0; i < N;i++)
	{
		if (array[i].getage())
		{
			array[i].display();
		}
	}

}
int searchstu(const student *array, char *na)
{
	int i, j = N;
	for (i = 0; i < N;i++)
	{
		if (array[i].getage())
		if (strcmp(array[i].getname(),na))
		{
			j = i;
			break;
		}
	}
	return j;
}
void inputstu(student *array)
{
	char ch;
	int i = 0;
	do 
	{
		if (student::getcount()==N)
		{
			cout << "人数已满,无法继续录入" << endl;
		}
		if (!array[i].getage())
		{
			array[i++].input();
		}
		cout << "继续输入吗(Y or N)" << endl;
		cin >> ch;
	} while (ch=='Y');
}

bool insertstu(student *array)
{
	if (student::getcount()==N)
	{
		cout << "人数已满,无法继续输入" << endl;
		return false;
	}
	for (int i = 0; array[i].getage();i++)
	{
		array[i].insert();
	}
	return true;

}
bool deletestu(student *array, char *na)
{
	if (student::getcount()==0)
	{
		cout << "没有记录,无法删除" << endl;
		return false;
	}
	int i = searchstu(array, na);
	if (i==N)
	{
		cout << "查无此人,无法删除" << endl;
		return false;
	}
	array[i].Delete();
	return true;
}

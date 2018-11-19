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
							cout << "���޴���\n";
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
						   cout << "�ɹ�����һ����¼\n";

				}
					   else
						   cout << "����ʧ��\n";
					break;
				case  5:
					cout << "input the name delete" << endl;
					cin >> na;
					if (deletestu(array, na))
					{
						cout << "�ɹ�ɾ��һ����¼\n";
					}
					else
						cout << "ɾ��ʧ��\n";
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
	cout << "*******1.¼����Ϣ*******" << endl;
	cout << "*******2.�����Ϣ*******" << endl;
	cout << "*******3.��ѯ��Ϣ*******" << endl;
	cout << "*******4.������Ϣ*******" << endl;
	cout << "*******5.ɾ����Ϣ*******" << endl;
	cout << "*******0.��    ��*******" << endl;
}

void outputstu(const student *array)
{
	cout << "ѧ��������" << student::getcount() << endl;
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
			cout << "��������,�޷�����¼��" << endl;
		}
		if (!array[i].getage())
		{
			array[i++].input();
		}
		cout << "����������(Y or N)" << endl;
		cin >> ch;
	} while (ch=='Y');
}

bool insertstu(student *array)
{
	if (student::getcount()==N)
	{
		cout << "��������,�޷���������" << endl;
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
		cout << "û�м�¼,�޷�ɾ��" << endl;
		return false;
	}
	int i = searchstu(array, na);
	if (i==N)
	{
		cout << "���޴���,�޷�ɾ��" << endl;
		return false;
	}
	array[i].Delete();
	return true;
}

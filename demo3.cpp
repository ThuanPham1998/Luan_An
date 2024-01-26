#include <string>
#include <iostream>
using namespace std;

struct infoPatient
{
	int p_no = 0;
	string name;
	int age;
	infoPatient(int p, const string& n, int a) : p_no(p), name(n), age(a) {}
};

struct Node {
	infoPatient data; 
	Node* next; 
};

Node* front = nullptr;
Node* rear = nullptr;

bool isempty()
{ 
	if (front == nullptr && rear == nullptr)
		return true;
	else
		return false;
}

void addPatient(infoPatient info)
{
	Node* ptr = new Node();
	ptr->data = info;
	ptr->next = nullptr;

	if (front == nullptr)
	{
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->next = ptr;
	}
}

int main()
{
	int choice;
	cout << "\n UNG DUNG QUAN LY XEP HANG PHONG KHAM XYZ \n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";

	while (true)
	{
		//Menu chinh:
		cout << "Hay chon cac chuc nang sau \n";
		cout << "1. Them Benh Nhan.\n";
		cout << "2. Goi Benh Nhan:\n";
		cout << "3. Quan ly Benh Nhan xep hang:\n";
		cout << "4. Thoat.\n";
		cout << "Nhap su lua chon cua ban: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Da them Benh Nhan.\n";
			break;

		case 2:
			int choice2;
			cout << "   2.1. Goi Benh Nhan tiep theo.\n";
			cout << "   2.2. Goi lai Benh Nhan.\n";
			cout << "   2.3. Bo qua Benh Nhan hien tai.\n";
			cin >> choice2;
			cout << "Ban da chon: " << choice2 << "\n";
			break;

		case 3:
			int choice3;
			cout << "   3.1. So Benh Nhan da kham.\n";
			cout << "   3.2. Hien dang kham Benh Nhan nao.\n";
			cout << "   3.3. Hien thi so luong Benh Nhan chua kham va danh sach chua kham.\n";
			cin >> choice3;
			cout << "Ban da chon: " << choice3 << "\n";
			break;
		default:
			cout << "Lua chon khong hop le.\n";
		}
	}
	return 0;
}

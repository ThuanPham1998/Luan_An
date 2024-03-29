﻿#include <queue>
#include <string>
#include <iostream>
#include <limits>
using namespace std;

//data structure declaration
struct Patient {
	int p_no;
	string name;
	int age;

	Patient(int p, const string& n, int a) : p_no(p), name(n), age(a) {}
};

using Data = queue<Patient>;

ostream& operator<<(ostream& os, const Patient& pat)
{
	return os << pat.p_no << "  " << pat.name << "  " << pat.age;
}

int menu()
{
	/* Hien thi menu*/

	int choice{};

	cout << "\n1) Bam so xep hang\n";
	cout << "2) Xem con bao nhieu benh nhan dang xep hang\n";
	cout << "3) Hien thi ten benh nhan dang xep hang\n";
	cout << "4) Kham benh nhan tiep theo\n";
	cout << "5) Thoat chuong trinh\n";
	cout << "\nMoi chon (1 - 5) :";

	while (!(cin >> choice) || choice < 1 || choice > 5) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ban da nhan sai. Vui long chon lai tu 1-5: ";
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

void append(Data& data)
{
	/*Nhận tên bệnh nhân từ người dùng và thêm bệnh nhân đó vào cuối hàng đợi. Số thứ tự của mỗi bệnh nhân mới sẽ tăng lên 1 so với bệnh nhân trước đó.*/

	static int num = 0;
	string name;
	int age;

	cout << "Ho va ten Benh nhan: ";
	getline(cin, name);
	cout << "Tuoi Benh nhan: ";
	cin >> age;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	data.emplace(++num, name, age);
}

int inqueue(const Data& data)
{
	/*Trả về số lượng bệnh nhân đang chờ trong hàng đợi.*/

	return data.size();
}

void display(Data& data)
{
	/*Hiển thị danh sách tất cả bệnh nhân đang chờ trong hàng đợi, bao gồm số thứ tự và tên của họ.*/

	if (!data.empty())
		for (size_t count{ 0 }; count < data.size(); ++count) {
			cout << data.front() << '\n';
			data.emplace(data.front());
			data.pop();
		}
	else
		cout << "Khong con Benh Nhan nao\n";
}

void serve(Data& data)
{
	/*Phục vụ bệnh nhân đầu tiên trong hàng đợi. Nếu người dùng chọn phục vụ bệnh nhân này (bằng cách nhập ‘y’ hoặc ‘Y’), bệnh nhân sẽ được loại bỏ khỏi hàng đợi.*/

	if (!data.empty()) {
		cout << "Benh nhan " << data.front() << " se vao kham [Y/N]: ";

		char ans;

		while (!(cin >> ans) || (ans = tolower(ans)) != 'y' && ans != 'n') {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ban da chon sai. Vui long chon lai: ";
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (ans == 'Y' || ans == 'y')
		 {
			data.pop();
			cout << "Hang doi duoc cap nhat\n";
		}
	}
	else
		cout << "Khong con benh nhan nao\n";
}

int main()
{
	Data data;
	int choice{};

	cout << "UNG DUNG QUAN LY BENH NHAN TRONG PHONG KHAM\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	do {
		//invoke function menu() to receive user’s selection.
		switch (choice = menu()) {
		case 1:
			append(data);
			break;

		case 2:
			cout << "Tong cong co " << inqueue(data) << " benh nhan dang xep hang\n";
			break;

		case 3:
			display(data);
			break;

		case 4:
			serve(data);
		}
	} while (choice != 5);
}
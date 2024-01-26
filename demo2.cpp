#include <string>
#include <iostream>
using namespace std;

struct dataPatient
{
    int p_no = 0;
    string name;
    int age;
    dataPatient() : p_no(0), name(""), age(0) {}
    dataPatient(int p, const string& n, int a) : p_no(p), name(n), age(a) {}
};

class Node {
public:
    dataPatient data;
    Node* next;
    Node(const dataPatient& d) : data(d), next(nullptr) {}
};


Node* front = nullptr; 
Node* rear = nullptr; 

int size = 0; 
int maxsize = 100; 
int patientsExamined = 0; 
int patientsRemaining = 0; 

bool isFull()
{
    return ::size == maxsize; 
}

bool isEmpty()
{
    return ::size == 0;
}

void Enqueue(const dataPatient& data)
{
    if (isFull()) {
        cout << "Benh Nhan xep hang da day. Vui long quay lai sau.\n";
        return;
    }

    Node* temp = new Node(data);
    temp->data = data;
    temp->next = nullptr;
    if (front == nullptr)  
    {
        front = temp;
    }
    else 
    {
        rear->next = temp;
    }

    rear = temp;
    :: size++;
    patientsRemaining++;
}

void AppendPatient(dataPatient& data)
{
    static int num = 0;
    cout << "Ho va ten Benh nhan: ";
    cin >> data.name;

    cout << "Tuoi Benh nhan: ";
    cin >> data.age;

    data.p_no = ++num;
    Enqueue(data);
}

void Dequeue() 
{
    if (isEmpty()) 
    {
        cout << "Da het Benh Nhan.\n"; 
        return;
    }

    Node* temp = front; 
    front = front->next; 
    if (front == nullptr) 
    {
        rear = nullptr;
    }

    delete temp; 
    :: size--; 
    patientsExamined++; 
    patientsRemaining--; 
}

void DisplayQueue() 
{
    Node* current = front;
    cout << "So benh nhan con xep hang: " << patientsRemaining << "\n";
    cout << "Danh sach benh nhan dang xep hang:\n";

    while (current != nullptr)
    {
        dataPatient patient = current->data;
        cout << "So thu tu: " << patient.p_no << ", Ten Benh Nhan: " << patient.name << ", Tuoi: " << patient.age << "\n";
        current = current->next;
    }
}

void ShowStatistics()
{
    cout << "So benh nhan da kham: " << patientsExamined << "\n";
}

void ShowCurrentPatients()
{
    cout << "So benh nhan dang kham:\n";
    DisplayQueue();
}

void ShowRemainingPatients()
{
    cout << "So benh nhan con lai: " << patientsRemaining << "\n";
    cout << "Danh sach benh nhan chua kham:\n";
    DisplayQueue();
}

//int main()
{
    dataPatient data;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Them Benh Nhan.\n";
        cout << "2. Goi Benh Nhan:\n";
        cout << "   2.1. Goi Benh Nhan tiep theo.\n";
        cout << "   2.2. Goi lai Benh Nhan.\n";
        cout << "   2.3. Bo qua Benh Nhan hien tai.\n";
        cout << "3. Quan ly:\n";
        cout << "   3.1. So Benh Nhan da kham.\n";
        cout << "   3.2. Hien dang kham Benh Nhan nao.\n";
        cout << "   3.3. Hien thi so luong Benh Nhan chua kham va danh sach chua kham.\n";
        cout << "0. Thoat.\n";

        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 0:
            return 0;
        case 1:
            // Them Benh Nhan
            AppendPatient(data);
            break;
        case 2:
            // Goi Benh Nhan
            cout << "Lua chon cua ban:\n";
            cout << "   2.1. Goi Benh Nhan tiep theo.\n";
            cout << "   2.2. Goi lai Benh Nhan.\n";
            cout << "   2.3. Bo qua Benh Nhan hien tai.\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice) {
            case 1:
                // Goi Benh Nhan tiep theo
                Dequeue();
                break;
            case 2:
                // Goi lai Benh Nhan
                // Implement as needed
                break;
            case 3:
                // Bo qua Benh Nhan hien tai
                // Implement as needed
                break;
            default:
                cout << "Lua chon khong hop le.\n";
            }
            break;
        case 3:
            // Quan ly
            cout << "Lua chon cua ban:\n";
            cout << "   3.1. So Benh Nhan da kham.\n";
            cout << "   3.2. Hien dang kham Benh Nhan nao.\n";
            cout << "   3.3. Hien thi so luong Benh Nhan chua kham va danh sach chua kham.\n";
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;
            switch (choice) {
            case 1:
                // So Benh Nhan da kham
                ShowStatistics();
                break;
            case 2:
                // Hien dang kham Benh Nhan nao
                ShowCurrentPatients();
                break;
            case 3:
                // Hien thi so luong Benh Nhan chua kham va danh sach chua kham
                ShowRemainingPatients();
                break;
            default:
                cout << "Lua chon khong hop le.\n";
            }
            break;
        default:
            cout << "Lua chon khong hop le.\n";
        }
    }

    return 0;
}

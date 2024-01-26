/*#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

struct BenhNhan {
    int soThuTu;
    string ten;
    int tuoi;
};

struct HangDoi {
    BenhNhan elements[MAX_SIZE];
    int front, rear;

    HangDoi() : front(-1), rear(-1) {}

    bool IsEmpty() {
        return front == -1 && rear == -1;
    }

    bool IsFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void Enqueue(const BenhNhan& bn) {
        if (IsFull()) {
            cout << "Hang doi day. Khong the them benh nhan.\n";
            return;
        }

        if (IsEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }

        elements[rear] = bn;
        cout << "Da them benh nhan vao hang doi.\n";
    }

    BenhNhan Dequeue() {
        BenhNhan bn;
        if (IsEmpty()) {
            cout << "Hang doi rong. Khong co benh nhan de goi.\n";
        }
        else if (front == rear) {
            bn = elements[front];
            front = rear = -1;
        }
        else {
            bn = elements[front];
            front = (front + 1) % MAX_SIZE;
        }
        return bn;
    }

    int Size() {
        if (IsEmpty()) {
            return 0;
        }
        else if (front <= rear) {
            return rear - front + 1;
        }
        else {
            return MAX_SIZE - front + rear + 1;
        }
    }
};

HangDoi hangDoi;

void ThemThongTinBenhNhan() {
    BenhNhan bn;
    cout << "Nhap so thu tu: ";
    cin >> bn.soThuTu;
    cin.ignore(); // Xoa bo ky tu newline trong buffer
    cout << "Nhap ten benh nhan: ";
    getline(cin, bn.ten);
    cout << "Nhap tuoi: ";
    cin >> bn.tuoi;

    hangDoi.Enqueue(bn);
}

void GoiBenhNhanTiepTheo() {
    if (!hangDoi.IsEmpty()) {
        BenhNhan bn = hangDoi.Dequeue();
        cout << "Benh nhan tiep theo la: " << bn.ten << " (So thu tu: " << bn.soThuTu << ", Tuoi: " << bn.tuoi << ")\n";
    }
    else {
        cout << "Khong co benh nhan trong hang doi.\n";
    }
}

void HienThiSoLuongDaKham() {
    cout << "So luong benh nhan da kham: " << hangDoi.Size() << endl;
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Them thong tin benh nhan\n";
        cout << "2. Goi benh nhan tiep theo\n";
        cout << "3. Hien thi so luong benh nhan da kham\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ThemThongTinBenhNhan();
            break;
        case 2:
            GoiBenhNhanTiepTheo();
            break;
        case 3:
            HienThiSoLuongDaKham();
            break;
        case 0:
            cout << "Cam on da su dung chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }

    } while (choice != 0);

    return 0;
}

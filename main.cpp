#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Lagu {
    string judullagu;
    string penyayi;
};

struct KodeRBT {
    string tahunprod;
    string notrack;
    string kodealb;
};

struct conclusion {
    string nolagu;
    Lagu musik;
    KodeRBT kode;
    conclusion* next;
};

void tambahLagu(conclusion*& head, int& count) {
    conclusion* newNode = new conclusion();
    cout << "Nomor lagu : "; cin >> newNode->nolagu;
    cout << "Judul lagu : "; cin >> newNode->musik.judullagu;
    cout << "Penyanyi : "; cin >> newNode->musik.penyayi;
    cout << "Tahun Produksi : "; cin >> newNode->kode.tahunprod;
    cout << "Nomor track : "; cin >> newNode->kode.notrack;
    cout << "Kode album: "; cin >> newNode->kode.kodealb;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        conclusion* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    count++;
}

void tampilkanLagu(conclusion* head) {
    cout << "No lagu\t\tJudul Lagu\tPenyanyi\tTahun Produksi\t\tNomor Track\t\tKode Album" << endl;
    cout << "=============================================================================================================" << endl;
    conclusion* current = head;
    while (current != NULL) {
        cout << current->nolagu << "\t\t";
        cout << current->musik.judullagu << "\t\t";
        cout << current->musik.penyayi << "\t\t";
        cout << current->kode.tahunprod << "\t\t\t";
        cout << current->kode.notrack << "\t\t\t";
        cout << current->kode.kodealb << endl;
        current = current->next;
    }
}

int main() {
    conclusion* head = NULL;
    string x;
    int count = 0;
    do {
        system("cls");
        cout << "Lagu ke-" << count + 1 << endl;
        tambahLagu(head, count);
        cout << "Ingin mengisi data selanjutnya (y/n)?"; cin >> x;
    } while (x == "y" && count < 20);

    tampilkanLagu(head);

    // hapus linked list untuk menghindari memory leak
    conclusion* current = head;
    while (current != NULL) {
        conclusion* temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;

    return 0;
}



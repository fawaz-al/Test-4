#include <iostream>
using namespace std;

struct Mahasiswa{
    string npm, nama, jurusan;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *newNode, *cur, *del;

// Create Circular Single Linked List
void createCircularSingleLinkedList(string dataBaru[3]){
    head = new Mahasiswa();
    head->npm = dataBaru[0];
    head->nama = dataBaru[1];
    head->jurusan = dataBaru[2];
    tail = head;
    tail->next = head;
}

void AddFirst(string data[3]){
    if (head == NULL){
        cout << "Buat Linked List dulu!!" << endl;
    }
    else{
        newNode = new Mahasiswa();
        newNode->npm = data[0];
        newNode->nama = data[1];
        newNode->jurusan = data[2];
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void AddLast(string data[3]){
    if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
    }else{
        newNode = new Mahasiswa();
        newNode->npm = data[0];
        newNode->nama = data[1];
        newNode->jurusan = data[2];
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void AddMiddle(string data[3], int posisi){
    if( head == NULL ){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        if (posisi == 1){
            cout << "\nPosisi satu bukan di tengah!!!" << endl;
        }else{
            newNode = new Mahasiswa();
            newNode->npm = data[0];
            newNode->nama = data[1];
            newNode->jurusan = data[2];
            // tranversing
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1){
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

void RemoveFirst(){
    if( head == NULL ){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
    }
}

void RemoveLast(){
    if( head == NULL ){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        del = tail;
        cur = head;
        while( cur->next != tail ){
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
    }
}

void RemoveMiddle(int posisi){
    if( head == NULL ){
        cout << "Buat Linked List dulu!!" << endl;
    }else{
        if (posisi == 1){
            cout << "\nPosisi satu bukan di tengah!!!" << endl;
        }else{
            // tranversing
            int nomor = 1;
            cur = head;
            while( nomor < posisi - 1 ){
                cur = cur->next;
                nomor++;
            }
            del = cur->next;
            cur->next = del->next;
            delete del;
        }
    }
}


void PrintCircular(){
    cout << "\n===== Data Mahasiswa =====" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| NPM\t\t| Nama\t\t\t| Jurusan\t|" << endl;
    cout << "---------------------------------------------------------" << endl;
    cur = head;
    while (cur->next != head)
    {
        cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t|" << endl;
        cur = cur->next;
    }
    cout << "| " << cur->npm << "\t| " << cur->nama << "\t| " << cur->jurusan << "\t|" << endl;

    cout << "---------------------------------------------------------" << endl;
}

int main(){
    string dataBaru[3] = {"N0001", "Fuulan", "Informatika"};
    createCircularSingleLinkedList(dataBaru);
    PrintCircular();
    cout << endl;
    cout << "===== Add First =====";
    string data2[3] = {"N0002", "Fulann", "Informatika"};
    AddFirst(data2);
    PrintCircular();
    cout << endl;
    cout << "===== Add Last =====";
    string data3[3] = {"N0003", "Fulaan", "Informatika"};
    string data4[3] = {"N0004", "Fullan", "Informatika"};
    AddLast(data3);
    AddLast(data4);
    PrintCircular();
    cout << endl;
    cout << "===== Add Middle =====";
    string data5[3] = {"N0005", "Ffulan", "Informatika"};
    AddMiddle(data5, 3);
    PrintCircular();
    cout << endl;
    cout << "===== Remove First =====";
    RemoveFirst();
    PrintCircular();
    cout << endl;
    cout << "===== Remove Last =====";
    RemoveLast();
    PrintCircular();
    cout << endl;
    cout << "===== Remove Middle =====";
    RemoveMiddle(2);
    PrintCircular();
    cout << endl;
    return 0;
}
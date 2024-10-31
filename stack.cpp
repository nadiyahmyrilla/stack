#include<iostream>


using namespace std;

typedef struct Node { //stack node struct
    int data;
    struct Node *next;
} Node;

typedef struct Stack { //stack head struct
    int count;
    int maxSize;
    struct Node *top;
} Stack;

Stack stack;

void createStack(int size) { // membuat awal stack yang count = 0
    stack.count = 0;
    stack.maxSize = size;
    stack.top = NULL;
}

bool isFull() { // ceek untuk stack full
    return stack.count >= stack.maxSize;
}

void push(int data){
	if (isFull()) { //cek apa penuh
        cout << "Stack penuh! Tidak bisa push.\n";
        return;
    }
    
    Node *newPtr = new Node;
    if(newPtr == NULL){
        cout << "Alokasi memori gagal!";
        return;
    }
    newPtr -> data = data;
    newPtr -> next = stack.top;
    stack.top = newPtr;
    stack.count++;
}

bool isEmpty(){ //cek untuk apa stuck kosong
    return stack.count == 0;
}

void pop(){ // menghapus data
    if(isEmpty()){
        cout << "Stack kosong!";
    }
    Node *dltPtr = stack.top;
    stack.top = stack.top -> next;
    stack.count--;
    delete dltPtr;
}

void stackTop(){ // mengecek top data
    if(isEmpty()){
        cout << "Stack kosong!";
        return;
    }
    cout << stack.top -> data;
}


int stackCount(){ //menghitung data
    return stack.count;
}

void destroyStack(){ // hapus total data
    while (stack.top != NULL){
        Node *temp = stack.top;
        stack.top = stack.top -> next;
        delete temp;
    }
    stack.count = 0;
}

void printStack() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
        return;
    }
    Node *pwalker = stack.top; // Rename current to pwalker
    cout << "Isi stack dari atas ke bawah:\n";
    cout << "------------------------------\n";
    while (pwalker != NULL) {
        cout << pwalker->data << endl;
        pwalker = pwalker->next; // Move to the next node
    }
    cout << "------------------------------\n";
}

int main(){
    int pilihan, value;
    int maxSize;

    cout << "Masukkan ukuran maksimum stack: ";
    cin >> maxSize;
    createStack(maxSize);
    
    do {
        system("cls");
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Ukuran\n5. Destroy\n6. Print Stack\n7. Exit\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan nilai untuk di push: ";
            cin >> value;
            push(value);
        } else if (pilihan == 2) {
        		cout << "Telah menghapus top: ";
	            pop();
	            cin.ignore();
	            cin.get();
        } else if (pilihan == 3) {
	            cout << "Nilai pada top: ";
	            stackTop();
	            cout << endl;
	            cin.ignore();
	            cin.get();
        } else if (pilihan == 4) {
	            cout << "Ukuran stack: " << stackCount() << endl;
	            cin.ignore();
	            cin.get();
        } else if (pilihan == 6) {
            printStack();
            cin.ignore();
            cin.get();
        } else if (pilihan == 7) {
            cout << "Exiting...\n";
        } else {
            cout << "Input tidak valid!\n";
        }
    } while (pilihan != 7);

    return 0;
}
    

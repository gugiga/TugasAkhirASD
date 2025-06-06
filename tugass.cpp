#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
    int id;
    string nama;
    string jurusan;
    struct node *next;
};
typedef struct node node;
node *top;
int choice;
int id;
string nama;
string jurusan;
int count = 1;
int keluar = 0;


void push(int id, string nama, string jurusan)
{
node *temp = new node;
temp->id = id;
temp->nama = nama;
temp->jurusan = jurusan;
temp->next = NULL;
if (top == NULL)
{
top = temp;
temp = NULL;
}
else
{
    temp->next = top;
    top = temp;    
}
cout << "\n# PUSH : No urut/index : " << count << ", Push : "
<< id << "_" << nama << "_" << jurusan;
count++;
}

void pop()
{
if (top==NULL)
cout << "\n## Stack kosong";
else
    {
    --count;
    int id=top->id;
    node *temp = new node;
    temp=top->next;
    top=temp;
    cout << "\n##POP hasil:" << id;
    cout << "\n##jumlah id dalam stack : " << count ;
    }
}

void printAll()
{
cout << "\n## Stack Size : " << count;

node *temp=new node;
temp=top;
int i=count - 1;
while(temp!=NULL)
{
cout << "\n## No Urut/index : " << i << ", Value : " <<
temp->id;
temp=temp->next;
i--;
}
}

void menu()
{
do {
cout << "\nMasukkan operasi yang akan dilakukan (1:push, 2:pop, 3:print, 4:Exit) : ";
cin >> choice;
switch (choice)
{
case 1:
{
cout << "\nMasukkan nomor ID : ";
cin >> id;
cout << "\nMasukkan Nama : ";
cin >> nama;
cout << "\nMasukkan Jurusan : ";
cin >> jurusan;
push(id, nama, jurusan);
break;
}
case 2:pop();
break;
case 3:printAll();
break;
case 4 :
cout << "Program Shutdown...";
keluar =1;
}
}while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

int main()
{
do
{
menu();
} while (keluar == 0);
}
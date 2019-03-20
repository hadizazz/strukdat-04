/*
Nama		: Hadiza Cahya Firdaus
NPM			: 140810180042
Tanggal		: 20 Maret 2019
Deskripsi	: Linked List	
*/

#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct ElemtList{
 string nama;
 char bidang[30];
 int gaji;
 ElemtList* next;
};

typedef ElemtList* pointer;
typedef pointer List;


void createList(List& First){
 First=NULL;
}

void createElmt(pointer& pBaru){
 pBaru = new ElemtList;
 cout<<"Nama : ";getline(cin,pBaru->nama);
 cout<<"Bidang : ";cin>>pBaru->bidang;
 cout<<"Gaji : ";cin>>pBaru->gaji;
 pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
 if(First==NULL){
  First=pBaru;
 }
 else{
  pBaru->next=First;
  First=pBaru;
 }
}

void insertLast(List& First, pointer pBaru){
 pointer last;
 if(First==NULL){
  First==pBaru;
 }
 else{
  last=First;
  while(last->next!=NULL){
   last=last->next;
  }
  last->next=pBaru;
 }
}

void deleteFirst (List& First, pointer& pHapus){
 if(First==NULL){
  pHapus=NULL;
  cout<<"List kosong, tidak ada yang dihapus"<<endl;
 }
 else if( First->next==NULL){
  pHapus=First;
  First=NULL;
 }
 else {
  pHapus=First;
  First=First->next;
  pHapus->next=NULL;
 }
}

void deleteLast(List&First, pointer&pHapus){
 pointer last,precLast;
 cout<<"Delete Last"<<endl;
 if(First==NULL){
  pHapus=NULL;
  cout<<"List kosong, tidak ada yang dihapus"<<endl;
 }
 else if(First->next==NULL){
  pHapus=First;
  First=NULL;
 }
 else{
  last=First;
  precLast=NULL;
  while(last->next!=NULL){
   precLast=last;
   last=last->next;
  }
  pHapus=last;
  precLast->next=NULL;
 }
}

void traversal(List First){
 int i=1;
 pointer pBantu;
 if(First==NULL){
  cout<<"List kosong"<<endl;
 }
 else{
  pBantu=First;
  do{
   cout<<"No. "<<(i)<<endl;
   cout<<"Nama : "<<pBantu->nama<<endl;
   cout<<"Bidang : "<<pBantu->bidang<<endl;
   cout<<"Gaji : "<<pBantu->gaji<<endl;
   pBantu = pBantu->next;
  }while(pBantu !=NULL);
 }
}

main(){
 char loop;
 List M;
 pointer A;
 int jawab;
 cout<<"Pilihan Menu"<<endl;
 cout<<"1. Insert First"<<endl;
 cout<<"2. Insert Last"<<endl;
 cout<<"3. Delete First"<<endl;
 cout<<"4. Delete Last"<<endl;
 cout<<"5. Traversal"<<endl;
 cout<<"Masukkan Menu : ";cin>>jawab;
  do{
     cin>>jawab;
     }while(jawab<1 || jawab>6);
    switch(jawab){
    case 1:
     createElmt(A);
     insertFirst(M,A);
     cout<<"\nData berhasil dibuat!\n";
     getch();
     break;
    case 2:
     createElmt(A);
     insertLast(M,A);
     cout<<"\nData berhasil dibuat!\n";
     getch();
     break;
    case 3:
     deleteFirst(M,A);
     cout<<"\nData berhasil dihapus!\n";
     getch();
     break;
    case 4:
     deleteLast(M,A);
     cout<<"\nData berhasil dihapus!\n";
     getch();
     break;
    case 5:
     traversal(M);
     cout<<"\nKembali ke menu? (Y/N) ";
     do{
      cin>>loop;
     }while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
     break;
    case 6:
     loop='x';
     break;
}
}

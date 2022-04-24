#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

int pilih; void pilihan();
void insert_data();
void hapus_data();
void cetak_data();
struct node
{
 int nim;
 char nama [40];
 char umur [20];
 node *prev, *next;
};
node *baru, *head=NULL, *tail=NULL,*help,*del;
main()
{
 do
 {
  system("cls");
  cout<<"\tLIN. DOUBLY LINKED LIST"<<endl;
  cout<<"\t=========================="<<endl;
  cout<<"\t1. INSERT DATA"<<endl;
  cout<<"\t2. HAPUS DATA"<<endl;
  cout<<"\t3. CETAK DATA"<<endl;
  cout<<"\t4. EXIT"<<endl;
  cout<<"\tPilihan (1 - 4) : ";
  cin>>pilih;
  cout<<endl<<endl;
  pilihan();
  cout<<"==============================="<<endl;
 }
 while(pilih!=4);
}
void pilihan()
{
 if(pilih==1)
 insert_data();
 else if(pilih==2)
 hapus_data();
 else if(pilih==3)
 cetak_data();
 else
 {
  cout<<"EXIT";
  cout<<"\nSee you"<<endl;
 }
}
void buat_baru()
{
 baru = new(node);
 cout<<"Masukkan NIM : ";cin>>baru->nim;
 cout<<"Masukkan Nama : ";cin>>baru->nama;
 cout<<"Masukkan Umur : ";cin>>baru->umur;
 cout<<"\n\t---Data telah dimasukkan---";
 cout<<"\n\nPRESS ENTER TO CONTINUE...";
 getch();
 baru->prev=NULL;
 baru->next=NULL;
}

void insert_data()
{
 buat_baru();
 if(head==NULL)
 {
  head=baru;
  tail=baru;
 }
 else
 {
  baru->next=head;
  head->prev=baru;
  head=baru;
 }
 cout<<endl<<endl;
}
void hapus_data()
{
 int hapus,nim;
 if(head==NULL)
 {
  cout<<"\nLinked List kosong, \nPenghapusan tidak dapat dilakukan"<<endl;
 }
 else
 {
  hapus=head->nim;
  cout<<"\nData yang dihapus: ";
  cin>>nim;
  del = head;
  head = head->next;
  delete del;
 }
}

void cetak_data()
{
 if (head==NULL)
 cout<<"\nData tidak dapat ditemukan!"<<endl; 
 else
 {
  help=head;
  while(help!=NULL)
  {
   cout<<" NIM : "<<help->nim;
   cout<<" NAMA : "<<help->nama;
   cout<<" UUMUR : "<<help->umur;
   help=help->next;
  }
 }
getch();
}

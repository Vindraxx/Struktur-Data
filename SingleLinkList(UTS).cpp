//Owner By Vindrax.Net
//Have License

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;


struct TNode{
    int data;
    int data1;
    TNode *next;
};

TNode *head, *tail;
TNode *posisi;
void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)
        return 1;
    else
        return 0;
}

void load(){
	char a = 219;
	gotoxy(36, 14);
	cout << "Sabar, Kalau Gak Mau Sabar Pake SSD..."<< endl;
	gotoxy(43,15);
	for(int r =1; r<=20; r++)
	{
		for(int q=0; q<=100000000; q++);
		cout << a;
	}
}

void loadcepet(){
	char a = 219;
	gotoxy(36, 14);
	cout << "Sabar Cok..."<< endl;
	gotoxy(43,15);
	for(int r =1; r<=20; r++)
	{
		for(int q=0; q<=10000000; q++);
		cout << a;
	}
}

void insertDepan(int databaru , int databaru1){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->data1= databaru1;
    baru->next = NULL;
    if(isEmpty()==1)
        head=tail=baru;
    else{
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->data<<" ";
                cout<<bantu->data1<<" \n";
                bantu=bantu->next;
            }
        }
        else
            cout <<"Data Masih kosong\n";
}

void hapusDepan(){
    TNode *hapus;
    hapus=head;
    head=head->next;
    delete hapus;
    cout<<"Press Any Key...";
}
void hapusTengah(){
    int banyakdata,posisi_hapus,poshapus;
    TNode *hapus, *bantu;
    if(head != NULL){
        cout<<" Akan dihapus pada data ke : ";
        cin>>posisi_hapus;
        banyakdata=1;
        bantu=head;
            while(bantu->next != NULL){
                bantu=bantu->next;
                banyakdata++;
            }
        if((posisi_hapus<1)||(posisi_hapus>banyakdata)){
            cout<<"Belum ada data !! masukkan Data dula aja...\n";
        }
        else{
            bantu=head;
            poshapus=1;
            while(poshapus<(posisi_hapus-1)){
                bantu=bantu->next;
                poshapus++;
            }
            hapus=bantu->next;
            bantu->next=hapus->next;
            delete hapus;
        }
    }
    else{
        cout<<"Data Masih kosong, tidak bisa hapus data dari tengah! ";
    }
}

void hapusBelakang(){
    TNode *baru,*bantu;
    if(head== NULL){
		cout<<"Data kosong";
	}
	else{
		baru=head;
		if(baru->next==NULL){
			delete baru;
			head=NULL;
		}
		else{
			while(baru->next != NULL){
				bantu=baru;
				baru=baru->next;
			}
		delete baru;
		bantu->next=NULL;
		}
	}
 }

void insertBelakang (int databaru,int databaru1){
    struct TNode *baru, *bantu;
    baru = new struct TNode;
    baru->data = databaru;
    baru->data1 = databaru1;
    baru->next = NULL;
    if(head==NULL){
		head=baru;
		posisi=head;
	}
	else{
		bantu=head;
		while(bantu->next !=NULL){
			bantu=bantu->next;
		}
		bantu->next=baru;
	}
    cout<<"Data masuk\n";
}

void searchData (int key){
    int flag {-1};
    struct TNode *bantu;
    bantu = head;
    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            if (bantu->data == key)
            {
                flag =  key;
                cout << "Data ditemukan : " << flag << endl;
                break;
            }
            bantu = bantu->next;
        }
    }
    else
        cout << "Linked List masih kosong\n";
}

void insertAfter(int data){
    TNode *baru, *bantu;
    int sesudah;
    if(head != NULL){
        cout<<"\n Tambah data setelah data ke : ";
        cin>>sesudah;
        bantu=head;
        baru = new TNode;
        for(int i=1;i<sesudah;i++) {
            if(bantu->next != NULL)
                bantu=bantu->next;
            else
            break;
        }
        cout << "Masukkan Data1 : ";
        cin >> baru->data;
        cout << "Masukkan Data2 : ";
        cin >> baru->data1;
        baru->next=bantu->next;
        bantu->next=baru;
    }
    else{
        cout<<"Belum ada data !! silahkan isi data dulu....";
    }
 }

void insertBefore(int data){
      TNode *baru, *bantu;
    int sesudah;
    if(head != NULL){
        cout<<"\n Tambah data sebelum data ke : ";
        cin>>sesudah;
        bantu=head;
        baru = new TNode;
        for(int i=1;i<sesudah-1;i++) {
            if(bantu->next != NULL)
                bantu=bantu->next;
            else
            break;
        }
        cout << "Masukkan Data1 : ";
        cin >> baru->data;
        cout << "Masukkan Data2 : ";
        cin >> baru->data1;
        baru->next=bantu->next;
        bantu->next=baru;
    }
    else{
        cout<<"Belum ada data !! silahkan isi data dulu....";
    }
}


void clear(){
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

int main(){
    int pilih,databaru,databaru1;
    system("color 9f");
    //load();
    do{
        system("cls");
        loadcepet();
        system("cls");
        cout<<"\t\t\t+========================+\n";
        cout<<"\t\t\t|   SINGLE LINKED LIST   |\n";
        cout<<"\t\t\t|    Owner By Vindrax    |\n";
        cout<<"\t\t\t|    Programmer Subuh    |\n";
        cout<<"\t\t\t+========================+\n";
        cout<<"\t\t\t|   (1)Insert Depan      |\n";
        cout<<"\t\t\t|   (2)Insert Belakang   |\n";
        cout<<"\t\t\t|   (3)Insert Sesudah    |\n";
        cout<<"\t\t\t|   (4)Insert Sebelum    |\n";
        cout<<"\t\t\t|   (5)Delete Depan      |\n";
        cout<<"\t\t\t|   (6)Delete Belakang   |\n";
        cout<<"\t\t\t|   (7)Delete Tengah     |\n";
        cout<<"\t\t\t|   (8)Search Data       |\n";
        cout<<"\t\t\t|   (9)Tampil Data       |\n";
        cout<<"\t\t\t|   (0)Exit              |\n";
        cout<<"\t\t\t+========================+\n";
        cout<<"\t\t\t Leboke Pilihanmu : ";
        cin>>pilih;
        if(pilih==1){
            cout<<"Masukkan Data1 = ";
            cin>>databaru;
            cout<<"Masukan Data2 = ";
            cin>>databaru1;
            insertDepan(databaru,databaru1);
        }
        else if(pilih==2){
            cout<<"Masukkan Data1 = ";
            cin>>databaru;
            cout<<"Masukkan Data2 = ";
            cin>>databaru1;
            insertBelakang(databaru,databaru1);
        }
        else if(pilih==3){
            insertAfter(databaru);
        }
        else if(pilih==4){
            insertBefore(databaru);
        }
        else if(pilih==5){
            hapusDepan();
        }
        else if(pilih==6){
            hapusBelakang();
        }
        else if(pilih==7){
            hapusTengah();
        }
        else if(pilih==8){
            if (!isEmpty())
                {
                    cout<<"Cari Data : ";
                    cin>>databaru;
                    searchData(databaru);
                }
                else{
                    cout << "Data masih kosong\n";
                }
        }
        else if(pilih==9){
            tampil();
        }
    cout<<"Press Any Key...";
    getch();
    }while(pilih!=0);
    return 0;
}

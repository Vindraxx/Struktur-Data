#include<iostream>
#include<conio.h>
#include<windows.h>
//Judul : program search,push and pop aka stack in cpp
//owner : vindrax.net

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[100];
    int berat;
    char kota[100];
};

struct paket kirim[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}
void cari(int x){
    string a;
    gotoxy(20,13);cout<<"Search(nama barang) : ";
    cin>>a;
    string ketemu;
    int y;
    for(int i=1; i<9; i++)
    {
        if(a==kirim[i].jenis_brg)
        {
             ketemu=a;
             y=i;
        }
    }
    if(ketemu==a){
        cout<<"jenis barang "<<a<<" ditemukan pada kolom ke -> "<<y;
    }
    else{
        cout<<"maaf gak ketemu, atau g inputanya g bener atau gak pilih program ke 3";
    }
    cout<<"/npress any key to continue...";
    getch();
}
void load()
{
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

void loadcepet()
{
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

void tambahdata(int x)
{
    gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
    cin>>kirim[x].jenis_brg;
    gotoxy(20,16);cout<<"Inputkan Berat           :";
    cin>>kirim[x].berat;
    gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
    cin>>kirim[x].kota;
}

void tampildata(int x)
{
    gotoxy(40,10);cout<<"Daftar Kiriman Paket:"<<endl;
    for(int a=1; a<x; a++)
    {
        gotoxy(40,11+a);
        cout<<"| "<<a<<" | ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }

    gotoxy(40,21);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void hapusdata(int x)
{
    gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    int datake=1;
    system("color 9f");
	load();
    do
    {
        bersihlayar();
        loadcepet();
        bersihlayar();
        gotoxy(1,1);cout<<"|----------------------|";
        gotoxy(1,2);cout<<"|------MENU UTAMA------|";
        gotoxy(1,3);cout<<"|1. Tambah Data        |";
        gotoxy(1,4);cout<<"|2. Hapus Data Terakhir|"<<endl;
        gotoxy(1,5);cout<<"|3. Tampil Data        |"<<endl;
        gotoxy(1,6);cout<<"|4. Cari Data          |"<<endl;
        gotoxy(1,7);cout<<"|0. Keluar             |"<<endl;
        gotoxy(1,8);cout<<"|----------------------|";

        gotoxy(1,9);cout<<"|\tPilihan Anda [1/2/3/4/0] :";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                    if(datake>=10){
                        gotoxy(20,13);cout<<"datanya kepenuhan tolong hapus datanya";
                        gotoxy(20,14);cout<<"press 1 to continue";
                        getch();
                    }
                    else{
                        tambahdata(datake);
                        datake++;
                    }
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                hapusdata(datake-1);
                datake--;
            }
        if(pilih==3) {/*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);}
        if(pilih==4){
            cari(datake);
        }
    }
    while(pilih!=0);
    return 0;
}


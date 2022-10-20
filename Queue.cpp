#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct antrian
{
    char nama[100];
    char jkel;
    int umur;
};

struct antrian pasien[10];
int datake=1;

bool isEmpty()
{
    if (datake==1)
        return true;
    else
        return false;
}

bool isFull()
{
    if (datake==11)
        return true;
    else
        return false;
}

void tampildata()
{
    cout<<"Antrian Pasien"<<endl;
    for (int x=1;x<datake;x++)
    {
        cout<<x<<". "<<pasien[x].nama<<" ";
        cout<<pasien[x].jkel<<" ";
        cout<<pasien[x].umur<<endl;
    }
    cout<<endl;
}

void inqueue(int a)
{
    int i=datake;

    if (isFull() || a>datake)
    {
        cout<<"Melebihi antrian"<<endl;
        getch();
    }
    else
    {
        while (i>=a)
        {
            pasien[i]=pasien[i-1];
            i--;
        }
        cout<<endl<<"Nama Pasien: ";
        cin>>pasien[a].nama;
        cout<<"Jenis Kelamin(L/P): ";
        cin>>pasien[a].jkel;
        cout<<"Umur Pasien: ";
        cin>>pasien[a].umur;
        datake++;
    }
}

void pindah(int a)
{
    for (a;a<datake;a++)
    {
        pasien[a] = pasien[a+1];
    }
}

void dequeue(int a)
{
    if (isEmpty() || (a>=datake))
    {
        cout<<"Antrian tidak ada"<<endl;
        getch();
    }
    else
    {
        cout<<"Antrian yang keluar "<<endl;
        cout<<pasien[a].nama<<" ";
        cout<<pasien[a].jkel<<" ";
        cout<<pasien[a].umur<<endl;
        pindah(a);
        cout<<endl;
        datake--;
        getch();
    }
}

int main ()
{
    int pilih,n;
    do
    {
        system("cls");
        tampildata();
        cout<<"1. Inqueue"<<endl;
        cout<<"2. Inqueue ke n"<<endl;
        cout<<"3. Dequeue"<<endl;
        cout<<"4. Dequeue ke n"<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"Pilihan anda (1-9) :";
        cin>>pilih;
        if (pilih==1)
        {
            inqueue(datake);
        }
        if (pilih==2)
        {
            cout<<"Akan disela ke antrian berapa ";
            cin>>n;
            inqueue(n);
        }
        else if (pilih==3)
        {
            dequeue(1);
        }
        else if (pilih==4)
        {
            cout<<"Masukkan nomor antrian yang akan dikeluarkan ";
            cin>>n;
            dequeue(n);
        }

    }
    while (pilih!=9);

    return 0;
}

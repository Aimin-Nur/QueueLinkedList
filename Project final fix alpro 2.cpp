#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <iomanip>
#include <string.h>
#include<stdio.h>
using namespace std;
int i,nr,isi,ch,pulang;  //deklarasi variabel global
int j, k, m, n, x;		//deklarasi variabel global
struct node
{
    int norek;
    int a,b,c,d,e,f;
    int u,v,w,x,y,z;
	string nama;
	string blkng;				//struct node queue linked list
	string alamat;				// int a : tanggal check in			// int u : tanggal check in (untuk mengedit data)
	int saldo;					// int b : bulan check in			// int v : bulan check in	(untuk mengedit data)
	int checkIn;				// int c : tahun check in			// int w : tahun check in	(untuk mengedit data)
	int umur;					// int d : tanggal check out		// int x : tanggal check Out(untuk mengedit data)
	int sewa;					// int e : bulan check out			// int y : bulan check Out(untuk mengedit data)
	int hari,bulan, tahun;		// int f : tahun check out			// int z : tahun check Out(untuk mengedit data)
	int masuk;
	int gnti;
	struct node *next;
}*front=NULL,*rear,*temp,*ubah,selisih,masuk,keluar;	//pointer queue linked list

void waktu()
{  														//prosedur untuk menetukan tanggal check in & check out customer
    cout<<"-> Check In"<<endl;
    cout<<"-> Masukan Tahun : ";cin>>masuk.tahun;
    cout<<"-> Masukan Bulan : ";cin>>masuk.bulan;		//proses input waktu check in pengunjung
    cout<<"-> Masukan Tanggal :";cin>>masuk.hari;
 
    cout<<endl<<endl;
 
    cout<<"-> Check Out" <<endl;
    cout<<"-> Masukan Tahun : ";cin>>keluar.tahun;
    cout<<"-> Masukan Bulan : ";cin>>keluar.bulan;	//proses input waktu check out pengunjung
    cout<<"-> Masukan Tanggal :";cin>>keluar.hari;
 
    if((keluar.hari-masuk.hari)<0)
	{
        selisih.hari=((30+keluar.hari)-masuk.hari);	//jika tanggal check out < waktu check in maka program akan menghitung 30 + tanggal check out lalu hasilnya dikurangi dengan waktu chek in
    }    else {
        selisih.hari=keluar.hari-masuk.hari;
    }
    if((keluar.bulan-masuk.bulan<0))
	{
        selisih.bulan=(12+keluar.bulan-masuk.bulan);
            selisih.tahun=keluar.tahun-masuk.tahun-1;	
    } else 
	{
        selisih.bulan=keluar.bulan-masuk.bulan;
    selisih.tahun=keluar.tahun-masuk.tahun;
    }
 
    cout<<endl<<endl;
 	temp->a=masuk.hari;
 	temp->b=masuk.bulan;  //proses inisialisasi (pengisiian queue linked list)
 	temp->c=masuk.tahun;
 	temp->d=keluar.hari;
 	temp->e=keluar.bulan;
 	temp->f=keluar.tahun;
    selisih.tahun*365+selisih.bulan*30+selisih.hari;				//formula untuk mencari berapa lama pengunjung menginap di hotel
    temp->sewa=selisih.tahun*365+selisih.bulan*30+selisih.hari; 	//setelah hasilnya diperoleh, maka hasilnya disimpan dalam variabel temp->sewa;
 
    cout<<endl;
}

void ins()  //prosedur untuk mengisi queue linked list
{
	for(i=1; i<=nr; i++){
	temp=new node;
	int asal;
	string n;
	string belakang;
    cout<<"-> Input nama\t\t: ";
    cin>>n;
    cout<<"-> Input nama belakang\t: ";		//proses penginputan data oleh pengunjung
    cin>>belakang;
    cout<<"-> Input umur\t\t: ";
    cin>>asal;
    waktu();
    cout<<" ";
    temp->umur=asal;
    temp->checkIn=pulang;
    temp->blkng=belakang;		//semua data yang diisi oleh pengunjung diganti posisinya menjadi temp->
	temp->norek=nr;
	temp->nama=n;
	temp->saldo=isi;
	temp->next=NULL;

	if(front==NULL)
		front=rear=temp;	//proses pembuatan queu linked list yang baru
	else
	{
		rear->next=temp;
		rear=temp;			//proses melanjutkan/meneruskan sambungan queue yang sudah ada sebelumnya
	}
}
	i++;					//sama saja kalau kita menuliskan temp=temp->next
}	

void periksa()
{													//prosedur untuk memeriksa jumlah pengunjung hotel
	cout<<"-> Jumlah Customer yang ingin diinput : ";			
    cin>>nr;
    cin.ignore(1,'\n');
	if(nr>=21){
		cout<<"======================================="<<endl;
		cout<<"| -> Maaf, Kapasistas Hotel sudah penuh!"<<endl;
		cout<<"| -> Kami hanya memiliki 20 kamar saja!"<<endl;			//jika pengunjung lebih dari 20 maka akan menampilkan output seperti ini
		cout<<"========================================"<<endl;
		getch();
	}else{
		ins();					// jika pengungjung <= 20 maka akan menjalankan prosedur ins();
	}
}

void del()   //prosedur untuk menghapus queue
{
	if(front==NULL)
		{cout<<" Belum ada nasabah!\n";		//pengecekan queue linked list, jika front kosong maka akan tampil output seperiini
		getch();}
	else
	{
		temp=front;                         //menset/mengatur pointer temp menunjuk pada queue yang paling awal/atas
		front=front->next;                  //seteleh pointer diset maka front akan meneruskan pada queue selanjutnya
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"            \tPROGRAM RESERVASI HOTEL KING SAUD																	   				"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<"NO. || NAMA DEPAN | NAMA BELAKANG | Waktu check Out |      Status       |    "<<endl;
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout <<setiosflags(ios::right)<<"|"<<setw(0) <<temp->norek<<setw(4)<<"|";
		cout<<setiosflags(ios::left)<<""<<setw(9)<<temp->nama <<setw(4)<<"|";
		cout<<setiosflags(ios::left)<<""<<setw(8)<<temp->blkng <<setw(8)<<"|";							//tampilan yang akan muncul saat menghapus data
		cout<<setiosflags(ios::left)<<""<<setw(6)<<temp->d<<temp->e<<temp->f<<setw(6)<<"|";
		cout<<setiosflags(ios::left)<<""<<setw(12)<<"Berhasil Chek Out"<<setw(3)<< "|"<<endl;
		cout<<"-------------------------------------------------------------------------"<<endl;
		cout<<" -> Customer atas nama "<<temp->nama<<" "<<temp->blkng<<" berhasil melakukan check out"<<endl; 		//akan menampilkan output penghapusan queue
		delete(temp);
		getch();
	}
}

void tampilan()
{														//tampilan/tabel program
	cout<<"|---------------------------------------------- --------------------------------------------------------------|"<<endl;
	cout<<"|                                    PROGRAM RESERVASI KING SAUD ARABIAN		                      |"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------|"<<endl;
	cout<<"NO ||   NAMA DEPAN  |  NAMA BELAKANG  |  Waktu Check In  |   Waktu check Out |     Umur    |     Lama Sewa    |    "<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
}


void dis(){         //prosedur untuk menampilkan semua data yang telah diinput oleh user
	if(front==NULL)
		{cout<<" Belum ada customer!\n"; 		//program melakukan penegecekan terlebih dahulu, jika quue front nilai nol, maka akan menampilkan output seperti berikut
		getch();}
	else
	{
		temp=front;   			//jika tidak maka pointer temp akan diset lagi menjadi front 
		int i=1;
		do{
			cout <<setiosflags(ios::right)<<"|"<<setw(0)<<i<<setw(2)<<"|";
			cout<<setiosflags(ios::left)<<""<<setw(10)<<temp->nama<<setw(7)<<"|";
			cout<<setiosflags(ios::left)<<""<<setw(10)<<temp->blkng<<setw(8)<<"|";
			cout<<setiosflags(ios::left)<<""<<setw(6)<<temp->a<<temp->b<<temp->c<<setw(7)<<"|";
			cout<<setiosflags(ios::left)<<""<<setw(7)<<temp->d<<temp->e<<temp->f<<setw(7)<<"|";			//proses menampilkan seluruh data yang telah diinput oleh user
			cout<<setiosflags(ios::left)<<""<<setw(7)<<temp->umur<<setw(7)<<"|";
			cout<<setiosflags(ios::left)<<""<<setw(7)<< temp->sewa<< " hari"<<setw(7)<<"|"<<endl;
			cout<<" ------------------------------------------------------------------------------------------------------------"<<endl;
			temp=temp->next;
			i++;
		}while(temp!=rear->next);			//jadi perulangan akan berhenti jika pointer temp tidak sama dengan queue rear ->next
		getch();
	}
}
void cari(){	//prosedur untuk mencari pengunjung yang terdaftar dalam sistem
    node *temp;
    temp=front;
    string caridata;
    int ketemu=0;     //variabel untuk menetukan jika data yg dicari sudah ketemu
    if(front != NULL)
    {
        cout<<"\n Input nama Customer yang dicari\t: ";
        cin>>caridata;
        while(temp!=NULL)
        {
            temp->nama;
            if(caridata==temp->nama)			//jika caridata menunjukkan hasil yang sama dengan temp->nama maka program akan menampilkan list berikut
            {
                cout<<"\n\n>>>  Data Yang Anda Cari Ditemukan  <<<"<<endl;
                cout<<" Nama\t    : "<<temp->nama<<" "<<temp->blkng<<endl;
                cout<<" Umur\t    : "<<temp->umur<<endl;
                cout<<" Check In   : "<<temp->a<<temp->b<<temp->c<<endl;
                cout<<" Check Out  : "<<temp->d<<temp->e<<temp->f<<endl;
                cout<<" --------------------------------------"<<endl;
                cout<<"\n\n";
              	ketemu=1;
            }
            temp=temp->next;		//setelah itu, pointer next diset lagi agar supaya menunjuk pada queue setelahnya
        }
        if(ketemu==0)  				//jika variabel ketemu hasilnya ==0, maka program akan menampilkan output berikut
        {
            cout<<" Data tidak ditemukan";
        }
    }
    else cout<<" Belum ada Customer!";
    getch();
}

void ganti()					//prosedur unutk mengedit data pengunjung
{	
    node *temp;
    temp=front;
    string edit;
    int ketemu=0;
    if(front != NULL)
    {
        cout<<"\n Input nama Customer yang dicari\t: ";			//petugas menginput nama customer yang akan diedit
        cin>>edit;
        while(temp!=NULL)   
        {
            temp->nama;
            if(edit==temp->nama){
                cout<<"\n\n>>>  Data Yang Anda Cari Ditemukan  <<<"<<endl;
                cout<<" Nama depan\t: "<<temp->nama<<endl;
                cout<<" Nama belakang\t: "<<temp->blkng<<endl;
                cout<<" Umur\t       : "<<temp->umur<<endl;
                cout<<" Jam Check In\t: "<<temp->a<<temp->b<<temp->c<<endl;
                cout<<" Jam Check Out\t: "<<temp->d<<temp->e<<temp->f<<endl;
                cout<<" ------------------------------"<<endl;
                
                cout<<"\n\n";
                cout<<"============================="<<endl;
                cout<<"Silahkan Edit waktu check In"<<endl;
                cout<<"========== =================="<<endl;
            	cout<<"Check In"<<endl;
   				 cout<<"Masukan Tahun : ";cin>>masuk.tahun;
    			cout<<"Masukan Bulan : ";cin>>masuk.bulan;			//proses penginputan data yang mau diedit
    			cout<<"Masukan Tanggal :";cin>>masuk.hari;
 
    			cout<<endl<<endl;
                cout<<"============================="<<endl;
                cout<<"Silahkan Edit waktu Check Out"<<endl;
                cout<<"==== ========================"<<endl;
    			cout<<"Check Out" <<endl;
    			cout<<"Masukan Tahun : ";cin>>keluar.tahun;
   				cout<<"Masukan Bulan : ";cin>>keluar.bulan;
    			cout<<"Masukan Tanggal :";cin>>keluar.hari;
 
    			if((keluar.hari-masuk.hari)<0){
    			    selisih.hari=((30+keluar.hari)-masuk.hari);
    			}    else {
        			selisih.hari=keluar.hari-masuk.hari;
    			}
    			if((keluar.bulan-masuk.bulan<0)){
        			selisih.bulan=(12+keluar.bulan-masuk.bulan);
    	        selisih.tahun=keluar.tahun-masuk.tahun-1;
   				} else {
        			selisih.bulan=keluar.bulan-masuk.bulan;
    				selisih.tahun=keluar.tahun-masuk.tahun;
    			}
 
    			cout<<endl<<endl;
 				temp->u=temp->a=masuk.hari;
 				temp->v=temp->b=masuk.bulan;
 				temp->w=temp->c=masuk.tahun;		//inisialisasi setiap variabel kedalam pointer
 				temp->x=temp->d=keluar.hari;
 				temp->y=temp->e=keluar.bulan;
 				temp->z=temp->f=keluar.tahun;
   		 		selisih.tahun*365+selisih.bulan*30+selisih.hari;
    			temp->sewa=selisih.tahun*365+selisih.bulan*30+selisih.hari;
            	tampilan();							//jalankan prosedur tampilan (tabel)
            	temp->norek;
				{
					cout <<setiosflags(ios::right)<<""<<setw(0) <<temp->norek;
					cout<<setiosflags(ios::left)<<""<<setw(14)<<temp->nama;
					cout<<setiosflags(ios::left)<<""<<setw(15)<<temp->blkng;
					cout<<setiosflags(ios::left)<<""<<setw(14)<<temp->u<<temp->v<<temp->w;
					cout<<setiosflags(ios::left)<<""<<setw(15)<<temp->x<<temp->y<<temp->z;			//proses pemanggilan data yang sudah diedit kedalam tabel
					cout<<setiosflags(ios::left)<<""<<setw(14)<<temp->umur;
					cout<<setiosflags(ios::left)<<""<<setw(15)<< temp->sewa << " hari"<<endl;
					cout<<" --------------------------------------------------------------------------------------------------------------"<<endl;
					cout<<"-> Pemesan dengan nama "<<temp->nama<<" "<<temp->blkng<<" melakukan perubahan data berupa waktu check in : "<<temp->u<<temp->v<<temp->w<<endl;
					cout<<"-> Dan juga mengubah waktu Check Out menjadi : "<<temp->x<<temp->y<<temp->z<<endl;
            		ketemu=1;
				}
            	getch();
			}
			temp=temp->next;
        }
        if(ketemu==0)
        {
            cout<<" Data tidak ditemukan";
        }
    }
    else cout<<" Belum ada Customer!";
    getch();
}

void transaksi()	//prosedur untuk menampilkan info pembayaran customer
{
	string name;
    node *temp;
    temp=front;
    int ketemu=0;
    if(front != NULL)
    {
        cout<<"\n Input Nama Customer\t: ";
        cin>>name;
        cout<<endl;
            while(temp!=NULL)			//perulangan akan berhenti jika pointer temp hasilnya tidak sama dengan NULL
                {
                temp->nama;				//pointer temp kita set menunjuk pada variabel nama temp->nama
            if(name==temp->nama)
               {
                    cout<<"==================================================================================================================================================="<<endl;
                    cout<<"-> Info harga : Rp. 100.000/malam"<<endl;
                    cout<<"-> Customer atas nama "<<temp->nama<<" "<<temp->blkng<<" menginap selama "<<temp->sewa<<" hari di hotel, total biaya menginap Rp."<<100000*temp->sewa<<endl;
                    cout<<"-> Silahkan melakukan pemabayaran Rp. "<<100000*temp->sewa<<" di resepsionis"<<endl;
                    cout<<"===================================================================================================================================================="<<endl;
                    cout<<"\t\t\t\tTERIMA KASIH SUDAH MEMILIH LAYANAN HOTEL KAMI"<<endl;
                    cout<<"====================================================================================================================================================="<<endl;
					ketemu=1;
					getch();
                    }
                    else {cout<<"Inputan salah!\n"; getch;}
            
                 temp=temp->next;
                }
                if(ketemu==0)
                    {
                        cout<<"Data tidak ditemukan";
                    }
        		getch();  
		}
}
    

void sorting(){
	char sementara [10];
	char customer [10][10];
	temp=front;
//	temp->nama=customer[i][j];
//	cout<<" List Nama-nama Customer: "<<endl;
//	for(i=1;i<=nr;i++)
	cout<<"Input banyak pengunjung : ";
	cin>>n;
	for(i=1;i<=n; i++)
	{
		cout<<"Input nama ke -"<<i<<": ";
		cin>>customer[i];
//		cout<<i<<". "<< temp->nama<<endl;
//		temp=temp->next;
	}
	for (i=1;i<=n;i++)
	{ 
        if (i>1) 
		{
           for (j=1;j<=(i-1);j++)
		   {
               x=(strcmp(customer[i], customer[j])); 
            if (x<=0)
			{
                  strcpy(sementara, customer[i]);          	//proses pengurtan nama menggunakan metode bubble sort
                  for (k=(i-1);k>=j;k--) 
				  {
                      m=(k+1);
                      strcpy (customer[m], customer[k]);    //strcpy berguna untuk menyamakan nilai dari kedua string yang berbeda
                  }
                 
                  strcpy (customer[j], sementara);
               }
           }
        }
    }
    cout<<"==============================="<<endl;
    cout<<"HASIL PENGURUTAN NAMA CUSTOMER"<<endl;
    cout<<"==============================="<<endl;
    for(i=1; i<=n; i++)
	{
    	cout<<i<<". "<<customer[i]<<endl;				//menampilkan hasil sorting bubble sort
	}
	getch();
	
}
int main()
{
	int ch,nr,isi;		//variabel untuk pengisian data di menu utama
	while(1)
	{
	    system("cls");
	    cout<<"\n\n|===================================================|";
	    cout<<"\n|               HOTEL KING SAUD ARABIAN             |";
		cout<<"\n|___________________________________________________|";
		cout<<"\n|                      Main Menu                    |";
        cout<<"\n|===================================================|";
		cout<<"\n| 1.Input Data Customer                             |";
		cout<<"\n| 2.Hapus Data Customer                             |";
		cout<<"\n| 3.Transaksi                                       |";			//tampilan menu utama
		cout<<"\n| 4.Tampilkan Daftar Customer                       |";
		cout<<"\n| 5.Cari Data Pengunjung                            |";
		cout<<"\n| 6.Edit Data                                       |";
		cout<<"\n| 7.Sorting Data                                    |";
		cout<<"\n|___________________________________________________|";
		cout<<"\n|===================================================|";
		cout<<"\n\n Masukkan Pilihan (1-7): ";
		cin>>ch;
		cout<<"\n";
		switch(ch)
		{
			case 1:
				periksa();
                break;
			case 2:
			    del();
			    break;
            case 3:
                transaksi();
                break;
            case 4:
                tampilan();
                dis();
                break;
			case 5:
				cari();
                break;
            case 6:
                ganti();
                break;
			case 7:
			    sorting();
                break;
			default:
			    cout<<"Input salah, silahkan input ulang!(press any key)";
			    getch();
		}
	}
	return 0;
}

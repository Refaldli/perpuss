#include <iostream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

using namespace std;
void login();
void menu();

int main()
{
	int a;
	system("CLS");
	cout <<"\t\t\t===========================================================\n";
	cout <<"\t\t\t 	     Selamat datang di perpustakaan kami 			 \n";
	cout <<"\t\t\t===========================================================\n";
	cout <<"\t\t\t Jl.lingkar selatan, Sukabumi \t Telfon 813-8764-6336" << endl << endl;
	system ("pause");
	system ("CLS");
	logg:
	cout <<"\nSelamat datang di menu Login\n";
	cout <<"=============================" << endl;
	cout <<"Tekan 1 untuk login ke akun anda \n";
	cout <<"Tekan 2 untuk Mendafatar akun  \n";
	cout <<"Tekan 3 untuk Keluar  \n";
	cout <<"=============================" << endl;
	cout <<"Silahkan input [1-3] : "; cin >> a;
	switch(a){
		case 1:
			system("cls");
			login();
			break;
		case 2:
			cout <<"\nMohon maaf program belum selesai\n";
			cout <<"Anda akan diarahkan ke menu login ";
			system("pause");
			system("cls");
			goto logg;
			break;
		case 3:
			cout <<"\n\t\t\t 	     Terimakasih atas kunjungan anda 			 \n";
			cout <<"\n\t\t\t\t 	     PROGRAM SELESAI !! 			 \n";
			break;
		default:
			cout <<"\nAnda salah memasukan input !! \n";
			cout <<"Anda akan diarahkan ke menu login ";
			system("pause");
			system("cls");
			goto logg;
	}
}

void login()
{
	string username,password;
	char ch;
	cout <<"\nSelamat datang di Login Page\n";
	cout <<"=============================" << endl;
	cout <<"Silahkan Masukan Username dan password anda \n\n";
	cout <<"USERNAME : "; cin >> username;
	cout <<"PASSWORD : ";
	ch=_getch();
	while(ch !=13){
 		password.push_back(ch);
	 	cout<<'*';
 		ch = _getch();
}
	if(username =="mahasiswa" && password =="123"){
		cout <<"\n\tLOGIN SUKSES , Selanjutnya anda akan diarahkan ke menu perpustakaan\n";
		cout <<"\t";system("pause");
		menu();
	} else {
		cout <<"\nUSERNAME dan PASSWORD yang anda masukan salah !! ";
		system("pause");
		system("cls");
		login();
	}
}

void menu()
{
	system("cls");
	#define ppn 0.10
	const int diskon = 10000;
	char nama[50], menu[20], back, yo;
	int jumlah, pilih, buku, total, bayar, kurang, bonus, pajak, kembalian, input,
		harga[5]={17500, 25000, 23500, 20000}, i=0;
	bool saldo;

	do{
		system("CLS");
		men:
		cout <<"\nSilahkan Pilih Menu yang tersedia [1-2]\n";
		cout <<"1. Daftar Buku\n";
		cout <<"2. Pembelian Buku\n";
		cout <<"Input menu : "; cin >> input;
		switch(input){
			case 1:
			goto menuu;
			break;
			case 2:
			goto pesan;
		}
		menuu:
		system("cls");
		cout <<"\nDAFTAR BUKU YANG TERSEDIA " << endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"[1] Buku C++	= Rp 17.500" << endl;
		cout<<"[2] Buku java	= RP 25.000"<< endl;
		cout<<"[3] Buku python	= RP 23.500"<< endl;
		cout<<"[4] Buku HTML	= Rp 20.000"<< endl;
		cout<<"-------------------------------------"<<endl;
		cout <<"Apakah anda ingin memesan Buku ? Y/N : "; cin >> yo;
		if(yo == 'Y' || yo == 'y'){
			goto pesan;
		}else if(yo == 'N' || yo == 'n'){
			system("cls");
			goto men;
		}else {
			cout <<"Y/N !!";
			goto menuu;
		}
		pesan:
		system("cls");
		cout <<"\nRuang Pemesanan BUKU " << endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Masukkan Nama Anda : " ; cin >>nama;
		cout <<"Kode buku sesuai nomor menu / Buku yang tersedia" << endl; 
		cout<<"Silahkan Pilih Buku anda [1-4] : "; cin >> pilih;
		
		//Percabangan
		switch(pilih){
			case 1:
				strcpy(menu,"Buku C++");
				break;
			case 2:
				strcpy(menu,"Buku java");
				i=1;
				break;
			case 3:
				strcpy(menu,"Buku python");
				i=2;
				break;
			case 4:
				strcpy(menu,"Buku HTML");
				i=3;
				break;
			default:
				cout << "Pilihan menu yang anda pilih tidak tersedia..." << endl;
				goto ulang;
		}
		
		cout<<"	Anda memilih " << menu <<endl;
		cout<<endl;
		cout<<"Jumlah Buku yang dibeli : ";cin>> jumlah;
		
		buku = jumlah * harga[i];
		pajak   = buku * ppn;
		total   = pajak + buku;
		cout << endl;
		system("cls");
		cout<<"---------------------------------------------"<<endl;
		cout << "Nama Pemesan 		: "	<< nama     <<endl;
		cout << "Judul Buku 		: "	<< menu     <<endl;
		cout << "Jumlah Buku 		: "	<< jumlah   <<" Buku" <<endl;
		cout << "Harga Buku 		: "	<< harga[i] << " * "   << jumlah << endl;
		cout << "Pajak 			: "	<< pajak    <<endl;	
		cout << "Total Pembayaran 	: Rp " << total    <<endl;
		cout<<"---------------------------------------------"<<endl;
		
		if(jumlah>=4){
			bonus = total - diskon;
			total = bonus;
			cout << endl;
			cout << "# Anda mendapatkan diskon Potongan Harga : Rp " << diskon <<" #"<< endl;
			cout << "Total Pembayaran Setelah diskon  : Rp "<< total << endl;
		}
		
		cout << "--------------------------------------------" << endl;
		cout << "Silahkan bayar disini 		 : Rp."; 		cin>>bayar;
		cout << endl;
				
		while (saldo=bayar<total){
			cout << "Saldo anda kurang, Silahkan bayar lagi : Rp. "; cin>>kurang;
			bayar+=kurang;
		};
		
		kembalian=bayar-total;
		cout << "Uang yang anda bayar \t\t\t Rp. " << bayar<<endl;
		cout << "Uang kembalian \t\t\t\t Rp. "     << kembalian <<endl;
		cout << "##################################################"<<endl;
		
		ulang:
			cout << "		Apakah anda ingin memesan lagi ? Y/N : "; cin>>back;
		}while (back=='Y'||back=='y');
		cout << endl;
		cout << "		Terima kasih telah Memesan Buku di perpustakaan kami"<<endl;	
		cout << "			Selamat Menikmati"<<endl;
}


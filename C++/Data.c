#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char kode[8], nama[50];
int nilai, sks;


typedef struct matkul{
	char nama [50];
	char kode [8];
	int sks;
	int nilai;
	struct matkul *lanjut, *kembali;
} matkul;

matkul*kepala, * ekor;

void init(){
	kepala = NULL;
	ekor = NULL;
}


int isEmpty(){
	if(ekor==NULL) return 1;
	else return 0;
}


void Datadepan(char *kode, char *nama, int sks, int nilai){
	matkul *temp;
	
	temp = malloc (sizeof (struct matkul));
	strcpy(temp->kode, kode);
	strcpy(temp->nama, nama);
	temp->nilai = nilai;
	temp->sks = sks;
	
	if(isEmpty()==1){
		
		kepala = temp;
		ekor = kepala;
		kepala ->lanjut = kepala;
		kepala->kembali = kepala;
		ekor->lanjut = ekor;
		ekor->kembali = ekor;
	}else{
		
		temp->lanjut=kepala;
		kepala->kembali = temp;
		kepala = temp;
		kepala->kembali = ekor;
		ekor->lanjut = kepala;
		}
		
	printf("===========================================================\n");
	printf(" Data Telah TerInputkan\n");
	printf(" Data Dengan kode: %s\n", temp->kode);
	printf(" Data Dengan Nama: %s\n", temp->nama);
	printf(" Data Berhasil ditambah di depan\n");
}


void DataBelakang (char *kode, char *nama, int sks, int nilai){
	matkul *temp;
	
	temp = malloc (sizeof(struct matkul));
	strcpy(temp->kode, kode);
	strcpy(temp->nama, nama);
	temp->nilai = nilai;
	temp->sks = sks;
	
	if(isEmpty()==1){
			
			kepala = temp;
			ekor = kepala;
			kepala -> lanjut = kepala;
			kepala-> kembali = kepala;
			ekor->lanjut = ekor;
			ekor->kembali = ekor;
	}else {
			ekor->lanjut = temp;
			temp->kembali = ekor;
			ekor = temp;
			ekor->lanjut = kepala;
			kepala->kembali = ekor;
	}
	
	printf("=================================================\n");
	printf(" Data Telah TerInputkan: \n");
	printf(" Data Dengan Kode: &s\n", temp->kode);
	printf(" Data Dengan Nama: &s\n", temp->nama);
	printf(" Data Berhasil ditambah di belakang\n");
}


void hapus_depan (){
	matkul *del;
	char d[8];
	
	if(kepala != ekor){
		
		del = kepala;
		strcpy (d, del->kode);
		kepala = kepala->lanjut;
		kepala->kembali = ekor;
		ekor->lanjut = kepala;
		free(del);
	}else{
		strcpy (d, del->kode);
		kepala 	= NULL;
		ekor 	= NULL;
	}
	
	printf("Data %s Data Berhasil dihapus didepan \n", d);
}


void hapus_belakang (){
	matkul *del;
	char d[8];
	
	if(kepala!=ekor){
		
		del = ekor;
		strcpy (d, del->kode);
		ekor = ekor->kembali;
		ekor->lanjut = kepala;
		kepala->kembali = ekor;
		free(del);
	} else{
		strcpy (d, del->kode);
		kepala 	= NULL;
		ekor	= NULL;
	}
	
	printf("Data %s Data Berhasil dihapus dibelakang\n", d);
}


void cariData(char *cari){

	matkul *help, *carii;
	int index;
	
	help = kepala;
	index = 1 ;
	do{
		if(strcmp(help->kode, cari)==0){
			carii = help;
			
			printf ("Data Kode %s Dengan Baris %d \n", cari,index);
			return;
		}
		
		index++;
		help = help->lanjut;
	}
	while(help!= ekor->lanjut);
	
	printf("Data Kode %s tidak ditemukan \n", cari);

}


void menampilkan_jumlah(){
	matkul *help;
	help = kepala;
	
	int n = 0;
	if (isEmpty()==1){
		printf("Data Masih Kosong");
		return;
		
	}else{
		do{
			n++;
			help = help->lanjut;
			
		}while(help != ekor->lanjut);
		printf("Jumlah Data :%d\n", n);
		printf("___________________\n");
	}
}


void menampilkan_semua(){
	matkul *help;
	help = kepala;
	
	int n =1;
	if (isEmpty()==1){
		printf("Maaf Data Masih Kosong \nSilahkan Menambahkan data Terlebih Dahulu \n");
		return;
	}else{
		printf("=============== D A T A    M A T A   K U L I A H=================/n");
		do{
			printf("Mata Kuliah Ke	: %d\n", n);
			printf("Kode Matkul		: %s\n", help->kode);
			printf("Nama Matkul		: %s\n", help->nama);
			printf("Nilai Matkul	: %d\n", help->nilai);
			printf("Jumalah SKS		: %d\n", help->sks);
			printf("__________________________________\n");
			help = help->lanjut;
			n++;
 		} while (help !=ekor->lanjut);
		
		printf("\n");
		
		 }
		}
	
	
void nilaiminmax(){
	matkul *help, *terbesar, *terkecil;
	
	help = kepala;
	terbesar = help;
	terkecil = help;
	
	if(isEmpty()==1){
		printf("Belum Terdapat Data\n");
		return;
	}else{
		do{
			if (help->nilai <terbesar->nilai){
				terbesar = help;
			}
			
			if (help->nilai >terkecil->nilai){
				terkecil = help;
		}
		help = help->lanjut;
	}while (help!=ekor->lanjut);
	
	printf("=================Data Matkul Terbesar===========\n");
	printf(" Kode Matkul	: %s\n", terbesar->kode);
	printf(" Nama Matkul	: %s\n", terbesar->nama);
	printf(" Jumlah SKS		: %d\n", terbesar->sks);
	printf(" Nilai			: %d\n", terbesar->nilai);
	printf("================================================\n");
	
	printf("==========Data Matkul Terkecil============\n");
	printf(" Kode Matkul	: %s\n", terkecil->kode);
	printf(" Nama Matkul	: %s\n", terkecil->nama);
	printf(" Jumlah Matkul	: %d\n", terkecil->sks);
	printf(" Nilai 			: %d\n", terkecil->nilai);
	printf("======================================\n");
	}
	 
}
	
	
void lulus (int nilai){
matkul *help;
int jumlah = 0;

help = kepala;
	
printf("\n Nilai Minimal :%d\n",nilai);
printf("==============Data Matkul Yang Tidak Lulus========");
	
	do{
		if(help->nilai < nilai){
			printf("======================================\n");
			printf(" Kode Matkul	: %s\n", help->kode);
			printf(" Nama Matkul	: %s\n", help->nama);
			printf(" Jumlah SKS		: %d\n", help->sks);
			printf(" Nilai 			: %d\n", help->nilai);
			printf("Tidak lulus !\n");
			printf("======================================\n");
			jumlah++;
		}
		help = help->lanjut;
	}while (help !=ekor->lanjut);
	
	 if (jumlah==0){
	 	printf("==============================\n");
	 	printf("Semua Matkul Lulus\n");
	 
	 }
}


void rata_rata(){
	matkul *help;
	int jumlah;
	int n;
	float rata;
	
	help = kepala;
	jumlah = 0;
	n = 0;
	do{
		jumlah = jumlah + help->nilai;
		n++;
		help = help->lanjut;
	}while(help!= ekor->lanjut);
	
		rata = jumlah/n;
		
		printf("========Rata-Rata========\n");
		printf("Jumlah Nilai	: %d\n",jumlah);
		printf("Jumlah Data	 	: %d\n",n);
		printf("Rata-Rata	 	: %.2f\n",rata);
		printf("=========================\n");
}


void reset(){
	matkul *help, *hapus;
	help = kepala;
	
	do {
		hapus = help;
		help = kepala ->lanjut;
		free(hapus);
	} while (help->lanjut!=kepala);
	
	kepala=NULL;
	ekor=NULL;
	printf ("Data Telah Terhapus\n");
}
void ceksks(int newsks){
if (newsks > 3){
	do{
		printf("Maaf Rentang Jumlah SKS salah\n");
		printf("Masukan Jumlah SKS MAX 3 : ");
		scanf("%d", &newsks);
		fflush(stdin);
	} while(newsks>3);
}
sks = newsks;
}
void cekkodekul(char *kode){
matkul *carii;

carii=kepala;

	if(isEmpty()==0){
		do{
			if(strcmp(carii->kode, kode)==0){
			do{
				printf("kode Kuliah Sudah ada \n");
				printf("Masukkan Kode Matkul : ");
				gets(kode);
			}while(strcmp(carii->kode, kode)==0);
	}
	carii = carii->lanjut;
}while(carii !=ekor);

	}
}
void cekminmax(int nilaii){
if (nilaii > 100){
	do{
		printf("input nilai salah, rentang nilai 1-100\n");
		printf("Masukkan Nilai Matkul: ");
		scanf("%d", &nilaii);
		fflush(stdin);
	}while(nilaii>100);
	nilai = nilaii;
}
}
void dels(char *poin){
	
matkul *del, *help;

help = kepala;

	do{
		if(strcmp(help->kode, poin)==0){
			del = help;
			
				if(help == kepala && kepala == ekor){
					kepala = NULL;
					ekor = NULL;
				}else if(help == kepala){
					kepala = kepala->lanjut;
					kepala->kembali = ekor;
					ekor->lanjut = kepala;
					free(del);
				}else if(help == ekor){
					ekor = ekor->kembali;
					ekor->lanjut = kepala;
					kepala->kembali = ekor;
					free(del);
				}else{
					help->kembali->lanjut = help->lanjut;
					help->lanjut->kembali = help->kembali;
					free(del);
				}
				printf("Data Dengan Kode Mata Kuliah %s Terhapus \n",poin);
				return;
			}
			help = help->lanjut;
		}while(help != ekor->lanjut);
	
	printf("Data Tidak Ditemukan %s\n", poin);
}

main(){
	init();
	
	int tidaklulus, menu;
	char kirim[5], del[10],cari[15],poin[20];
	
	do{
		
	printf("=====================MENU DATA MATAKULIAH==================\n");
	printf("Menu\n");
	printf("1. Menambahkan MataKuliah Di Belakang\n");
	printf("2. Menambahkan MataKuliah Di Depan\n");
	printf("3. Menghapus Data MataKuliah Di Depan\n");
	printf("4. Menghapus Data MataKuliah Di Belakang\n");
	printf("5. Menghapus Data MataKuliah Dengan Kode \n");
	printf("6. Mencari Dan Menampilkan Data MataKuliah \n");
	printf("7. Menampilkan Jumlah Data MataKuliah \n");
	printf("8. Menampilkan Semua Data\n");
	printf("9. Mencari Nilai Terbesar Dan Nilai Terkecil \n");
	printf("10.Menampilkan Daftar MataKuliah Yang Tidak Lulus\n");
	printf("11. Menampilkan Rata-Rata\n");
	printf("12. Reset\n");
	printf("13. Keluar\n");
	printf("============================================================\n");
	printf("Masukan Pilihan : ");
	scanf("%d",&menu);
	fflush(stdin);
	
	switch (menu){
		case 1 :{
			fflush(stdin);
			printf("===============TAMBAH DATA BELAKANG===========\n");
			
			printf("Masukan Data	: \n");
			printf("Kode Matkul		:	");
			gets(kode);
			fflush(stdin);
			cekkodekul(kode);
			
			
			printf("Nama Matkul	: ");
			gets(nama);
			fflush(stdin);
			
			printf("Jumlah sks Matkul MAX3	:");
			scanf("%d", &sks);
			fflush(stdin);
			ceksks(sks);
			
			
			printf("Masukan Nilai Matkul MAX100	:");
			scanf("%d",&nilai);
			fflush(stdin);
			cekminmax(nilai);
			
			DataBelakang (kode,nama,sks,nilai);
			break;
		}
		
		case 2: {
			fflush(stdin);
			printf("================TAMBAH DATA DEPAN===============\n");
			
			printf("Masukan Data	:\n");
			printf("Kode Matkul		:\n");
			gets(kode);
			fflush(stdin);
			cekkodekul(kode);
			
			
			printf("Nama Matkul	:");
			gets(nama);
			fflush(stdin);
			
			printf("Jumlah sks Matkul MAX3	:");
			scanf("%d", &sks);
			fflush(stdin);
			ceksks(sks);
			
			printf("Masukan Nilai Matkul MAX100	:");
			scanf("%d", &nilai);
			fflush(stdin);
			cekminmax(nilai);
			
			Datadepan (kode,nama,sks,nilai);
			break;
		}
		case 3 : {
			fflush (stdin);
			
			if (isEmpty()==1){
				printf("Maaf Tidak Tedapat Data\n");
			}else{
				printf("Apakah anda yakin menghapus data di depan? (y/t) : ");
				gets(kirim);
				fflush(stdin);
				if(strcmp(kirim, "y")==0){
					
					hapus_depan();
				}else{
					
					printf("Data gagal dihapus\n");
				}
			}
			
			break;
		}
		case 4:{
				fflush (stdin);
				
			if (isEmpty()==1){
				printf("Maaf Tidak Terdapat Data\n");
			}else{
					printf("Apakah anda yakin menghapus data di belakang (y/t) : ");
					gets(kirim);
					fflush(stdin);
					if(strcmp(kirim,"y")==0){
						
						hapus_belakang();
					}else{
						
						printf("Data gagal dihapus!\n");
				}
			}
			
			break;
		}
		case 5:{
				fflush(stdin);
				
			if (isEmpty()==1){
				printf("Maaf Tidak Terdapat Data\n");
			}else{
					printf("Masukan Kode Mata Kuliah : ");
					gets(del);
					printf("Apakah anda yakin akan menghapus Data? : ");
					gets(kirim);
					fflush(stdin);
					if(strcmp(kirim, "y")==0){
					dels(del);
					}else{
						
						printf("Data gagal dihapus!\n");
				}
			}
			break;
		}
		case 6 :{
			printf("Masukan Kode Mata Kuliah: ");
			gets(cari);
			fflush(stdin);
			cariData(cari);
			break;
		}
		case 7 :{
			fflush(stdin);
			menampilkan_jumlah();
			break;
		}
		case 8 :{
			fflush(stdin);
			menampilkan_semua();
			break;
		}
		case 9 :{
			fflush(stdin);
			nilaiminmax();
			break;
		}
		case 10:{
			fflush(stdin);
			if (isEmpty()==1){
				printf ("Data Matakuliah Kosong\n");
			}else{
				printf("Data Matkul Tidak Lulus\n");
				printf("Masukkan Batas Nilai : ");
				scanf("%d", &nilai);
				fflush(stdin);
				lulus(nilai);
			}
			
			
			
			break;
		}
		case 11 :{
			fflush(stdin);
			rata_rata();
			break;
		}
		case 12 :{
			fflush(stdin);
			
			if (isEmpty()==1){
				printf("Maaf Tidak Terdapat Data\n");
			}else{
				
					printf("apakah anda yakin akan merest data? (y/t) : ");
					gets(kirim);
					fflush(stdin);
					if(strcmp(kirim, "y")==0){
						
						reset();
					}else{
						
						printf("Data gagal dihapus!\n");
					}
			
			}break;
		}
		
		case 13:{
			printf("Terima kasih telah menggunakan program ini!\n");
			exit;
			break;
		}
	
			default:{
				printf("maaf inputan tidak sesuai! \n");
				break;
			}
		}	
	}while(menu != 13);
}
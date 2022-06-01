#include <iostream>

using namespace std;

//struktur linked list

struct DataMahasiswa{
    String NamaMahasiswa;
    int KodeMatkul,NamaMatkul,Sks,Nilai;

    //pointer 
    DataMahasiswa *prev;
    DataMahasiswa *next;
};

DataMahasiswa *head , *tail, *cur, *del, *newNode, *afterNode;

//fungsi membuat circular double linkedlist
void createDataMahasiswa ( String NamMahas, int kode, int matkul, int Jumsks, int nilaimatkul) {

    head = new DataMahasiswa();
    head->NamaMahasiswa = NamMahas;
    head->KodeMatkul = kode;
    head->NamaMatkul = matkul;
    head->Sks = Jumsks;
    head->Nilai = nilaimatkul;
    head->prev = head;
    head->next = head;
    tail = head;
}

//fungsi print
void printDataMahasiswa(){

    if (head = NULL ){
        cout<<" Buat Data LinkedList Dahulu "<< endl;
    }else{
    cout<< " =================== Data Mahasiswa===========" << endl;
    cur = head;
    while ( cur->next !=head ){
        //print
        cout<< " Nama Mahasiswa " << cur->NaMahas << endl;
        cout<< " Kode Matkul " << cur->KodeMatkul << endl;
        cout<< " Nama Matkul " << cur->NamaMatkul << endl;
        cout<< " Jumlah SKS MAX 3 " << cur->Jumsks << endl;
        cout<< " Nilai Matkul " << cur->nilaimatkul << endl;
        }
    }
}

int main (){

    createDataMahasiswa("Maul", 15, SBD, 2, 100);
    printDataMahasiswa();
}
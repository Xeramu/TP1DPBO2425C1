//manggil library
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//manggil file kelas
#include "TokoElektronik.cpp"

void menu(){
    cout << "== Menu Toko Elektronik el Angjay == " << endl;
    cout << "1. Create" << endl;
    cout << "2. Read" << endl;
    cout << "3. Update" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Nyari barang berdasarkan kode" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu: ";
}

//fungsi buat nyari kode barang dalam list
//for loop ke smua barang yg ada dalem vector trus dimatching sama input kode yang dicari
int carikode(vector<TokoElektronik>& daftarBarang, string kode){
    for(int i = 0; i < daftarBarang.size(); i++){
        if(daftarBarang[i].getKodebarang() == kode){
            return i;//klo nemu, return index
        }
    }
    return -1;//klo engga nemu, return -1
}

int main(){

    //bikin list yang dnimais pake vector
    vector<TokoElektronik> daftarBarang;
    int pilihan;

    //looping selalu jalan sebelum user input pilihan 6, alias buat kluwar program
    do{
        //manggil fungsi nampilin menu
        menu();

        //minta input pilihan
        cin >> pilihan;

        if(pilihan == 1){
            //CREATE
            //minta inputan user
            string nama, kode;
            int stok, harga;
            cout << "Masukkan Nama Barang: ";
            //biar getline engga lnsgng keskip
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan Kode Barang: ";
            getline(cin, kode);
            cout << "Masukkan Stok: ";
            cin >> stok;
            cout << "Masukkan Harga: ";
            cin >> harga;

            //lngsng masukin barang baru ke vectorr
            daftarBarang.push_back(TokoElektronik(nama, kode, stok, harga));
            cout << "Barang berhasil ditambahkan!\n" << endl;
        }
        else if(pilihan == 2){
            //READ
            cout << "\n== Daftar Barang Toko Elektronik el Angjay ==" << endl;
            //for looping smua barang yg ada dlm vector dari pertama sampai akhir trus ditampilin pake getter
            for(int i = 0; i < daftarBarang.size(); i++){
                cout << i+1 << ". " << daftarBarang[i].getNamabarang() << " | " << daftarBarang[i].getKodebarang() << " | " << daftarBarang[i].getStok() << " | " << daftarBarang[i].getHarga() << endl;
            }
            cout << "\n";

            //klo blm ada isinya, kode bakal ngeprint enih
            if(daftarBarang.empty()){
                cout << "Belum ada barang beb\n" << endl;
            }

        }
        else if(pilihan == 3){
            //UPDATE
            string kode;
            cout << "Masukkin kode barang yang mau diupdate: ";
            //minta input user
            cin.ignore();
            getline(cin, kode);

            int idx = carikode(daftarBarang, kode);
            //klo nemu kodenya, lgsng bisa update
            if(idx != -1){
                //minta input user buwat update
                string namaBaru;
                int stokBaru, hargaBaru;
                cout << "Masukkan nama baru: ";
                getline(cin, namaBaru);
                cout << "Masukkan stok baru: ";
                cin >> stokBaru;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru;

                //ngupdate pake setter
                daftarBarang[idx].setNamabarang(namaBaru);
                daftarBarang[idx].setStok(stokBaru);
                daftarBarang[idx].setHarga(hargaBaru);

                cout << "Barang berhasil diupdate!\n" << endl;
            }
            //klo engga nemu, bakal print enih
            else{
                cout << "Engga nemu barang dengan kode: " << kode << " bang\n" << endl;
            }

        }
        else if(pilihan == 4){
            //DELETE
            //minta input user pake kode yg mau diapus
            string kode;
            cout << "Masukkan kode barang yang mau dihapus: ";
            cin.ignore();
            getline(cin, kode);

            //klo nemu kodenya, barang dengan kode itu diapus
            int idx = carikode(daftarBarang, kode);
            if(idx != -1){
                daftarBarang.erase(daftarBarang.begin() + idx);
                cout << "Barang berhasil dihapus!\n" << endl;
            } 
            //klo engga nemy, print enih
            else{
                cout << "Barang dengan kode " << kode << " tidak ditemukan!\n" << endl;
            }

        }
        else if(pilihan == 5){
            //SEARCH
            //minta inputan user
            string kode;
            cout << "Masukkan kode barang yang dicari: ";
            cin.ignore();
            getline(cin, kode);

            int idx = carikode(daftarBarang, kode);
            //klo nemu, print barang ditemukan
            if(idx != -1){
                cout << "Barang ditemukan: " << daftarBarang[idx].getNamabarang() << " | " << daftarBarang[idx].getKodebarang() << " | " << daftarBarang[idx].getStok() << " | " << daftarBarang[idx].getHarga() << "\n" << endl;
            }
            //klo engga nemu, print enih
            else{
                cout << "Barang dengan kode " << kode << " tidak ditemukan!\n" << endl;
            }

        }
        //pilihan buat kluwar program. ntar print pesan pamit
        else if(pilihan == 6){
            cout << "Bye bye. Maacih :P\n" << endl;
        }
        //klo pilihan yg dimasukkan bkn 1-6, bakal print enih
        else{
            cout << "Pilihan tidak valid!\n" << endl;
        }

    }while (pilihan != 6);

    return 0;
}
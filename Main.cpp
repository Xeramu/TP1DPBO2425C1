//manggil library
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//manggil file kelas
#include "TokoElektronik.cpp"

int main(){

    //CREATE bbrp objek
    //bikin list yang dnimais pake vector buat masukin objek
    vector<TokoElektronik> daftarBarang;

    //masukin objek baru kedalam list
    daftarBarang.push_back(TokoElektronik("Kabel", "001", 5, 15000));
    daftarBarang.push_back(TokoElektronik("Lampu", "002", 10, 5000));
    daftarBarang.push_back(TokoElektronik("Kulkas", "003", 3, 5000000));
    daftarBarang.push_back(TokoElektronik("Mesin Cuci", "004", 2, 1200000));

    //READ isi atribut pake getter
    cout << "== Daftar Barang Toko Elektronik el Angjay == " << endl;
    for (int i = 0; i < daftarBarang.size(); i++) {
        cout << "Barang ke-" << i+1 << ": " << daftarBarang[i].getNamabarang() << " | " << daftarBarang[i].getKodebarang() << " | " << daftarBarang[i].getStok() << " | " << daftarBarang[i].getHarga() << endl;
    }
    cout << "\n";

    //UPDATE isi atribut menggunakan setter
    daftarBarang[1].setNamabarang("Stop Kontak");
    cout << "== Setelah UPDATE ==" << endl;
    for (int i = 0; i < daftarBarang.size(); i++) {
        cout << "Barang ke-" << i+1 << ": " << daftarBarang[i].getNamabarang() << " | " << daftarBarang[i].getKodebarang() << " | " << daftarBarang[i].getStok() << " | " << daftarBarang[i].getHarga() << endl;
    }
    cout << "\n";

    //DELETE isi atribut
    daftarBarang.erase(daftarBarang.begin() + 3);
    cout << "== Setelah DELETE ==" << endl;
    for (int i = 0; i < daftarBarang.size(); i++) {
        cout << "Barang ke-" << i+1 << ": " << daftarBarang[i].getNamabarang() << " | " << daftarBarang[i].getKodebarang() << " | " << daftarBarang[i].getStok() << " | " << daftarBarang[i].getHarga() << endl;
    }

    return 0;
}
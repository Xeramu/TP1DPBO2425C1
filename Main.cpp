#include <string>
#include <iostream>
using namespace std;
#include "TokoElektronik.cpp"

int main(){

    //buat bbrp objek buat demo
    TokoElektronik s1 = TokoElektronik("Kabel", "001", "5", "15000");
    TokoElektronik s2 = TokoElektronik("Lampu", "002", "10", "5000");

    //akses atribut nama pake getter
    cout << "Barang s1: " << s1.getNamabarang() << " | " << s1.getKodebarang() << " | " << s1.getStok()  << " | " << s1.getHarga() << endl;
    cout << "Barang s2: " << s2.getNamabarang() << " | " << s2.getKodebarang() << " | " << s2.getStok()  << " | " << s2.getHarga() << endl;

    s1.setNamabarang("Stop Kontak");
    cout << "Barang s1 setelah setNamabarang: " << s1.getNamabarang() << " | " << s1.getKodebarang() << " | " << s1.getStok()  << " | " << s1.getHarga() << endl;
    return 0;
}
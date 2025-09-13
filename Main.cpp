#include <string>
#include <iostream>
using namespace std;
#include "TokoElektronik.cpp"

int main(){

    //buat bbrp objek buat demo
    TokoElektronik s1 = TokoElektronik("Kabel");
    TokoElektronik s2 = TokoElektronik("Lampu");

    //akses atribut nama pake getter
    cout << "Nama s1: " << s1.getNamabarang() << endl;
    cout << "Nama s2: " << s2.getNamabarang() << endl;

    s1.setNamabarang("Kabel LAN");
    cout << "Nama s1 setelah setNamabarang: " << s1.getNamabarang() << endl;
    return 0;
}
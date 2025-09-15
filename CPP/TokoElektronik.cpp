#include <string>
#include <iostream>
using namespace std;

class TokoElektronik {

    //atribut pakenya private
    private:
        string namabarang;
        string kodebarang;
        int stok;
        int harga; 
    
    //method yang bersifat public
    public:

        //constructor untuk inisiasi atribut
        TokoElektronik(string namabarang, string kodebarang, int stok, int harga){
            this->namabarang = namabarang;
            this->kodebarang = kodebarang;
            this->stok = stok;
            this->harga = harga;
        }

        //getter untuk ngakses atau READ atribut namabarang
        string getNamabarang(){
            return namabarang;
        }

        //setter untuk ngubah atau UPDATE atribut namabarang
        void setNamabarang(string namabarang){
            this->namabarang = namabarang;
        }

        //getter untuk ngakses atau READ atribut kodebarang
        string getKodebarang(){
            return kodebarang;
        }

        //setter untuk ngubah atau UPDATE atribut kodebarang
        void setKodebarang(string kodebarang){
            this->kodebarang = kodebarang;
        }

        //getter untuk ngakses atau READ atribut stok
        int getStok(){
            return stok;
        }

        //setter untuk ngubah atau UPDATE atribut stok
        void setStok(int stok){
            this->stok = stok;
        }

        //getter untuk ngakses atau READ atribut harga
        int getHarga(){
            return harga;
        }

        //setter untuk ngubah atau UPDATE atribut harga
        void setHarga(int harga){
            this->harga = harga;
        }

        //destruktor
        ~TokoElektronik(){ }
};
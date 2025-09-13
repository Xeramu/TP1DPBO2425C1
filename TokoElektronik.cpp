#include <string>
#include <iostream>
using namespace std;

class TokoElektronik {

    //atribut bersifat ketroprak rahasia (engga dikasih tahu)
    private:
        string namabarang;
        string kodebarang;
        string stok;
        string harga; 
    
    //method yang bersifat public
    public:

        //constructor untuk inisiasi atribut
        TokoElektronik(string namabarang, string kodebarang, string stok, string harga){
            this->namabarang = namabarang;
            this->kodebarang = kodebarang;
            this->stok = stok;
            this->harga = harga;
        }

        //getter untuk ngakses atribut namabarang
        string getNamabarang(){
            return namabarang;
        }

        //setter untuk ngubah atribut namabarang
        void setNamabarang(string namabarang){
            this->namabarang = namabarang;
        }

        //getter untuk ngakses atribut kodebarang
        string getKodebarang(){
            return kodebarang;
        }

        //setter untuk ngubah atribut kodebarang
        void setKodebarang(string kodebarang){
            this->kodebarang = kodebarang;
        }

         //getter untuk ngakses atribut stok
        string getStok(){
            return stok;
        }

        //setter untuk ngubah atribut stok
        void setStok(string stok){
            this->stok = stok;
        }

        //getter untuk ngakses atribut harga
        string getHarga(){
            return harga;
        }

        //setter untuk ngubah atribut harga
        void setHarga(string harga){
            this->harga = harga;
        }

        //destruktor
        ~TokoElektronik(){ }
};
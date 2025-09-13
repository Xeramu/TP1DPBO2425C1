#include <string>
#include <iostream>
using namespace std;

class TokoElektronik {

    //atribut bersifat ketroprak rahasia (engga dikasih tahu)
    private:
        string namabarang;
        /*
        string kodebarang;
        int stok;
        string harga; 
        */
    
    //method yang bersifat public
    public:

        //constructor untuk inisiasi atribut
        TokoElektronik(string namabarang /*, string kodebarang, int stok, string harga*/){
            this->namabarang = namabarang;
            /*
            this->kodebarang = kodebarang;
            this->stok = stok;
            this->harga;
            */
        }

        //getter untuk ngakses atribut
        string getNamabarang(){
            return namabarang;
        }

        //setter untuk ngubah atribut
        void setNamabarang(string namabarang){
            this->namabarang = namabarang;
        }

        //destruktor
        ~TokoElektronik(){ }
};
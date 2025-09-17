public class TokoElektronik {

    //atributnya private
    private String namabarang;
    private String kodebarang;
    private int stok;
    private int harga;

    //constructoir
    public TokoElektronik(String namabarang, String kodebarang, int stok, int harga){
        this.namabarang = namabarang;
        this.kodebarang = kodebarang;
        this.stok = stok;
        this.harga = harga;
    }

    //getter nama
    public String getNamabarang() {
        return namabarang;
    }

    //setter nama
    public void setNamabarang(String namabarang) {
        this.namabarang = namabarang;
    }

    //getter kode
    public String getKodebarang() {
        return kodebarang;
    }

    //setter kode
    public void setKodebarang(String kodebarang) {
        this.kodebarang = kodebarang;
    }

    //getter stok
    public int getStok() {
        return stok;
    }

    //setter stok
    public void setStok(int stok) {
        this.stok = stok;
    }

    //getter harga
    public int getHarga() {
        return harga;
    }

    //setter harga
    public void setHarga(int harga) {
        this.harga = harga;
    }
}
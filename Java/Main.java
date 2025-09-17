import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    //fungsi nyari kodebarang pake index
    //looping ke smua isi list trus di matching. klo nemu balikin posisi index
    public static int cariIndexByKode(ArrayList<TokoElektronik> daftarBarang, String kode) {
        for (int i = 0; i < daftarBarang.size(); i++) {
            if (daftarBarang.get(i).getKodebarang().equals(kode)) {
                return i;
            }
        }
        return -1; //klo engga nemu, balikin -1
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<TokoElektronik> daftarBarang = new ArrayList<>();
        int pilihan;

        //loop do while. selama input user bkn 6, prog ttp jalans
        do {
            System.out.println("\n== Menu Toko Elektronik el Angjay ==");
            System.out.println("1. CREATE");
            System.out.println("2. READ");
            System.out.println("3. UPDATE");
            System.out.println("4. DELETE");
            System.out.println("5. SEARCH");
            System.out.println("6. EXIT");
            System.out.print("Pilih menu: ");
            pilihan = sc.nextInt();
            sc.nextLine();//buat buang newline

            if (pilihan == 1) {
                //CREATE
                //user masukin nama, kode, stok, harga
                System.out.print("Masukkan Nama Barang: ");
                String nama = sc.nextLine();
                System.out.print("Masukkan Kode Barang: ");
                String kode = sc.nextLine();
                System.out.print("Masukkan Stok: ");
                int stok = sc.nextInt();
                System.out.print("Masukkan Harga: ");
                int harga = sc.nextInt();
                sc.nextLine();

                //trus data dimasukin ke list
                daftarBarang.add(new TokoElektronik(nama, kode, stok, harga));
                //trus print pesan berhasil
                System.out.println("Barang berhasil ditambahkan!");

            } else if (pilihan == 2) {
                //READ
                System.out.println("\n== Daftar Barang Toko Elektronik el Angjay ==");

                //ngecek dlu ada engga isi listnya
                if (daftarBarang.isEmpty()) {
                    //klo engga ada, print pesan engga ada
                    System.out.println("Belum ada data barang.");
                } else {

                    //klo ada print smua barang yg ada dilist pake for lopp
                    for (int i = 0; i < daftarBarang.size(); i++) {
                        TokoElektronik b = daftarBarang.get(i);
                        System.out.println((i + 1) + ". " + b.getNamabarang() + " | " + b.getKodebarang() + " | " + b.getStok() + " | " + b.getHarga()
                        );
                    }
                }

            } else if (pilihan == 3) {
                //UPDATE
                //user input kode barang yg mau diubah
                System.out.print("Masukkan kode barang yang mau diupdate: ");
                String kode = sc.nextLine();

                //nyari posisi barang pake fungsi nyari index
                int idx = cariIndexByKode(daftarBarang, kode);

                //klo nemu, user lgsng isi data baru
                if (idx != -1) {
                    System.out.print("Masukkan Nama Baru: ");
                    String namaBaru = sc.nextLine();
                    System.out.print("Masukkan Stok Baru: ");
                    int stokBaru = sc.nextInt();
                    System.out.print("Masukkan Harga Baru: ");
                    int hargaBaru = sc.nextInt();
                    sc.nextLine();

                    //updatenya pake stter
                    daftarBarang.get(idx).setNamabarang(namaBaru);
                    daftarBarang.get(idx).setStok(stokBaru);
                    daftarBarang.get(idx).setHarga(hargaBaru);

                    //print pesan berhasil
                    System.out.println("Barang berhasil diupdate!");
                } else {
                    //klo engga nemu kodenya, bakal print pesan errior
                    System.out.println("Barang dengan kode " + kode + " tidak ditemukan!");
                }

            } else if (pilihan == 4) {
                //DELETE
                //user input kode barang yg mau diapus
                System.out.print("Masukkan kode barang yang mau dihapus: ");
                String kode = sc.nextLine();

                //nyari posisi barang pake fungsi nyari index
                int idx = cariIndexByKode(daftarBarang, kode);

                //klo nemu, hps barang dr list
                if (idx != -1) {
                    daftarBarang.remove(idx);
                    System.out.println("Barang berhasil dihapus!");
                } else {
                    //klo engga nemu, print pesan error
                    System.out.println("Barang dengan kode " + kode + " tidak ditemukan!");
                }

            } else if (pilihan == 5) {
                //SEARCH
                //user input kode barang yg mau dicari
                System.out.print("Masukkan kode barang yang dicari: ");
                String kode = sc.nextLine();
                
                //nyari posisi barang pake fungsi nyari index
                int idx = cariIndexByKode(daftarBarang, kode);

                //klo nemu, print barang yg yg kodenya match
                if (idx != -1) {
                    TokoElektronik b = daftarBarang.get(idx);
                    System.out.println("Barang ditemukan: " + b.getNamabarang() + " | " + b.getKodebarang() + " | " + b.getStok() + " | " + b.getHarga()
                    );
                } else {
                    //klo engga nemu, print pesan eeorr
                    System.out.println("Barang dengan kode " + kode + " tidak ditemukan!");
                }
            }

        } while (pilihan != 6);
        //klo input user 6, print pesan, trus kluar program
        System.out.println("Bye bye. maacih :P");
        sc.close();
    }
}

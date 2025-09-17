import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    // Fungsi cari index by kode
    public static int cariIndexByKode(ArrayList<TokoElektronik> daftarBarang, String kode) {
        for (int i = 0; i < daftarBarang.size(); i++) {
            if (daftarBarang.get(i).getKodebarang().equals(kode)) {
                return i;
            }
        }
        return -1; // tidak ketemu
    }

    public static void main(String[] args) {
        ArrayList<TokoElektronik> daftarBarang = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int pilihan;
        
        do {
            System.out.println("== Menu Toko Elektronik el Angjay ==");
            System.out.println("1. Create");
            System.out.println("2. Read");
            System.out.println("3. Update");
            System.out.println("4. Delete");
            System.out.println("5. Search");
            System.out.println("6. Exit");
            System.out.print("Pilih menu: ");
            pilihan = sc.nextInt();

            if (pilihan == 1) {
                // CREATE
                System.out.print("Masukkan Nama Barang: ");
                String nama = sc.nextLine();
                System.out.print("Masukkan Kode Barang: ");
                String kode = sc.nextLine();
                System.out.print("Masukkan Stok: ");
                int stok = sc.nextInt();
                System.out.print("Masukkan Harga: ");
                int harga = sc.nextInt();
                sc.nextLine();

                daftarBarang.add(new TokoElektronik(nama, kode, stok, harga));
                System.out.println("Barang berhasil ditambahkan!");

            } else if (pilihan == 2) {
                // READ
                System.out.println("\n== Daftar Barang ==");
                if (daftarBarang.isEmpty()) {
                    System.out.println("Belum ada data barang.");
                } else {
                    for (int i = 0; i < daftarBarang.size(); i++) {
                        TokoElektronik b = daftarBarang.get(i);
                        System.out.println((i + 1) + ". " +
                            b.getNamabarang() + " | " +
                            b.getKodebarang() + " | " +
                            b.getStok() + " | " +
                            b.getHarga()
                        );
                    }
                }

            } else if (pilihan == 3) {
                // UPDATE
                System.out.print("Masukkan kode barang yang mau diupdate: ");
                String kode = sc.nextLine();
                int idx = cariIndexByKode(daftarBarang, kode);

                if (idx != -1) {
                    System.out.print("Masukkan Nama Baru: ");
                    String namaBaru = sc.nextLine();
                    System.out.print("Masukkan Stok Baru: ");
                    int stokBaru = sc.nextInt();
                    System.out.print("Masukkan Harga Baru: ");
                    int hargaBaru = sc.nextInt();
                    sc.nextLine();

                    daftarBarang.get(idx).setNamabarang(namaBaru);
                    daftarBarang.get(idx).setStok(stokBaru);
                    daftarBarang.get(idx).setHarga(hargaBaru);

                    System.out.println("Barang berhasil diupdate!");
                } else {
                    System.out.println("Barang dengan kode " + kode + " tidak ditemukan!");
                }

            } else if (pilihan == 4) {
                // DELETE
                System.out.print("Masukkan kode barang yang mau dihapus: ");
                String kode = sc.nextLine();
                int idx = cariIndexByKode(daftarBarang, kode);

                if (idx != -1) {
                    daftarBarang.remove(idx);
                    System.out.println("Barang berhasil dihapus!");
                } else {
                    System.out.println("Barang dengan kode " + kode + " tidak ditemukan!");
                }

            } else if (pilihan == 5) {
                // SEARCH
                System.out.print("Masukkan kode barang yang dicari: ");
                String kode = sc.nextLine();
                int idx = cariIndexByKode(daftarBarang, kode);

                if (idx != -1) {
                    TokoElektronik b = daftarBarang.get(idx);
                    System.out.println("Barang ditemukan: " +
                        b.getNamabarang() + " | " +
                        b.getKodebarang() + " | " +
                        b.getStok() + " | " +
                        b.getHarga()
                    );
                } else {
                    System.out.println("Barang dengan kode " + kode + " tidak ditemukan!");
                }
            }
        } while (pilihan != 6);
        System.out.println("Bye bye. Maacih :P\n");

        sc.close();
    }

}
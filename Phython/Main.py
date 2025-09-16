from TokoElektronik import TokoElektronik

def main():

    # list koshong buat nyimpen objek
    daftarBarang = []

    # looping, sebelum user input 6, kodenya msh jalan
    while True:

        #nampilin menu
        print("== Menu Toko Elektronik el Angjay ==")
        print("1. Create")
        print("2. Read")
        print("3. Update")
        print("4. Delete")
        print("5. Search")
        print("6. Exit")
        print()  

        #minta masukan user
        pilihan = int(input("Masukkan pilihan: "))

        #CREATE
        if pilihan == 1:
            #user masukin data baru
            nama = input("Masukkan Nama Barang: ")
            kode = input("Masukkan Kode Barang: ")
            stok = int(input("Masukkan Stok: "))
            harga = int(input("Masukkan Harga: "))

            #objek dibikin lalu dimasukan kedalam daftarbarang
            daftarBarang.append(TokoElektronik(nama, kode, stok, harga))

            #print pesan
            print("Barang berhasil ditambahkan!\n")

        #READ
        elif pilihan == 2:

            #kalau daftarbarang kosong, print pesan
            if not daftarBarang:
                print("Daftar barang kosong.\n")
            else:

                #kalau daftarbarang ada isinya, for loop ke smua barang trus ditampilin pake getter
                print("== Daftar Barang Toko Elektronik el Angjay ==")
                for i, barang in enumerate(daftarBarang, start=1):
                    print(f"{i}. {barang.getNamabarang()} | {barang.getKodebarang()} | {barang.getStok()} | {barang.getHarga()}")
                print()  

        #UPDATE
        elif pilihan == 3:

            #user input kode barang yang mau diubah
            kode = input("Masukkan kode barang yang mau diupdate: ")

            #progrm nyari indeks barang dilist
            idx = next((i for i, b in enumerate(daftarBarang) if b.getKodebarang() == kode), -1)
            if idx != -1:

                #kalau nemu, bisa lgsng update barangnya pake setter
                nama = input("Masukkan nama baru: ")
                stok = int(input("Masukkan stok baru: "))
                harga = int(input("Masukkan harga baru: "))
                daftarBarang[idx].setNamabarang(nama)
                daftarBarang[idx].setStok(stok)
                daftarBarang[idx].setHarga(harga)

                #print pesan
                print("Barang berhasil diupdate!\n")
            else:

                #klo engga nemu, tampil pesan engga nemu
                print(f"Barang dengan kode {kode} tidak ditemukan.\n")

        #DELETE
        elif pilihan == 4:

            #user input kode barang yang mau diapus
            kode = input("Masukkan kode barang yang mau dihapus: ")

            #progrm nyari indeks barang dilist
            idx = next((i for i, b in enumerate(daftarBarang) if b.getKodebarang() == kode), -1)
            if idx != -1:

                #klo nemu, barang diapus
                daftarBarang.pop(idx)

                #print pesan
                print("Barang berhasil dihapus!\n")
            else:

                #klo engga nemu, print pesan engga namu
                print(f"Barang dengan kode {kode} tidak ditemukan.\n")

        #SEARCH
        elif pilihan == 5:

            #user input kode barang yang mau dicaro
            kode = input("Masukkan kode barang yang dicari: ")

            #program jdnya ngecek kedalam isi list, nyari yg kodenya match
            barang = next((b for b in daftarBarang if b.getKodebarang() == kode), None)
            if barang:

                #klo nemu, barangnya diprint
                print(f"Barang ditemukan: {barang.getNamabarang()} | {barang.getKodebarang()} | {barang.getStok()} | {barang.getHarga()}")
                print()  
            else:

                #klo engga nemu, print pesan engga nemu
                print(f"Barang dengan kode {kode} tidak ditemukan.\n")

        #EXIT
        #klo user masukin 6, bakal print pesan trus kluar program pake break
        elif pilihan == 6:
            print("Bye bye. Maacih :P\n")
            break
        else:

            #klo engga ada pilihannya, program print pesan error
            print("pilihan tidak validd\n")

if __name__ == "__main__":
    main()
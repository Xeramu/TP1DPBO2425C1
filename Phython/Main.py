from TokoElektronik import TokoElektronik

def main():

    # buat 2 objek demo
    s1 = TokoElektronik("Kabel", "001", 2, 500)
    s2 = TokoElektronik("Stop Kontak", "002", 3, 600)

    print("s1:", s1.getNamabarang(), s1.getKodebarang(), s1.getStok(), s1.getHarga())
    print("s2:", s2.getNamabarang(), s2.getKodebarang(), s2.getStok(), s2.getHarga())

    s1.setNamabarang("Budi Santoso")
    print("Nama s1 setela setNama:", s1.getNamabarang(), s1.getKodebarang(), s1.getStok(), s1.getHarga())

    # looping, sebelum user input 6, kodenya msh jalan
    while True:
        pilihan = int(input("Masukkan pilihan: "))
        if pilihan == 1:
            print("CREATE")
        elif pilihan == 2:
            print("READ")
        elif pilihan == 3:
            print("UPDATE")
        elif pilihan == 4:
            print("DELETE")
        elif pilihan == 5:
            print("SEARCH")
        elif pilihan == 6:
            break
        else:
            print("pilihan tidak validd")

if __name__ == "__main__":
    main()
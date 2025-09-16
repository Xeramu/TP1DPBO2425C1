class TokoElektronik:
    
    # constructor untuk inisialisasi atribut nama dan umur
    def __init__(self, namabarang: str, kodebarang: str, stok: int, harga: int):
        self._namabarang = str(namabarang) #underscore 1 unutk private
        self._kodebarang = str(kodebarang) #underscore 1 untuk private
        self._stok = int(stok) #underscore 1 untuk private
        self._harga = int(harga) #underscore 1 untuk private

    # getter buat atibut nama barang    
    def getNamabarang(self) -> str:
        return self._namabarang
        
    # setter buat atribut nama barang
    def setNamabarang(self, namabarang: str) -> None:
        self._namabarang = str(namabarang)

    # getter buat atibut kode barang    
    def getKodebarang(self) -> str:
        return self._kodebarang

    # setter buat atribut kode barang
    def setKodebarang(self, kodebarang: str) -> None:
        self._kodebarang = str(kodebarang)

    # getter buat atibut stok    
    def getStok(self) -> int:
        return self._stok

    # setter buat atribut stok
    def setStok(self, stok: int) -> None:
        self._stok = int(stok)
    
    # getter buat atibut harga    
    def getHarga(self) -> int:
        return self._harga

    # setter buat atribut harga
    def setHarga(self, harga: int) -> None:
        self._harga = int(harga)
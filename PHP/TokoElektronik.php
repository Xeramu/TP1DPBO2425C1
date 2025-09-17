<?php
class TokoElektronik {

    private string $namabarang;
    private string $kodebarang;
    private int $stok;
    private int $harga;
    private string $gambar; //path file gambar lokal

    public function __construct(string $namabarang, string $kodebarang, int $stok, int $harga, string $gambar) {
        $this->namabarang = $namabarang;
        $this->kodebarang = $kodebarang;
        $this->setStok($stok);
        $this->setHarga($harga);
        $this->gambar = $gambar;
    }

    public function getNamabarang(): string { 
        return $this->namabarang; 
    }
    public function setNamabarang(string $namabarang): void { 
        $this->namabarang = $namabarang; 
    }

    public function getKodebarang(): string { 
        return $this->kodebarang; 
    }
    public function setKodebarang(string $kodebarang): void { 
        $this->kodebarang = $kodebarang; 
    }

    public function getStok(): int { 
        return $this->stok;
     }
    public function setStok(int $stok): void { 
        $this->stok = ($stok < 0) ? 0 : $stok; 
    }

    public function getHarga(): int { 
        return $this->harga; 
    }
    public function setHarga(int $harga): void { 
        $this->harga = ($harga < 0) ? 0 : $harga; 
    }

    public function getGambar(): string { 
        return $this->gambar;
     }
    public function setGambar(string $gambar): void { 
        $this->gambar = $gambar; 
    }
}

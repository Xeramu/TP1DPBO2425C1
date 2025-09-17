<?php

class TokoElektronik{

    //atribut private
    private string $namabarang;
    private string $kodebarang;
    private int $stok;
    private int $harga;

    //contrsctor untuk inisiai atribut awal
    public function __construct(string $namabarang, string $kodebarang, int $stok, int $harga) {
        $this->namabarang = $namabarang;
        $this->kodebarang = $kodebarang;
        $this->setStok($stok);
        $this->setHarga($harga);
    }

    //getter & setter nama barang
    public function getNamabarang(): string {
        return $this->namabarang;
    }

    public function setNamabarang(string $namabarang): void {
        $this->namabarang = $namabarang;
    }

    //getter & setter kode barang
    public function getKodebarang(): string {
        return $this->kodebarang;
    }

    public function setKodebarang(string $kodebarang): void {
        $this->kodebarang = $kodebarang;
    }

    //getter & setter stok
    public function getStok(): int {
        return $this->stok;
    }

    public function setStok(int $stok): void {
        if ($stok < 0) {
            $this->stok = 0; // biar stok ga minus
        } else {
            $this->stok = $stok;
        }
    }

    //getter & setter harga
    public function getHarga(): int {
        return $this->harga;
    }

    public function setHarga(int $harga): void {
        if ($harga < 0) {
            $this->harga = 0; // biar harga ga minus
        } else {
            $this->harga = $harga;
        }
    }
}
<?php

//ambil library
require_once __DIR__ . '/TokoElektronik.php';

//buat objek demo
$s1 = new TokoElektronik('Kabel', '001', 3, 4000);
$s2 = new TokoElektronik('Lampu', '002', 4, 5000);

echo "Barang s1: " . $s1->getNamabarang() . " | " . $s1->getKodebarang() . " | " . $s1->getStok() . " | " . $s1->getHarga();
echo "Barang s2: " . $s2->getNamabarang() . " | " . $s2->getKodebarang() . " | " . $s2->getStok() . " | " . $s2->getHarga();

$s1->setNamabarang('Kulkas');
echo "Barang s1: " . $s1->getNamabarang() . " | " . $s1->getKodebarang() . " | " . $s1->getStok() . " | " . $s1->getHarga();
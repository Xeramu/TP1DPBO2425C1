<?php
require_once __DIR__ . '/TokoElektronik.php';
session_start();

// inisialisasi daftarBarang di session
if (!isset($_SESSION['daftarBarang'])) {
    $_SESSION['daftarBarang'] = [];
}

// CREATE
if (isset($_POST['tambah'])) {
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $stok = intval($_POST['stok']);
    $harga = intval($_POST['harga']);
    $gambar = "img/" . $_FILES['gambar']['name'];

    move_uploaded_file($_FILES['gambar']['tmp_name'], $gambar);

    $barang = new TokoElektronik($nama, $kode, $stok, $harga, $gambar);
    $_SESSION['daftarBarang'][] = $barang;
}

// DELETE
if (isset($_GET['hapus'])) {
    $idx = intval($_GET['hapus']);
    unset($_SESSION['daftarBarang'][$idx]);
    $_SESSION['daftarBarang'] = array_values($_SESSION['daftarBarang']); // reindex array
}

// UPDATE - tampilkan form edit
$editMode = false;
$editIndex = -1;
$editBarang = null;

if (isset($_GET['edit'])) {
    $editIndex = intval($_GET['edit']);
    if (isset($_SESSION['daftarBarang'][$editIndex])) {
        $editMode = true;
        $editBarang = $_SESSION['daftarBarang'][$editIndex];
    }
}

// UPDATE - simpan perubahan
if (isset($_POST['update'])) {
    $idx = intval($_POST['index']);
    if (isset($_SESSION['daftarBarang'][$idx])) {
        $nama = $_POST['nama'];
        $kode = $_POST['kode'];
        $stok = intval($_POST['stok']);
        $harga = intval($_POST['harga']);
        $gambar = $_SESSION['daftarBarang'][$idx]->getGambar(); // default gambar lama

        if (!empty($_FILES['gambar']['name'])) {
            $gambar = "img/" . $_FILES['gambar']['name'];
            move_uploaded_file($_FILES['gambar']['tmp_name'], $gambar);
        }

        $_SESSION['daftarBarang'][$idx] = new TokoElektronik($nama, $kode, $stok, $harga, $gambar);
    }
    header("Location: index.php");
    exit();
}
?>
<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <title>Toko Elektronik</title>
    <style>
        table { border-collapse: collapse; width: 80%; margin: 20px auto; }
        th, td { border: 1px solid black; padding: 8px; text-align: center; }
        img { max-width: 80px; }
        form { margin: 20px auto; width: 50%; border: 1px solid gray; padding: 10px; }
    </style>
</head>
<body>

<h2 style="text-align:center;">Toko Elektronik - CRUD PHP (Session)</h2>

<!-- Form Input -->
<form method="POST" enctype="multipart/form-data">
    <input type="hidden" name="index" value="<?= $editIndex ?>">
    <label>Nama Barang:</label><br>
    <input type="text" name="nama" required value="<?= $editMode ? $editBarang->getNamabarang() : '' ?>"><br><br>

    <label>Kode Barang:</label><br>
    <input type="text" name="kode" required value="<?= $editMode ? $editBarang->getKodebarang() : '' ?>"><br><br>

    <label>Stok:</label><br>
    <input type="number" name="stok" required value="<?= $editMode ? $editBarang->getStok() : '' ?>"><br><br>

    <label>Harga:</label><br>
    <input type="number" name="harga" required value="<?= $editMode ? $editBarang->getHarga() : '' ?>"><br><br>

    <label>Gambar:</label><br>
    <?php if ($editMode): ?>
        <img src="<?= $editBarang->getGambar() ?>" alt="gambar"><br>
    <?php endif; ?>
    <input type="file" name="gambar" accept="image/*"><br><br>

    <?php if ($editMode): ?>
        <button type="submit" name="update">Update Barang</button>
        <a href="index.php">Batal</a>
    <?php else: ?>
        <button type="submit" name="tambah">Tambah Barang</button>
    <?php endif; ?>
</form>

<!-- Tabel Data -->
<table>
    <tr>
        <th>No</th>
        <th>Nama</th>
        <th>Kode</th>
        <th>Stok</th>
        <th>Harga</th>
        <th>Gambar</th>
        <th>Aksi</th>
    </tr>
    <?php if (!empty($_SESSION['daftarBarang'])): ?>
        <?php foreach ($_SESSION['daftarBarang'] as $i => $b): ?>
            <tr>
                <td><?= $i+1 ?></td>
                <td><?= $b->getNamabarang() ?></td>
                <td><?= $b->getKodebarang() ?></td>
                <td><?= $b->getStok() ?></td>
                <td><?= $b->getHarga() ?></td>
                <td><img src="<?= $b->getGambar() ?>" alt="gambar"></td>
                <td>
                    <a href="?edit=<?= $i ?>">Edit</a> | 
                    <a href="?hapus=<?= $i ?>" onclick="return confirm('Hapus barang ini?')">Hapus</a>
                </td>
            </tr>
        <?php endforeach; ?>
    <?php else: ?>
        <tr><td colspan="7">Belum ada data barang.</td></tr>
    <?php endif; ?>
</table>

</body>
</html>

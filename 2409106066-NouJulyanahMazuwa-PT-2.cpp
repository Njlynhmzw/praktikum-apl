#include <iostream>
#include <iomanip>
#include <string>

#define CLEAR "cls"

using namespace std;

#define MAX_NOVEL 100

int cls() {
    system(CLEAR);
    return 0;
}

int login() {
    string username, PIN;
    int kesempatan = 3;

    while (kesempatan > 0) {
        cout << "Silahkan masukkan username anda: ";
        cin >> username;
        cout << "Silahkan masukkan PIN anda: ";
        cin >> PIN;

        if (username == "nou" && PIN == "066") {
            return 1;
        }

        kesempatan--;
        cout << "Login gagal! Sisa percobaan: " << kesempatan << "\n";
    }
    return 0;
}

int tampilkanNovel(string novel[][3], int jumlah_novel) {
    cls();
    if (jumlah_novel == 0) {
        cout << "Silahkan masukkan data novel terlebih dahulu.\n";
        return 0;
    }

    cout << "\nDaftar Novel:\n";
    cout << "+----+----------------------+----------------------+------------+\n";
    cout << "| No | Judul               | Penulis             | Harga      |\n";
    cout << "+----+----------------------+----------------------+------------+\n";

    for (int i = 0; i < jumlah_novel; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(20) << novel[i][0] << " | "
             << setw(20) << novel[i][1] << " | "
             << "Rp." << setw(8) << novel[i][2] << " |\n";
    }

    cout << "+----+----------------------+----------------------+------------+\n";
    return 0;
}

int tambahNovel(string novel[][3], int &jumlah_novel) {
    cls();
    if (jumlah_novel >= MAX_NOVEL) {
        cout << "Tidak bisa menambahkan novel lagi.\n";
        return 0;
    }

    cout << "Masukkan Judul Novel: ";
    cin.ignore();
    getline(cin, novel[jumlah_novel][0]);

    cout << "Masukkan Nama Penulis Novel: ";
    getline(cin, novel[jumlah_novel][1]);

    cout << "Masukkan Harga Novel: Rp.";
    cin >> novel[jumlah_novel][2];

    jumlah_novel++;
    cout << "Novel berhasil ditambahkan!\n";
    return 0;
}

int perbaruiNovel(string novel[][3], int jumlah_novel) {
    cls();
    if (jumlah_novel == 0) {
        cout << "Belum ada novel untuk diperbarui.\n";
        return 0;
    }

    tampilkanNovel(novel, jumlah_novel);

    int index;
    cout << "Masukkan nomor novel yang ingin diperbarui: ";
    cin >> index;

    if (index < 1 || index > jumlah_novel) {
        cout << "Nomor tidak valid!\n";
        return 0;
    }

    index--;
    cout << "Masukkan Judul Baru: ";
    cin.ignore();
    getline(cin, novel[index][0]);

    cout << "Masukkan Nama Penulis Baru: ";
    getline(cin, novel[index][1]);

    cout << "Masukkan Harga Baru: Rp.";
    cin >> novel[index][2];

    cout << "Novel berhasil diperbarui!\n";
    return 0;
}

int hapusNovel(string novel[][3], int &jumlah_novel) {
    cls();
    if (jumlah_novel == 0) {
        cout << "Belum ada novel untuk dihapus.\n";
        return 0;
    }

    tampilkanNovel(novel, jumlah_novel);

    int index;
    cout << "Masukkan nomor novel yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlah_novel) {
        cout << "Nomor tidak valid!\n";
        return 0;
    }

    index--;
    for (int i = index; i < jumlah_novel - 1; i++) {
        novel[i][0] = novel[i + 1][0];
        novel[i][1] = novel[i + 1][1];
        novel[i][2] = novel[i + 1][2];
    }

    jumlah_novel--;
    cout << "Novel berhasil dihapus!\n";
    return 0;
}

int main() {
    if (!login()) {
        cout << "Anda telah gagal login sebanyak 3 kali!! Sistem berhenti.\n";
        return 0;
    }

    int jumlah_novel = 5 ;
    string novel[MAX_NOVEL][3] = {
        {"Bumi", "Tere Liye", "120000"},
        {"Laskar Pelangi", "Andrea Hirata", "75000"},
        {"Dilan 1990", "Pidi Baiq", "85000"},
        {"Negeri 5 Menara", "Ahmad Fuadi", "95000"},
        {"Hujan", "Tere Liye", "135000"}
    };

    int pilihan;
    do {
        cout << "\n== Sistem Penjualan Novel ==\n";
        cout << " 1. Tambah Novel\n";
        cout << " 2. Lihat Novel\n";
        cout << " 3. Perbarui Novel\n";
        cout << " 4. Hapus Novel\n";
        cout << " 5. Keluar\n";
        cout << "Silahkan memilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahNovel(novel, jumlah_novel);
                break;
            case 2:
                tampilkanNovel(novel, jumlah_novel);
                break;
            case 3:
                perbaruiNovel(novel, jumlah_novel);
                break;
            case 4:
                hapusNovel(novel, jumlah_novel);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silahkan mencoba kembali.\n";
        }
    } while (pilihan != 5);

    return 0;
}

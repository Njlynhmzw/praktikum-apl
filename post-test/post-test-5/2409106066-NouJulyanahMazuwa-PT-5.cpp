#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Novel {
    string judul;
    string penulis;
    int tahun_terbit;
    int harga;
};

const int MAX_NOVEL = 10;

void cls() {
    system("cls");
}

bool login() {
    string nama, NIM;
    int kesempatan = 3;

    while (kesempatan > 0) {
        cout << "Silahkan masukkan Nama anda: ";
        cin >> nama;
        cout << "Silahkan masukkan NIM anda: ";
        cin >> NIM;

        if (nama == "nou" && NIM == "066") {
            return true;
        }

        kesempatan--;
        cout << "Login gagal! Sisa percobaan: " << kesempatan << "\n";
    }
    return false;
}

void tampilkanDaftarNovel(Novel daftar_novel[], int jumlah_novel) {
    if (jumlah_novel == 0) {
        cout << "Belum ada novel yang tersedia.\n";
    } else {
        cout << "\nDaftar Novel:\n";
        cout << "+----+----------------------+----------------------+--------------+--------------+\n";
        cout << "| No | Judul                | Penulis              | Tahun Terbit | Harga (Rp)   |\n";
        cout << "+----+----------------------+----------------------+--------------+--------------+\n";

        for (int i = 0; i < jumlah_novel; i++) {
            cout << "| " << setw(2) << i + 1 << " | "
                 << left << setw(20) << daftar_novel[i].judul << " | "
                 << left << setw(20) << daftar_novel[i].penulis << " | "
                 << right << setw(12) << daftar_novel[i].tahun_terbit << " | "
                 << right << setw(12) << daftar_novel[i].harga << " |\n";
        }
        cout << "+----+----------------------+----------------------+--------------+--------------+\n";
    }
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.get();
}

void tambahNovel(Novel daftar_novel[], int* jumlah_novel) {
    if (*jumlah_novel < MAX_NOVEL) {
        cout << "Masukkan judul novel: ";
        getline(cin, daftar_novel[*jumlah_novel].judul);

        cout << "Masukkan nama penulis: ";
        getline(cin, daftar_novel[*jumlah_novel].penulis);

        cout << "Masukkan tahun terbit: ";
        cin >> daftar_novel[*jumlah_novel].tahun_terbit;

        cout << "Masukkan harga: Rp. ";
        cin >> daftar_novel[*jumlah_novel].harga;
        cin.ignore();

        (*jumlah_novel)++;
        cout << "Novel berhasil ditambahkan!\n";
    } else {
        cout << "Daftar novel sudah penuh!\n";
    }
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.get();
}

void perbaruiNovel(Novel daftar_novel[], int jumlah_novel) {
    if (jumlah_novel == 0) {
        cout << "Belum ada novel untuk diperbarui.\n";
    } else {
        int index;
        cout << "Masukkan nomor novel yang ingin diperbarui: ";
        cin >> index;
        cin.ignore();

        if (index < 1 || index > jumlah_novel) {
            cout << "Nomor tidak valid!\n";
        } else {
            index--;
            cout << "Masukkan judul baru: ";
            getline(cin, daftar_novel[index].judul);

            cout << "Masukkan nama penulis baru: ";
            getline(cin, daftar_novel[index].penulis);

            cout << "Masukkan tahun terbit baru: ";
            cin >> daftar_novel[index].tahun_terbit;

            cout << "Masukkan harga baru: Rp. ";
            cin >> daftar_novel[index].harga;
            cin.ignore();

            cout << "Novel berhasil diperbarui!\n";
        }
    }
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.get();
}

void hapusNovel(Novel daftar_novel[], int* jumlah_novel) {
    if (*jumlah_novel == 0) {
        cout << "Belum ada novel untuk dihapus.\n";
    } else {
        int index;
        cout << "Masukkan nomor novel yang ingin dihapus: ";
        cin >> index;

        if (index < 1 || index > *jumlah_novel) {
            cout << "Nomor tidak valid!\n";
        } else {
            index--;
            for (int i = index; i < *jumlah_novel - 1; i++) {
                daftar_novel[i] = daftar_novel[i + 1];
            }
            (*jumlah_novel)--;
            cout << "Novel berhasil dihapus!\n";
        }
    }
    cin.ignore();
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.get();
}

int main() {
    if (!login()) {
        cout << "Anda gagal login 3 kali! Program berhenti.\n";
        return 0;
    }

    Novel daftar_novel[MAX_NOVEL] = {
        {"Bumi", "Tere Liye", 2017, 120000},
        {"Laskar Pelangi", "Andrea Hirata", 2016, 75000},
        {"Dilan 1990", "Pidi Baiq", 2020, 85000},
        {"Negeri 5 Menara", "Ahmad Fuadi", 2002, 95000},
        {"Hujan", "Tere Liye", 2015, 135000}
    };

    int jumlah_novel = 5;
    int pilihan;

    do {
        cls();
        cout << "\n=== Sistem Penjualan Novel ===\n";
        cout << "1. Lihat Daftar Novel\n";
        cout << "2. Tambah Novel\n";
        cout << "3. Perbarui Novel\n";
        cout << "4. Hapus Novel\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cls();
                tampilkanDaftarNovel(daftar_novel, jumlah_novel);
                break;
            case 2:
                cls();
                tambahNovel(daftar_novel, &jumlah_novel);
                break;
            case 3:
                cls();
                perbaruiNovel(daftar_novel, jumlah_novel);
                break;
            case 4:
                cls();
                hapusNovel(daftar_novel, &jumlah_novel);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                cout << "\nTekan enter untuk kembali ke menu...";
                cin.get();
        }
    } while (pilihan != 5);

    return 0;
}

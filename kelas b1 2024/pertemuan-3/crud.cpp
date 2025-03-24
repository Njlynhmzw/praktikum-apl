#include <iostream>
using namespace std;

struct Alamat
{
    string jalan;
    string kota;
};

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
    Alamat alamat;
};

#define MAX_MAHASISWA 5

int main()
{
    int panjang = 0;
    Mahasiswa mhs[MAX_MAHASISWA];
    int pilihan;

    do
    {
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (panjang == 0)
                cout << "Belum ada datang bang" << endl;
            else
            {
                cout << "Data Mahasiswa" << endl;
                for (int i = 0; i < panjang; i++)
                {
                    cout << "Nama\t: " << mhs[i].nama << endl;
                    cout << "NIM\t: " << mhs[i].nim << endl;
                    cout << "IPK\t: " << mhs[i].ipk << endl;
                    cout << "Jalan\t: " << mhs[i].alamat.jalan << endl;
                    cout << "IPK\t: " << mhs[i].alamat.kota << endl
                         << endl;
                }
            }
            break;
        case 2:
            if (panjang < MAX_MAHASISWA)
            {
                cout << "MasukkaBelum ada datang bangn nama: ";
                cin.ignore();
                getline(cin, mhs[panjang].nama);

                cout << "Masukkan NIM: ";
                cin.ignore();
                getline(cin, mhs[panjang].nim);

                cout << "Masukkan ipk: ";
                cin >> mhs[panjang].ipk;

                cout << "Masukkan jalan: ";
                cin.ignore();
                getline(cin, mhs[panjang].alamat.jalan);

                cout << "Masukkan kota: ";
                cin.ignore();
                getline(cin, mhs[panjang].alamat.kota);

                panjang++;
                cout << "Mahasiswa berhasil ditambahkan" << endl;
            }
            else
            {
                cout << "Penuh sudah bang" << endl;
            }
            break;
        case 3:
            break;
        case 4:
            cout << "Daftar Mahasiswa" << endl;
            for (int i = 0; i < panjang; i++)
            {
                cout << i + 1 << ". Nama\t: " << mhs[i].nama << endl;
            }

            int index;
            cout << "Masukkan nomor mahasiswa yang ingin dihapus: ";
            cin >> index;

            for (int i = index - 1; i < panjang - 1; i++)
            {
                mhs[i] = mhs[i + 1];
            }

            panjang--;
            break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);
}
#include <iostream>
using namespace std;

const int PIN = 6066 ;
double saldo = 100000000 ;

int main() {
    int input_pin, percobaan = 0 ;
    bool login = false;

    while (percobaan < 3) {
        cout << "Masukkan Pin ATM Anda " ;
        cin >> input_pin ;

        if (input_pin == PIN) {
            login = true;
            break ; 
        } else {
            cout << "Pin yang anda masukkan salah. Silahkan coba kembali" << endl ;
            percobaan ++ ;
        }
    }

    if (!login){
        cout << "Anda telah gagal login 3 kali. ATM Terblokir !!!" ;
        return 0;
    } 

    int pilihan ;
    double jumlah;

    do {
        cout << "\n== Menu ATM ==" << endl ;
        cout << " 1. Setor Tunai" << endl ;
        cout << " 2. Cek Saldo" << endl ;
        cout << " 3. Tarik Tunai" << endl ;
        cout << " 4. keluar" << endl ;
        cout << "Silahkan memilih menu: " ;
        cin >> pilihan;

        switch (pilihan) {
            case 1 :
                cout << "Masukkan jumlah setor tunai: " ;
                cin >> jumlah ;
                saldo += jumlah;
                cout << "Saldo Anda adalah : " << saldo << endl;
                break;

            case 2 :
                cout << "Saldo anda adalah : " << saldo << endl;
                break;

            case 3 :
                cout << "Masukkan Jumlah tarik tunai: " ;
                cin >> jumlah;
                if (jumlah <= saldo) {
                    saldo -= jumlah;
                    cout << "Tarik tunai telah berhasil. Sisa saldo anda adalah: " << saldo << endl ;
                } else {
                    cout << "Saldo anda tidak mencukupi untuk melakukan tarik tunai" ;
                }
                break;

            case 4 :
                cout << "Anda telah keluar dari ATM. Terimakasih" << endl;
                break;

            default :
                cout << "Pilihan tidak valid. Silahkan masukkan pilihan menu yang benar" ;
        }
    } while (pilihan != 4) ;
    {
        return 0;
    }
    
}
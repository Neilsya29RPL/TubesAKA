#include <iostream>
#include <vector>
using namespace std;

void hitungWaktuTungguRekursif(int jalurLayanan[], int jumlahJalur, int kendaraanKe, int jumlahKendaraan, int waktuLayanan, int index = 0, int jalurTercepat = 0) {
    if (kendaraanKe > jumlahKendaraan) return; 
    if (index == jumlahJalur) {
        int waktuTunggu = jalurLayanan[jalurTercepat];
        jalurLayanan[jalurTercepat] += waktuLayanan;

        cout << "Kendaraan " << kendaraanKe
             << " waktu tunggu: " << waktuTunggu
             << " menit di jalur " << jalurTercepat + 1 << "\n";

        hitungWaktuTungguRekursif(jalurLayanan, jumlahJalur, kendaraanKe +
        1, jumlahKendaraan, waktuLayanan);
        return;
    }

    if (jalurLayanan[index] < jalurLayanan[jalurTercepat]) {
        jalurTercepat = index;
    }

    hitungWaktuTungguRekursif(jalurLayanan, jumlahJalur, kendaraanKe, 
    jumlahKendaraan, waktuLayanan, index + 1, jalurTercepat);
}

int main() {
    const int jumlahKendaraan = 10;
    const int jumlahJalur = 3;
    const int waktuLayanan = 3;

    int jalurLayanan[jumlahJalur] = {0}; 

    cout << "Optimasi waktu tunggu kendaraan di SPBU:\n";
    hitungWaktuTungguRekursif(jalurLayanan, jumlahJalur, 1, jumlahKendaraan, 
    waktuLayanan);

    return 0;
}
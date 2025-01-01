#include <iostream>
#include <vector>
using namespace std;

void hitungWaktuTungguIteratif(const vector<int>& urutanKendaraan, int jumlahJalur) {
    int waktuLayanan = 3;
    int waktuTunggu = 0;  
    vector<int> jalurLayanan(jumlahJalur, 0);  

    cout << "Hasil waktu tunggu kendaraan di SPBU (Iteratif dengan pencarian jalur tercepat):\n";
    
    for (size_t i = 0; i < urutanKendaraan.size(); i++) {
        int jalurTercepat = 0;
        for (size_t j = 1; j < jalurLayanan.size(); j++) {
            if (jalurLayanan[j] < jalurLayanan[jalurTercepat]) {
                jalurTercepat = j;
            }
        }

        waktuTunggu = jalurLayanan[jalurTercepat];
        jalurLayanan[jalurTercepat] += waktuLayanan;

        cout << "Kendaraan " << urutanKendaraan[i] 
             << " waktu tunggu: " << waktuTunggu << " menit di jalur " 
             << jalurTercepat + 1 << "\n";
    }
}

int main() {
    int n = 10;  
    int jumlahJalur = 3;  
    vector<int> urutanKendaraan(n); 

    for (int i = 0; i < n; i++) {
        urutanKendaraan[i] = i + 1;
    }

    hitungWaktuTungguIteratif(urutanKendaraan, jumlahJalur);

    return 0;
}
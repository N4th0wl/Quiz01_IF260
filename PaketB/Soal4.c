#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define CONTESTANT 3
int mangkokTersedia;
int mangkokTerkonsumsi[CONTESTANT] = {0};
// (A) Deklarasikan variabel Mutex di sini! -- (2.5 Points)

void *lombaMakan(void *arg) {
    int id = *(int *)arg;
    while (1) {
        // (B) Kunci akses ke variabel global -- (2.5 Points)

        if (mangkokTersedia <= 0) {
            // (C) Apa yang harus dilakukan sebelum keluar dari loop (break)? -- (2.5 Points)
            break;
        }

        mangkokTersedia--;
        mangkokTerkonsumsi[id]++;
        printf("Kontestan %d makan 1 porsi. Sisa: %d\n", id + 1, mangkokTersedia); 

        // (D) Lepas kembali akses variabel global -- (2.5 Points)

        sleep(rand() % 5); // Simulasi waktu makan agar adil
    }
    return NULL;
}

int main() {
    pthread_t peserta[CONTESTANT], status_thread;
    int ids[CONTESTANT] = {0, 1, 2};

    // (E) Inisialisasi Mutex sebelum digunakan -- (2.5 Points)


    printf("Masukkan jumlah porsi (11-199): ");
    scanf("%d", &mangkokTersedia);

    // (F) Buat thread untuk masing-masing kontestan -- (2.5 Points)
    for (int i = 0; i < CONTESTANT; i++) {

    }

    // (G) Tunggu semua thread peserta selesai (join) -- (2.5 Points)
    for (int i = 0; i < CONTESTANT; i++) {

    }

    pthread_mutex_destroy(&lock);
    // (H) Tampilkan hasil akhir konsumsi Mie Ayam masing-masing kontestan -- (2.5 Points)
    return 0;
}
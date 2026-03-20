#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Deklarasi Variabel Global
#define CONTESTANT 3
int mangkukTersedia;
int mangkukTerkonsumsi[CONTESTANT] = {0};
// (A) Deklarasikan variabel Mutex di sini! -- (2.5 Points)

// Fungsi makanMie (Thread Kontestan)
void *makanMie(void *arg){
    int id = *(int *)arg; // Mengambil id kontestan
    while (1){
        // (B) Kunci akses ke variabel global -- (2.5 Points)
        
        // Jika mangkukTersedia <= 0
        if(mangkukTersedia <= 0){
            // (C) Apa yang harus dilakukan sebelum keluar dari loop? -- (2.5 Points)
            break;
        }
        
        mangkukTersedia--; // Mengurangi jumlah mie tersedia
        mangkukTerkonsumsi[id]++; // Menambah jumlah mie yang dikonsumsi kontestan
        printf("Kontestan %d makan 1 mangkuk mie. Sisa di meja: %d\n", id+1, mangkukTersedia);
        
        // (D) Lepas kembali akses variabel global -- (2.5 Points)
        
        sleep(rand() % 5); // Simulasi waktu makan berupa waktu random (0 - 4 detik).
    } 
    return NULL;
}

// Fungsi tampilkanStatus
void *tampilkanStatus(void *arg){
    while(1){
        // (E) Kunci akses ke variabel global -- (2.5 Points)
        
        // Jika mangkukTersedia <= 0
        if(mangkukTersedia <= 0){
            // (F) Apa yang harus dilakukan sebelum keluar dari loop? -- (2.5 Points)
            break;
        }
        
        printf("\t[PAPAN SKOR] Sisa mangkuk: %d\n\tK1: %d Mangkuk, K2: %d Mangkuk, K3: %d Mangkuk\n", 
            mangkukTersedia, mangkukTerkonsumsi[0], mangkukTerkonsumsi[1], mangkukTerkonsumsi[2]);
        // (G) Lepas kembali akses variabel global -- (2.5 Points)
        sleep(2); // Update Status tiap 2 detik (delay)
    }
    return NULL;
}

// Fungsi Utama
int main (int argc, char *argv[]) {
    srand(time(NULL)); // Inisialisasi waktu random
    
    printf("=== FESTIVAL KICAU MANIA JOMOKERTO ===\n");
    printf("Masukkan jumlah total mangkuk mie ayam (11 - 199): ");
    scanf("%d", &mangkukTersedia);

    // Validasi Input
    if(mangkukTersedia < 11 || mangkukTersedia > 199){
        printf("Jumlah mangkuk harus berjumlah antara 11 - 199!\n");
        return 1;
    }

    // Inisiasi Mutex dan Thread sebelum digunakan
    pthread_t kontestan_thread[CONTESTANT], status_thread;
    pthread_mutex_init(&lock, NULL);

    // Buat Thread untuk tiap kontestan
    int ids[CONTESTANT] = {0, 1, 2};
    for(int i = 0; i < CONTESTANT; i++){
        // (H) Buat thread untuk masing-masing kontestan -- (2.5 Points)
        
    }
    
    // (I) Buat thread untuk menampilkan status -- (2.5 Points)
    

    // Menunggu semua thread kontestan selesai
    for(int i = 0; i < CONTESTANT; i++){
        // (J) Tunggu semua thread peserta selesai (join) -- (2.5 Points)
        
    }
    
    // (K) Tunggu thread status selesai (join) -- (2.5 Points)
    

    // (L) Hancurkan Mutex setelah selesai digunakan -- (2.5 Points)
    pthread_mutex_destroy(&lock);

    // Penentuan juara berdasarkan mangkukTerkonsumsi
    printf("\n=== HASIL AKHIR LOMBA MAKAN MIE ===\n");
    int ranking[CONTESTANT] = {0, 1, 2};
    for(int i = 0; i < CONTESTANT - 1; i++){
        for(int j = i + 1; j < CONTESTANT; j++){
            if(mangkukTerkonsumsi[ranking[i]] < mangkukTerkonsumsi[ranking[j]]){
                int temp = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = temp;
            }
        }
    }

    // Print hasil kompetisi
    for(int i = 0; i < CONTESTANT; i++){
        printf("Juara %d: Kontestan %d dengan total %d mangkuk mie ayam\n", i + 1, ranking[i] + 1, mangkukTerkonsumsi[ranking[i]]);
    }

    return 0;
}
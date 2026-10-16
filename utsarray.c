#include <stdio.h>

#define LANTAI 2
#define BARIS  3
#define KOLOM  5

int main() {
    // Declaration
    long long nim[LANTAI][BARIS][KOLOM];
    char tipe[LANTAI][BARIS][KOLOM];
    int i, j, k, c;
    int totalIndeks;
    int countA = 0, countB = 0;

    // Header program
    printf("=============================================\n");
    printf("   PENGALOKASIAN TIPE SOAL UJIAN BERTINGKAT\n");
    printf("=============================================\n");
    printf("Ruang ujian: %d lantai x %d baris x %d kolom\n", LANTAI, BARIS, KOLOM);

    // Input NIM and assign soal type based on index sum
    for (i = 0; i < LANTAI; i++) {
        for (j = 0; j < BARIS; j++) {
            for (k = 0; k < KOLOM; k++) {
                do {
                    printf("NIM Lantai %d, Baris %d, Kolom %d: ", i + 1, j + 1, k + 1);
                    if (scanf("%lld", &nim[i][j][k]) != 1) {
                        while ((c = getchar()) != '\n' && c != EOF);
                        nim[i][j][k] = 0;
                    }
                    if (nim[i][j][k] <= 0) {
                        printf("NIM harus berupa angka positif!\n");
                    }
                } while (nim[i][j][k] <= 0);

                totalIndeks = i + j + k;
                if (totalIndeks % 2 == 0) {
                    tipe[i][j][k] = 'A';
                    countA = countA + 1;
                } else {
                    tipe[i][j][k] = 'B';
                    countB = countB + 1;
                }
            }
        }
    }

    // Print list 
    printf("\n================ DAFTAR PESERTA ================\n");
    for (i = 0; i < LANTAI; i++) {
        for (j = 0; j < BARIS; j++) {
            for (k = 0; k < KOLOM; k++) {
                printf("Lantai %d, Baris %d, Kolom %d | NIM: %lld | Soal Tipe %c\n",
                       i + 1, j + 1, k + 1, nim[i][j][k], tipe[i][j][k]);
            }
        }
    }

    // Print recap
    printf("\n================ REKAP SOAL ================\n");
    printf("Total peserta Soal Tipe A : %d orang\n", countA);
    printf("Total peserta Soal Tipe B : %d orang\n", countB);
    printf("============================================\n");

    return 0;
}
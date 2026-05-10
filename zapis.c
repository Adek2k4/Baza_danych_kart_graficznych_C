#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct karty {
    char marka[50];
    char model[50];
    int przepustowosc;
    int taktowanie;
    int rdzenie;
    int TDP;
    char RT[10];
};

void zapiszPrzykladoweDane(const char *filename) {
    struct karty przykladoweKarty[492] = {
    {"Intel", "Xe HPG", 512, 2000, 768, 275, "Nie"},
    {"AMD", "Radeon RX 7900 XT", 640, 2200, 10240, 350, "Tak"},
    {"NVIDIA", "Ampere A100", 640, 1410, 8192, 400, "Tak"},
    {"Intel", "Xe LP", 256, 1800, 512, 120, "Nie"},
    {"AMD", "Radeon RX 7800 XT", 512, 2000, 7680, 300, "Tak"},
    {"NVIDIA", "Ampere A6000", 576, 1410, 10752, 300, "Tak"},
    {"Intel", "Xe HP", 384, 1800, 768, 150, "Nie"},
    {"AMD", "Radeon RX 7700 XT", 448, 2100, 5120, 250, "Tak"},
    {"NVIDIA", "Ampere A40", 432, 1245, 10752, 300, "Tak"},
    {"Intel", "Xe HPC", 768, 1800, 1536, 300, "Tak"},
    {"AMD", "Radeon RX 7600 XT", 384, 2000, 4096, 200, "Tak"},
    {"NVIDIA", "Ampere A30", 384, 1245, 6144, 150, "Nie"},
    {"Intel", "Xe HPE", 640, 1800, 1024, 250, "Tak"},
    {"AMD", "Radeon RX 7500 XT", 320, 2100, 3072, 150, "Nie"},
    {"NVIDIA", "Ampere A10", 288, 1245, 4096, 150, "Nie"},
    {"Intel", "Xe HPC+", 960, 1800, 2048, 350, "Tak"},
    {"AMD", "Radeon RX 7400 XT", 256, 2000, 2048, 120, "Nie"},
    {"NVIDIA", "Ampere A16", 288, 1245, 6144, 180, "Nie"},
    {"Intel", "Xe HPG 2", 1024, 2200, 1536, 400, "Tak"},
    {"AMD", "Radeon RX 7300 XT", 224, 2100, 1536, 100, "Nie"},
    {"NVIDIA", "Ampere A12", 192, 1245, 3072, 120, "Nie"},
    {"Intel", "Xe HPC X", 1152, 1800, 2304, 450, "Tak"},
    {"AMD", "Radeon RX 7200 XT", 192, 2000, 1024, 80, "Nie"},
    {"NVIDIA", "Ampere A8", 192, 1245, 2048, 100, "Nie"},
    {"Intel", "Xe HP", 896, 1800, 1792, 300, "Tak"},
    {"AMD", "Radeon RX 7100 XT", 160, 2100, 768, 60, "Nie"},
    {"NVIDIA", "Ampere A6", 128, 1245, 1024, 80, "Nie"},
    {"Intel", "Xe H1", 768, 1800, 1536, 250, "Tak"},
    {"AMD", "Radeon RX 7000 XT", 128, 2000, 512, 40, "Nie"},
    {"NVIDIA", "Ampere A4", 96, 1245, 512, 50, "Nie"}
};
    

    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Nie udało się otworzyć pliku %s do zapisu.\n", filename);
        return;
    }

    size_t liczbaZapisanych = fwrite(przykladoweKarty, sizeof(struct karty), 30, file);
    if (liczbaZapisanych != 30) {
        printf("Wystąpił błąd podczas zapisywania do pliku.\n");
    } else {
        printf("Zapisano %zu przykladowych struktur do pliku %s.\n", liczbaZapisanych, filename);
    }

    fclose(file);
}

int main() {
    const char *filename = "baza1.dat";
    zapiszPrzykladoweDane(filename);
    return 0;
}


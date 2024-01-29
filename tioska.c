#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definirea clasei "Carte"
struct Carte {
    char titlu[100];
    char autor[100];
    char ISBN[20];
};

// Definirea clasei "Bibliotecă"
struct Biblioteca {
    struct Carte carti[100]; // presupunem că biblioteca poate stoca maxim 100 de cărți
    int numarCarti;
};

// Metoda pentru a adăuga o carte în bibliotecă
void adaugaCarte(struct Biblioteca *biblioteca, const char *titlu, const char *autor, const char *ISBN) {
    if (biblioteca->numarCarti < 100) { // verificăm dacă mai este spațiu în bibliotecă
        struct Carte carteNoua;
        strcpy(carteNoua.titlu, titlu);
        strcpy(carteNoua.autor, autor);
        strcpy(carteNoua.ISBN, ISBN);

        biblioteca->carti[biblioteca->numarCarti] = carteNoua;
        biblioteca->numarCarti++;

        printf("Cartea \"%s\" a fost adăugată în bibliotecă.\n", titlu);
    } else {
        printf("Biblioteca este plină. Nu se poate adăuga o carte nouă.\n");
    }
}

// Metoda pentru a elimina o carte din bibliotecă
void eliminaCarte(struct Biblioteca *biblioteca, const char *ISBN) {
    int index = -1;

    for (int i = 0; i < biblioteca->numarCarti; i++) {
        if (strcmp(biblioteca->carti[i].ISBN, ISBN) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < biblioteca->numarCarti - 1; i++) {
            biblioteca->carti[i] = biblioteca->carti[i + 1];
        }
        biblioteca->numarCarti--;

        printf("Cartea cu ISBN-ul %s a fost eliminată din bibliotecă.\n", ISBN);
    } else {
        printf("Cartea cu ISBN-ul %s nu a fost găsită în bibliotecă.\n", ISBN);
    }
}

// Metoda pentru a afișa toate cărțile din bibliotecă
void afiseazaCarti(struct Biblioteca *biblioteca) {
    printf("Cărțile din bibliotecă:\n");

    for (int i = 0; i < biblioteca->numarCarti; i++) {
        printf("Titlu: %s\n", biblioteca->carti[i].titlu);
        printf("Autor: %s\n", biblioteca->carti[i].autor);
        printf("ISBN: %s\n\n", biblioteca->carti[i].ISBN);
    }
}

int main() {
    // Exemplu de utilizare
    struct Biblioteca biblioteca;
    biblioteca.numarCarti = 0;

    adaugaCarte(&biblioteca, "Programarea C", "John Doe", "978-3-16-148410-0");
    adaugaCarte(&biblioteca, "Introducere în OOP", "Jane Smith", "978-1-23-456789-0");

    afiseazaCarti(&biblioteca);

    eliminaCarte(&biblioteca, "978-3-16-148410-0");

    afiseazaCarti(&biblioteca);

    return 0;
}

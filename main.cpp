/*
 ============================================================================
 Name        : main.cpp
 Author      : InfinitePain
 Version     : 0.1.0
 License     : Apache License 2.0
 Description : Vehicle License Plate Manager Main Program
 ============================================================================
 */

#include <iostream>
#include "kennzeichen.h"
#include "datenbank.h"
#include <ctime>
#include <cstdlib>

void schnapszahlTest() {
    kfz::kennzeichen* testKennzeichen = new kfz::kennzeichen;
    
    int anzahlBuchstaben = rand() % 3 + 1;
    for (int j = 0; j < anzahlBuchstaben; j++) {
        testKennzeichen->ort += (char)(rand() % 26 + (int)'A');
    }
    
    anzahlBuchstaben = rand() % 2 + 1;
    for (int j = 0; j < anzahlBuchstaben; j++) {
        testKennzeichen->buchstaben += (char)(rand() % 26 + (int)'A');
    }

    
    testKennzeichen->zahl = 444;
    std::cout << kfz::ausgabe(*testKennzeichen);
    std::cout << (kfz::istSchnapszahl(testKennzeichen) ? " hat eine Schnapszahl." : " hat keine Schnapszahl.") << std::endl;
    testKennzeichen->zahl = 123;
    std::cout << kfz::ausgabe(*testKennzeichen);
    std::cout << (kfz::istSchnapszahl(testKennzeichen) ? " hat eine Schnapszahl." : " hat keine Schnapszahl.") << std::endl;
}
void einlesenTest() {
    kfz::kennzeichen* testKennzeichen = kfz::einlesen();
    std::cout << kfz::ausgabe(*testKennzeichen) << std::endl;
    kfz::schildTest(testKennzeichen);
}
void datenbankTest() {
    srand(time(NULL));
    db::datenbank testDatenbank;
    testDatenbank.name = "Testdatenbank";
    bool istDbVoll = false;
    int anzahlTestKennzeichen = 2;
    kfz::kennzeichen* testKennzeichen[anzahlTestKennzeichen];
    for (int i = 0; i < anzahlTestKennzeichen; i++) {
        testKennzeichen[i] = new kfz::kennzeichen;
        
        int anzahlBuchstaben = rand() % 3 + 1;
        for (int j = 0; j < anzahlBuchstaben; j++) {
            testKennzeichen[i]->ort += (char)(rand() % 26 + (int)'A');
        }
        
        anzahlBuchstaben = rand() % 2 + 1;
        for (int j = 0; j < anzahlBuchstaben; j++) {
            testKennzeichen[i]->buchstaben += (char)(rand() % 26 + (int)'A');
        }
        
        testKennzeichen[i]->zahl = rand() % 9999 + 1;
    }

    for (int i = 0; i < anzahlTestKennzeichen; i++) {
        istDbVoll = db::einfuegen(&testDatenbank, testKennzeichen[i]);
        if (istDbVoll) {
            std::cout << "Kennzeichen eingefügt: " << kfz::ausgabe(*testKennzeichen[i]) << std::endl;
        }
        else {
            std::cout << "Datenbank voll! Einfügen fehlgeschlagen." << std::endl;
            break;
        }
    }

    std::cout << db::ausgabe(testDatenbank) << std::endl;
}
int main() {
    schnapszahlTest();
    einlesenTest();
    datenbankTest();
    return 0;
}

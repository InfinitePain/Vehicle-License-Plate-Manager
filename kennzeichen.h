/*
 ============================================================================
 Name        : kennzeichen.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Vehicle License Plate Structure and Associated Functions Header
 ============================================================================
 */

#pragma once
#include <string>
#include <iostream>
 /* IHR CODE */
namespace kfz
{
	typedef struct kennzeichen {
		std::string ort;
		std::string buchstaben;
		short zahl;
	} kennzeichen;

	std::string einlesenOrt() {
		std::string ort;
		bool gueltige_eingabe = false;

		while (!gueltige_eingabe) {
			std::cout << "Bitte geben Sie eine Ortsabkürzung ein (1-3 Buchstaben): ";
			std::cin >> ort;

			if (ort.length() >= 1 && ort.length() <= 3) {
				gueltige_eingabe = true;
			}
			else {
				std::cout << "Ungültige Eingabe. Die Ortsabkürzung muss 1-3 Buchstaben lang sein. Bitte versuchen Sie es erneut." << std::endl;
			}
		}

		return ort;
	}
	short einlesenZahl() {
		short zahl;
		bool gueltige_eingabe = false;

		while (!gueltige_eingabe) {
			std::cout << "Bitte geben Sie eine Zahl ein (1-9999): ";
			std::cin >> zahl;

			if (zahl >= 1 && zahl <= 9999) {
				gueltige_eingabe = true;
			}
			else {
				std::cout << "Ungültige Eingabe. Die Zahl muss zwischen 1 und 999 liegen. Bitte versuchen Sie es erneut." << std::endl;
			}
		}

		return zahl;
	}
	kennzeichen* einlesen() {
		kennzeichen* pKennzeichen = new kennzeichen;
		std::cout << "Bitte geben Sie Ihr Wunschkennzeichen ein:" << std::endl;
		pKennzeichen->ort = einlesenOrt();
		pKennzeichen->zahl = einlesenZahl();
		return pKennzeichen;
	}
	bool istSchnapszahl(const kennzeichen* pKennzeichen) {
		int zahl = pKennzeichen->zahl;
		int letzte_ziffer = zahl % 10;

		while (zahl > 0) {
			int letzte_ziffer = zahl % 10;
			zahl /= 10;
			int aktuelle_ziffer = zahl % 10;

			if (aktuelle_ziffer != letzte_ziffer) {
				return false;
			}
		}
		return true;
	}
	bool istZehner(const kennzeichen* pKennzeichen) {
		int zahl = pKennzeichen->zahl;

		if (zahl >= 10 && zahl <= 99 && zahl % 10 == 0) {
			return true;
		}
		
		return false;
	}
	bool istHunderter(const kennzeichen& rKennzeichen) {
		int zahl = rKennzeichen.zahl;

		if (zahl >= 100 && zahl <= 999 && zahl % 100 == 0) {
			return true;
		}

		return false;
	}
	bool istTausender(const kennzeichen* pKennzeichen) {
		int zahl = pKennzeichen->zahl;

		if (zahl >= 1000 && zahl <= 9999 && zahl % 1000 == 0) {
			return true;
		}

		return false;
	}
	void schildTest(kennzeichen* schild) {
		if (istSchnapszahl(schild)) {
			std::cout << "Eine Schnapszahl! Gute Wahl!"<< std::endl;
		}
		else if (istZehner(schild)) {
			std::cout << "Ein 10er Kennzeichen! Gute Wahl!" << std::endl;
		}
		else if (istHunderter(*schild)) {
			std::cout << "Ein 100er Kennzeichen! Gute Wahl!" << std::endl;
		}
		else if (istTausender(schild)) {
			std::cout << "Ein 1000er Kennzeichen! Gute Wahl!" << std::endl;
		}
	}
	std::string ausgabe(const kennzeichen& rKennzeichen) {
		/* IHR CODE */
	}
}

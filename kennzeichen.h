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
#include <limits>

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
	std::string einlesenBuchstaben() {
		std::string buchstaben;
		bool gueltige_eingabe = false;

		while (!gueltige_eingabe) {
			std::cout << "Bitte geben Sie eine Buchstabenkombination ein (1-2 Buchstaben):";
			std::cin >> buchstaben;

			if (buchstaben.length() >= 1 && buchstaben.length() <= 2) {
				gueltige_eingabe = true;
			}
			else {
				std::cout << "Ungültige Eingabe. Die Buchstabenkombination muss 1-2 Buchstaben lang sein. Bitte versuchen Sie es erneut." << std::endl;
			}
		}

		return buchstaben;
	}
	short einlesenZahl() {
		short zahl;
		bool gueltige_eingabe = false;

		while (!gueltige_eingabe) {
			std::cout << "Bitte geben Sie eine Zahl ein (1-9999): ";
			std::cin >> zahl;

			if (std::cin.good() && zahl >= 1 && zahl <= 9999) {
				gueltige_eingabe = true;
			}
			else {
				std::cout << "Ungültige Eingabe. Die Zahl muss zwischen 1 und 9999 liegen. Bitte versuchen Sie es erneut." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}

		return zahl;
	}
	kennzeichen* einlesen() {
		kennzeichen* pKennzeichen = new kennzeichen;
		std::cout << "Bitte geben Sie Ihr Wunschkennzeichen ein:" << std::endl;
		pKennzeichen->ort = einlesenOrt();
		pKennzeichen->buchstaben = einlesenBuchstaben();
		pKennzeichen->zahl = einlesenZahl();
		return pKennzeichen;
	}
	bool istSchnapszahl(const kennzeichen* pKennzeichen) {
		int zahl = pKennzeichen->zahl;
		int letzte_ziffer = -1;

		while (zahl > 0) {
			int aktuelle_ziffer = zahl % 10;

			if (letzte_ziffer != -1 && aktuelle_ziffer != letzte_ziffer) {
				return false;
			}

			letzte_ziffer = aktuelle_ziffer;
			zahl /= 10;
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
		std::string ausgabe = rKennzeichen.ort + " " + rKennzeichen.buchstaben + " " + std::to_string(rKennzeichen.zahl);
		return ausgabe;
	}
}

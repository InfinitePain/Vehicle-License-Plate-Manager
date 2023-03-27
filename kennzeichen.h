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

	std::string einlesenOrt() { /* IHR CODE */
	}
	short einlesenZahl() { /* IHR CODE */
	}
	kennzeichen* einlesen() { /* IHR CODE */
	}
	bool istSchnapszahl(const kennzeichen* pKennzeichen) { /* IHR CODE */
	}
	bool istZehner(const kennzeichen* pKennzeichen) { /* IHR CODE */
	}
	bool istHunderter(const kennzeichen& rKennzeichen) { /* IHR CODE */
	}
	void schildTest(kennzeichen* schild) { /* IHR CODE */
	}
	std::string ausgabe(const kennzeichen& rKennzeichen) { /* IHR CODE */
	}
}
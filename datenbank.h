/*
 ============================================================================
 Name        : datenbank.h
 Author      : InfinitePain
 License     : Apache License 2.0
 Description : Simple Database Functions Header for Vehicle License Plate Manager
 ============================================================================
 */

#pragma once
#define DB_LIMIT 10
#include "kennzeichen.h"
#include <string>

namespace db
{
	typedef struct datenbank {
		std::string name;
		kfz::kennzeichen* schilder[DB_LIMIT];
		int eintraege = 0;
	} datenbank;
	
	bool einfuegen(datenbank* db, kfz::kennzeichen* schild) {
		if (db->eintraege < DB_LIMIT) {
			db->schilder[db->eintraege] = schild;
			db->eintraege++;
			return true;
		}
		else {
			return false;
		}
	}
	std::string ausgabe(const datenbank& db) {
		std::string ausgabe = "Datenbank: "  + db.name + "\n";
		for (int i = 0; i < db.eintraege; i++) {
			ausgabe += kfz::ausgabe(*db.schilder[i]) + "\n";
		}
		return ausgabe;
	}
}

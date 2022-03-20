// String.cpp
#include <iostream>
using namespace std;

#include "String.h"

/*
Konstruktor : Standard Konstruktor
Beschreibung :
	Konstruktor eines Stringobjekts.  
	Initialisiert die aktuelle Instanz.
	Erstellt einem Leere Zeichenkette als Inhalt des Objekts

Parameter:
	keine

Rückgabe:  
	keine
*/
String::String() {
    size = 0;
    str = new char[1];
    str[0] = '\0';
}


/*
Konstruktor : Zeichen
Beschreibung :
	Konstruktor eines Stringobjekts.  
	Initialisiert die aktuelle Instanz.
	Das übergebene Zeichen wird als String des Objekts gespeichert

Parameter:
	c - Zeichen  

Rückgabe:  
	keine
*/
String::String(char c) {
    size = 1;
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}


/*
Konstruktor : Zeichenkette
Beschreibung :
	Konstruktor eines Stringobjekts.  
	Initialisiert die aktuelle Instanz.
	Die übergeben Zeichenkette wird als String des Objekts gespeichert

Parameter:
	s - Zeichenkette  

Rückgabe:  
	keine
*/

String::String(const char *s) {
  size = 0;
  	// Bekomme die Länge des passenden Strings und setze Objekt Parameter
  while (*(s + size) != '\0') {
	  size++;
  }

  str = new char[size + 1];

	// Kopiere ein String
  for (int i = 0; i <= size; i++) {
	  str[i] = s[i];
  }
}

/*
Konstruktor : Kopierkonstruktor 
Beschreibung :
	Konstruktor eines Stringobjekts.  
	Initialisiert die aktuelle Instanz.
	Kopiert die Zeichenkette des als Parameter Übergebenen String Objekts 

Parameter:
	s - Objekt aus dem die Zeichenkette kopiert wird 

Rückgabe:  
	keine
*/

String::String(const String& s) {
  size = s.size;
  str = new char[size + 1];
  for (int i = 0; i <= size; i++) {
	  str[i] = s.str[i];
  }
}


/*
Konstruktor : Verschiebekonstruktor 
Beschreibung :
	Konstruktor einer Stringobjekt.  
	Initialisiert die aktuelle Instanz.
	Übernimmt die Zeichenkette der Übergebenen Instanz


Parameter:
	s - Objekt aus dem die Zeichenkette Übernommen wird  

Rückgabe:  
	keine
*/

String::String(String&& s) {
	// An eine neue Adresse wird verschoben
  size = s.size;
  str = s.str;
  s.str = nullptr;
}

String::~String() { delete[] str; }


/*
Operator : []
Beschreibung :
	Liefert das an der  übergebenen Position vorhanden Zeichen zurück.

Parameter:
	index - Position des Zeichen in der Zeichenkette 

Rückgabe:  
	Zeichen an der Stelle index
*/

char& String::operator[](int index) {
  
	if (index < size && index >= 0) {
		return *(str + index);
	}

	// Wenn Index "Out of bounds" ist, wird Zeiger auf null-Terminator gesetzt
	return *(str + size);
}


/*
Operator : =
Beschreibung :
	Kopiert den Inhalt des Übergebenen String Objektes in das aktuelle Objekt.


Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt Kopiert wird

Rückgabe:  
	Referenz auf das aktuelle Stringobjekt
*/

String& String::operator=(const String& s) {
  // Copy-Zuweisungsoperator
	
	// erzeuge neues kopierten String
	char* tmpstr = new char[s.size];

	for (int i = 0; i < s.size; i++) {
		tmpstr[i] = s.str[i];
	}

	// free altes Speicher des Strings
	delete str;
	size = s.size;
	str = tmpstr;

	return *this;
  }


/*
Operator : = (move)
Beschreibung :
	verschiebt den Inhalt des Übergebenen String Objektes in das aktuelle Objekt.


Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt verschoben wird

Rückgabe:  
	Referenz auf das aktuelle Stringobjekt
*/

String& String::operator=(String&& s) {
	
	if (str != s.str) {
		delete str;
		str = s.str;
		s.str = nullptr;
	}
	return *this;
}



/*
Operator : +
Beschreibung :
	hängt den Inhalt des Übergebenen String Objektes an das aktuelle Objekt na. 


Parameter:
	s - Referenz auf eine String Instanz aus dem der Inhalt angehängt wird

Rückgabe:  
	Referenz auf das aktuelle Stringobjekt
*/

String& String::operator+=(String& s) {
	
	int new_size = size + s.size;
	char *new_string = new char[new_size + 1];
	int index = 0;

	for (int i = 0; i < size; i++) {
		new_string[index] = str[i];
		index++;
	} 

	for (int i = 0; i < s.size; i++) {
		new_string[index] = s.str[i];
		index++;
	}
	new_string[index] = '\0';

	delete str;
	str = new char[new_size];
	str = new_string;
	size = new_size;

	return *this;
}

int String::getSize() {
    return size;
}

char* String::getString() {
    return str;
}


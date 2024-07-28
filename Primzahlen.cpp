// Primzahlen.cpp.
// Autor: knights-to-mate-you 😀
// Erstmalige Bearbeitung: 27.07.2024
// 
// Das Programm lässt den Anwender auswählen wie er Primzahlen präsentiert haben möchte:
// (1) - Welche Zahl soll auf Prim geprüft werden?
// (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden?
// (3) - Berechnungen zu Primzahlen - Herleitung des Primzahlsatzes
// 
// Zu (3)
// Die Idee zur Berechnung der Verteilung von Primzahlen zu einer Zahlenreihe erhielt knights-to-mate-you aus einem Vortrag der
// Professoren Doktoren Damaris Schindler und Valentin Blomer, gehalten 2022 --> https://www.youtube.com/watch?v=2w53AvWaxPE
// Ein 3GHz-Rechner benötigt für die Berechnung der Anzahl von Primzahlen im Bereich 2 bis 10 Millionen über eine Stunde (ca. 1:14)!
// Für die Intervallberechnungen wird daher der Bereich bis maximal eine Million genommen.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stdbool.h>
#include "Primzahlen.h"

 // Variablendefinitionen:
int Zahl = 0;                // Numerische Variable für die zu prüfende Zahl des Anwenders
int Teilersuchzahl = 2;      // Numerische Variable für die Teilersuche
int Mal = 0;				 // Numerische Variabel für Schleifenzähler
int Anzahl = 0;              // Numerische Variable für das Zählen aller gefundenen Primzahlen
int Anzahl1 = 0;			 // Numerische Variable für das Zählen aller gefundenen Primzahlen im ersten Intervall
int Anzahl2 = 0;			 // Numerische Variable für das Zählen aller gefundenen Primzahlen im ersten Intervall
int Anzahl3 = 0;			 // Numerische Variable für das Zählen aller gefundenen Primzahlen im ersten Intervall
int Anzahl4 = 0;			 // Numerische Variable für das Zählen aller gefundenen Primzahlen im ersten Intervall
int Anzahl5 = 0;			 // Numerische Variable für das Zählen aller gefundenen Primzahlen im ersten Intervall
int Primzahlindikator = 0;   // Numerische Variable für Primzahlindikator
float Verhaeltnis = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen
float Verhaeltnis1 = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen
float Verhaeltnis2 = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen
float Verhaeltnis3 = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen
float Verhaeltnis4 = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen
float Verhaeltnis5 = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen
float Differenz1 = 0.00000000; // Dezimalvariable für die Differenz des Primzahlenverteilungverhältnisses
float Differenz2 = 0.00000000; // Dezimalvariable für die Differenz des Primzahlenverteilungverhältnisses
float Differenz3 = 0.00000000; // Dezimalvariable für die Differenz des Primzahlenverteilungverhältnisses
float Differenz4 = 0.00000000; // Dezimalvariable für die Differenz des Primzahlenverteilungverhältnisses

static void Pruefe_Zahl(int Zahl) // Anwenderoption 1
{
	std::cout << "                       Geben Sie nun die Zahl ein, die auf Prim geprueft werden soll: "; std::cin >> Zahl; std::cout << std::endl;
	while (Teilersuchzahl <= sqrt(Zahl)) // oder alternativ: while (Teilersuchzahl * Teilersuchzahl <= Zahl)
	{
		if (Zahl % Teilersuchzahl == 0)
		{
			std::cout << "                       " << Zahl << " ist keine Primzahl. \n";
			break;  // Sobald ein Teiler gefunden wurde, muss nicht weiter auf Primzahl geprüft werden - Verlassen der if-Schleife.
		}
		else
		{
			std::cout << "Teilnehmersuchzahl: " << Teilersuchzahl << " \n";
			Teilersuchzahl = Teilersuchzahl + 1;
		}
	}
	std::cout << "                      " << Zahl << " ist eine Primzahl. \n";

}

static void Anwendergrenze(int Zahl)  // Anwenderoption 2
{
	std::cout << "                       Geben Sie jetzt die Zahl ein, bis zu der alle Primzahlen angezeigt werden sollen: "; std::cin >> Zahl; std::cout << std::endl;

	for (int i = 2; i <= Zahl; i++)   // Es müssen solange die Zahlen von 2 ausgehend auf Prim geprüft werden, bis die vom Anwender gewünschte Zahl erreicht ist.
		// Dazu muss man wissen, dass 1 per Definition in der Mathematik nicht als Primzahl gilt. Daher wird mit 2 begonnen.
	{
		// Jede Zahl von 2 ausgehend wird beginnend mit 2 solange geteilt bis die vom Anwender gewünschte Zahl erreicht ist.
		Primzahlindikator = 1;
		for (int Teilersuche = 2; Teilersuche < i; Teilersuche++)
		{
			if (i % Teilersuche == 0)
			{
				Primzahlindikator = 0;
				break;      // Sobald ein Teiler gefunden wurde, wird die Schleife verlassen, da weitere Prüfung auf Primzahl nicht nötig.
			}
		}
		if (Primzahlindikator == 1)
		{
			Anzahl++;
			std::cout << "                                                    " << i << " --> Anzahl:  " << Anzahl << "\n";
		}
	}
	std::cout << std::endl;
	std::cout << "                         Es gibt somit " << Anzahl << " Primzahlen im Zahlenbereich von 2 bis " << Zahl << ".\n";
	std::cout << std::endl;
	float Verhaeltnis = (float)Zahl / Anzahl;
	std::cout << "                         " << "Ein " << Verhaeltnis << ".tel der Zahlen von 2 bis " << Zahl << " sind also Primzahlen. " << "\n";
}

static void Berechnungen(int Zahl)  // Anwenderoption 3
{
	std::cout << "                       + + + Berechnungen zu Primzahlen + + +   Ueberblick   + + +\n\n\n";
	std::cout << "                       fuer x >= 2 sei Pi(x) die Anzahl der Primzahlen im Intervall [2, x].\n\n";
	std::cout << "                       1 - Anzahl Primzahlen fuer Intervall 2 bis 10^2, 10^3, 10^4, 10^5 und 10^6 \n\n";
	std::cout << "                       2 - Verteilung der Primzahlen auf alle Zahlen, also Verhaeltnis der gefundenen\n";
	std::cout << "                           Primzahlen zu allen Zahlen des Intervalls, ergo x / Pi(x) \n\n";
	std::cout << "                       3 - Differenz der Primzahlverteilungsverhaeltnisse zueinander \n\n\n\n";
	system("pause");
	std::cout << std::endl << std::endl;

	std::cout << "                       Berechnungen starten ... \n\n\n";
	for ( int Mal = 1; Mal <= 5; Mal++)
	{
		switch (Mal)
		{
		case 1:
			Zahl = 100;
			break;
		case 2:
			Zahl = 1000;
			break;
		case 3:
			Zahl = 10000;
			break;
		case 4:
			Zahl = 100000;
			break;
		case 5:
			Zahl = 1000000;
			break;

		default:
			std::cout << " Fehler in der Zahl!  😒 \n\n";
			break;
		}
		
		
		Anzahl = 0;
		Verhaeltnis = 0;

		for (int i = 2; i <= Zahl; i++)   // Es müssen solange die Zahlen von 2 ausgehend auf Prim geprüft werden, bis die Endezahl des Intervalls erreicht ist.
			
		{
			// Jede Zahl von 2 ausgehend wird beginnend mit 2 solange geteilt bis die Endezahl des Invervalls erreicht ist.
			Primzahlindikator = 1;
			for (int Teilersuche = 2; Teilersuche < i; Teilersuche++)
			{
				if (i % Teilersuche == 0)
				{
					Primzahlindikator = 0;
					break;      // Sobald ein Teiler gefunden wurde, wird die Schleife verlassen, da weitere Prüfung auf Primzahl nicht nötig.
				}
			}
			if (Primzahlindikator == 1)
			{
				Anzahl++;
				std::cout << "                                            Primzahl: " << i << " --> Anzahl:  " << Anzahl << "\n";
			}
		}
		std::cout << std::endl;
		std::cout << "                         Es gibt somit " << Anzahl << " Primzahlen im Zahlenbereich von 2 bis " << Zahl << ".\n";
		std::cout << std::endl;
		float Verhaeltnis = (float)Zahl / Anzahl;
		std::cout << "                         " << "Ein " << Verhaeltnis << ".tel der Zahlen von 2 bis " << Zahl << " sind also Primzahlen. " << "\n";
		system("pause");
		std::cout << std::endl << std::endl << std::endl;
		switch (Mal)
		{
		case 1:
			Anzahl1 = Anzahl;
			Verhaeltnis1 = Verhaeltnis;
			break;
		case 2:
			Anzahl2 = Anzahl; 
			Verhaeltnis2 = Verhaeltnis;
			break;
		case 3:
			Anzahl3 = Anzahl;
			Verhaeltnis3 = Verhaeltnis;
			break;
		case 4:
			Anzahl4 = Anzahl;
			Verhaeltnis4 = Verhaeltnis;
			break;
		case 5:
			Anzahl5 = Anzahl;
			Verhaeltnis5 = Verhaeltnis;
			break;

		default:
			std::cout << " Fehler in der Zahl!  😒 \n\n";
			break;
		}
	}
	std::cout << "\n\n\n\n";
	std::cout << "Fuer die Zahlen 2 bis 100 gibt es " << Anzahl1 << " Primzahlen, wobei sie im Verhaeltnis von " << Verhaeltnis1 << " zu allen Zahlen dieser Reihe stehen. \n";
	std::cout << "Fuer die Zahlen 2 bis 1000 gibt es " << Anzahl2 << " Primzahlen, wobei sie im Verhaeltnis von " << Verhaeltnis2 << " zu allen Zahlen dieser Reihe stehen. \n";
	std::cout << "Fuer die Zahlen 2 bis 10000 gibt es " << Anzahl3 << " Primzahlen, wobei sie im Verhaeltnis von " << Verhaeltnis3 << " zu allen Zahlen dieser Reihe stehen. \n";
	std::cout << "Fuer die Zahlen 2 bis 100000 gibt es " << Anzahl4 << " Primzahlen, wobei sie im Verhaeltnis von " << Verhaeltnis4 << " zu allen Zahlen dieser Reihe stehen. \n";
	std::cout << "Fuer die Zahlen 2 bis 1000000 gibt es " << Anzahl5 << " Primzahlen, wobei sie im Verhaeltnis von " << Verhaeltnis5 << " zu allen Zahlen dieser Reihe stehen. \n\n\n";

	system("pause");
	std::cout << std::endl << std::endl;
	
	Differenz1 = Verhaeltnis2 - Verhaeltnis1;
	Differenz2 = Verhaeltnis3 - Verhaeltnis2;
	Differenz3 = Verhaeltnis4 - Verhaeltnis3;
	Differenz4 = Verhaeltnis5 - Verhaeltnis4;

	std::cout << "Aus der Differenz der Primzahlverteilungsverhaeltnisse der einzelenen Intervalle bis max. 1.000.000 gibt es eine Auffaelligkeit:\n\n";
	std::cout << "Intervalle 2 bis 1000 minus 2 bis 100       --> Differenz 1: " << Differenz1 << "\n";
	std::cout << "Intervalle 2 bis 10000 minus 2 bis 1000     --> Differenz 2: " << Differenz2 << "\n";
	std::cout << "Intervalle 2 bis 100000 minus 2 bis 10000   --> Differenz 3: " << Differenz3 << "\n";
	std::cout << "Intervalle 2 bis 1000000 minus 2 bis 100000 --> Differenz 4: " << Differenz4 << "\n\n\n";
	std::cout << "Die Auffaelligkeit besteht darin, dass die Differenz4 nahe dem natuerlichen Logarithmus von 10 ist und dies auch die weiteren \n";
	std::cout << "Differenzen der Primzahlverteilungsverhaeltnisse betrifft (die hier mangels Rechenkraft nicht dargestellt werden koennen). \n";
	std::cout << "Aus diesem Fakt leitet sich der Primzahlsatz ab.\n\n";
}

static void Auswahl()       // muss hier stehen, d. h. unter allen anderen Funktionen, da Parameter sonst nicht bekannt sind.
{
	int Auswahloption = 0;       // Numerische Variable für die Anwenderauswahl
	std::cout << "                       (1) - Welche Zahl soll auf Prim geprueft werden ?\n";
	std::cout << "                       (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden ?\n\n";
	std::cout << "                       (3) - Berechnungen zu Primzahlen --> Primzahlsatz \n\n";
	std::cout << "                       Auswahl: "; std::cin >> Auswahloption; std::cout << "\n\n\n";
	switch (Auswahloption)
	{
	case 1:
		Pruefe_Zahl(Zahl);   // Funktionsaufruf (1): Die vom Anwender eingegebene Zahl wird auf Prim geprüft.   
		break;
	case 2:
		Anwendergrenze(Zahl);  // Funktionsaufruf (2): Prüfen der Zahlen auf Prim bis zu der vom Anwender gewünschten.
		break;
	case 3:
		Berechnungen(Zahl); // Funktionsaufruf (3): Berechnung der Anzahl von Primzahlen in einem bestimmten Intervall.
		break;
	default:            // ist gleichzeitig die Prüfung auf Korrektheit der Anwendereingabe
		std::cout << "              Sie haben " << Auswahloption << " angegeben. \n";
		std::cout << "              Die Auswahl muss jedoch ausschliesslich 1, 2 oder 3 sein! \n\n";
		Auswahl();  // Funktionsaufruf: Anwendereingabe (Auswahl)
		break;
	}
}
int main()
{
	std::cout << "                       ******** Primzahlenprogramm ******** \n\n";
	std::cout << "                       Primzahlen sind Zahlen, die nur durch Eins und sich selbst geteilt werden koennen.\n";
	std::cout << "                       Eins ist per Definition keine Primzahl. \n\n";
	std::cout << "                       ************************************ \n\n";
	std::cout << "                       \n\n\n";
	Auswahl();  // Funktionsaufruf: Auswahl
}
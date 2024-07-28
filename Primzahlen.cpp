// Primzahlen.cpp.
// Autor: knights_to_mate_you 😀
// Erstmalige Bearbeitung: 27.07.2024
// 
// Das Programm lässt den Anwender auswählen wie er Primzahlen präsentiert haben möchte:
// (1) - Welche Zahl soll auf Prim geprüft werden?
// (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden?
// (3) - Intervalle vorgegeben, wobei gilt: für x >= 2 sei π(x) die Anzahl der Primzahlen im Intervall [2, x].
// 
// 
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stdbool.h>
#include "Primzahlen.h"



 // Variablendefinitionen:
int Auswahloption = 0;       // Numerische Variable für die Anwenderauswahl
int Zahl = 0;                // Numerische Variable für die zu prüfende Zahl des Anwenders
int Teilersuchzahl = 2;      // Numerische Variable für die Teilersuche
int Anzahl = 0;              // Numerische Variable für das Zählen aller gefundenen Primzahlen
int Primzahlindikator = 0;   // Numerische Variable für Primzahlindikator
float Verhaeltnis = 0.00000; // Dezimalvariable für das Verhältnis von Zahl zu Anzahl der Primzahlen

static void Auswahl()
{
        std::cout << "                       (1) - Welche Zahl soll auf Prim geprueft werden ?\n";
        std::cout << "                       (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden ?\n\n";
        std::cout << "                       (3) - Anzahl der Primzahlen in bestimmten Intervallen \n\n";
        std::cout << "                       Auswahl: "; std::cin >> Auswahloption; std::cout << "\n\n\n";
}

static void Pruefe_Zahl(int Zahl)
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

static void Anwendergrenze(int Zahl)
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
    std::cout << "                         Es gibt also " << Anzahl << " Primzahlen im Zahlenbereich von 2 bis " << Zahl << ".\n";
    std::cout << std::endl;
    float Verhaeltnis = (float)Zahl / Anzahl;
    std::cout << "                         " << "Ein " << Verhaeltnis << ".tel der Zahlen von 2 bis " << Zahl << " sind also Primzahlen. " << "\n";
}

static void Intervall(int Zahl)
{
    std::cout << "                       Hier kommt der Intervall-Teil rein - in Bearbeitung ... \n\n";
}

int main()
{
    std::cout << "                       ******** Primzahlenprogramm ******** \n\n";
    std::cout << "                       Primzahlen sind Zahlen, die nur durch Eins und sich selbst geteilt werden koennen.\n";
    std::cout << "                       Eins ist per Definition keine Primzahl. \n\n";
    std::cout << "                       ************************************ \n\n";
    std::cout << "                       \n\n\n";
       
   
        Auswahl();  // Funktionsaufruf: Prüfen der Anwendereingabe auf Korrektheit.
        switch (Auswahloption)
        {
        case 1:
            Pruefe_Zahl(Zahl);   // Funktionsaufruf: Die vom Anwender eingegebene Zahl wird auf Prim geprüft.   
            break;
        case 2:
            Anwendergrenze(Zahl);  // Funktionsaufruf: Prüfen der Zahlen auf Prim bis zu der vom Anwender gewünschten.
            break;
        case 3:
            Intervall(Zahl); // Funktionsaufruf: Berechnung der Anzahl von Primzahlen in einem bestimmten Intervall.
            break;
        default:
            std::cout << "              Sie haben " << Auswahloption << " angegeben. \n";
            std::cout << "              Die Auswahl muss jedoch ausschliesslich 1, 2 oder 3 sein! \n\n";
            Auswahl();  // Funktionsaufruf: Anwendereingabe (Auswahl)
            break;
        }
   
    
    // return 0;
        // Last Edit: 08.10 am GMT+1

   
}



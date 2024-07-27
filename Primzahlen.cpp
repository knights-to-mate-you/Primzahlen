// Primzahlen.cpp.
// Autor: knights_to_mate_you 😀
// Erstmalige Bearbeitung: 27.07.2024
// 
// Das Programm lässt den Anwender auswählen wie er Primzahlen präsentiert haben möchte:
// (1) - Welche Zahl soll auf Prim geprüft werden?
// (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden?
// 
// 
// 
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stdbool.h>

int main()
{
    // Variablendefinitionen:
    int Auswahl = 0;             // Numerische Variable für die Anwenderauswahl
    int Zahl = 0;                // Numerische Variable für die zu prüfende Zahl des Anwenders
    int Teilersuchzahl = 2;      // Numerische Variable für die Teilersuche
    int Anzahl = 0;              // Numerische Variable für das Zählen aller gefundenen Primzahlen
    int Primzahlindikator = 0;   // Numerische Variable für Primzahlindikator

    std::cout << "                       ******** Primzahlenprogramm ******** \n\n";
    std::cout << "                       (1) - Welche Zahl soll auf Prim geprueft werden ?\n";
    std::cout << "                       (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden ?\n\n";
    std::cout << "                       Auswahl: "; std::cin >> Auswahl; std::cout << "\n\n\n";

    while (Auswahl<1 or Auswahl > 2)   // Prüfen der Anwendereingabe auf Korrektheit
    {
        std::cout << "                       Sie haben " << Auswahl << " eingegeben.\n";
        std::cout << "                       Die Auswahl muss jedoch ausschliesslich 1 oder 2 sein! \n\n";
        std::cout << "                       (1) - Welche Zahl soll auf Prim geprueft werden ?\n";
        std::cout << "                       (2) - Bis zu welcher Zahl sollen Primzahlen angezeigt werden ?\n\n";
        std::cout << "                       Auswahl: "; std::cin >> Auswahl; std::cout << "\n\n\n";
    }
    if (Auswahl == 1)
    {
        std::cout << "                       Geben Sie nun die Zahl ein, die auf Prim geprueft werden sollen: "; std::cin >> Zahl; std::cout << std::endl;
        while (Teilersuchzahl <= sqrt(Zahl)) // oder alternativ: while (Teilersuchzahl * Teilersuchzahl <= Zahl)
        {
            if (Zahl % Teilersuchzahl == 0)
            {
                std::cout << "                       " << Zahl << " ist keine Primzahl. \n";
                return 0;  // Beenden der while-Schleife, weil ein Teiler gefunden wurde und damit keine weitere Prüfung auf Prim nötig ist.
            }
            else
            {
                std::cout << "Teilnehmersuchzahl: " << Teilersuchzahl << " \n";
                Teilersuchzahl = Teilersuchzahl + 1;
            }
        }
        std::cout << "                         " << Zahl << " ist eine Primzahl. \n";
    }
    else // Wenn also die Auswahl = 2 ist, dann: ... sollen alle Zahlen bis zur vom Anwender eingegebenen auf Prim geprüft werden.
    {
        std::cout << "                       Geben Sie jetzt die Zahl ein, bis zu der alle Primzahlen angezeigt werden sollen: "; std::cin >> Zahl; std::cout << std::endl;

        for (int i = 2; i <= Zahl; i++)   // Es müssen solange die Zahlen von 2 ausgehend auf Prim geprüft werden, bis die vom Anwender gewünschte Zahl erreicht ist.
                                          // Dazu muss man wissen, dass 1 per Definition in der Mathematik nicht als Primzahl gilt. Daher wird mit 2 begonnen.
        {
            // Jede Zahl von 2 ausgehend wird beginnend mit 2 solange geteilt bis die vom Anwender gewünschte Zahl erreicht ist.
            Primzahlindikator = 1;
            for (int Teilersuche = 2; Teilersuche< i; Teilersuche++)
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
                std::cout << "                                                    " << i << "\n";
            }   
        }
        std::cout << std::endl;
        std::cout << "                    Es gibt also " << Anzahl << " Primzahlen im Zahlenbereich von 1 bis " << Zahl << ".\n";
    }
}



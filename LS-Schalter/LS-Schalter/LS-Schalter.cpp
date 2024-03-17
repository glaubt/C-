//LS Schalter
#include <iostream>
#include<Windows.h>
int main() {
	std::cout << "Was ist ein LS-Schalter? : Press 1\n";
	std::cout << "Wann der Lost auf? : Press 2\n";
	std::cout << "Aus was besteht ein LS-Schalter? : Press 3\n";
	std::cout << "Welche Typen gibt es? : Press 4\n";

	int wählen;

    std::cin >> wählen;

    switch (wählen) {
    case 1:
        std::cout << "Der Leitungsschutzschalter begrenzt den Kurzschlussstrom konstruktionsbedingt auf einen niedrigeren Wert.";
        break;
    case 2:
        std::cout << "LS-Schalter losen aus,Typ B beim 3-bis 5 fachen, Typ C beim 5-bis 10 fachen, Typ D beim 10-bis 20 fachen Bemessungsstrom.";
        break;
    case 3:
        std::cout << "thermischen Auslöser (Bimetall) einen Überlastschutz und durch die elektromagnetische Auslösung einen Schutz gegen Kurzschluss";
        break;
    case 4:
        std::cout << "Typ A, Typ B, Typ C es ist am meistens draußen eingebaut werden.";
        break;
    default:
        std::cout << "Ungültige Auswahl!";
    }

    return 0;
}
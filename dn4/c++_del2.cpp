#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Odpremo vhodno datoteko
    ifstream inputFile("poly.txt");
    if (!inputFile) {
        cerr << "Napaka pri odpiranju datoteke poly.txt" << endl;
        return 1;
    }

    // Preberemo prvo vrstico, ki predstavlja stevilo vrednosti
    int N_points;
    inputFile >> N_points;

    //Definiramo vektorja za shranjevanje vrednosti x in f(x)
    vector<double> xValues;
    vector<double> fxValues;

    // Preberemo vrstice z vrednostmi x in f(x) ter jih shranimo v prej definirana vektorja
    for (int i = 0; i < N_points; ++i) {
        int id;
        double x, fx;
        char colon;
        inputFile >> id >> colon >> x >> fx;
        xValues.push_back(x);
        fxValues.push_back(fx);
    }

    // Zapremo vhodno datoteko
    inputFile.close();

    // Odpremo izhodno datoteko za shranjevanje odvodov
    ofstream outputFile("diff_poly.txt");
    if (!outputFile) {
        cerr << "Napaka pri ustvarjanju izhodne datoteke diff_poly.txt" << endl;
        return 1;
    }

    // Izracunamo vrednosti odvodov
    for (int i = 0; i < N_points; ++i) {
        double df;

        if (i == 0) {
            // Diferencna shema naprej za prvo tocko
            df = (-3 * fxValues[i] + 4 * fxValues[i + 1] - fxValues[i + 2]) / (2 * (xValues[i + 1] - xValues[i]));
        }
        else if (i == N_points - 1) {
            // Diferenčna shema nazaj za zadnjo tocko
            df = (3 * fxValues[i] - 4 * fxValues[i - 1] + fxValues[i - 2]) / (2 * (xValues[i] - xValues[i - 1]));
        }
        else {
            // Centralna diferencna shema za vmesne tocke
            df = (fxValues[i + 1] - fxValues[i - 1]) / (2 * (xValues[i + 1] - xValues[i]));
        }

        // Shranimo vrednosti odvodov v izhodno datoteko
        outputFile << df << endl;
    }

    // Zapremo izhodno datoteko
    outputFile.close();

    cout << "Odvodi so bili uspesno izracunani in shranjeni v diff_poly.txt" << endl;

    return 0;
}

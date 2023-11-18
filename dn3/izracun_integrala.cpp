#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

double arctan_taylorjeva_vrsta(double x, int n) {
    // Razvoj funkcije arctan(x) v Taylorjevo vrsto, n clenov
    double vsota = 0;
    for (int i = 0; i <= n; ++i) {
        double clen = (pow(-1, i) * pow(x, 2 * i + 1)) / (2 * i + 1); // Vrednost i-tega clena
        vsota += clen; // Vsota i clenov
    }
    return vsota;
}

double f(double x, int n) {
    // Definicija funkcije f
    double arctan_taylor = arctan_taylorjeva_vrsta(x / 2, n); // Taylorjeva vrsta funkcije arctan(x/2), n clenov
    return exp(3 * x) * arctan_taylor; // Funkcija f
}

double trapezna_metoda(double a, double b, int n) {
    // Definicija numericnega integrala s trapezno metodo
    double h = (b - a) / n; // Dolzina podintervala
    double integral = (f(a, n) + f(b, n)) / 2; // Polovica vsote vrednosti funkcije f na mejah integracijskega intervala
    for (int j = 1; j < n; ++j) {
        double x_j = a + j * h; // X-koordinate tock mej podintervalov, brez mej integracijskega intervala
        integral += f(x_j, n); // Vsota vrednosti funkcije f na mejah podintervalov ter na mejama integracijskega intervala
    }
    integral *= h; // Mnozenje prej omenjene vsote z dolzino intervala
    return integral; // Vrednost priblizka dolocenega integrala funkcije f
}

int main() {
    // Meji integracijskega intervala
    double a = 0; // Spodnja meja
    double b = M_PI / 4; // Zgornja meja

    // Stevilo podintervalov in stevilo clenov razvoja Taylorjeve vrste
    int n = 1000;

    // Vrednost integrala z uporabo trapezne metode
    double rezultat = trapezna_metoda(a, b, n);

    std::cout << "Priblizna vrednost integrala: " << rezultat << std::endl;

    return 0;
}

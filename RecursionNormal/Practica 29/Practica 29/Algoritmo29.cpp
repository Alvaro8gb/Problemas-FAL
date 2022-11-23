// ALVARO GARCIA BARRagan
// A31
// A16
//
#include <iostream>
#include <fstream>
// Aqui ecuaciones recursivas que resuelven el problema.
// Se puede elegir dar las ecuaciones para una recursión final
// o para una no final.
//
//
//
/*
ECUACIONES algoritmo no final:
f(n,digito) = 1 si n<10 y n=digito
f(n,digito) = 0 si n<10 y n!=digito
f(n,digito) = f(n/10,digito) +1 si n>10 y n=digito
f(n,digito) = f(n/10,digito) si n>10 y n!=digito

*/
// Función recursiva no final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionNoFinal(int n, int digito) {
	if (n < 10) {
		if (digito == n) return 1;
		else return 0;
	}
	else {
		if (digito == n % 10) return recursionNoFinal(n / 10, digito) + 1;
		else return recursionNoFinal(n / 10, digito);
	}
}
// Función recursiva final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionFinal(int n, int digito, int cont) {
	if (n < 10) {

		if (digito == n) return 1 + cont;
		else return 0 + cont;
	}
	else {
		if (digito == n % 10) return recursionFinal(n / 10, digito, cont + 1);
		else return recursionFinal(n / 10, digito, cont);
	}
}
void resuelveCaso() {
	// lectura delos datos
	int numero, digito;
	std::cin >> numero >> digito;
	// LLamadas a las funciones recursivas
	// Modificar parámetros o tipo de retorno donde se necesite
	int s1 = recursionNoFinal(numero, digito);
	int s2 = recursionFinal(numero, digito, 0);
	// Escribir los resultados. Modificar si se necesita
	std::cout << s1 << ' ' << s2 << '\n';
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
// ALVARO GARCIA BARRagan
// A31
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
f(n,pot) = (n *10 + n) * pot     si n<10 
f(n,pot) =  f(n/10,pot*100)  + ((n%10)*10 + n%10)*pot   si n>10 

*/
// Función recursiva no final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionNoFinal(int n,int pot) {
	if (n < 10) return (n *10 + n) * pot ;
	else {
		int digito = n % 10;
		return recursionNoFinal(n / 10,pot*100) + (digito*10 + digito)*pot;
	}
	
}
// Función recursiva final
// Se pueden añadir parámetros por valor a la función
// Se pueden devolver más valores si se necesitan en el valor de retorno
int recursionFinal(int n, int pot,int act ) {
	if (n < 10) return (n * 10 + n) * pot + act;
	else {
		int digito = n % 10;
		return recursionFinal(n / 10, pot * 100,act+ (digito * 10 + digito) * pot);
	}

}
void resuelveCaso() {
	// lectura delos datos
	int numero;
	std::cin >> numero ;
	// Modificar parámetros o tipo de retorno donde se necesite
	// Escribir los resultados. Modificar si se necesita
	std::cout << recursionNoFinal(numero, 1) << ' ' << recursionFinal(numero,1,0)<< '\n';
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
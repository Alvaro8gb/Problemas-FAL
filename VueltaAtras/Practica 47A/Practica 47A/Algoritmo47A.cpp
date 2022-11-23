//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//VR
//Variaciones con repeticion de 3 elementos tomados de n en n  VR 3,n= 3^n 

const int COLORS = 3; // azul,rojo,verde
//k es la etapa del arbol de exploracion

std::string numToColor(int n) {
	switch (n) {

	case(0):
		return  "azul";

	case(1):
		return "rojo";

	case(2):
		return  "verde";
	}
}
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v)std::cout <<  numToColor(num)<<" ";
		
	std::cout << '\n';
}
// Calcula de forma recursiva las variaciones de los elementos
void variaciones(int m, int n, int k, std::vector <int >& sol) {
	for (int i = 0; i < COLORS; i++) {
		sol[k] = i;
		if (k == n - 1) { // Es solucion
			escribirSolucion(sol);
		}
		else { // Sigue completando la solucion
			variaciones(m, n, k + 1, sol);
		}
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int n;
	std::cin >> n;
	if (n==0) return false;
	// Generar las soluciones
	std::vector <int > sol(n);
	variaciones(COLORS, n, 0, sol);
	std::cout << '\n';
	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif

	while (resuelveCaso()) {} // Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
# endif
	return 0;
}

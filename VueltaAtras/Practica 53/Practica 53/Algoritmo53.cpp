//Alvaro GARCIA BARRAGAN
//A31
#include <fstream>
#include <vector>
#include <iostream>

//k es la estapa del arbol de exploracion, que identifica  en este problema a los  niños
// n es el  numero de tareas  que hay que realizar
// a el numero de alumnos de la clase a 
// t  el numero m´aximo de tareas que puede realizar un alumno 
// sol vector que contiene los niños que asigna a cada tarea

using tMatriz = std::vector <std::vector<short int>>;

struct tDatos {
	int n,a,t;
};

struct tSol {
	std::vector <int> sol;
	int sumaPuntuacion;
};
// Escribe una solucion
void escribirSolucion(std::vector <int > const& v) {
	for (int num : v) std::cout << num << " ";
	std::cout << '\n';
}

int inicializarSol(tMatriz const& puntuacionNinoTarea, tDatos const& d) {
	//a*t > 2*n
	int posibleSol = 0,i = 0,j= 0 , numTareas = 0;

	while (j < d.a && numTareas < 2 * d.n) {
		while (i < d.t && numTareas < 2*d.n) {
			posibleSol += puntuacionNinoTarea[j][i];
			numTareas++;
			i++;
		}
		if (i == d.t) {
			j++;
			i = 0;
		}
	}

	return posibleSol;
}
bool esValida(tDatos const &  d,int i, int k, tSol& s, std::vector <int>& ninosUsados) {
	//esValida tiene coste constante
	if (k % 2 == 1) {//El mismo niño no puede relizar una tarea dos veces

		if (s.sol[k - 1] == s.sol[k])return false;
	}

	if (ninosUsados[i] > d.t) return false;

	return true;
}
// Calcula de forma recursiva las variaciones de los elementos
void resolver(tDatos const& d, int k,std::vector <int> & ninosUsados, std::vector <int> const &acum, tMatriz const& puntuacionNinoTarea , tSol s, tSol& mejorSol) {

	for (int i = 0; i < d.a; i++) {

		s.sol[k] = i;
		
		ninosUsados[i]++;
		s.sumaPuntuacion += puntuacionNinoTarea[i][k / 2];

		if (esValida(d,i,k,s,ninosUsados)){

			if (k == d.n*2 -1) { //Es solución
				if (s.sumaPuntuacion > mejorSol.sumaPuntuacion)mejorSol = s;
				
			}
			else { // Sigue completando la solucion 
				if(acum[k/2] + s.sumaPuntuacion  > s.sumaPuntuacion) resolver(d, k + 1,ninosUsados,acum, puntuacionNinoTarea, s,mejorSol);
			}
		}
		ninosUsados[i]--;
		s.sumaPuntuacion -= puntuacionNinoTarea[i][k / 2];
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;
	std::cin >> d.n >> d.a >> d.t;

	if (d.n == 0) return false;

	tSol s;
	s.sol.resize(d.n*2);
	s.sumaPuntuacion = 0;

	tMatriz puntuacionNinoTarea(d.a, std::vector <short int >(d.n));
	for (int i = 0; i < d.a; i++) {
		for (int j = 0; j < d.n; j++) std::cin >> puntuacionNinoTarea[i][j];
	}

	std::vector <int> ninosUsados(d.a,0); //marcas

	tSol mejorSol = s;//Se inicializa una puntuacion posible
	//para guardar la solucion

	//Para estimar
	std::vector <int> acum(d.n);
	int max, maxS;
	for (int i = 0; i < d.n; i++) {
		max = maxS = puntuacionNinoTarea[0][i];
		for (int j = 1; j < d.a; j++) {
			if (max < puntuacionNinoTarea[j][i]) {
				maxS = max;
				max = puntuacionNinoTarea[j][i];
			}
		}
		acum[i] = max + maxS;
	}

	for (int i = acum.size() - 1; i > 0; i--) acum[i - 1] += acum[i];

	resolver(d, 0, ninosUsados, acum, puntuacionNinoTarea, s,mejorSol);

	std::cout << mejorSol.sumaPuntuacion << "\n";

	escribirSolucion(mejorSol.sol);

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
	system("PAUSE");
# endif
	return 0;
}


//Alvaro GARCIA BARRAGAN
//A31

//Link video: https://www.youtube.com/watch?v=yuhFdICyPQw leer descripcion del video


#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

// sol vector booleano (arbol de exploracion binario) que para un calle i , si v[i] = true limpia la calle , cc v[i] = false (no la limpia).
//k etapa del arbol de exploracion  en  la que esta y en este problema es la calle en la que se encuentra
// variable a maximizar sumaLongitud

/**Restricciones de funcionalidad**/
/* numCalles,salTotalDisponible,numMinVecinosSatisfechos >=0 
Ademas para toda calle i se cumple que longitud, cantidadSal, numVecinos >=0*/

/***Tipos de datos***/
struct tCalle {
	int longitud, cantidadSal, numVecinos;
};
struct tDatos {
	int numCalles, salTotalDisponible, numMinVecinosSatisfechos;
	std:: vector <tCalle> listaCalles;
};
struct tSol {
	std::vector <bool> sol;
	int sumaSal, sumaLongitud, sumaVecinos;
};
class comparador {
public:
	bool operator ()(tCalle p1, tCalle p2) {
		return (float)p1.longitud / p1.cantidadSal > (float)p2.longitud / p2.cantidadSal;
	}
};

/***** Funciones adicionales *****/
void mostrarSolEnModoLectura(tSol const& sol, const std::string nombreCiudad);
void mostrarEnModoDebug(tSol const& sol);

// Escribe una solucion
void escribirSolucion(std::vector <bool > const& v) {
	for (int i = 0; i < v.size(); i++) if (v[i]) std::cout << i << " ";
	std::cout << '\n';
}
// Para estimar la mayor longitud que se puede conseguir desde este momento
int estimar(tDatos const& d, int sumaSalAct, int k) {
	int i = k+1, sumaLongitud = 0, sumaSal = sumaSalAct, numVecinosSats = 0;
	while (i < d.numCalles && sumaSal + d.listaCalles[i].cantidadSal <= d.salTotalDisponible) {
		sumaLongitud += d.listaCalles[i].longitud;
		sumaSal += d.listaCalles[i].cantidadSal;
		numVecinosSats += d.listaCalles[i].numVecinos;
		i++;
	}
	// La parte que queda sin completar , se añade un objeto partido que siempre va a ser mejor que lo real
	if (i <  d.numCalles && sumaSal < d.salTotalDisponible) sumaLongitud += d.listaCalles[i].longitud * (d.salTotalDisponible - sumaSal) / (float)d.listaCalles[i].longitud;

	return sumaLongitud;
}
tSol inicializarSolucion(tDatos const& d ) {
	tSol s,noValida = { {0},0,-1,0 };
	int i = 0;

	s.sol.resize(d.numCalles);
	s.sumaSal = s.sumaLongitud = s.sumaVecinos = 0;

	while (i < d.numCalles && s.sumaSal + d.listaCalles[i].cantidadSal <= d.salTotalDisponible) {
		s.sol[i] = true;
		s.sumaLongitud += d.listaCalles[i].longitud;
		s.sumaSal += d.listaCalles[i].cantidadSal;
		s.sumaVecinos += d.listaCalles[i].numVecinos;
		
		i++;
	}
	return d.numMinVecinosSatisfechos < s.sumaVecinos ? s : noValida;
}
// Calcula de forma recursiva las variaciones de los elementos
void resolver(tDatos const& d, int k, tSol& s, tSol& mejorSol) {

	s.sol[k] = true; //seleccionamos la calle
	s.sumaSal += d.listaCalles[k].cantidadSal;

	if (s.sumaSal <= d.salTotalDisponible ) { //Es valida
		s.sumaLongitud += d.listaCalles[k].longitud;
		s.sumaVecinos += d.listaCalles[k].numVecinos;

		if (k == d.numCalles - 1 ) { //Es solución
			if (mejorSol.sumaLongitud < s.sumaLongitud && s.sumaVecinos >= d.numMinVecinosSatisfechos) mejorSol = s;
		}
		else { // Sigue completando la solucion 
			resolver(d, k + 1, s, mejorSol);

		}
		s.sumaLongitud -= d.listaCalles[k].longitud;
		s.sumaVecinos -= d.listaCalles[k].numVecinos;
	}

	s.sol[k] = false; //No seleccionamos la calle
	s.sumaSal -= d.listaCalles[k].cantidadSal;

	if (k == d.numCalles - 1 ) { //Es solución
		if (mejorSol.sumaLongitud < s.sumaLongitud && s.sumaVecinos >= d.numMinVecinosSatisfechos) mejorSol = s;
	}
	else { // Sigue completando la solucion 
		if (estimar(d, s.sumaSal, k) + s.sumaLongitud > mejorSol.sumaLongitud) //si es posible superar la solucion 	
			resolver(d, k + 1, s, mejorSol);
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;
	std::string nombreCiudad;

	std::cin >> nombreCiudad >> d.numCalles >> d.salTotalDisponible >> d.numMinVecinosSatisfechos;

	if (!std::cin) return false;

	d.listaCalles.resize(d.numCalles);
	for (tCalle& x : d.listaCalles) std::cin >> x.longitud >> x.cantidadSal >> x.numVecinos ;

	sort(d.listaCalles.begin(), d.listaCalles.end(), comparador()); //Ordenamos de mayor a menor por longitud por unidad de sal

	tSol s;
	s.sol.resize(d.numCalles);
	s.sumaSal = s.sumaLongitud = s.sumaVecinos = 0;

	tSol mejorSol = inicializarSolucion(d); //para guardar la solucion  y la inicializamos a una solucion posible

	resolver(d, 0, s, mejorSol);
	
	if (mejorSol.sumaLongitud == -1) std::cout << "SIN SOLUCION\n";
	else {

		std::cout << mejorSol.sumaLongitud << "\n";
		//mostrarSolEnModoLectura(mejorSol, nombreCiudad);
		//mostrarEnModoDebug(mejorSol);
	}

	return true;
}
int main() {
#ifndef DOMJUDGE
	std::ifstream in("datosGrandes.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
# endif

	while (resuelveCaso()) {} // Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
# endif
	return 0;
}
void mostrarSolEnModoLectura(tSol const& s, const std::string nombreCiudad) {

	std::cout << "\nEn la ciudad " << nombreCiudad << " se pueden limpiar como maximo " << s.sumaLongitud << " metros de calles con " << s.sumaSal << " kilos de sal y satisfacer a un total de " << s.sumaVecinos << " vecinos.\n"; 
	std::cout << "\nListado de calles por su identificador : ";
	escribirSolucion(s.sol);

}
void mostrarEnModoDebug(tSol const& s) {
	std::cout << s.sumaLongitud <<"\n";
	escribirSolucion(s.sol);

}


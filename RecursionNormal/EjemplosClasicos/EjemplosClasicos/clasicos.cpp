#include <iostream>
#include <vector>
#include <string>
using li = long int;

//Cálculo de la potencia
//Recursión simple
/*
	Ecuaciones : 
	x^0 = 1; 
	x^n = x^(n-1)* x;

	Ej: 2^4 =  16
*/
li potenciaNoFinal(li num,int pot) {

	if (pot == 0) return 1;
	else return potenciaNoFinal(num, pot - 1) * num;
	//llamada : potenciaNoFinal(2,4);
}
li potenciaFinal(li num,li actual, int pot) {

	if (pot == 0) return 1*actual;
	else return potenciaFinal(num,actual*num, pot - 1);
	// llamada : potenciaFinal(2,1, 4); 
	
}
//Calculo del factorial
//Recursión simple
/*
	 Ecuaciones:
	 0! = 1; 
	 n! = (n − 1)! ∗ n;

	 Ej: 4! =24;
*/
li factorialNoFinal(li num) {

	if (num == 0) return 1;
	else return factorialNoFinal(num - 1)* num;
	//llamada: factorialNoFinal(4);
}

li factorialFinal(li num,li actual) {

	if (num == 0) return 1 *actual;
	else return factorialFinal(num - 1,actual*num);
	//llamada: factorialFinal(4,1);
}
//Busqueda binaria
//Recursión simple
std::vector<int>  v1 = { 0,1,2,3,4,5,6,7,8};
bool buscar(std::vector<int> const &v, int x,int ini, int fin){
	if (ini == fin) return false;
	else {
		int m = (ini + fin) / 2;
		if (x < v[m]) return buscar(v, x, ini, m);
		else if (x > v[m]) return buscar(v, x, m + 1, fin);
		else return true;
	}

	//llamada buscar(v1,8,0,v1.size()); devuelve true
}
//Calcula el termino introducido de la sucesióm de Fibonacci
//Recursion multipl MUY COMPLEJA 0(n^2)
li fib(li n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fib(n - 1) + fib(n - 2);
}

std::vector<int>  v2 = {2,4,6};
//Dado el vector 2 4 6, escribe 2 + 4 + 6
//Recursión simple
//Leindo el vector de principio a final
void escribirVector(std::vector<int> const& v, int i, int fin) {

	if (i == fin - 1) std::cout << v[i];
	else {
		std::cout << v[i] << "+";
		escribirVector(v, i + 1, fin);
	}
}
void escribirVectorAlReves(std::vector<int> const& v, int i, int fin) {

	if (i == fin-1) std::cout << v[i];
	else {
		
		escribirVectorAlReves(v, i+1, fin);

		std::cout << "+" << v[i] ;
	}
}

//Dado el numero x = 1572 escribe 2 + 7 + 5 + 1
void escribirDigitos(int num) {
	if (num < 10) std::cout << num;
	else {
		std::cout << num % 10 <<"+";
		escribirDigitos(num / 10);
		
	}
}
struct tSol {
	int inverso;
	int pot;
};
tSol invertirNoFinal(int num) {
	if (num < 10) return { num,10 };
	
	else {
		tSol sol = invertirNoFinal(num / 10);
		return { sol.inverso + (num % 10) * sol.pot,sol.pot * 10 };
	}
	// llamada tSol sol = invertirNoFinal(123); std::cout << sol.inverso;
	//salida 321
}
int invertirFinal(int num, int act) {

	if (num < 10) return num + act*10;
	else return invertirFinal(num / 10, num % 10 + act* 10);

	//llamada invertirFinal(123, 0);
	//salida 321
}
int main() {

	std::cout << fib(50);
	

	return 0;
}
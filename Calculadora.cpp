#include <iostream>

class Calculadora {
public:
    int sumar(int a, int b) {
        return a + b;
    }

    int restar(int a, int b) {
        return a - b;
    }

    int multiplicar(int a, int b) {
        return a * b;
    }

    double dividir(int a, int b) {
        if (b != 0) {
            return static_cast<double>(a) / b;
        } else {
            std::cout << "Error: No se puede dividir por cero." << std::endl;
            return 0.0;
        }
    }
};

int main() {
    Calculadora calculadora;

    // Ejemplo de uso
    int num1, num2;
    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;

    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    std::cout << "Suma: " << calculadora.sumar(num1, num2) << std::endl;
    std::cout << "Resta: " << calculadora.restar(num1, num2) << std::endl;
    std::cout << "Multiplicación: " << calculadora.multiplicar(num1, num2) << std::endl;
    std::cout << "División: " << calculadora.dividir(num1, num2) << std::endl;

    return 0;
}
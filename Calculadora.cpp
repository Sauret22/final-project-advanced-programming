// Santiago Sauret y Andres Gomez

#include <iostream>

// Base class: Operations
class Operations {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    double divide(int a, int b) {
        if (b != 0) {
            return static_cast<double>(a) / b;
        } else {
            std::cout << "Error: Cannot divide by zero." << std::endl;
            return 0.0;
        }
    }
};

// Derived class: Calculadora inherits from Operations
class Calculadora : public Operations {
    // No need to add new methods here since it inherits from Operations.
};

int main() {
    Calculadora calculadora;

    // Usage example
    int num1, num2;
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Sum: " << calculadora.add(num1, num2) << std::endl;
    std::cout << "Subtraction: " << calculadora.subtract(num1, num2) << std::endl;
    std::cout << "Multiplication: " << calculadora.multiply(num1, num2) << std::endl;
    std::cout << "Division: " << calculadora.divide(num1, num2) << std::endl;

    return 0;
}

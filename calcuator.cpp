// Santiago Sauret y Andres Gomez

#include <iostream>
#include <vector>

// Base class: Operations
class Operations {
public:
    // Method to add two integers
    int add(int a, int b) {
        int result = a + b;
        results.push_back(result);  // Store the result
        return result;
    }

    // Method to subtract two integers
    int subtract(int a, int b) {
        int result = a - b;
        results.push_back(result);
        return result;
    }

    // Method to multiply two integers
    int multiply(int a, int b) {
        int result = a * b;
        results.push_back(result);
        return result;
    }

    // Method to divide two integers
    double divide(int a, int b) {
        if (b != 0) {
            double result = static_cast<double>(a) / b;
            results.push_back(result);
            return result;
        } else {
            std::cout << "Error: Cannot divide by zero." << std::endl;
            return 0.0;
        }
    }

    // Method to get the results vector
    const std::vector<double>& getResults() const {
        return results;
    }

private:
    std::vector<double> results;
};

// Derived class: Calculator inherits from Operations
class Calculator : public Operations {
    // No need to add new methods here since it inherits from Operations.
};

int main() {
    Calculator calculator;

    // Usage example
    int num1, num2;
    char option;

    do {
        std::cout << "Enter the first number: ";
        std::cin >> num1;

        std::cout << "Enter the second number: ";
        std::cin >> num2;

        std::cout << "Select operation (+, -, *, /): ";
        std::cin >> option;

        switch (option) {
            case '+':
                std::cout << "Sum: " << calculator.add(num1, num2) << 
std::endl;
                break;
            case '-':
                std::cout << "Subtraction: " << calculator.subtract(num1, 
num2) << std::endl;
                break;
            case '*':
                std::cout << "Multiplication: " << 
calculator.multiply(num1, num2) << std::endl;
                break;
            case '/':
                std::cout << "Division: " << calculator.divide(num1, num2) 
<< std::endl;
                break;
            default:
                std::cout << "Invalid operation." << std::endl;
        }

        // Ask the user if they want to perform another operation
        std::cout << "Do you want to perform another operation? (y/n): ";
        std::cin >> option;

    } while (option == 'y' || option == 'Y');

    // Show previous operations
    const std::vector<double>& results = calculator.getResults();
    std::cout << "\nPrevious Results:" << std::endl;
    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << "Result " << (i + 1) << ": " << results[i] << 
std::endl;
    }

    return 0;
}


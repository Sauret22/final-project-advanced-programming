//Santiago Sauret y Andres Gomez

#include <iostream>
#include <string>

// Base class: Equipo
class Equipo {
protected:
    int puntos;

public:
    Equipo() : puntos(0) {}

    virtual void anotar(std::string equipo) = 0; // Pure virtual method for scoring, must be implemented by derived classes.
    virtual void mostrarPuntos() const {
        // Optional virtual method to display points.
        // Can be overridden by derived classes if necessary.
        std::cout << "Points: " << puntos << std::endl;
    }
};

// Derived class: ContadorPuntos inherits from Equipo
class ContadorPuntos : public Equipo {
private:
    std::string nombre;

public:
    ContadorPuntos(const std::string& nombreEquipo) : nombre(nombreEquipo) {}

    void anotar(std::string equipo) override {
        if (equipo == "E1") {
            puntos += 6;
            std::cout << "Touchdown for Team 1! 6 points added." << std::endl;
        } else if (equipo == "E2") {
            puntos += 6;
            std::cout << "Touchdown for Team 2! 6 points added." << std::endl;
        } else {
            std::cout << "Invalid team." << std::endl;
        }
    }

    void mostrarPuntos() const override {
        std::cout << "Points for " << nombre << ": " << puntos << std::endl;
    }
};

int main() {
    ContadorPuntos equipo1("Team 1");
    ContadorPuntos equipo2("Team 2");

    std::string equipo;
    char opcion;

    do {
        std::cout << "Enter the team (E1 or E2): ";
        std::cin >> equipo;

        std::cout << "Enter the action (T for Touchdown, Q to quit): ";
        std::cin >> opcion;

        switch (opcion) {
            case 'T':
                if (equipo == "E1") {
                    equipo1.anotar(equipo);
                } else if (equipo == "E2") {
                    equipo2.anotar(equipo);
                } else {
                    std::cout << "Invalid team." << std::endl;
                }
                break;
            case 'Q':
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid option." << std::endl;
        }

        equipo1.mostrarPuntos();
        equipo2.mostrarPuntos();

    } while (opcion != 'Q');

    return 0;
}
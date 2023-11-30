#include <iostream>
#include <string>

class ContadorPuntos {
private:
    int puntosEquipo1;
    int puntosEquipo2;

public:
    ContadorPuntos() : puntosEquipo1(0), puntosEquipo2(0) {}

    void anotarTouchdown(std::string equipo) {
        if (equipo == "E1") {
            puntosEquipo1 += 6;
            std::cout << "¡Touchdown para el Equipo 1! Se suman 6 puntos." << std::endl;
        } else if (equipo == "E2") {
            puntosEquipo2 += 6;
            std::cout << "¡Touchdown para el Equipo 2! Se suman 6 puntos." << std::endl;
        } else {
            std::cout << "Equipo no válido." << std::endl;
        }
    }

    void anotarPuntoExtra(std::string equipo) {
        if (equipo == "E1") {
            puntosEquipo1 += 1;
            std::cout << "Punto extra para el Equipo 1 anotado. Se suma 1 punto." << std::endl;
        } else if (equipo == "E2") {
            puntosEquipo2 += 1;
            std::cout << "Punto extra para el Equipo 2 anotado. Se suma 1 punto." << std::endl;
        } else {
            std::cout << "Equipo no válido." << std::endl;
        }
    }

    void anotarFieldGoal(std::string equipo) {
        if (equipo == "E1") {
            puntosEquipo1 += 3;
            std::cout << "Field Goal para el Equipo 1 anotado. Se suman 3 puntos." << std::endl;
        } else if (equipo == "E2") {
            puntosEquipo2 += 3;
            std::cout << "Field Goal para el Equipo 2 anotado. Se suman 3 puntos." << std::endl;
        } else {
            std::cout << "Equipo no válido." << std::endl;
        }
    }

    void mostrarPuntos() const {
        std::cout << "Puntos del Equipo 1: " << puntosEquipo1 << std::endl;
        std::cout << "Puntos del Equipo 2: " << puntosEquipo2 << std::endl;
    }
};

int main() {
    ContadorPuntos contador;

    // Ejemplo de uso
    std::string equipo;
    char opcion;

    do {
        std::cout << "Ingrese el equipo (E1 o E2): ";
        std::cin >> equipo;

        std::cout << "Ingrese la acción (T para Touchdown, F para Punto Extra, G para Field Goal, Q para salir): ";
        std::cin >> opcion;

        switch (opcion) {
            case 'T':
                contador.anotarTouchdown(equipo);
                break;
            case 'F':
                contador.anotarPuntoExtra(equipo);
                break;
            case 'G':
                contador.anotarFieldGoal(equipo);
                break;
            case 'Q':
                std::cout << "Saliendo del programa." << std::endl;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
        }

        contador.mostrarPuntos();

    } while (opcion != 'Q');

    return 0;
}
#include <iostream>
#include <string>

class Carro {
private:
    std::string marca;
    std::string modelo;
    std::string color;
    int velocidad;

public:
    Carro(std::string marca, std::string modelo, std::string color) {
        this->marca = marca;
        this->modelo = modelo;
        this->color = color;
        this->velocidad = 0;
    }

    void acelerar(int incremento) {
        velocidad += incremento;
        std::cout << "El carro " << marca << " " << modelo << " aceleró. Velocidad actual: " << velocidad << " km/h" << std::endl;
    }

    void frenar(int decremento) {
        if (velocidad >= decremento) {
            velocidad -= decremento;
        } else {
            velocidad = 0;
        }
        std::cout << "El carro " << marca << " " << modelo << " frenó. Velocidad actual: " << velocidad << " km/h" << std::endl;
    }

    void obtenerInformacion() {
        std::cout << "Carro: " << marca << " " << modelo << ", Color: " << color << ", Velocidad: " << velocidad << " km/h" << std::endl;
    }
};

int main() {
    // Ejemplo de uso
    Carro carro1("Toyota", "Corolla", "Rojo");
    carro1.obtenerInformacion();

    carro1.acelerar(30);
    carro1.frenar(10);

    carro1.obtenerInformacion();

    return 0;
}
//Santiago Sauret y Andres Gomez

#include <iostream>
#include <string>

// Base class: Vehiculo
class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    std::string color;
    int velocidad;

public:
    Vehiculo(std::string marca, std::string modelo, std::string color) : marca(marca), modelo(modelo), color(color), velocidad(0) {}

    void accelerate(int increment) {
        velocidad += increment;
        std::cout << "The vehicle accelerated. Current speed: " << velocidad << " km/h" << std::endl;
    }

    void brake(int decrement) {
        if (velocidad >= decrement) {
            velocidad -= decrement;
        } else {
            velocidad = 0;
        }
        std::cout << "The vehicle braked. Current speed: " << velocidad << " km/h" << std::endl;
    }

    void getInfo() {
        std::cout << "Vehicle: " << marca << " " << modelo << ", Color: " << color << ", Speed: " << velocidad << " km/h" << std::endl;
    }
};

// Derived class: Carro inherits from Vehiculo
class Carro : public Vehiculo {
public:
    Carro(std::string marca, std::string modelo, std::string color) : Vehiculo(marca, modelo, color) {}
};

int main() {
    // Example usage
    Carro carro1("Toyota", "Corolla", "Red");
    carro1.getInfo();

    carro1.accelerate(30);
    carro1.brake(10);

    carro1.getInfo();

    return 0;
}
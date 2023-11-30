/* Examen Segudno Parcial  
Santiago Sauret Hernandez
Andres Gomez Nava


*/


#include <iostream>
#include <string>

// Abstract Class Deporte 
class Deporte {
public:
    Deporte(std::string nombre) : nombre(nombre) {}

    void jugar() const {
        std::cout  << std::endl;
    }

    void mostrarNombre() const {
        std::cout << "Deporte: " << nombre << std::endl;
    }

    ~Deporte() {
        std::cout << "Destroying Deporte" << std::endl;
    }

private:
    std::string nombre;
};

// Concrete class American Football inheriting from Deporte
class FutbolAmericano : public virtual Deporte {
public:
    FutbolAmericano(std::string equipo) : Deporte("Football"), equipo(equipo) {}

    void jugar() const {
        std::cout << equipo << " is the team of football" << std::endl;
    }

    ~FutbolAmericano() {
        std::cout << "Destroying FutbolAmericano" << std::endl;
    }

    FutbolAmericano(const FutbolAmericano& other) : Deporte("Futbol Americano"), equipo(other.equipo) {}

private:
    std::string equipo;
};


// Concrete class Baseball inheriting from Deporte
class Beisbol : public virtual Deporte {
public:
    Beisbol(std::string equipo) : Deporte("baseball"), equipo(equipo) {}

    void jugar() const {
        std::cout << equipo << " is the team of baseball" << std::endl;
    }

    ~Beisbol() {
        std::cout << "Destroying baseball" << std::endl;
    }

    Beisbol(const Beisbol& other) : Deporte("baseball"), equipo(other.equipo) {}

private:
    std::string equipo;
};

// Athlete Class inheriting from FutbolAmericano and Beisbol (Multiple Inheritance)
class Atleta : public FutbolAmericano, public Beisbol {
public:
    Atleta(std::string nombre, std::string equipoFutbol, std::string equipoBeisbol)
        : Deporte("football"), FutbolAmericano(equipoFutbol), Beisbol(equipoBeisbol), nombre(nombre) {}

    ~Atleta() {
        std::cout << "Destroying Atleta" << std::endl;
    }

    Atleta(const Atleta& other)
        : Deporte("player"), FutbolAmericano(other), Beisbol(other), nombre(other.nombre) {}

    void entrenar() const {
        std::cout << nombre << " is training both sports" << std::endl;
    }

private:
    std::string nombre;
};

int main() {
    // Create an instance of FutbolAmericano and call its own method
    FutbolAmericano futbolAmericano("Greenbay");
    futbolAmericano.mostrarNombre();
    futbolAmericano.jugar();
    
    // Create an instance of Beisbol and call its own method
    Beisbol beisbol("Rays");
    beisbol.mostrarNombre();
    beisbol.jugar();
    
   // Create an instance of Atleta and call its own method
    Atleta atleta("Carlos", "Greenbay", "Rays");
    atleta.mostrarNombre();
    atleta.FutbolAmericano::jugar(); 
    atleta.entrenar();

    return 0;
}
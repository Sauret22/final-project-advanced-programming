/* Ejercicio miercoles 
Santiago Sauret Hernandez
Andres Gomez Nava

https://www.codingame.com/playgrounds/50577/miembros-especiales-de-la-clase-en-c-practica-2/constructores
*/



#include <iostream>
#include <string>

class Jugadorp {
private:
    std::string nombre;
    std::string apodo;
    std::string posicion;
    int numeroCamiseta;
    int hits;
    int carrerasAnotadas;

public:
    // Constructor por defecto
    Jugadorp() : nombre(""), apodo(""), posicion(""), numeroCamiseta(0), hits(0), carrerasAnotadas(0) {}

    // Constructor sobrecargado
    Jugadorp(const std::string& nombre, const std::string& apodo, const std::string& posicion, int numeroCamiseta)
        : nombre(nombre), apodo(apodo), posicion(posicion), numeroCamiseta(numeroCamiseta), hits(0), carrerasAnotadas(0) {}

    // Constructor de copia
    Jugadorp(const Jugadorp& other)
        : nombre(other.nombre), apodo(other.apodo), posicion(other.posicion), numeroCamiseta(other.numeroCamiseta),
          hits(other.hits), carrerasAnotadas(other.carrerasAnotadas) {}

    // Destructor
    ~Jugadorp() {

    }

    // Función amiga para mostrar las estadisticas del jugador
    friend void MostrarEstadisticas(const Jugadorp& jugador);

    // Incrementar el número de hits y carreras anotadas
    void RegistrarHit() {
        hits++;
    }

    void RegistrarCarreraAnotada() {
        carrerasAnotadas++;
    }

    // Getter para el nombre
    std::string GetNombre() const {
        return nombre;
    }

    // Getter para el apodo
    std::string GetApodo() const {
        return apodo;
    }

    // Getter para la posición en el campo
    std::string GetPosicion() const {
        return posicion;
    }

    // Getter para el número de camiseta
    int GetNumeroCamiseta() const {
        return numeroCamiseta;
    }

    // Getter para las carreras anotadas
    int GetCarrerasAnotadas() const {
        return carrerasAnotadas;
    }
};

// Función amiga para mostrar las estadisticas del jugador
void MostrarEstadisticas(const Jugadorp& jugador) {
    std::cout << "Nombre: " << jugador.nombre << " (" << jugador.apodo << "), Posicion: " << jugador.posicion << ", Numero de Camiseta: " << jugador.numeroCamiseta << std::endl;
    std::cout << "Hits: " << jugador.hits << ", Carreras Anotadas: " << jugador.carrerasAnotadas << std::endl;
}

int main() {
    // Crear objetos de la clase Jugadorp utilizando diferentes constructores
    Jugadorp jugador0;
    Jugadorp jugador1("Santiago", "sau", "Jardin izquierdo", 22);
    Jugadorp jugador2("Alex Lopez", "Lex", "Tercera Base", 17);
    Jugadorp jugador3(jugador2);

    // Registrar estadisticas para los jugadores
    
    jugador2.RegistrarHit();
    jugador2.RegistrarHit();
    jugador1.RegistrarHit();
    jugador1.RegistrarHit();
    jugador1.RegistrarHit();

    // Registrar carreras anotadas
    jugador2.RegistrarCarreraAnotada();
    jugador1.RegistrarCarreraAnotada();

    // Mostrar estadisticas de los jugadores utilizando la función amiga
    MostrarEstadisticas(jugador0);
    MostrarEstadisticas(jugador1);
    MostrarEstadisticas(jugador2);
    MostrarEstadisticas(jugador3);

    return 0;
}
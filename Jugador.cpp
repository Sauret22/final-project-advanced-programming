#include <iostream>
#include <string>

// Base Class: Jugadorp
class Jugadorp {
private:
    std::string nombre;
    std::string apodo;
    std::string posicion;
    int numeroCamiseta;
    int hits;
    int runsScored;

public:
    // Default Constructor
    Jugadorp() : nombre(""), apodo(""), posicion(""), numeroCamiseta(0), hits(0), runsScored(0) {}

    // Parameterized Constructor
    Jugadorp(const std::string& name, const std::string& nickname, const std::string& position, int jerseyNumber)
        : nombre(name), apodo(nickname), posicion(position), numeroCamiseta(jerseyNumber), hits(0), runsScored(0) {}

    // Copy Constructor
    Jugadorp(const Jugadorp& other)
        : nombre(other.nombre), apodo(other.apodo), posicion(other.posicion), numeroCamiseta(other.numeroCamiseta),
          hits(other.hits), runsScored(other.runsScored) {}

    // Destructor
    ~Jugadorp() {}

    // Friend function to display player statistics
    friend void ShowStatistics(const Jugadorp& player);

    // Increment the number of hits and runs scored
    void RecordHit() {
        hits++;
    }

    void RecordRunScored() {
        runsScored++;
    }

    // Getter for name
    std::string GetName() const {
        return nombre;
    }

    // Getter for nickname
    std::string GetNickname() const {
        return apodo;
    }

    // Getter for position
    std::string GetPosition() const {
        return posicion;
    }

    // Getter for jersey number
    int GetJerseyNumber() const {
        return numeroCamiseta;
    }

    // Getter for runs scored
    int GetRunsScored() const {
        return runsScored;
    }
};

// Friend function to display player statistics
void ShowStatistics(const Jugadorp& player) {
    std::cout << "Name: " << player.nombre << " (" << player.apodo << "), Position: " << player.posicion << ", Jersey Number: " << player.numeroCamiseta << std::endl;
    std::cout << "Hits: " << player.hits << ", Runs Scored: " << player.runsScored << std::endl;
}

int main() {
    // Create objects of the Jugadorp class using different constructors
    Jugadorp player0;
    Jugadorp player1("Santiago", "sau", "Left Field", 22);
    Jugadorp player2("Alex Lopez", "Lex", "Third Base", 17);
    Jugadorp player3(player2);

    // Record statistics for players
    player2.RecordHit();
    player2.RecordHit();
    player1.RecordHit();
    player1.RecordHit();
    player1.RecordHit();

    // Record runs scored
    player2.RecordRunScored();
    player1.RecordRunScored();

    // Display player statistics using the friend function
    ShowStatistics(player0);
    ShowStatistics(player1);
    ShowStatistics(player2);
    ShowStatistics(player3);

    return 0;
}
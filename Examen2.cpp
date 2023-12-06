/* Examen Segudno Parcial  
Santiago Sauret Hernandez
Andres Gomez Nava


*/


#include <iostream>
#include <string>

// Abstract Class Sport
class Sport {
public:
    Sport(std::string name) : name(name) {}

    void play() const {
        std::cout << std::endl;
    }

    void showName() const {
        std::cout << "Sport: " << name << std::endl;
    }

    ~Sport() {
        std::cout << "Destroying Sport" << std::endl;
    }

private:
    std::string name;
};

// Concrete class American Football inheriting from Sport
class AmericanFootball : public virtual Sport {
public:
    AmericanFootball(std::string team) : Sport("Football"), team(team) {}

    void play() const {
        std::cout << team << " is the football team" << std::endl;
    }

    ~AmericanFootball() {
        std::cout << "Destroying AmericanFootball" << std::endl;
    }

    AmericanFootball(const AmericanFootball& other) : Sport("American Football"), team(other.team) {}

private:
    std::string team;
};

// Concrete class Baseball inheriting from Sport
class Baseball : public virtual Sport {
public:
    Baseball(std::string team) : Sport("Baseball"), team(team) {}

    void play() const {
        std::cout << team << " is the baseball team" << std::endl;
    }

    ~Baseball() {
        std::cout << "Destroying Baseball" << std::endl;
    }

    Baseball(const Baseball& other) : Sport("Baseball"), team(other.team) {}

private:
    std::string team;
};

// Athlete Class inheriting from AmericanFootball and Baseball (Multiple Inheritance)
class Athlete : public AmericanFootball, public Baseball {
public:
    Athlete(std::string name, std::string footballTeam, std::string baseballTeam)
        : Sport("Football"), AmericanFootball(footballTeam), Baseball(baseballTeam), name(name) {}

    ~Athlete() {
        std::cout << "Destroying Athlete" << std::endl;
    }

    Athlete(const Athlete& other)
        : Sport("Player"), AmericanFootball(other), Baseball(other), name(other.name) {}

    void train() const {
        std::cout << name << " is training both sports" << std::endl;
    }

private:
    std::string name;
};

int main() {
    // Create an instance of AmericanFootball and call its own method
    AmericanFootball americanFootball("Greenbay");
    americanFootball.showName();
    americanFootball.play();
    
    // Create an instance of Baseball and call its own method
    Baseball baseball("Rays");
    baseball.showName();
    baseball.play();
    
    // Create an instance of Athlete and call its own method
    Athlete athlete("Carlos", "Greenbay", "Rays");
    athlete.showName();
    athlete.AmericanFootball::play(); 
    athlete.train();

    return 0;
}
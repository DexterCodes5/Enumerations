#include <iostream>

class Player {
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
public:
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};
    
    Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North):
        name{name}, mode{mode}, direction{direction} {}
        
    std::string get_name() const {
        return name;
    }
    
    void set_name(std::string s) {
        name = s;
    }
    
    Mode get_mode() { return mode; }
    void set_mode(Mode m) {
        mode = m;
    }
    
    Direction get_direction() {return direction;}
    void set_direction(Direction d) {
        direction = d;
    }
private:
    std::string name;
    Mode mode;
    Direction direction;

};

std::string get_player_mode(Player::Mode mode) {
    std::string result;
    switch (mode) {
        case Player::Mode::Attack:
            result = "Attack";
            break;
        case Player::Mode::Defense:
            result = "Defense";
            break;
        case Player::Mode::Idle:
            result = "Idle";
            break;
    }
    return result;
}

std::string get_player_direction(Player::Direction direction) {
    std::string result;
    switch (direction) {
        case Player::Direction::North:
            result = "North";
            break;
        case Player::Direction::South:
            result = "South";
            break;
        case Player::Direction::East:
            result = "East";
            break;
        case Player::Direction::West:
            result = "West";
            break;
    }
    return result;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << "Player name:      " << p.name << "\n"
       << "Player mode:      " << get_player_mode(p.mode) << "\n"
       << "Player direction: " << get_player_direction(p.direction)
       << std::endl;
       return os;
}

int main(){
    std::cout << "-------------------------------\n" << std::endl;
    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::South};
    
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    
    return 0;
}

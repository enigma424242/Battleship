//Stephen M. Struble
//Battleship
//10/28/21

#include <iostream>
#include "battleship.hpp"

Location::Location(int x, char y) :
    x_(x), y_(y)
{}

Ship::Ship(bool sunk) :
    sunk_(sunk)
{}


void Location::pick() {
    
    int ranIntX = rand() % 6 + 1;
    int ranIntY = rand() % 6 + 1;
    x_ = ranIntX;
    
    switch (ranIntY) {
    case 1:
        y_ = 'a';
        break;
    case 2:
        y_ = 'b';
        break;
    case 3:
        y_ = 'c';
        break;
    case 4:
        y_ = 'd';
        break;
    case 5:
        y_ = 'e';
        break;
    case 6:
        y_ = 'f';
        break;
    }
}

void Location::print() const {
    std::cout << std::endl << y_ << x_ << std::endl;
}

void Location::fire() {
    std::cout << "\nEnter the coordinates of the designated shot that you would like to fire.\n: ";
    std::cin >> y_ >> x_;
}

bool compare(const Location& ship, const Location& cord) {
    return ship.x_ == cord.x_ && ship.y_ == cord.y_;
}

void Ship::setLocation(const Location& depLoc) {
    loc_ = depLoc;
}

bool Ship::match(const Location& checkLoc) const {
    if (compare(checkLoc, loc_))
        return true;
    else
        return false;
}

void Ship::sink() {
    sunk_ = true;
}

void Ship::printShip() const {
    loc_.print();
    if (sunk_)
        std::cout << "Sunk\n";
    else
        std::cout << "Not sunk\n";
}

void Fleet::deployFleet() {
    int deployedShips = 0;
    while (deployedShips < fleetSize_) {
        Location ranLoc;
        ranLoc.pick();
        for (int i = 0; i <= deployedShips; i++) {
            if (deployedShips != 0 && ships_[i].match(ranLoc)) {
                ranLoc.pick();
                i = 0;
            }
        }
        ships_[deployedShips].setLocation(ranLoc);
        deployedShips += 1;
    }
}

bool Fleet::operational() const {
    int checkShips = 0;
    while (checkShips < fleetSize_) {
        if (ships_[checkShips].isSunk()) {
            checkShips += 1;
            continue;
        }
        else
            return true;
    }
    return false;
}

bool Fleet::isHitNSink(const Location& checkLoc) {
    for (int i = 0; i < fleetSize_; ++i) {
        if (ships_[i].match(checkLoc)) {
            ships_[i].sink();
            std::cout << "Hit!\n";
            return true;
        }
    }
    std::cout << "Miss...\n";
    return false;
}

void Fleet::printFleet() const {
    for (int i = 0; i < fleetSize_; ++i) {
        ships_[i].printShip();
    }
}

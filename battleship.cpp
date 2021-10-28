//Stephen M. Struble
//Battleship
//10/28/21

#include <iostream>
#include "battleship.hpp"

Location pick() {
    int ranIntx = rand() % 6 + 1;
    int ranInty = rand() % 6 + 1;
    Location ranLoc;
    ranLoc.x = ranIntx;
    switch (ranInty) {
    case 1:
        ranLoc.y = 'a';
        break;
    case 2:
        ranLoc.y = 'b';
        break;
    case 3:
        ranLoc.y = 'c';
        break;
    case 4:
        ranLoc.y = 'd';
        break;
    case 5:
        ranLoc.y = 'e';
        break;
    case 6:
        ranLoc.y = 'f';
        break;
    }
    return ranLoc;
}

Location fire() {
    std::cout << "Enter the cordinates of the next designated shot.\n: ";
    Location UserCord;
    std::cin >> UserCord.y >> UserCord.x;
    return UserCord;
}

int check(const Ship myFleet[], const Location& mySpot) {
    for (int i = 0; i < fleetSize; ++i) {
        if (match(myFleet[i], mySpot))
            return i;
    }
    return -1;
}

bool match(const Ship& myShip, const Location& mySpot) {
    if (myShip.loc.x == mySpot.x && myShip.loc.y == mySpot.y)
        return true;
    else
        return false;
}

void sink(Ship& myShip) {
    myShip.sunk = true;
    myShip.loc.x = -1;
    myShip.loc.y = '*';
}

void initialize(Ship myFleet[]) {
    for (int i = 0; i < fleetSize; ++i) {
        myFleet[i].loc.x = -1;
        myFleet[i].loc.y = '*';
    }
}

/*
void printShip(const Ship& myShip) {
    std::cout << "The cordinates of the randomly placed ship is " << myShip.loc.y << myShip.loc.x << std::endl;
}

void printFleet(const Ship Fleet[]) {
    for (int i = 0; i < fleetSize; ++i) {
        std::cout << i + 1 << " Ship location: " << Fleet[i].loc.y << Fleet[i].loc.x;
        std::cout << " Status: ";
        if (Fleet[i].sunk == true)
            std::cout << "down\n";
        else if (Fleet[i].sunk == false)
            std::cout << "up\n";
        else
            std::cout << "Not available\n";
    }
}
*/

void deploy(Ship myFleet[]) {
    int deployedShips = 0;
    while (deployedShips < fleetSize) {
        Location ranSpot = pick();
        int locAvail = check(myFleet, ranSpot);
        if (locAvail == -1) {
            myFleet[deployedShips].loc = ranSpot;
            myFleet[deployedShips].sunk = false;
            deployedShips += 1;
        }
    }
}

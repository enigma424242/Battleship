// Mikhail Nesterenko
// tests battleShip functions implementation
// 3/11/2019

// Stephen M. Struble
// Battleship
// 10/28/21

#include "battleship.hpp"
#include <iostream>

int main() {

    std::cout << "Wecome to Battleship!\n\n";
    srand(time(nullptr)); // fixed seed        

    Ship myShip;

    myShip.loc = pick(); // assign random Location to myShip
    myShip.sunk = false;  // myShip is not sunk

    Ship myFleet[fleetSize];

    initialize(myFleet); //assigning -1 to all ship's Locations in myFleet

    deploy(myFleet); // deploying ships at random Locations
    //printFleet(myFleet);

    std::cout << "8 enemy ships are designated to random locations on a 6x6 plain.\n"
        << "Rows are designated 1-6 and columns are designated a-f.\n"
        << "You are given 24 missiles.\n"
        << "To fire a missile at a designated location enter the desired coordinates.\n\n"
        << "Example: a1\n\n"
        << "WARNING:\n"
        << "If you fire a missile outside of the 6x6 plain or at an undefined location \n"
        << "then you will waste ammunition.\n"
        << "Be careful and good luck!\n\n";
    int currentShips = 8;
    int currentMissiles = 24;
    while (currentShips > 0) {
        Location currentShot = fire();
        int currentStatus = check(myFleet, currentShot);
        if (currentMissiles == 0 && currentShips > 0) {
            std::cout << "\nYou are out of ammunition and more enemy vessels still remain.\n"
                << "\nYou lose.\n";
            return 0;
        }
        else if (currentStatus != -1 && currentMissiles > 0) {
            sink(myFleet[currentStatus]);
            std::cout << "Hit!\n";
            currentShips -= 1;
            currentMissiles -= 1;
            if (currentShips == 0 && currentMissiles > 0) {
                std::cout << "\nCongratulations! You have successfully eliminated all enemy vessels.\n"
                    << "\nYou win!\n"
                    << "\nNow exiting...\n";
                return 0;
            }
        }
        else {
            std::cout << "Miss...\n";
            currentMissiles -= 1;
        }
    }
}

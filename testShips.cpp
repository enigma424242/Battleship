/// Mikhail Nesterenko
/// tests battleship with classes implementation 
/// 10/20/2013 

#include "battleship.hpp"
#include <iostream>

int main() {

    srand(time(nullptr));

    std::cout << "\nWelcome to Battleship!\n";
    std::cout << "\n8 enemy ships will be placed in random locations on a 6x6 plain.\n";
    std::cout << "Rows are designated 1-6 and columns are designated a-f.\n";
    std::cout << "Simply enter the coordinates of the shot you would like to fire.\n";
    std::cout << "Example: a1\n";
    std::cout << "Each enemy vessel occupies 1 coordinate.\n";
    std::cout << "You will waste ammunition if you\n";
    std::cout << "1. Designate a shot at a repeated coordinate.\n";
    std::cout << "2. Designate a shot outside the 6x6 plain.\n";
    std::cout << "3. Designate a shot that is undefined.\n";
    std::cout << "\nGood luck!\n";


    Fleet theFleet;
    theFleet.deployFleet();
    
    int missiles = 24;
    while (missiles > 0) {
        Location cordLoc;
        cordLoc.fire();
        missiles -= 1;
        theFleet.isHitNSink(cordLoc);
        //theFleet.printFleet();
        if (!theFleet.operational()) {
            std::cout << "\nCongratulations! You have eliminated all enemy vessels.\n";
            std::cout << "\nNow exiting...\n";
            return 0;
        }
        if (missiles == 0) {
            std::cout << "\nYou are out of ammunition and enemy ships still remain.\n";
            std::cout << "\nYou lose...\n";
            std::cout << "\nNow exiting...\n";
            return 0;
        }
    }
}

/*
For debugging purposes include 
theFleet.printFleet();
within the main while loop.
*/
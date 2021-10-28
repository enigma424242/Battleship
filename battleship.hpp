// structure definitions and function prototypes for the battleship assignment
// Mikhail Nesterenko
// 10/19/2020

#include <cstdlib>
#include <ctime>


#ifndef BATTLESHIP_HPP_
#define BATTLESHIP_HPP_

//
// data structures definitions
//

const int fleetSize = 8; // number of battleships
const int fieldSize = 6;  // the field (ocean) is fieldSize * fieldSize

// coordinates (Location) of the ship and shots
struct Location {
    int x;  // 1 through fieldSize
    char y; // 'a' through fieldSize
};

// contains ship's coordinates (Location) and whether is was sunk
struct Ship {
    Location loc;
    bool sunk;
};


//
// initialization functions
//
void initialize(Ship[]); // places every Ship in a Location where x-coordinate is -1
                         // and y-coordinate is '*' (a star) to signify
                         // that the Ship is not deployed

Location pick(); // generates a random Location
bool match(const Ship&, const Location&); // returns true if this Location matches
                                            // the Location of the Ship
                                            // returns false otherwise
int check(const Ship[], const Location&); // returns the index of element of the array
                                           // that matches the Location
                                           // returns -1 if none do
                                           // uses match()
void deploy(Ship[]); // places an array of battleships in
                     // random Locations in the ocean

//
// display functions
//
void printShip(const Ship&); // prints the Location and status (sunk or not) 
                             // of a single ship
void printFleet(const Ship[]); // prints the Locations of all the ships and 
                               // whether they are sunk


//
// battle functions 
//
bool operational(const Ship[]);  // returns true if at least one ship in the array
                                 // is not sunk
Location fire();           // asks the user to input the coordinates of the next
                           // shot
// note that check() is also used in the battle

void sink(Ship&);          // sets "sunk" member variable of the ship to true

#endif // BATTLESHIP_HPP_
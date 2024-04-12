#include <iostream>
#include "MemoryGame.hpp"
#include <cstdlib> 
#include <iomanip>
#include <ios>
#include <time.h>

using namespace std;

MemoryGame::MemoryGame() {
    numPairs = 3;
    numSlots = 8;
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Generate three random integers in [0, 999]
    int random1 = rand() % 1000;
    int random2 = rand() % 1000;
    int random3 = rand() % 1000;

    // Place the random integers in pairs in the values array
    for (int i = 0; i < numSlots; i += 2) {
        if (i < 2) {
            values[i] = to_string(random1);
            values[i + 1] = to_string(random1);
            bShown[i] = false;
            bShown[i + 1] = false;
        } else if (i < 4) {
            values[i] = to_string(random2);
            values[i + 1] = to_string(random2);
            bShown[i] = false;
            bShown[i + 1] = false;
        } else {
            values[i] = to_string(random3);
            values[i + 1] = to_string(random3);
            bShown[i] = false;
            bShown[i + 1] = false;
        }
    }

    // Set the rest of the elements of values to be empty strings
    for (int i = 6; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame(int numPairs, int numSlots) {
    if (numPairs <= 0 || numSlots <= 0 || numSlots < 2 * numPairs) {
        // Default values if parameters are invalid
        numPairs = 3;
        numSlots = 8;
    }

    this->numPairs = numPairs;
    this->numSlots = numSlots;
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Generate numPairs random integers in [0, 999]
    for (int i = 0; i < numPairs; i++) {
        int random = rand() % 1000;
        for (int j = 0; j < 2; j++) {
            values[i * 2 + j] = to_string(random);
            bShown[i * 2 + j] = false;
        }
    }

    // Set the rest of the elements of values to be empty strings
    for (int i = numPairs * 2; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame(string* words, int size, int numSlots) {
    // Adjust numSlots if necessary
    if (size <= 0 || numSlots <= 0 || numSlots < 2 * size) {
        numSlots = 2 * size;
    }

    // Set data members numPairs and numSlots
    numPairs = size;
    this->numSlots = numSlots;

    // Allocate dynamic memory for values and bShown
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Initialize values with words and empty strings
    int wordIndex = 0;
    for (int i = 0; i < numSlots; i++) {
        if (wordIndex < size) {
            values[i] = words[wordIndex];
            values[i + 1] = words[wordIndex]; // Place each word in pairs
            i++; // Skip next iteration
        } else {
            values[i] = ""; // Fill the rest with empty strings
        }
        bShown[i] = false; // Initialize bShown
        wordIndex++;
    }
}

MemoryGame::~MemoryGame() {
    delete[] values;
    delete[] bShown;

    // Set values and bShown to nullptr after deletion
    values = nullptr;
    bShown = nullptr;
}

// Task B
// Based on the code of Task A, define randomize function.
// The idea is similar to the randomization process of Project 1 Task D. 
// 1. Initialize size to be the number of element of array values, which is saved in data member ... (you find this out). 
// 2. Generate a random index in [0,size). Swap the element at chosen index with the last element in values.
// 3. Then reduce size by 1 so that we do not consider the already-chosen element, which resides in the last element of values. 
// 4. Continue Step 2-3 until size is 1 (why not 0? Hint: do we need to randomize if there is only one element left in the 
// array to be randomized?) Said differently, as long as size is larger than 1, run codes in Steps 2-3.


void MemoryGame::randomize()
{
    int size = numSlots;
    while (size > 1){
        int index = rand() % size;
        swap(values[index], values[size-1]);
        size --;
    }      
}

// Task C 


void printSeparatedLine(int size) {

    cout << "+"; // the first +
    // draw -----+ for (size) many times
    for (int i = 0; i < size; i++) {
        cout << "-----+";
    }
    cout << endl;

    cout << "|";
    for (int i = 0; i < size; i++){
        cout << "     |";
    }
    cout << endl;

    cout << "+"; // the first +
    // draw -----+ for (size) many times
    for (int i = 0; i < size; i++) {
        cout << "-----+";
    }
    cout << endl;
}

void MemoryGame::display() const
{
    cout << ""; // Starting with an empty string

    for (int i = 0; i < numSlots; i++) {
        if (i < 10){
            cout << setw(4) << i << setw(2) << "";
        } else if (i >= 10 && i <= 99){
            cout << setw(5) << i << setw(2) << "";
        }
    }
    cout << endl;   
    printSeparatedLine(numSlots);
    


}


void MemoryGame::play()
{
    randomize();

}

int MemoryGame:: input() const
{

}
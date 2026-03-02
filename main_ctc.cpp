#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>
#include <thread>
#include <vector>

using namespace std;
using namespace std::chrono;

//code for numbers
//const int SIZE_PW = 100000000;//relates to the size of the password


//code for challenge 2
/*
const int passwordLength = 8;
int SIZE_PW = pow(10, passwordLength); //does 10^passwordlength
*/

//code for challenge 1 and 2
// Function to generate a random x-digit passcode
/*
int generatePasscode() {
    return rand() % SIZE_PW; // Ensures x-digit number (1000-9999)
}
*/

//code for challenge 3 
const string Charset = "0123456789abcd";
const int passwordLength = 8;

string generatePasscode() {
    string pass = "";
    for(int i = 0; i < passwordLength; i++) {
        pass += Charset[rand() % Charset.length()];
    }
    return pass;
}



    
int main() {
    srand(time(0)); // Seed for random number generation
    //code for challenge 1 and 2
    /*
    int passcode = generatePasscode();
    */

    string passcode = generatePasscode();

    cout << "A "<< passwordLength << " digit passcode has been generated. Try to crack it! " << endl;
    cout<<passcode<<endl;

    // Start Timer
    auto start = high_resolution_clock::now();

    // Students will write their algorithm here to find 'passcode'

    //Algorithm for challenge 1 and 2
    /*
    int found = -1;
    for(int guess = 0; guess < SIZE_PW; guess++) {
        if(guess == passcode) {
            found = guess;
            break;
        }
    }
    */

    //Algorithm for challenge 3 (numbers and letters combined)

    //Algorithm for Final challenge
    string guess(passwordLength, Charset[0]);
    int base = Charset.length();

    vector<int> indices(passwordLength, 0);

    while (true) {
        for (int i = 0; i < passwordLength; i++) {
            guess[i] = Charset[indices[i]];
        }
        if (guess == passcode) break;
        int position = passwordLength - 1;
        
        while (position >= 0) {
            indices[position]++;
            if (indices[position] < base) break;
            indices[position] = 0;
            position--;
    }
        if (position < 0) break;
    }



    // Stop Timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Passcode cracked in: " << duration.count() << " nanoseconds!" << endl;

    return 0;
}

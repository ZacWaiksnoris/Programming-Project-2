//
// Created by Zac Waiksnoris
// Date Created 9/30/2022
// Programming Project 1

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream input;
    std::string   filename;
    std::cout << "Enter the file name. Enter 'def' to use default file: ";
    std::cin >> filename;

    if ( filename == "def" ) {
        input.open( "Programming-Project-1.txt" );
    } else {
        input.open( filename.c_str() );
    }

    int number_of_lines = 0;
    std::string line;

    while ( getline( input, line ) ) {
        ++number_of_lines;
    }
    std::cout << "\nNumber of lines in file: " << number_of_lines << "\n\n";

    input.clear();
    input.seekg( 0, input.beg );    

    std::string w, x1, y1;
    unsigned int x, y;

    while ( input >> w >> x1 >> y1 ) {

        if ( w == "ADD" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;

            std::cout << "Solution: " << x + y << std::endl;
        }

    }


    std::cout << "\nPress any key and enter to quit." << std::endl;
    char c;
    std::cin >> c;

    return 0;
}
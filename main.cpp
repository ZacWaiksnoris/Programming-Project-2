//
// Created by Zac Waiksnoris
// Date Created 11/4/2022
// Programming Project 1

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstring>  


using namespace std;


int main() {
    fstream input;
    string   filename, userinput;
    cout << "Enter the file name. Enter 'def' to use default file: ";
    cin >> userinput;
    string def = "Programming-Project-2.txt";

    if ( userinput == "def" ) {
        input.open( def);
        filename = def;
    } else {
        input.open( userinput.c_str() );
        filename = userinput;
    }
    if ( !input.is_open() ) {
        cout << "Error opening file. Exiting program." << endl;
        return 1;
    }

    int number_of_lines = 0;
    string line;

    while ( getline( input, line ) ) {
        ++number_of_lines;
    }
    cout << "\nNumber of lines in file: " << number_of_lines << "\n\n";

    input.clear();
    input.seekg( 0, input.beg );    

    std::string w, x1, y1, solutionHex;
    unsigned int x, y;

    //string to hold each line for insert into vector
        string fileLine;
    //vector to hold all lines
        vector<string> lines;

    //read each line into vector

     while ((input >> w >> x1) || (input >> w >> x1 >> y1)) {
        getline(input, fileLine);
        lines.push_back(fileLine);
        int currentIndex = 0;
        for (int i = 0; i < lines.size(); i++) {
            if (lines[i] == fileLine) {
                currentIndex = i;
            }
        }
        //Add the 2 operand together
        if ( w == "ADD" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x + y;
            std::stringstream ss3;
            ss3 << hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;
        }
        //And the 2 operands together
         else if ( w == "AND" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x & y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;

        }
        //Athrtimic Shift right
        else if ( w == "ASR" ) {           
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x >> y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;


        }
        //Shift Right
        else if ( w == "LSR" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x >> y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;

        }
        //Shift Left
        else if ( w == "LSL" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x << y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;

        }
        // Not the 2 opparnds
        else if ( w == "NOT" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            int solution = ~x;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;

        }
        // OR the 2 opparands
        else if ( w == "ORR" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x | y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;


        }
        // Subtration
        if ( w == "SUB" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x - y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
            string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;

        }
        // Xor the 2 varibles
        if ( w == "XOR" ) {
            std::stringstream ss2;
            ss2 << std::hex <<x1;
            ss2 >> x;
            std::stringstream ss1;
            ss1 << std::hex <<y1;
            ss1 >> y;
            int solution = x ^ y;
            std::stringstream ss3;
            ss3 << std::hex << solution;
            ss3 >> solutionHex;
             string stringTemp = w + " " + x1 + " " + y1 + ": " + "0x" +solutionHex;
            lines[currentIndex] = stringTemp;
            currentIndex++;


        }
    }
    //close the reading file
        input.close();
    // open the file to write to and replace all the lines in the file
     ofstream newFile(filename, std::ofstream::trunc);

         for (int i = 0; i < lines.size(); i++) {
              newFile << lines[i] << endl;
         }
            newFile.close();

    std::cout << "\nPress any key and enter to quit." << std::endl;
    char c;
    std::cin >> c;

    return 0;
}


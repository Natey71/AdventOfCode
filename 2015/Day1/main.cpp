#include <iostream>
#include <fstream>


int main() {
    int floor = 0;
    std::ifstream file("file.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(file, line)) { 
        for(char &c : line) {
            // Used in part one
            if(c == '(') {
                floor++;
            } else if(c == ')') {
                floor--;
            }
            // Added this to find where the basement is first reached
            // Delete below for part 1
            if(floor == -1) {
                std::cout << "Basement reached at position: " << (&c - &line[0] + 1) << std::endl;
                return 1;
            }
            // Delete above for part 1
        }
        std::cout << floor << std::endl;
    }
    return 0;
}
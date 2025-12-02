#include <iostream>
#include <fstream>
#include <vector>
#include <set> 
#include <utility>

int main() {
    std::ifstream file("file.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;  
    }
    std::string line;
    // Starting position Santa
    int xS = 0;
    int yS = 0;
    // Starting position Robo 
    int xR = 0;
    int yR = 0;
    // To track visited houses
    std::set<std::pair<int, int>> visited;
    // Add starting position to visited
    // Both start at same position so add once
    visited.insert({xS, yS});
    while(std::getline(file, line)) {
        for(size_t i = 0; i < line.size(); ++i) {
            // Get index of line to decide who moves
            char c = line[i];
            // Move based on character
            // ^ = up, v = down, > = right, < = left
            // ^ add to y, v subtract from y
            // > add to x, < subtract from x
            // Santa's turn
            if(i % 2 == 0) { 
                if(c == '^') {
                    yS += 1;
                } else if(c == 'v') {
                    yS -= 1;
                } else if(c == '>') {
                    xS += 1;
                } else if(c == '<') {
                    xS -= 1;
                }
                // Add Santa position to visited
                visited.insert({xS, yS});
            // Robo turns
            } else { 
                if(c == '^') {
                    yR += 1;
                } else if(c == 'v') {
                    yR -= 1;
                } else if(c == '>') {
                    xR += 1;
                } else if(c == '<') {
                    xR -= 1;
                }
                // Add Robo's position to visited
                visited.insert({xR, yR});
            }
        }
    }
    
    // Total visited houses
    std::cout << "Visited Houses: " << visited.size() << std::endl;
    return 0;
}
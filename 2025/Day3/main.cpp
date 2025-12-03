#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int findLargetNumber(std::string& line){
    char max1 = '0';
    char max2 = '0';
    std::size_t maxIndex = 0;
    
    std::string result;

    for(std::size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if(c > max1) {
          max1 = c;
          maxIndex = i;
        } 
    }
    bool nextFound = false;
    std::cout << "Max: " << maxIndex << " Line: " << line.size() << std::endl;

    for(std::size_t i = maxIndex; i < line.size(); ++i){
        char c = line[i];
        if(!nextFound || c > max2) {
          max2 = c;
          nextFound = true;
        }
    }
    
    std::cout << "Max 1: " << max1 << std::endl;
    std::cout << "Max 2: " << max2 << std::endl;

    int one = max1 - '0';
    int two = max2 - '0';

    return one * 10 + two;
}

int main() 
{
    std::ifstream file("test.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::string line;
    int sum;
    while(std::getline(file, line)){
        std::cout << line << std::endl;
        int item = findLargetNumber(line);
        std::cout << "Item: " << item << std::endl;
        sum += item;
    }
    
    std::cout << "Item: " << sum << std::endl;
    
    return 0;
}

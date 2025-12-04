#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


int findLargetNumber(std::string& line){
    
    const int INF = std::numeric_limits<int>::max();
    
    int first[10], last[10], count[10];
    
    for(int d = 0; d < 10; ++d) {
        first[d] = INF;
        last[d] = -1;
        count[d] = 0;
    }

    for (int i = 0; i < (int)line.size(); ++i) {

       
        if (!std::isdigit((unsigned char)line[i])) continue;

        int d = line[i] - '0'; 

        if (i < first[d])
            first[d] = i;

        if (i > last[d])
            last[d] = i;

        ++count[d];
    }

    int best = -1; 

    for (int d1 = 9; d1 >= 0; --d1) {

        if (first[d1] == INF)
            continue;

        for (int d2 = 9; d2 >= 0; --d2) {
            if (last[d2] == -1)
                continue;

            bool ok = false;

            if (d1 == d2) {
                ok = (count[d1] >= 2 && first[d1] < last[d1]);
            } else {
                ok = (first[d1] < last[d2]);
            }

            if (ok) {
                int value = d1 * 10 + d2; 
                if (value > best)
                    best = value;
            }
        }
    }

    return best; 
  
}

int main() 
{
    std::ifstream file("file.txt");
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

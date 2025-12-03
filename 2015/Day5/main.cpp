/*
    Conditions of Satisfaction
    - Contains at least three vowels (aeiou only)
    - Contains at lease one letter that appears twice in a row
    - Does not contain the strings "ab", "cd", "pq", or "xy"
*/
/*
    Conditions of Satisfaction - Part 2
    - Contains a pair of any two letters that appears at least twice in the string without overlapping (aa, xyxy, aabcdefgaa)
    - Contains at least one letter which repeats with exactly one letter between them (xyx, aba, efe, aaa)

*/
#include <iostream>
#include <fstream>
#include <vector>

bool hasDoubleLetter(const std::string &s) {
    for(size_t i = 1; i < s.length(); i++) {
        if(s[i] == s[i-1]) {
            std::string doubleFound = s[i] + s[i-1];
            continue;
        }
        else {
            return false;
        }
    }
    if(&s.find(doubleFound) != nullptr) {
        return true;
    }
    return false;
}

int main() {
    std::ifstream file("test.txt");
    if(!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;  
    }
    std::string line;
    std::vector<std::string> vowels = {"a", "e", "i", "o", "u"};
    std::vector<std::string> forbidden = {"ab", "cd", "pq", "xy"}; 

    std::vector<std::string> goodStrings;

    while(std::getline(file, line)) {
        if(line.find(forbidden[0]) != std::string::npos ||
           line.find(forbidden[1]) != std::string::npos ||
           line.find(forbidden[2]) != std::string::npos ||
           line.find(forbidden[3]) != std::string::npos) {
            //std::cout << "Contains forbidden substring." << line << std::endl;
            continue;
        }
        if(!hasDoubleLetter(line)) {
            //std::cout << "Does not have double letter: " << line << std::endl;
            continue;
        }

        int vowelCount = 0;
        for(char c : line) {
            for(const std::string& v : vowels) {
                if(c == v[0]) {
                    vowelCount++; 
                }
            }
            if(vowelCount >= 3) {
                goodStrings.push_back(line);
                break; 
            }
        }

    }
    /*
    for(std::string s : goodStrings) {
        std::cout << "Good string: " << s << std::endl;
    }
    */
    std::cout << "Total good strings: " << goodStrings.size() << std::endl; 
    return 0;
}
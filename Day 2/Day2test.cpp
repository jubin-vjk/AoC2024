#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
 
bool isLevelValid(std::vector<int> level);
bool canBeSafe(std::vector<int> level);
bool isNotInRange(int num1, int num2);
std::vector<int> stringNumsToVector(std::string);
 
int main() {
    std::ifstream infile;
    std::ofstream fout("output-correct.txt");
    infile.open("Day2input.txt");
    if (!infile.is_open()) {
        std::cout << "Input file opening failed." << std::endl;
        exit(1);
    }
 
    std::vector<std::string> fileData;
 
    for (unsigned int i = 0; !infile.eof(); i++) {
        fileData.push_back("");
        getline(infile, fileData.at(i));
    }
 
    int numSafeReports = 0;
    int numReport = 0;
    for (std::string level : fileData) {
        if (isLevelValid(stringNumsToVector(level)) || canBeSafe(stringNumsToVector(level))) {
            fout << numReport << ". Safe" << std::endl;
            numSafeReports++;
        } else {
            fout << numReport << ". Unsafe" << std::endl;
        }
        numReport++;
    }
 
    fout << "\nSafe reports: " << numSafeReports << std::endl;
}
 
bool isLevelValid(std::vector<int> level) {
    bool ascendingOrDescending = false;
    //*Check if the level is in ascending order
    if (std::is_sorted(level.begin(), level.end())) {
        ascendingOrDescending = true;
    }
 
    //*Check if the level is in descending order
    std::reverse(level.begin(), level.end());
    if (std::is_sorted(level.begin(), level.end())) {
        ascendingOrDescending = true;
    }
    std::reverse(level.begin(), level.end()); //Reverse back to normal
 
    if (ascendingOrDescending == false) {
        return false;
    }
 
    //*Check that no two values are the same
    if (std::adjacent_find(level.begin(), level.end()) != level.end()) {
        return false;
    }
 
    //*Check that adjacent values differ by 1-3
    if (std::adjacent_find(level.begin(), level.end(), isNotInRange) != level.end()) {
        return false;
    }
 
    //* If all tests pass, the level is safe
    return true;
}
 
bool canBeSafe(std::vector<int> level) {
    std::vector<int> tempLevel(level.size()); //*Init so tempIt pos can be set before loop
    std::vector<int>::iterator tempIt = tempLevel.begin();
    for (std::vector<int>::iterator levelIt = level.begin(); levelIt != level.end(); levelIt++, tempIt++) {
        tempLevel = level;
        tempLevel.erase(tempIt);
        if (isLevelValid(tempLevel)) {
            return true;
        }
    }
    return false;
}
 
bool isNotInRange(int num1, int num2) {
    if ((abs(num1 - num2) < 1) || (abs(num1 - num2) > 3)) {
        return true;
    }
    return false;
}
 
std::vector<int> stringNumsToVector(std::string str) {
    std::stringstream ss(str);
    std::vector<int> stringNums;
    std::string currentNum;
 
    while (std::getline(ss, currentNum, ' ')) {
        stringNums.push_back(stoi(currentNum));
    }
    return stringNums;
}
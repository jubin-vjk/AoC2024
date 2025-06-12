#include <iostream>
#include <sstream>
#include<cctype>
using namespace std;

int main() {
    int sum = 0, count = 0, dos =0, donts = 0;
    bool doOrDont = true;
    string line;
   while (getline(cin, line)) {
        for(size_t i = 0; i < line.length(); i++) {
            if (line.substr(i, 4) == "do()") {
                doOrDont = true;
                dos++;
                i+= 4;
            }
            if (line.substr(i, 7) == "don't()") {
                doOrDont = false;
                donts++;
                i+= 7;
            }
            if (line.substr(i, 4) == "mul(" && doOrDont) {
                i+= 4;
                string num1 = "", num2 = "";
                bool isNum = true;
                while (isdigit(line[i])) {
                    num1 += line[i];
                    i++;
                }
                if (line[i] != ',' || num1.size() > 3) {
                    isNum = false;
                    continue;
                }
                if (line[i] == ',') {
                    i++;
                    while (isdigit(line[i])) {
                        num2 += line[i];
                        i++;
                    }
                }
                else {
                    isNum = false;
                    continue;
                }
                if (line[i] != ')' || num2.size() > 3) {
                    isNum = false;
                    continue;
                }
                if (isNum) {
                    sum += stoi(num1) * stoi(num2);
                    count++;
                }
            }
        }
    }
    cout << "Sum: " << sum << "\nCount: " << count << "\nDo: " << dos << "\nDon't: " << donts << endl;
}
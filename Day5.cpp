#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {

    string line;
    map<int, vector<int>> rules;

    while (getline(cin, line)) {
        string first, second;
        if (line.empty()) break;
        for(size_t i = 0; i < line.length(); ++i) {
            if (!(isdigit(line[i]))) {
                first = line.substr(0, i);
                second = line.substr(i + 1);
            }
        }
        rules[stoi(first)].push_back(stoi(second));
    }

    vector<vector<int>> pages;
    while (getline(cin, line)) {
        line+=" ";
        vector<int> update;
        string number;
        int index1 = -1, index2;
        for (size_t i = 0; i < line.length(); ++i) {
            if (!(isdigit(line[i]))) {
                index2 = i;
                number = line.substr(index1+1, index2);
                index1 = index2;
                update.push_back(stoi(number));
                cout << "Adding " << number << " to vector." << endl;
            }   
        }
        pages.push_back(update);
    }

    vector<bool> valid(pages.size(), true);
    int invalid = 0;
    for (size_t i = 0; i < pages.size(); ++i) {
        cerr << "Processing vector " << i << ": ";
        for (size_t j = pages[i].size()-1; j >= 0; j--) {
            cerr << "\n\tChecking " << pages[i][j] << " against previous elements.";
            for (size_t k = j - 1; k >= 0; k--) {
                cerr << "\n\t\tAgainst " << pages[i][k];
                for (int rule : rules[pages[i][j]]) {
                    if (rule == pages[i][k]) {
                        valid[i] = false;
                        invalid++;
                        break;
                    }
                }
            }
        }
    }

    int output = 0;
    for (size_t i = 0; i < pages.size(); ++i) {
        if (valid[i]) {
            for (int j : pages[i]) cout << j << " ";
            cout << endl;
            output += pages[i][pages[i].size()/2];
        }
    }
    cout << output << endl << invalid << endl;
    

}
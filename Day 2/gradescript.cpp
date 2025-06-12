#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {

    ifstream fin;
    vector<string> mine, correct;
    string line;

    fin.open("output.txt");
    while (getline(fin, line)) mine.push_back(line);
    fin.close();
    fin.open("output-correct.txt");
    while (getline(fin, line)) correct.push_back(line);
    fin.close();

    size_t smaller = mine.size() != correct.size() ? (mine.size() < correct.size() ? mine.size() : correct.size()) : mine.size();
    bool missing = mine.size() < correct.size() ? true : false;
    bool extra = mine.size() > correct.size() ? true : false;
    for (size_t i = 0; i < smaller; i++) if (mine[i] != correct[i]) cout << left << setw(25) << mine[i] << left << setw(25) << correct[i] << endl;
    if (missing) cout << "Missing lines" << endl;
    if (extra) cout << "Extra lines" << endl;
}
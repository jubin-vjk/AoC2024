#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
int main() {

    vector<vector<int>> reports;    
    string line;
    ofstream fout("output.txt");
    while (getline(cin, line)) {
        vector<int> level;
        int number;
        stringstream ss(line);
        while(ss >> number) level.push_back(number);
        reports.push_back(level);
    }
    
    int safe = 0;
    for (size_t i = 0; i < reports.size(); i++) {
        bool check = true, upOrDown = (reports[i][0] < reports[i][1]) ? true : false;
        int many = 0;
        for (size_t j = 0; j < reports[i].size()-1; j++) {
            vector<int> level = reports[i];
            if (upOrDown && j+1 != level.size() && level[j] < level[j+1] && level[j+1]-level[j] <= 3 && level[j+1]!=level[j]) continue;
            else if (!upOrDown && j+1 != level.size() && level[j] > level[j+1] && level[j]-level[j+1] <= 3 && level[j+1]!=level[j]) continue;
            else {
                check = false;
                many++;
                if (many <= 1) {
                    if (j==0) { 
                        upOrDown = level[1] < level[2] ? true : false;
                        check = true;
                    }
                    else if (j==1) {
                        upOrDown = level[0] < level[2] ? true : false;
                        if (upOrDown && level[0] < level[2] && level[2]-level[0] <= 3) check = true;
                        else if (!upOrDown && level[0] > level[2] && level[0]-level[2] <= 3) check = true;
                        else {
                            check = false;
                            break;
                        }
                    }
                    else if (j==level.size()-2) {
                        if (upOrDown && (level[j] > level[j+1] || level[j+1]-level[j] > 3)) check = true;
                        else if (!upOrDown && (level[j] < level[j+1] || level[j]-level[j+1] > 3)) check = true;
                        else if (upOrDown && j+1 != level.size() && level[j-1] < level[j+1] && level[j+1]-level[j-1] <= 3) check = true;
                        else if (!upOrDown && j+1 != level.size() && level[j-1] > level[j+1] && level[j-1]-level[j+1] <= 3) check = true;
                        else {
                            check = false;
                            break;
                        }
                    }
                    else if (upOrDown && j+1 != level.size() && level[j-1] < level[j+1] && level[j+1]-level[j-1] <= 3) check = true;
                    else if (!upOrDown && j+1 != level.size() && level[j-1] > level[j+1] && level[j-1]-level[j+1] <= 3) check = true;
                    else {
                        check = false;
                        break;
                    }
                }
                else break;
            }
        }
        if (check) {
            safe++;
            fout << i << ". Safe" << endl;
            }
        else {
            fout << i << ". Unsafe" << endl;
        }
    }
    fout << "\nSafe reports: " << safe << endl;
}
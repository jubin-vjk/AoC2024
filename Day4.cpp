#include <iostream>
#include <vector>
using namespace std;
int main() {
    
    string input;
    int found = 0, cross = 0;
    vector<string> inputs;
    while (cin >> input) inputs.push_back(input);

    bool mFound, aFound, sFound;

    for (int i = 0; i < inputs.size(); i++) {
        for (int j = 0; j < inputs[i].size(); j++) {
            vector<pair<int, int>> mDir = {{0+i, 1+j}, {1+i, 0+j}, {1+i, 1+j}, {1+i, -1+j}, {0+i, -1+j}, {-1+i, 0+j}, {-1+i, -1+j}, {-1+i, 1+j}};
            vector<pair<int, int>> aDir = {{0+i, 2+j}, {2+i, 0+j}, {2+i, 2+j}, {2+i, -2+j}, {0+i, -2+j}, {-2+i, 0+j}, {-2+i, -2+j}, {-2+i, 2+j}};
            vector<pair<int, int>> sDir = {{0+i, 3+j}, {3+i, 0+j}, {3+i, 3+j}, {3+i, -3+j}, {0+i, -3+j}, {-3+i, 0+j}, {-3+i, -3+j}, {-3+i, 3+j}};

            if(inputs[i][j] == 'X') {
                for (int k = 0; k < 8; k++) { 
                    mFound = false, aFound = false, sFound = false;
                    if (mDir[k].first < 0 ||  mDir[k].first >= inputs.size() || mDir[k].second < 0 || mDir[k].second >= inputs[i].size()) continue;
                    if (inputs[mDir[k].first][mDir[k].second] == 'M') mFound = true;
                    if (aDir[k].first < 0 ||  aDir[k].first >= inputs.size() || aDir[k].second < 0 || aDir[k].second >= inputs[i].size()) continue;
                    if (inputs[aDir[k].first][aDir[k].second] == 'A') aFound = true;
                    if (sDir[k].first < 0 ||  sDir[k].first >= inputs.size() || sDir[k].second < 0 || sDir[k].second >= inputs[i].size()) continue;
                    if (inputs[sDir[k].first][sDir[k].second] == 'S') sFound = true;

                    if (mFound && aFound && sFound) found++;
                }
            }

             if (inputs[i][j] == 'A') {
                if (i-1 < 0 || i+1 >= inputs.size() || j-1 < 0 || j+1 >= inputs[i].size()) continue;
                if (inputs[i-1][j-1] == 'M' && inputs[i+1][j+1] == 'S' && inputs[i+1][j-1] == 'M' && inputs[i-1][j+1] == 'S') cross++;
                if (inputs[i-1][j-1] == 'S' && inputs[i+1][j+1] == 'M' && inputs[i+1][j-1] == 'S' && inputs[i-1][j+1] == 'M') cross++;  
                if (inputs[i-1][j-1] == 'S' && inputs[i+1][j+1] == 'M' && inputs[i+1][j-1] == 'M' && inputs[i-1][j+1] == 'S') cross++;
                if (inputs[i-1][j-1] == 'M' && inputs[i+1][j+1] == 'S' && inputs[i+1][j-1] == 'S' && inputs[i-1][j+1] == 'M') cross++;
            }
        }
    }

    cout << found << endl << cross << endl;
}
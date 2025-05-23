#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main() {
    priority_queue<int> list1, list2;
    map <int, int> check;
    int number1, number2, sum = 0, score = 0;
    while (cin >> number1 >> number2) {
        list1.push(number1);
        list2.push(number2);
        check[number2]++;
    }
    while(!list1.empty() && !list2.empty()) {
        sum += abs(list1.top()-list2.top());
        score += list1.top() * check[list1.top()];
        list1.pop();
        list2.pop();
    }
   
    cout << "Part 1: " << sum << "\nPart 2: " << score << endl; 
}

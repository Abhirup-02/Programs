#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printResult(const string& approachName, const vector<int>& result) {
    cout << approachName << ": ";
    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]\n";
    } else {
        cout << "No solution found\n";
    }
}


#include <iostream>
#include <string>
using namespace std;

const char TILE = '_';
const char NINJA = '&';

void printNinjaPositions(int floorSize) {
    for (int i = 1; i <= floorSize - 4; i++) {
        for (int j = i + 2; j <= floorSize - 2; j++) {

            string output = "";

            for (int k = 0; k < floorSize; k++) {
                if (k == i || k == j) {
                    output += NINJA;
                }
                else {
                    output += TILE;
                }
            }

            cout << output << endl;
        }
    }
}

int main() {
    int floorSize;

    cout << "Enter floor size: ";
    cin >> floorSize;

    printNinjaPositions(floorSize);

    return 0;
}
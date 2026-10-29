
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ====================
// Problem 1
// ====================

struct Image {
    Image(vector<vector<double>> image) {
        pixels = image;
    }

    vector<vector<double>> pixels;
};

Image downsizeByHalf(Image one) {
    vector<vector<double>> smaller(
        one.pixels.size() / 2,
        vector<double>(one.pixels[0].size() / 2)
    );

    for (int i = 0; i < one.pixels.size(); i += 2) {
        for (int j = 0; j < one.pixels[i].size(); j += 2) {
            smaller[i / 2][j / 2] = one.pixels[i][j];
        }
    }

    Image result(smaller);
    return result;
}


// ====================
// Problem 2
// ====================

int findGrowth(vector<int>& months) {
    if (months.empty()) return 0;
    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < months.size(); i++) {
        if (months[i] >= months[i - 1]) {
            currentStreak++;
            if(currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        }
        else {
            currentStreak = 1;
        }
    }

    return longestStreak;
}


// ====================
// Problem 3
// ====================

string militaryToAMPM(string time) {
    if (time.size() != 4) {
        return "Invalid";
    }

    for (char c : time) {
        if (c < '0' || c > '9') {
            return "Invalid";
        }
    }

    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(2));

    if (hours > 23 || minutes > 59) {
        return "Invalid";
    }

    string AMPM = "AM";

    if (hours >= 12) {
        AMPM = "PM";
    }

    if (hours == 0) {
        hours = 12;
    }
    else if (hours > 12) {
        hours -= 12;
    }

    string NewTime = to_string(hours) + ":" + to_string(minutes) + AMPM;
    return NewTime;
}

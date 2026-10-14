#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// This program is just a test to see if I can commit this wihtout help along with some extra practice

void numberGuessingGame(){

    srand(time(0));
    bool wantsToPlay = true;
    char playAgain;
    char choice;
    int guess;

    while(wantsToPlay == true){
        int max = 100;
        int min = 1;

        cout << "Would you like to pick a max & min number? (y/n): ";
        cin >> choice;

        if(choice == 'y'){
            cout << "What would you like your max to be? Enter an integer: ";
            cin >> max;
            cout << "What would you like your max to be? Enter an integer: ";
            cin >> min;
        }    
        // I am aware that I am not checking edge cases here and throughout this program.
        // This is just a test not a real project or assignment

        int secret = rand() % (max - min + 1) + min;

        do {
            cout << "Enter your guess: " << endl;
            cin >> guess;
            (guess > secret) ? cout << "Too high\n" : (guess < secret) ? cout << "Too low" << endl : cout << "You got it!" << endl; 
        } while(guess != secret);

        cout << "Would you like to play again? (y/n):";
        cin >> playAgain;
        if(playAgain == 'n'){
            cout << "Thanks for playing!";
            wantsToPlay = false;
        }
    }
}

int main(){
    numberGuessingGame();
    return 0;
}

//edit: testing push
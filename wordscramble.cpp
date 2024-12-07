#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to scramble a word
string scrambleWord(string word) {
    string scrambled = word;
    int length = scrambled.length();
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        // Swap characters at i and j
        char temp = scrambled[i];
        scrambled[i] = scrambled[j];
        scrambled[j] = temp;
    }
    return scrambled;
}

// Function to ask a question until the player gets it correct
void askQuestionUntilCorrect(string scrambledWord, string correctWord) {
    string userAnswer;
    while (true) {
        cout << "\nUnscramble the word: " << scrambledWord << "\nYour Answer: ";
        cin >> userAnswer;

        if (userAnswer == correctWord) {
            cout << "Correct! You may proceed to the next question.\n";
            break;
        } else {
            cout << "Incorrect! Try again.\n";
        }
    }
}

// Main game function
void wordScrambleGame() {
    cout << "Welcome to the Word Scramble Game!\n";
    cout << "Unscramble the following 12 words correctly to win.\n";

    // Words to scramble
    string words[12] = {"apple", "banana", "orange", "grape", "peach", "cherry",
                        "mango", "lemon", "plum", "berry", "melon", "kiwi"};

    srand(time(0)); // Seed for randomness

    for (int i = 0; i < 12; i++) {
        // Select a random word and scramble it
        string word = words[i];
        string scrambledWord = scrambleWord(word);

        // Ask the question until the player gets it correct
        askQuestionUntilCorrect(scrambledWord, word);
    }

    cout << "\nCongratulations! You unscrambled all 12 words and won the game!\n";
}

int main() {
    wordScrambleGame();
    return 0;
}

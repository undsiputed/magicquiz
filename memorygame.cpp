#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> // For mathematical functions

using namespace std;

// Function to ask a question until the player gets it correct
void askQuestionUntilCorrect(string question, double correctAnswer) {
    double userAnswer;
    while (true) {
        cout << "\nQuestion: " << question << "\nYour Answer: ";
        cin >> userAnswer;

        if (fabs(userAnswer - correctAnswer) < 0.001) { // Allow for small rounding errors
            cout << "Correct! You may proceed to the next question.\n";
            break;
        } else {
            cout << "Incorrect! Try again.\n";
        }
    }
}

// Main game function
void mathQuizGame() {
    cout << "Welcome to the Math Quiz Game: Square Root and Cube Root Edition!\n";
    cout << "Answer 9 questions correctly to win.\n";

    // Generate questions
    srand(time(0)); // Seed for randomness
    int questionCount = 0;

    while (questionCount < 9) {
        int randomNum = rand() % 20 + 1; // Random number between 1 and 20
        int questionType = rand() % 2;  // Randomly decide between square root (0) or cube root (1)
        string question;
        double correctAnswer;

        if (questionType == 0) { // Square root question
            int square = randomNum * randomNum;
            question = "What is the square root of " + to_string(square) + "?";
            correctAnswer = randomNum;
        } else { // Cube root question
            int cube = randomNum * randomNum * randomNum;
            question = "What is the cube root of " + to_string(cube) + "?";
            correctAnswer = randomNum;
        }

        // Ask the question until the answer is correct
        askQuestionUntilCorrect(question, correctAnswer);
        questionCount++;
    }

    cout << "\nCongratulations! You answered all 9 questions correctly and won the game!\n";
}

int main() {
    mathQuizGame();
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to ask a question until the player gets it correct
void askQuestionUntilCorrect(string question, string correctAnswer) {
    string userAnswer;
    while (true) {
        cout << "\nQuestion: " << question << "\nYour Answer: ";
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Correct! You may proceed to the next question.\n";
            break;
        } else {
            cout << "Incorrect! Try again.\n";
        }
    }
}

// Main game function
void codingQuizGame() {
    cout << "Welcome to the Coding Questions Quiz!\n";
    cout << "Answer 5 coding questions correctly to win.\n";

    // Questions and answers
    string questions[10] = {
        "What is the output of 2 + 3 * 4? (Answer: 14)", // Operator precedence
        "Which keyword is used to declare a constant variable in C++? (Answer: const)", // Keyword
        "What is the default return type of main() in C++? (Answer: int)", // Basic C++
        "Which header file is used for input/output in C++? (Answer: iostream)", // I/O basics
        "What does '++' operator do? (Answer: increment)", // Operators
        "What is the index of the first element in an array? (Answer: 0)", // Arrays
        "Which symbol is used to comment a single line in C++? (Answer: //)", // Comments
        "Which loop is guaranteed to execute at least once? (Answer: do-while)", // Loop logic
        "Which function is used to print output in C++? (Answer: cout)", // Printing
        "What is the meaning of '&&' in C++? (Answer: and)" // Logical operators
    };

    string answers[10] = {
        "14", "const", "int", "iostream", "increment",
        "0", "//", "do-while", "cout", "and"
    };

    bool asked[10] = {false}; // Track if a question has been asked
    int questionsAnswered = 0;

    srand(time(0)); // Seed the random number generator

    while (questionsAnswered < 5) {
        int index;
        do {
            index = rand() % 10; // Randomly select a question
        } while (asked[index]); // Ensure the question hasn't been asked already

        asked[index] = true; // Mark the question as asked
        askQuestionUntilCorrect(questions[index], answers[index]); // Ask the question
        questionsAnswered++;
    }

    cout << "\nCongratulations! You answered all 5 questions correctly and won the game!\n";
}

int main() {
    codingQuizGame();
    return 0;
}

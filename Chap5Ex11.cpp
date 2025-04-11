// File Name: Chap5Ex11.cpp
// Developer/Programmer: Bryan Hurley
// Date: April 2025
// Requirements:
// Display two random numbers to be added -> Pause and wait for student to solve the problem -> Display the correct solution. 
// Input should be validated, at least three modules, repeatable'
// Now, take input, react based on whether or not correct
#include <iostream>
#include <random>

using namespace std;

// Generates two random 3-digit numbers for the problem
void generateProblem(int& num1, int& num2) {
    static random_device rd;
    uniform_int_distribution<int> randomInt(100, 999);

    num1 = randomInt(rd);
    num2 = randomInt(rd);
}

// Gets the student's answer and validates input
int getStudentAnswer() {
    int answer;
    while (true) {
        cout << "Enter your answer: ";
        if (cin >> answer) {
            return answer;
        }
        else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

// Checks student's answer and provides feedback
void checkAnswer(int num1, int num2, int studentAnswer) {
    int correctAnswer = num1 + num2;

    if (studentAnswer == correctAnswer) {
        cout << "Congratulations! That's correct!\n";
    }
    else {
        cout << "Oops! The correct answer was: " << correctAnswer << endl;
    }
}

// Asks user if they want to try another problem
bool askToContinue() {
    char choice;
    while (true) {
        cout << "Would you like to try another problem? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
        cin.ignore(10000, '\n');

        if (choice == 'y') return true;
        else if (choice == 'n') return false;
        else cout << "Invalid input. Please enter 'y' or 'n'.\n";
    }
}

// Main program
int main() {
    cout << "Welcome to the Math Tutor!\n";

    bool keepGoing = true;
    while (keepGoing) {
        int num1, num2;
        generateProblem(num1, num2);

        // Display problem
        cout << "\nSolve this problem:\n";
        cout << "  " << num1 << endl;
        cout << "+ " << num2 << endl;
        cout << "------" << endl;

        // Get and check answer
        int studentAnswer = getStudentAnswer();
        checkAnswer(num1, num2, studentAnswer);

        keepGoing = askToContinue();
    }

    cout << "\nThank you for using the Math Tutor! Goodbye.\n";
    return 0;
}
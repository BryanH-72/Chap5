// File Name: Chap5Ex11.cpp
// Developer/Programmer: Bryan Hurley
// Date: April 2025
// Requirements:
// Display two random numbers to be added -> Pause and wait for student to solve the problem -> Display the correct solution. 
// Input should be validated, at least three modules, repeatable

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

// Fixes error where cin.get() doesnt work
void Fix() {
    char ch;
    
    while (cin.get(ch) && ch != '\n') {}
    // does nothing, fixes everything. Don't understand logic
}

// Displays the problem and waits for the user to press Enter
void showProblemAndWait(int num1, int num2) {
    cout << "\nSolve this problem:\n";
    cout << "  " << num1 << endl;
    cout << "+ " << num2 << endl;
    cout << "\nPress Enter when you're ready to see the answer...";
    
    cin.get();    // Wait for Enter
}

// Displays the correct answer to the problem
void displayAnswer(int num1, int num2) {
    cout << "\nThe correct answer is:\n";
    cout << "  " << num1 << endl;
    cout << "+ " << num2 << endl;
    cout << "-----" << endl;
    cout << "  " << (num1 + num2) << endl;
}

// Validates user input for continuation (y/n)
bool askToContinue() {
    char choice;
    while (true) {
        cout << "\nWould you like to try another problem? (y/n): ";
        cin >> choice;

        Fix();
        choice = tolower(choice);

        if (choice == 'y') return true;
        else if (choice == 'n') return false;
        else cout << "Invalid input. Please enter 'y' or 'n'.\n";
    }
}

// Main function
int main() {
    cout << "Welcome to the Math Tutor!\n";

    bool keepGoing = true;
    while (keepGoing) {
        int num1, num2;
        generateProblem(num1, num2);
        showProblemAndWait(num1, num2);
        displayAnswer(num1, num2);
        keepGoing = askToContinue();
    }

    cout << "\nThank you for using the Math Tutor! Goodbye.\n";
    return 0;
}

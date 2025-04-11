// File Name: Chap5Ex11.cpp
// Developer/Programmer: Bryan Hurley
// Date: April 2025
// Requirements:
// Display two random numbers to be added/subtracted/divided/multiplied -> Pause and wait for student to solve the problem -> Display the correct solution. 
// Input should be validated, at least three modules, repeatable'
// Now, take input, react based on whether or not correct

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

// Generates two random 3-digit numbers
void generateProblem(int& num1, int& num2) {
    static random_device rd;
    uniform_int_distribution<int> randomInt(100, 999);

    num1 = randomInt(rd);
    num2 = randomInt(rd);
}

// Gets validated numeric input from user
double getStudentAnswer() {
    double answer;
    while (true) {
        cout << "Enter your answer: ";
        if (cin >> answer)
            return answer;
        else {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

int main() {
    int choice;
    cout << "Welcome to the Math Tutor!\n";

    do {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Quit\n";

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Validate menu choice
        if (cin.fail() || choice < 1 || choice > 5) {
            cout << "Invalid choice. Please select a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 5) break; // Exit

        int num1, num2;
        generateProblem(num1, num2);

        // Ensure division is safe
        if (choice == 4) {
            while (num2 == 0) generateProblem(num1, num2);
        }

        // Display problem
        char op;
        double correctAnswer;

        switch (choice) {
        case 1:
            op = '+';
            correctAnswer = num1 + num2;
            break;
        case 2:
            op = '-';
            correctAnswer = num1 - num2;
            break;
        case 3:
            op = '*';
            correctAnswer = num1 * num2;
            break;
        case 4:
            op = '/';
            correctAnswer = static_cast<double>(num1) / num2;
            break;
        }

        cout << "\nSolve this problem:\n";
        cout << "  " << num1 << endl;
        cout << op << " " << num2 << endl;
        cout << "------" << endl;

        double studentAnswer = getStudentAnswer();

        if (fabs(studentAnswer - correctAnswer) < 0.0001)
            cout << "Correct!\n";
        else
            cout << "Incorrect. The correct answer is: " << correctAnswer << endl;

    } while (true);

    cout << "\nThanks for using the Math Tutor. Goodbye!\n";
    return 0;
}

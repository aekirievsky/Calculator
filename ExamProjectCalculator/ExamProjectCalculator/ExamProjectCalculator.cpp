#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double launch();

double multiplicationAndDivision();

double exponentiation();

double checkBracket();

double readNumber();

double launch() {
    double result;
    char action;

    result = multiplicationAndDivision();

    while (true) {
        action = cin.get();

        switch (action) {
        case '+':
            result += multiplicationAndDivision();
            break;
        case '-':
            result -= multiplicationAndDivision();
            break;
        default:
            cin.putback(action);
            return result;
        }
    }
}

double multiplicationAndDivision() {
    double result;
    char action;
    double temp;

    result = exponentiation();

    while (true) {
        action = cin.get();

        switch (action) {
        case '*':
            result *= exponentiation();
            break;
        case '/':
            temp = exponentiation();

            if (temp == 0.0) {
                cout << "Division by zero! Try again! Result incorrect!" << endl;
                return 0;
            }
            else {
                result /= temp;
            }
            break;
        default:
            cin.putback(action);
            return result;
        }
    }
}

double exponentiation() {
    double result;
    char action;
    vector<double> num;
    num.push_back(checkBracket());

    while (true) {
        action = cin.get();

        while (action == ' ')
            action = cin.get();

        if (action == '^')
            num.push_back(checkBracket());
        else {
            cin.putback(action);
            break;
        }
    }

    for (int i = num.size() - 1; i > 0; i--)
        num[i - 1] = pow(num[i - 1], num[i]);

    return num[0];
}

double checkBracket() {
    double result;
    char bracket;
    int numberSign = 1;

    bracket = cin.get();

    while (bracket == ' ')
        bracket = cin.get();

    switch (bracket) {
    case '-':
        numberSign = -1;
    case '+':
        bracket = cin.get();
        break;
    }

    while (bracket == ' ')
        bracket = cin.get();

    if (bracket == '(') {
        result = launch();
        bracket = cin.get();

        if (bracket != ')') {
            cout << "Incorrect placement of brackets" << endl;
            return 0;
        }
    }
    else {
        cin.putback(bracket);
        result = readNumber();
    }
    return numberSign * result;
}

double readNumber() {
    double result = 0.0;
    char digit;
    double k = 10.0;
    int numberSign = 1;

    digit = cin.get();

    switch (digit) {
    case '-':
        numberSign = -1;
        break;
    default:
        if (digit != '+')
            cin.putback(digit);
    }

    while (true) {
        digit = cin.get();

        while (digit == ' ')
            digit = cin.get();

        if (digit >= '0' && digit <= '9')
            result = result * 10.0 + (digit - '0');
        else {
            cin.putback(digit);
            break;
        }
    }

    digit = cin.get();

    if (digit == '.') {
        while (true) {
            digit = cin.get();

            while (digit == ' ')
                digit = cin.get();

            if (digit >= '0' && digit <= '9') {
                result += (digit - '0') / k;
                k *= 10.0;
            }
            else {
                cin.putback(digit);
                break;
            }
        }
    }
    else
        cin.putback(digit);
    return numberSign * result;
}

int main() {
    double userInput;

    cout << "Enter an launch: ";

    userInput = launch();

    cout << "Result = " << userInput << endl;

    return 0;
}


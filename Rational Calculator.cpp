// File Name : CS112_A2_T3_S28_20230315_20230256_20230213.cpp
// Purpose   : Rational Number Calculator

// Author 1  : Mohamed Ahmed Kotb  - Email: kotb200484@gmail.com
// ID 1      : 20230315 and he did all checking inputs, return_rational,check_rational and check_non_digits functions

// Author 2  : Omar Sayed Soliman Ibrahim  - Email: omarsayedsoliman165@gmail.com
// ID 2      : 20230256 and he did the greatest_common_factor and convert_decimal functions

// Author 3  : Abdelrahman Mohamed Ahmed El-Gaml  - Email: abdulrahmanelgaml89@gmail.com
// ID 3      : 20230213 and he did all the operators functions

/*         **********  Algorithms  **********

1. Define a function greatest_common_divisor(x, y) to find the greatest common divisor of two integers x and y.
2. Define a function convert_decimal(decimal) to convert a decimal number into a simplified fraction.
3. Implement arithmetic operations adding(n1, n2), subtracting(n1, n2), multiplying(n1, n2), and dividing(n1, n2).
4. Define a function return_rational(num, denom, numer, pos) to return the rational number as a decimal.
5. Define a function check_rational(num) to check if the input string represents a rational number.
6. Define a function check_non_digits(num, l) to check if the input string contains non-digit characters.
7. In the main() function:
a. Prompt the user for rational number operations until the user chooses to exit.
b. Parse input strings for numbers and operation.
c. Check for invalid inputs, including non-digit characters and unsupported operations.
d. Convert input strings to rational numbers.
e. Perform arithmetic operations on rational numbers.
f. Output the result as a simplified fraction.
8. Handle edge cases, such as division by zero and negative denominator */


#include <iostream>
#include <string>
#include <cctype>
using namespace std;
// to get the greatest common factor
int greatest_common_divisor(int x, int y)
{
    if (y == 0)
        return x;
    return greatest_common_divisor(y, x % y);
}
// to convert decimal number to fraction number
void convert_decimal(double decimal) {
    int denom = 1000000;
    int num = decimal * denom;
    for (int i = denom; i >= 2; i--) {
        if (num % i == 0 && denom % i == 0) {
            num = num / i;
            denom = denom / i;
        }
    }
    int common_divisor = greatest_common_divisor(num, denom);

    // Simplify the fraction
    num /= common_divisor;
    denom /= common_divisor;

    if (denom == 1)
        cout << num;
    else
        cout << num << "/" << denom;
    cout << endl;
}
// Adding function
double adding(double n1, double n2) {
    return n1 + n2;
}
// Subtraction function

double subtracting(double  n1, double n2) {

    return (n1 - n2) ;
}
// Multiplying function

double multiplying(double n1, double n2) {
    return n1 * n2;
}
// Dividing function

double dividing(double n1, double n2) {
    if (n2 == 0)
        return 0;
    else
        return n1 * (1/n2);
}
// it returns the number to rational number by converting it to numerator and denominator
double return_rational(string& num, int& denom, int& numer, int& pos) {

    numer = stoi(num.substr(0, pos));
    denom = stoi(num.substr(pos + 1));

    return double(numer) / double(denom);
}
// to check if the input is invalid and checks if it integer or decimal or fraction
int check_rational(string& num) {
    int c = 0;
    int pos = -1;
    for (int i = 0; i < num.length(); ++i) {
        if (num[i] == '/') {
            c++;
            pos = i;    // return the position of the division
            if (isdigit(num[i]))
                return 0;
        }
    }
    // If exactly one division operation is found and there are digits
    if (c== 1)
        return pos;
        // If more than one division operation is found return a message
    else if (c >1)
        return 0;
    else
        return -1;
}
// to check for the invalid inputs and special char
bool check_non_digits(string& num, int l) {
    int dot = 0;
    for (int i = 0; i < l; i++) {
        if (!isdigit(num[i]) && num[i] != '/') {
            // to skip + and - when they entered at the first of the number
            if (i == 0 && (num[i] == '+' || num[i] == '-')) {
                continue;
            }
            // to skip it decimal numbers and make them valid for the input
            if (num[i]== '.') {
                dot++;
                continue;
            }
            return true;
        }
    }
    // to check if there is more decimal points
    if (dot > 1)
        return true;
    return false;
}

int main() {
    cout << "Welcome to Rational Number Calculator.\n";
    while (true) {
        string n1, n2, operation;
        double result, res_rational_1, res_rational_2;
        cout << "Please enter a rational number operations (or exit): \n";
        cin >> n1;
        // if the user enters exit it ends the program
        if (n1 == "exit") {
            cout << "Thank you for using rational number calculator,\n"
                 << "Have a nice time.\n";
            return 0;
        }
        // take the operation from the user
        cin >> operation >> n2;
        // Checking if they are not digits
        bool check_non_1 = check_non_digits(n1, n1.length());
        bool check_non_2 = check_non_digits(n2, n2.length());

        int numerator_1, denominator_1, numerator_2,
        denominator_2,check_rational_1, check_rational_2;
        // Checking the invalid inputs
        check_rational_1 = check_rational(n1);
        check_rational_2 = check_rational(n2);
        // If the user enters invalid input it returns a message to him
        if(check_non_1 || check_non_2 ||(operation != "+" && operation != "-" &&
        operation != "*" && operation != "/" && operation.length() != 1))
        {
            cout << "Invalid operation.\n"
                    "Please try again...\n";
            continue;
        }
        // Checking the invalid inputs
        if (check_rational_1 == 0 || check_rational_2 == 0)
        {
            cout << "Invalid operation.\n"
                    "Please try again...\n";
            continue;
        }
        // Returning integers and decimals as they are
        if(check_rational_1 == -1 ) {
            res_rational_1 = stod(n1);

        }
        if (check_rational_2 == -1)
            res_rational_2 = stod(n2);

        if (check_rational_1 != -1){
            res_rational_1= return_rational(n1, denominator_1, numerator_1, check_rational_1);
            // to check if the denominator is negative or equals to zero
            if (denominator_1 <= 0 ) {
                cout << "Please enter a Positive number in the denominator\n";
                continue;
            }
        }
        if(check_rational_2 != -1){
            res_rational_2 = return_rational(n2, denominator_2, numerator_2, check_rational_2);
            // to check if the denominators are negative or equal to zero
            if (denominator_2 <= 0 || res_rational_2 == 0) {
                cout << "Please enter a Positive number in the denominator\n";
                continue;
            }
        }
        if (operation == "+") {           // Adding
            result = adding(res_rational_1, res_rational_2);


        } else if (operation == "-") {    // subtracting
            result = subtracting(res_rational_1, res_rational_2);


        } else if (operation == "*") {    // Multiplying
            result = multiplying(res_rational_1, res_rational_2);


        } else if (operation == "/") {    // Dividing
            result = dividing(res_rational_1, res_rational_2);
            // to check if the denominator is negative or equal zero
            if (result == 0) {
                cout << "Please enter a Positive number in the denominator\n";
            }

        }
        // converting the decimal to fraction number
        convert_decimal(result);
    }
}

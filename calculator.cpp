#include <iostream>
#include <cmath>
using namespace std;


/**
*@brief Displays appropriate messages and handles failed state of cin.
*/

void HandlingInputFailure() {
    cout << "Invalid input. Please enter valid input." << endl;
    cin.clear();
    cin.ignore();
    return;
}







/**
*@brief Prompts user to input number, checks whether input is valid or not,
and prompts user over and over again if input in invalid
*
*@param num Pointer to number whose value is to be input
*/

void getInput (float *num) {
    do {
        if (!cin) {
            HandlingInputFailure();
        }
        cout << "Enter Number: ";
        cin >> *num;
   }while(!cin);
   return;
}




/**
*@brief Prompts user to input number, checks whether input is valid or not,
and prompts user over and over again if input in invalid
*
*@param num Pointer to number whose value is to be input
*/

void getInput (int *num) {
    do {
        if (!cin) {
            HandlingInputFailure();
        }
        cout << "Enter Number: ";
        cin >> *num;
   }while(!cin);
   return;
}




void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void swapNumbers(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}






/**
*@brief Prompts user to keep on re-entering divisor until user enters a non zero divisor, to avoid division by zero
*
*@param b The Divisor
*@return Non-zero divisor
*/

float nonZeroDivisor(float b) {
    while (b==0) {
        cout << "Error: Division by zero is not allowed." << endl;
        cout << "Please enter a non zero divisor: ";
        cin >> b;
    }
    return b;
}





/**
*@brief Performs addition of two floating-point numbers.
*
*@param a The First Number.
*@param b The Second Number.
*@return The sum of a and b
*/

float addition(float a, float b) {
    return a+b;
}



/**
*@brief Performs subtraction of two floating-point numbers.
*
*@param a The First Number.
*@param b The Second Number.
*@return The difference of a and b
*/

float subtraction(float a, float b) {
    return a-b;
}



/**
*@brief Performs multiplication of two floating-point numbers.
*
*@param a The First Number.
*@param b The Second Number.
*@return The product of a and b
*/

float multiplication(float a, float b) {
    return a*b;
}



/**
*@brief Performs division of two floating-point numbers.
*
*@param a The First Number (dividend).
*@param b The Second Number (divisor).
*@return The result of a divided by b. If b is 0, prompts user to enter a non zero value for b and then returns the result of a divided by b.
*/

float division(float a, float b) {
    return a/b;
}



/**
*@brief Computes the quotient of two integers.
*
*@param a The Dividend.
*@param b The Divisor.
*@return The integer quotient of a divided by b
*/

int quotient(long long int a, long long int b) {
    if (b==0) {
        b = nonZeroDivisor(b);
    }
    return a/b;
}



/**
*@brief Computes the remainder of two integers.
*
*@param a The Dividend.
*@param b The Divisor.
*@return The remainder of a divided by b
*/

int remainder(int a, int b) {
    if (b==0) {
        b = nonZeroDivisor(b);
    }

    return a%b;
}



/**
*@brief Computes the exponentiation of two floating-point numbers.
*
*@param a The Base.
*@param b The Power.
*@return The exponentiation of a raise to b


float exponentiation(float a, float b) {
    float product = 1;
    for (int i = 1; i <= b; i++){
        product *= a;
    }
    return product;
}*/






/**
*@brief Computes the factorial of an integer
*
*@param a The integer whose factorial is to be found
*@return factorial of a
*/

unsigned long long int fact(unsigned long long int a) {
    if (a == 1 || a == 0) {
        return 1;
    } else {
        return a*fact(a-1);
    }
}





int greatestCommonDivisor(int a, int b) {
    int gcd = 0;
    if (b < a) {
        swapNumbers(&a, &b);
    }
    for (int i = a; i >= 1; i--) {
        if ((a%i == 0)&&(b%i == 0)) {
            gcd = i;
            break;
        }
    }
    return gcd;
}




int leastCommonMultiple(int a, int b) {
    int lcm;
    if (b < a) {
        swapNumbers(&a, &b);
    }
    for (int i = b; i <= a*b; i++) {
        if((i%a == 0)&&(i%b == 0)){
            lcm = i;
            break;
        }
    }
    return lcm;
}



float percent(float a, float b) {
    return (a/b)*100;
}




float percentDiff(float a, float b) {
    if (b < a) {
        swapNumbers(&a, &b);
    }
    float av = (a+b)/2;
    return ((b - a)/av)*100;
}




void percentIncDec(float old, float newv) {
    if(old == newv) {
        cout << "There is no percentage increase or decrease." << endl << endl;
    }
    else if (old < newv) {
        float perInc = ((newv-old)/old)*100;
        cout << "Percentage increase from " << old << " to " << newv << ": " << perInc << "%" << endl << endl;
    } else {
        float perDec = ((old-newv)/old)*100;
        cout << "Percentage decrease from " << old << " to " << newv << ": " << perDec << "%" << endl << endl;
    }
}





//Displays menu options for the calculator program.

void displayOptions (){
    cout << "Press 0 to exit calculator. \n"
         << "Press 1 to add two numbers. \n"
         << "Press 2 to subtract two numbers. \n"
         << "Press 3 to multiply two numbers.\n"
         << "Press 4 to divide two numbers. \n"
         << "Press 5 to find integer quotient of two numbers. \n"
         << "Press 6 to find remainder of two numbers.\n"
         << "Press 7 for exponentiation. \n"
         << "Press 8 to find square root of a number. \n"
         << "Press 9 to find factorial of a positive integer. \n"
         << "Press 10 to find greatest common divisor of two integers. \n"
         << "Press 11 to find least common multiple of two integers. \n"
         << "Press 12 to find percentage. \n"
         << "Press 13 to find percentage difference. \n"
         << "Press 14 to find percentage increase/decrease. \n\n";
         return;
}








/**
*@brief Passes pointers a and b to
*
*@param a Pointer to first number
*@param b Pointer to second number
*/

void inputValidNumbers(float *a, float *b) {
    cout << "First Number" << endl;
    getInput(a);
    cout << "Second Number" << endl;
    getInput(b);
    return;
}





//Main function that implements a simple calculator program.


int main () {
    float num1, num2;
    int choice;
    float result;

    cout << "Simple Calculator" << endl << endl;
    cout << "This calculator allows you to perform basic arithmetic operations." << endl;

    do {
        do {
            if (!cin) {
                HandlingInputFailure();
            }
            cout << "Press 1 to display options for available operations\nPress 2 to continue directly." << endl;
            cin >> choice;
        } while (!cin || !(choice == 1 || choice == 2));

        if (choice == 1) {
            displayOptions();
        }
        do {
            if (!cin) {
                HandlingInputFailure();
            }
            cout << "*Enter an integer(0-14): ";
            cin >> choice;
        }while (!cin || (choice < 0 || choice > 14));

        switch (choice) {
        case 0:
            break;
        case 1:
            inputValidNumbers(&num1, &num2);
            cout << num1 << " + " << num2 << " = " << addition (num1,num2) << endl << endl;
            break;
        case 2:
            inputValidNumbers(&num1, &num2);
            cout << num1 << " - " << num2 << " = " << subtraction (num1, num2) << endl << endl;
            break;
        case 3:
            inputValidNumbers(&num1, &num2);
            cout << num1 << " * " << num2 << " = " << multiplication (num1, num2) << endl << endl;
            break;
        case 4:
            inputValidNumbers(&num1, &num2);
            if (num2==0) {
                num2 = nonZeroDivisor(num2);
            }
            result = division (num1, num2);
            cout << num1 << " / " << num2 << " = " << result << endl << endl;
            break;
        case 5:
            inputValidNumbers(&num1, &num2);
            result = quotient (num1, num2);
            cout << "Integer Quotient: " << result << endl << endl;
            break;
        case 6:
            inputValidNumbers(&num1, &num2);
            result = remainder (num1, num2);
            cout << "Remainder: " << result << endl << endl;
            break;
        case 7:
            inputValidNumbers(&num1, &num2);
            cout << num1 << " ^ " << num2 << " = " << pow(num1, num2) << endl << endl;
            break;
        case 8:
            do {
                getInput(&num1);
                if (num1 < 0){
                    cout << "Error: Negative numbers don't have real square roots! Try again.";
                }
            }while(num1 < 0);
            cout << num1 << " ^ (1/2) = " << sqrt(num1) << endl << endl;
            break;
        case 9:
            do {
                getInput(&num1);
                if (num1 < 0) {
                    cout << "Error: Negative numbers don't have real factorials. Try again\n";
                }
                if (num1 > 20) {
                    cout << "Error: Number is too large. This calculator computes factorials of numbers upto 20 only.\nTry again\n";
                }
            } while (num1 < 0 || num1 > 20);
            result = fact(num1);
            cout << "Factorial of " << num1 << ": " << result << endl << endl;
            break;
        case 10:
            inputValidNumbers(&num1, &num2);
            result = greatestCommonDivisor(num1, num2);
            if (!result){
                cout << "There is no common divisor between the two integers." << endl << endl;
            } else {
                cout << "Greatest common divisor: " << result << endl << endl;
            }
            break;
        case 11:
            inputValidNumbers(&num1, &num2);
            result = leastCommonMultiple(num1, num2);
            cout << "Least common multiple: " << result << endl << endl;
            break;
        case 12:
            inputValidNumbers(&num1, &num2);
            result = percent(num1, num2);
            cout << num1 << " is " << result << "% of " << num2 << endl << endl;
            break;
        case 13:
            inputValidNumbers(&num1, &num2);
            result = percentDiff(num1, num2);
            cout << "Percentage difference between " <<  num1 << " and " << num2 << ": " << result << "%" << endl << endl;
            break;
        case 14:
            inputValidNumbers(&num1, &num2);
            percentIncDec(num1, num2);
            break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}


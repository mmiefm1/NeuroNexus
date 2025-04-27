#include <iostream>

int main() {
    double num1, num2;
    char operation;

    // Displaying options
    std::cout << "Simple Calculator\n";
    std::cout << "Enter two numbers and choose an operation:\n";
    std::cout << "Operations:\n";
    std::cout << "+  -> Addition\n";
    std::cout << "-  -> Subtraction\n";
    std::cout << "*  -> Multiplication\n";
    std::cout << "/  -> Division\n";
    
    // Taking user input
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    // Performing the chosen operation
    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed!" << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation!" << std::endl;
    }

    return 0;
}

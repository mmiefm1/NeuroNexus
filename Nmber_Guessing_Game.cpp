#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int secretNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n\n";

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < secretNumber) {
            std::cout << "Your guess is too low. Try again.\n";
        } else if (guess > secretNumber) {
            std::cout << "Your guess is too high. Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << "\n";
            break;
        }
    }

    return 0;
}

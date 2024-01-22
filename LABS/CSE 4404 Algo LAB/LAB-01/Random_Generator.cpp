#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));

    // Get the value of n from the user
    long long int n;
    std::cin >> n;

    // Generate n random numbers
    for (long long int i = 0; i < n; ++i) {
        int randomNumber = std::rand();
        std::cout << randomNumber << " ";
    }

    return 0;
}

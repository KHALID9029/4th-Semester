#include <iostream>
#include <chrono>
using namespace std;





int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000000; i++){\
        int a = 5;
    };

    // End the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = end - start;

    // Print the duration in seconds
    std::cout << "Execution time: " << duration.count() << " seconds." << std::endl;

}

#include <iostream>
#include <thread> // For simulating threads
#include "ChocolateBoiler.hpp"

// A function that acts like a "Worker" in the factory
void factoryWorker(int id) {
    // 1. Get the single instance
    // Note: We use a REFERENCE (&) to avoid making a copy!
    ChocolateBoiler& boiler = ChocolateBoiler::getInstance();
    
    std::cout << "Worker " << id << " got the boiler." << std::endl;

    // 2. Try to fill and boil
    // Since all workers share the SAME boiler, only the first one will succeed.
    boiler.fill();
    boiler.boil();
    boiler.drain();
}

int main() {
    std::cout << "--- STARTING CHOCOLATE FACTORY ---" << std::endl;

    // Let's create two threads (two workers) trying to use the boiler at once.
    std::thread worker1(factoryWorker, 1);
    std::thread worker2(factoryWorker, 2);

    // Wait for them to finish
    worker1.join();
    worker2.join();

    std::cout << "--- END OF SHIFT ---" << std::endl;
    return 0;
}
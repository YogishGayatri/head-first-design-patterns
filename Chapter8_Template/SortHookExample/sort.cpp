#include <iostream>
#include <vector>
#include <algorithm> // This contains the 'std::sort' Template Method
#include <string>

// THE CLASS WE WANT TO SORT
class Duck {
public:
    std::string name;
    int weight;

    Duck(std::string n, int w) : name(n), weight(w) {}

    // --- THIS IS THE "PRIMITIVE OPERATION" ---
    // The std::sort algorithm knows how to swap items, but it doesn't 
    // know how to compare Ducks. It calls THIS function to find out.
    //
    // The Hollywood Principle:
    // std::sort says: "Don't call me to check weights. I will call YOU 
    // when I need to know which Duck is smaller."
    bool operator<(const Duck& other) const {
        // We define that "Smaller" means "Lighter"
        return this->weight < other.weight;
    }

    // Helper to print the duck
    friend std::ostream& operator<<(std::ostream& os, const Duck& d) {
        return os << d.name << " weighs " << d.weight;
    }
};

int main() {
    // 1. Create a chaotic flock of ducks
    std::vector<Duck> ducks = {
        Duck("Daffy", 8),
        Duck("Dewey", 2),
        Duck("Howard", 7),
        Duck("Louie", 2),
        Duck("Donald", 10),
        Duck("Huey", 2)
    };

    std::cout << "--- BEFORE SORTING ---" << std::endl;
    for (const auto& d : ducks) std::cout << d << std::endl;

    // --- THE TEMPLATE METHOD CALL ---
    // 1. We call std::sort (The High-Level Algorithm).
    // 2. std::sort starts running its complex Quicksort/Introsort logic.
    // 3. Every time std::sort picks up two Ducks, it calls OUR operator< 
    //    to ask: "Is Duck A smaller than Duck B?"
    std::sort(ducks.begin(), ducks.end());

    std::cout << "\n--- AFTER SORTING (By Weight) ---" << std::endl;
    for (const auto& d : ducks) std::cout << d << std::endl;

    return 0;
}
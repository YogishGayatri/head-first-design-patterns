#include <iostream>
#include "concrete_streams/StringInputStream.hpp"
#include "decorators/LowerCaseInputStream.hpp"

int main() {
    // 1. Create the raw data stream (The "Coffee")
    std::string text = "I kNoW tHe DeCoRaToR pAtTeRn!";
    InputStream* stream = new StringInputStream(text);

    // 2. Wrap it in the decorator (The "Mocha")
    stream = new LowerCaseInputStream(stream);

    // 3. Read from it
    // The main loop doesn't know it's being decorated. 
    // It just asks for a char.
    std::cout << "Original: " << text << std::endl;
    std::cout << "Decorated: ";
    
    while (!stream->eof()) {
        char c = stream->read();
        if (c != '\0') {
            std::cout << c;
        }
    }
    std::cout << std::endl;

    // Clean up
    // Note: In real C++, use smart pointers (unique_ptr) to avoid leaks!
    // We are using raw pointers here to match the Java style simplicity.
    delete stream; 

    return 0;
}
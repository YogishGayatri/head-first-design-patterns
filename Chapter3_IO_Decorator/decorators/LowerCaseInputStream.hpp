#ifndef LOWER_CASE_INPUT_STREAM_HPP
#define LOWER_CASE_INPUT_STREAM_HPP

#include "../interfaces/FilterInputStream.hpp"
#include <cctype> // for std::tolower

class LowerCaseInputStream : public FilterInputStream {
public:
    LowerCaseInputStream(InputStream* in) : FilterInputStream(in) {}

    char read() override {
        // 1. Get the character from the wrapped stream
        char c = in->read();

        // 2. Modify it (The Decoration!)
        if (c == '\0') return c;
        
        return std::tolower(c);
    }
};

#endif
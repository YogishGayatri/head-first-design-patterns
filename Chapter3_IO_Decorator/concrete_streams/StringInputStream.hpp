#ifndef STRING_INPUT_STREAM_HPP
#define STRING_INPUT_STREAM_HPP

#include "../interfaces/InputStream.hpp"
#include <string>

class StringInputStream : public InputStream {
private:
    std::string data;
    size_t position;

public:
    StringInputStream(std::string text) : data(text), position(0) {}

    char read() override {
        if (position >= data.length()) {
            return '\0'; // End of file
        }
        return data[position++];
    }

    bool eof() override {
        return position >= data.length();
    }
};

#endif
#ifndef FILTER_INPUT_STREAM_HPP
#define FILTER_INPUT_STREAM_HPP

#include "InputStream.hpp"

class FilterInputStream : public InputStream {
protected:
    InputStream* in; // The stream we are wrapping

public:
    FilterInputStream(InputStream* stream) : in(stream) {} //(InputStream* stream) variable the user gives and save it to my local InputStream* in var such that I can use it later
    
    virtual ~FilterInputStream() {
        // Optional: In a real system, you might delete 'in' here
        // depending on ownership rules. For now, we keep it simple.
    }

    char read() override {
        return in->read(); // Default: Just pass it through
    }

    bool eof() override {
        return in->eof();
    }
};

#endif
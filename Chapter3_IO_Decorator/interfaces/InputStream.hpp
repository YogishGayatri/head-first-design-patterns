#ifndef INPUT_STREAM_HPP
#define INPUT_STREAM_HPP

#include <iostream>

class InputStream {
public:
    virtual ~InputStream() = default;

    // Returns the next character, or '\0' (null) if end of stream
    virtual char read() = 0;
    
    // Check if we are at the end
    virtual bool eof() = 0;
};

#endif
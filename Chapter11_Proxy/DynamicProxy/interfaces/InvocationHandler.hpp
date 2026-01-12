#ifndef INVOCATION_HANDLER_HPP
#define INVOCATION_HANDLER_HPP
#include <string>
#include <iostream>
#include "PersonBean.hpp"

// In Java, this takes (Object proxy, Method method, Object[] args).
// In C++, we simulate this by passing the "Real Subject" and the "Method Name".
class InvocationHandler {
protected:
    PersonBean* realPerson; // The target

public:
    InvocationHandler(PersonBean* person) : realPerson(person) {}
    
    virtual ~InvocationHandler() = default;

    // This is the "invoke" method.
    // Since C++ doesn't have reflection, we simulate it with explicit functions.
    virtual void invokeSet(std::string methodName, std::string value) = 0;
    virtual void invokeSetRating(int rating) = 0;
    virtual std::string invokeGet(std::string methodName) = 0;
    virtual int invokeGetRating() = 0;
};
#endif
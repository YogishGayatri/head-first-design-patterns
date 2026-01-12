#ifndef OWNER_HANDLER_HPP
#define OWNER_HANDLER_HPP
#include "../interfaces/InvocationHandler.hpp"

class OwnerInvocationHandler : public InvocationHandler {
public:
    using InvocationHandler::InvocationHandler; // Inherit constructor

    // Getters: ALWAYS ALLOWED
    std::string invokeGet(std::string methodName) override {
        if(methodName == "getName") return realPerson->getName();
        if(methodName == "getGender") return realPerson->getGender();
        if(methodName == "getInterests") return realPerson->getInterests();
        return "";
    }

    int invokeGetRating() override {
        return realPerson->getHotOrNotRating();
    }

    // Setters: ALLOWED (It's my profile!)
    void invokeSet(std::string methodName, std::string value) override {
        if(methodName == "setName") realPerson->setName(value);
        else if(methodName == "setGender") realPerson->setGender(value);
        else if(methodName == "setInterests") realPerson->setInterests(value);
    }

    // Rating: BLOCKED (Can't rate yourself!)
    void invokeSetRating(int rating) override {
        std::cout << ">> [Owner Proxy]: ERROR! You cannot rate yourself!" << std::endl;
    }
};
#endif
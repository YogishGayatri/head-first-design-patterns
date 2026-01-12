#ifndef NON_OWNER_HANDLER_HPP
#define NON_OWNER_HANDLER_HPP
#include "../interfaces/InvocationHandler.hpp"

class NonOwnerInvocationHandler : public InvocationHandler {
public:
    using InvocationHandler::InvocationHandler;

    // Getters: ALLOWED
    std::string invokeGet(std::string methodName) override {
        if(methodName == "getName") return realPerson->getName();
        if(methodName == "getGender") return realPerson->getGender();
        if(methodName == "getInterests") return realPerson->getInterests();
        return "";
    }

    int invokeGetRating() override {
        return realPerson->getHotOrNotRating();
    }

    // Setters: BLOCKED (Can't change someone else's data!)
    void invokeSet(std::string methodName, std::string value) override {
        std::cout << ">> [Non-Owner Proxy]: ERROR! You cannot edit another person's profile!" << std::endl;
    }

    // Rating: ALLOWED
    void invokeSetRating(int rating) override {
        realPerson->setHotOrNotRating(rating);
    }
};
#endif
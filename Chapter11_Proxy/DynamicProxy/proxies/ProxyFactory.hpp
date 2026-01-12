#ifndef PROXY_FACTORY_HPP
#define PROXY_FACTORY_HPP
#include "../interfaces/PersonBean.hpp"
#include "../interfaces/InvocationHandler.hpp"
#include "../handlers/OwnerInvocationHandler.hpp"
#include "../handlers/NonOwnerInvocationHandler.hpp"
#include <memory>

// This mimics the code Java generates at runtime.
// It intercepts every call and passes it to "handler->invoke(...)".
class PersonBeanProxy : public PersonBean {
    std::shared_ptr<InvocationHandler> handler;

public:
    PersonBeanProxy(std::shared_ptr<InvocationHandler> h) : handler(h) {}

    std::string getName() override { return handler->invokeGet("getName"); }
    std::string getGender() override { return handler->invokeGet("getGender"); }
    std::string getInterests() override { return handler->invokeGet("getInterests"); }
    int getHotOrNotRating() override { return handler->invokeGetRating(); }

    void setName(std::string name) override { handler->invokeSet("setName", name); }
    void setGender(std::string gender) override { handler->invokeSet("setGender", gender); }
    void setInterests(std::string interests) override { handler->invokeSet("setInterests", interests); }
    void setHotOrNotRating(int rating) override { handler->invokeSetRating(rating); }
};

class ProxyFactory {
public:
    static PersonBean* getOwnerProxy(PersonBean* person) {
        // Create a handler with "Owner Rules"
        auto handler = std::make_shared<OwnerInvocationHandler>(person);
        // Wrap it in a Proxy
        return new PersonBeanProxy(handler);
    }

    static PersonBean* getNonOwnerProxy(PersonBean* person) {
        // Create a handler with "Non-Owner Rules"
        auto handler = std::make_shared<NonOwnerInvocationHandler>(person);
        // Wrap it in a Proxy
        return new PersonBeanProxy(handler);
    }
};
#endif
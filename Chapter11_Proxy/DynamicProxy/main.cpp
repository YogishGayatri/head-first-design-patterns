#include <iostream>
#include "impl/PersonBeanImpl.hpp"
#include "proxies/ProxyFactory.hpp"

void drive() {
    // 1. Create the Real Person
    PersonBean* joe = new PersonBeanImpl("Joe Javabean", "Male", "Coding");

    // ---------------------------------------------
    // SCENARIO 1: OWNER ACCESS (Joe logs in)
    // ---------------------------------------------
    std::cout << "--- Creating Owner Proxy for Joe ---" << std::endl;
    PersonBean* ownerProxy = ProxyFactory::getOwnerProxy(joe);
    
    std::cout << "Name is: " << ownerProxy->getName() << std::endl;
    
    std::cout << "Setting interests to 'Bowling'..." << std::endl;
    ownerProxy->setInterests("Bowling"); // Should Work
    
    std::cout << "Joe tries to rate himself..." << std::endl;
    ownerProxy->setHotOrNotRating(10);   // Should Fail!

    std::cout << "Rating is still: " << ownerProxy->getHotOrNotRating() << std::endl;


    // ---------------------------------------------
    // SCENARIO 2: NON-OWNER ACCESS (Someone else views Joe)
    // ---------------------------------------------
    std::cout << "\n--- Creating Non-Owner Proxy for Joe ---" << std::endl;
    PersonBean* nonOwnerProxy = ProxyFactory::getNonOwnerProxy(joe);
    
    std::cout << "Name is: " << nonOwnerProxy->getName() << std::endl;
    
    std::cout << "Visitor tries to change interests..." << std::endl;
    nonOwnerProxy->setInterests("Hacking"); // Should Fail!

    std::cout << "Visitor rates Joe..." << std::endl;
    nonOwnerProxy->setHotOrNotRating(3);    // Should Work

    std::cout << "Rating is now: " << nonOwnerProxy->getHotOrNotRating() << std::endl;

    // Cleanup
    delete ownerProxy;
    delete nonOwnerProxy;
    delete joe;
}

int main() {
    drive();
    return 0;
}
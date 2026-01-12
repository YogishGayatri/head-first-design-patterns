#ifndef PERSONBEAN_IMPL_HPP
#define PERSONBEAN_IMPL_HPP
#include "../interfaces/PersonBean.hpp"

class PersonBeanImpl : public PersonBean {
    std::string name;
    std::string gender;
    std::string interests;
    int ratingCount = 0;
    int ratingSum = 0;

public:
    PersonBeanImpl(std::string n, std::string g, std::string i) 
        : name(n), gender(g), interests(i) {}

    std::string getName() override { return name; }
    std::string getGender() override { return gender; }
    std::string getInterests() override { return interests; }
    
    int getHotOrNotRating() override { 
        if (ratingCount == 0) return 0;
        return (ratingSum / ratingCount); 
    }

    void setName(std::string n) override { name = n; }
    void setGender(std::string g) override { gender = g; }
    void setInterests(std::string i) override { interests = i; }
    
    void setHotOrNotRating(int rating) override { 
        ratingSum += rating; 
        ratingCount++; 
    }
};
#endif
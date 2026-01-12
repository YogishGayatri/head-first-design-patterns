#ifndef PERSONBEAN_HPP
#define PERSONBEAN_HPP
#include <string>

class PersonBean {
public:
    virtual std::string getName() = 0;
    virtual std::string getGender() = 0;
    virtual std::string getInterests() = 0;
    virtual int getHotOrNotRating() = 0;

    virtual void setName(std::string name) = 0;
    virtual void setGender(std::string gender) = 0;
    virtual void setInterests(std::string interests) = 0;
    virtual void setHotOrNotRating(int rating) = 0;

    virtual ~PersonBean() = default;
};
#endif
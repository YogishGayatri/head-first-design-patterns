#ifndef INGREDIENTS_HPP
#define INGREDIENTS_HPP
#include <iostream>
#include <string>

// Abstract Products
//This is a another way where we define interfaces and then implement them in same file.
class Dough { public: virtual std::string toString() = 0; };
class Sauce { public: virtual std::string toString() = 0; };
class Cheese { public: virtual std::string toString() = 0; };

// Concrete Products (NY Family)
class ThinCrustDough : public Dough { public: std::string toString() override { return "Thin Crust Dough"; }};
class MarinaraSauce : public Sauce { public: std::string toString() override { return "Marinara Sauce"; }};
class ReggianoCheese : public Cheese { public: std::string toString() override { return "Reggiano Cheese"; }};

// Concrete Products (Chicago Family)
class ThickCrustDough : public Dough { public: std::string toString() override { return "Thick Crust Dough"; }};
class PlumTomatoSauce : public Sauce { public: std::string toString() override { return "Plum Tomato Sauce"; }};
class MozzarellaCheese : public Cheese { public: std::string toString() override { return "Mozzarella Cheese"; }};

#endif
#include "Menu.hpp"
#include "MenuItem.hpp"
#include "Waitress.hpp"

int main() {
    // 1. Create the Menu Objects (The Nodes)
    MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast");
    MenuComponent* dinerMenu = new Menu("DINER MENU", "Lunch");
    MenuComponent* cafeMenu = new Menu("CAFE MENU", "Dinner");
    MenuComponent* dessertMenu = new Menu("DESSERT MENU", "Dessert of course!");

    // 2. Create the Top-Level Container
    MenuComponent* allMenus = new Menu("ALL MENUS", "All menus combined");

    // 3. Build the Tree Structure
    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);

    // 4. Add items to menus
    pancakeHouseMenu->add(new MenuItem(
        "K&B's Pancake Breakfast", 
        "Pancakes with scrambled eggs", 
        true, 
        2.99));

    dinerMenu->add(new MenuItem(
        "Pasta", 
        "Spaghetti with Marinara Sauce", 
        true, 
        3.89));
    
    // --- THE COMPOSITE MAGIC ---
    // We add the Dessert Menu INSIDE the Diner Menu
    dinerMenu->add(dessertMenu);

    // Add items to the sub-menu
    dessertMenu->add(new MenuItem(
        "Apple Pie", 
        "Apple pie with a flakey crust", 
        true, 
        1.59));

    // 5. Run the Client
    Waitress* waitress = new Waitress(allMenus);
    
    std::cout << "--- WAITER PRINTING MENU ---" << std::endl;
    waitress->printMenu();

    // Cleanup (Top level menu destructor deletes children recursively)
    delete waitress;
    delete allMenus;

    return 0;
}
#include "PancakeHouseMenu.hpp"
#include "DinerMenu.hpp"
#include "Waitress.hpp"

int main() {
    PancakeHouseMenu* pancakeMenu = new PancakeHouseMenu();
    DinerMenu* dinerMenu = new DinerMenu();

    Waitress* waitress = new Waitress(pancakeMenu, dinerMenu);

    waitress->printMenu();

    return 0;
}
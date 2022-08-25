#define CATCH_CONFIG_MAIN
#include <iostream>
#include "warehouse.h"
#include "catch.hpp"  // Deze heb je natuurlijk wel nodig!
TEST_CASE("Testing if pick_items function removes the correct amount of materials, and removes none when there arent anough.",
          "pick_items"){
// Hier kun je de setup doen die je nodig hebt voor je test.
    Shelf s1 = {};
    Pallet p1 = {14, "wood", 20};
    Pallet *ptr_p1 = &p1 ;
    Warehouse w1 = {};

    s1.insert_pallet(0, ptr_p1);
    w1.add_shelf(s1);

    REQUIRE(w1.pick_items("wood", 13) == 1);
    REQUIRE(w1.pick_items("wood", 15) == 0);
}

TEST_CASE("Testing if rearrange_shelf behaves normally",
          "rearrange_shelf"){

    Employee e1 = {"jan", false};
    Employee e2 = {"boris", false};

    Shelf s1 = {};
    Pallet p1 = {20, "wood", 20};
    Pallet *ptr_p1 = &p1 ;
    Pallet p2 = {15, "iron", 30};
    Pallet *ptr_p2 = &p2 ;
    Pallet p3 = {14, "cement", 40};
    Pallet *ptr_p3 = &p3 ;
    Pallet p4 = {1, "plastic", 50};
    Pallet *ptr_p4 = &p4 ;

    Warehouse w1 = {};
    w1.add_employee(e1);
    w1.add_employee(e2);

    s1.insert_pallet(0, ptr_p1);
    s1.insert_pallet(1, ptr_p2);
    s1.insert_pallet(2, ptr_p3);
    s1.insert_pallet(3, ptr_p4);

    w1.add_shelf(s1);

    REQUIRE(w1.rearrange_shelf(w1.shelves[0]) == false);

    Employee e3 = {"mike", true};
    w1.add_employee(e3);

    REQUIRE(w1.rearrange_shelf(w1.shelves[0]) == true);

    REQUIRE(w1.shelves[0].pallets[0]->item_name == "plastic");
    REQUIRE(w1.shelves[0].pallets[1]->item_name == "cement");
    REQUIRE(w1.shelves[0].pallets[2]->item_name == "iron");
    REQUIRE(w1.shelves[0].pallets[3]->item_name == "wood");
}


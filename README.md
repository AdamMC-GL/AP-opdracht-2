# AP-opdracht-2

Be sure to have the CMake file unclude all the cpp files.

## baseline warehouse.cpp

This file contains all the code used to complete the UML diagram

pick_items(): loops through the pallets until the correct one is found, removes one with the take_one() function, if the item_count is above 1.
take_one(): removes one from the pallets item_count if the variable is above 1.
get_remaining_space(): returns how much capacity is left in a pallet slot.
rearrange_shelf(): sorts a shelf based on the item count of each pallet.

## baseline main.cpp

contains 2 Catch2 unit tests

    TEST_CASE("Testing if pick_items function removes the correct amount of materials, and removes none when there arent anough.")
    TEST_CASE("Testing if rearrange_shelf behaves normally")

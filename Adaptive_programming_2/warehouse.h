#ifndef ADAPTIVE_PROGRAMMING_2_WAREHOUSE_H
#define ADAPTIVE_PROGRAMMING_2_WAREHOUSE_H
#include <iostream>
#include <vector>
using namespace std;


class Employee{
public:
    string name;
    bool busy;
    bool forklift_certificate;

    Employee();
    Employee(string name, bool forklift_certificate);

    string get_name();
    bool get_busy();
    void set_busy(bool busy);
    bool get_forklift_certificate();
    void set_forklift_certificate(bool forklift_certificate);

};


class i_container{
public:
    virtual bool is_empty() = 0;
    virtual bool is_full() = 0;

};


class Pallet: public i_container{
public:
    int item_count;
    string item_name;
    int item_capacity;

    Pallet(int item_count, string item_name, int item_capacity);

    bool operator<(Pallet* &other) const {
        return item_count < other->item_count;
    } //to make sorting easier

    string get_item_name();
    int get_item_count();
    int get_remaining_space();

    bool reallocate_emtpy_pallet(string item_name, int item_capacity);

    bool take_one();
    bool put_one();

    bool is_empty();
    bool is_full();

};

class Shelf: public i_container{
public:
    Shelf();

    vector<Pallet*> pallets;

    vector<bool> get_slot_status();
    bool remove_pallet(int slot);
    bool insert_pallet(int slot, Pallet* pallet);

    bool is_empty();
    bool is_full();


};

class Warehouse{
public:
    Warehouse();

    vector<Employee> employees;
    vector<Shelf> shelves;

    void add_employee(Employee& employee);
    void add_shelf(Shelf& shelf);
    bool rearrange_shelf(Shelf& shelf);
    bool pick_items(string item_name, int item_count);


};

#endif

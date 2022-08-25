#include <string>
#include "warehouse.h"
using namespace std;


Employee::Employee()
{

}

Employee::Employee(string name, bool forklift_certificate){

    this->name = name;
    this->forklift_certificate = forklift_certificate;
}

string Employee::get_name(){
    return name;
}
bool Employee::get_busy(){
    return busy;
}

void Employee::set_busy(bool busy){
    this->busy = busy;
}

bool Employee::get_forklift_certificate(){
    return forklift_certificate;
}

void Employee::set_forklift_certificate(bool forklift_certificate){
    this->forklift_certificate = forklift_certificate;
}

Pallet::Pallet(int item_count, string item_name, int item_capacity){

    this->item_count = item_count;
    this->item_name = item_name;
    this->item_capacity = item_capacity;

}


string Pallet::get_item_name(){
    return item_name;
}
int Pallet::get_item_count(){
    return item_count;
}
int Pallet::get_remaining_space(){
    return item_capacity - item_count;
}

bool Pallet::reallocate_emtpy_pallet(string item_name, int item_capacity){
    //idunno
    return true;
}

bool Pallet::take_one(){
    if(item_count > 0){
        item_count--;
        return true;
    }
    return false;
}
bool Pallet::put_one(){
    if(item_count < item_capacity){
        item_count++;
        return true;
    }
    return false;
}

bool Pallet::is_empty(){
    if(item_count == 0){
        return true;
    }
    return false;
}

bool Pallet::is_full(){
    if(item_count == item_capacity){
        return true;
    }
    return false;

}

Shelf::Shelf()
{

}

vector<bool> Shelf::get_slot_status(){
    vector<bool> slot_statuses;
    for(unsigned int i = 0; i < 4; i++){
        slot_statuses.push_back(pallets[i]->is_empty());
    }
    return slot_statuses;
}

bool Shelf::remove_pallet(int slot){
    pallets.insert(pallets.begin() + slot, nullptr);
}
bool Shelf::insert_pallet(int slot, Pallet* pallet){
    pallets.insert(pallets.begin() + slot, pallet);
}

bool Shelf::is_empty(){
    // if any pallet is not empty, the shelf is not empty
    for(unsigned int i = 0; i < 4; i++){
        if(!pallets[i]->is_empty()){
            return false;
        }
    }
    return true;
}

bool Shelf::is_full(){
    // if any pallet is not full, the shelf is not full
    for(unsigned int i = 0; i < 4; i++){
        if(!pallets[i]->is_full()){
            return false;
        }
    }
    return true;
}

Warehouse::Warehouse(){

}

void Warehouse::add_employee(Employee& employee){
    employees.push_back(employee);
}
void Warehouse::add_shelf(Shelf& shelf){
    shelves.push_back(shelf);
}

bool Warehouse::rearrange_shelf(Shelf& shelf){
    for(auto & employee : employees){
        if (employee.get_forklift_certificate() && !employee.get_busy()){
            employee.set_busy(true);
            std::sort(shelf.pallets.begin(), shelf.pallets.end());
            employee.set_busy(false);
            return true;
        }
    }

    return false;
}
bool Warehouse::pick_items(string item_name, int item_count){

    for(auto & shelf : shelves){
        for(auto & pallet : shelf.pallets){

            while(pallet->item_name == item_name && pallet -> item_count > 0 && item_count > 0){
                pallet -> take_one();
                item_count--;
            }
            if(item_count <= 0){
                return true;
            }
        }
    }
    return false;
}






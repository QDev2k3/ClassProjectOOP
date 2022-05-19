#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Customer;

class Tourist {
    protected:
        string name,id,address;
        char gender;
        int age;
        int placeType; string place; 
        string transport /*bus, plane, cruiseship, train*/;
        int tier; string ticketTier; /* Regular vs VIP */
        int days; string duration /*not yet used*/;
        int price;
    public:
        void setName();
        void setID();
        void setGender();
        void setAge();
        void setAddress();
        void setPlace();
        void setTier();
        void setDuration();
        virtual void setPrice() = 0;
        
};

class Children: public Tourist {
    public:
        void setPrice();
        friend class Customer;
        friend void ReadFile(ifstream &fileIn, Customer &C);

};

class Adult: public Tourist {
    public:
        void setPrice();
        friend class Customer;
        friend void ReadFile(ifstream &fileIn, Customer &C);

};

class Customer {
    private:
        string type;
        Children children;
        Adult adult;
    public:
        string getType();
        void inputCustomer();
        void print();
        friend void ReadFile(ifstream &fileIn, Customer &C);
};

void ReadFile(ifstream &fileIn, Customer &C);
void VectorReadFile(ifstream &fileIn, vector<Customer> &list);
#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Customer;

class Tourist {
    protected:
        string name,id,address;   // Tên,CMND, Địa chỉ
        char gender; // Giới tính
        int age; // Tuổi
        int placeType; string place; // placeType=1 : Nội địa, placeType=2: Nước ngoài
        string transport /*bus, plane, cruiseship, train*/;
        int tier; string ticketTier; // loại vé
        int days; // Số ngày du lịch
        int price; // Phí du lịch
    public:
        void setName();
        void setID();
        void setGender();
        void setAge();
        void setAddress();
        void setPlace();
        void setTier(); 
        void setDuration();
        virtual void setPrice() = 0;  // Hàm thuần ảo
         
};

class Children: public Tourist {
    public:
        void setPrice();  // Set phí du lịch cho trẻ em
        friend class Customer;
        friend void PrintFile(ofstream &fileOut, Customer S);
        friend void ReadFile(ifstream &fileIn, Customer &C);
        friend void AddRecord();
        friend void SearchRecord();
        friend void DeleteRecord();
};

class Adult: public Tourist {
    public:
        void setPrice(); // Set phí du lịch cho người lớn
        friend class Customer;
        friend void PrintFile(ofstream &fileOut, Customer S);
        friend void ReadFile(ifstream &fileIn, Customer &C);
        friend void AddRecord();
        friend void SearchRecord();
        friend void DeleteRecord();
};

class Customer {
    private:
        string type;
        Children children;
        Adult adult;
    public:
        string getName();
        int getFee();
        void inputCustomer();
        void print();
        void printAll();
        friend void PrintFile(ofstream &fileOut, Customer S);
        friend void ReadFile(ifstream &fileIn, Customer &C);
        friend void AddRecord();
        friend void SearchRecord();
        friend void DeleteRecord();
};

void PrintFile(ofstream &fileOut, Customer S);  // In thông tin ra file
void ReadFile(ifstream &fileIn, Customer &C);   // Đọc thông tin cho 1 khách hàng từ file
void VectorReadFile(ifstream &fileIn, vector<Customer> &list);  // Đọc thông tin cho 1 mảng khách hàng từ file
void ViewByFee();  // In ra danh sách theo tên A-Z
void ViewByName(); // In ra danh sách theo phí du lịch
void ViewRecord(); // In ra danh sách (byName / byFee)
void AddRecord(); // Thêm 1 khách hàng mới vào danh sách
void SortRecord(); // Sắp xếp lại danh sách, gọi sau khi thêm một khách hàng mới vào danh sách
void SearchRecord();  // Tìm 1 khách hàng và in ra tất cả thông tin cần thiết
void DeleteRecord(); // Xóa 1 khách hàng

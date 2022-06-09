#pragma once 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

class Customer;

class Tourist {
    protected:
        string name,code,address;   // Tên,MS, Địa chỉ
        char gender; // Giới tính
        int age; // Tuổi
        int placeType; string place; // placeType=1 : Nội địa, placeType=2: Nước ngoài ;  place: địa điểm du lịch
        string transport /*bus, plane, cruiseship, train*/;
        int tier; string ticketTier; // loại vé
        int days; // Số ngày du lịch (>5 = thêm phí)
        int price; // Phí du lịch (Tính riêng vs trẻ em / người lớn
    public:
        void setCode();
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
        friend void VectorReadFile(ifstream &fileIn, vector<Customer> &list);
        friend void AddRecord();
        friend void SearchRecord();
        friend void DeleteRecord();
};

class Adult: public Tourist {
     private:
        string id;
    public:
        void setID();
        void setPrice();
        friend class Customer;
        friend void PrintFile(ofstream &fileOut, Customer S);
        friend void ReadFile(ifstream &fileIn, Customer &C);
        friend void VectorReadFile(ifstream &fileIn, vector<Customer> &list);
        friend void AddRecord();
        friend void SearchRecord();
        friend void DeleteRecord();
};
// Khách hàng nói chung, nếu tuổi <=18 thì nhập thông tin cho children ngược lại thì nhập cho adult
// Khi thao tác với customer, căn cứ vào "type" để truy xuất vào thông tin của đúng thuộc tính, vì nếu 1 Customer là trẻ em thì thuộc tính "adult" sẽ không có gì cả.
class Customer {
    private:
        string type; // loại ( người lớn, trẻ em)
        Children children;  // thuộc tính: trẻ em, nếu tuổi <=18 thì mọi thao tác sẽ được thực hiện trên thuộc tính children
        Adult adult;  // // thuộc tính: người lớn, nếu tuổi > 18 thì mọi thao tác sẽ được thực hiện trên thuộc tính adult
    public:
        string getName();
        int getFee();
        void inputCustomer(); // Nhập thông tin khách hàng
        void print();     // In ra thông tin cơ bản
        void printAll();  // In ra thông tin chi tiết
    
        friend void PrintFile(ofstream &fileOut, Customer S);
        friend void ReadFile(ifstream &fileIn, Customer &C);
        friend void VectorReadFile(ifstream &fileIn, vector<Customer> &list);
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
void SearchRecord();  // Tìm 1 khách hàng và in ra tất cả thông tin cần thiết
void DeleteRecord(); // Xóa 1 khách hàng

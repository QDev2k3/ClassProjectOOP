#include "Header.h"

void Tourist::setName() { // Set tên
    cout << "Name: ";
    getline(cin,name);
}

void Tourist::setID() { // Set CMND
    cout << "ID: ";
    getline(cin,id);
}

void Tourist::setGender() {  // // Set giới tính
    int x = 0;
    cout << "Gender [1.Male  2.Female]: ";
    cin >> x;
    while (x < 1 || x > 2) {
        cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
        cin >> x;
    }
    cin.ignore();
    if (x == 1)
        gender = 'M';
    else if (x == 2)
        gender = 'F';
}

void Tourist::setAge() { // Set tuổi
    cout << "Age: ";
    cin >> age;
    cin.ignore();
}
//Set địa chỉ
void Tourist::setAddress(){ 
    cout << "Address: ";
    getline(cin,address);
}
// Set địa điểm du lịch (place) + phương thức di chuyển (transport)
void Tourist::setPlace(){
    int x=0, transportType;
    cout << "Choose travel region [1.Domestic   2.International]: ";
    cin >> placeType; 
    cin.ignore();
    cout << "Choose your destination: " << endl;
    if (placeType == 1) {
        cout << "  1. Nha Trang" << endl;
        cout << "  2. Sa Pa" << endl;
        cout << "  3. Ha Long" << endl;
        cout << "  4. Da Nang" << endl;
        cin >> x;
        while (x > 4 || x < 1){
            cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
            cin >> x;
        }
        switch(x) {
            case 1:
                place = "Nha Trang";
                break;
            case 2:
                place = "Sa Pa";
                break;
            case 3:
                place = "Ha Long";
                break;
            case 4:
                place = "Da Nang";
                break;
        }
        cout << "Choose your transportation [1.Bus  2.Train]: ";
        cin >> transportType; cin.ignore();
        if (transportType == 1)
            transport = "Bus";
        else 
            transport = "Train";
    }
    else {

        cout << "  1. Japan" << endl;
        cout << "  2. Singapore" << endl;
        cout << "  3. America" << endl;
        cout << "  4. Korea" << endl;
        cin >> x;
        while (x > 4 || x < 1){
            cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
            cin >> x;
        }
        switch(x) {
            case 1:
                place = "Japan";
                break;
            case 2:
                place = "Singapore";
                break;
            case 3:
                place = "America";
                break;
            case 4:
                place = "Korea";
                break;
        }
        cout << "Choose your transportation [1.Cruise ship  2.Plane]: ";
        cin >> transportType; cin.ignore();
        if (transportType == 1)
            transport = "Cruise ship";
        else 
            transport = "Plane";
    }
}
// Chọn loại vé
void Tourist::setTier() {
    cout << "Choose your Ticket [1.Regular  2.VIP]: ";
    cin >> tier;
    while (tier > 2 || tier < 1){
        cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
        cout << "Your ticket type: ";
        cin >> tier;
    }
    cin.ignore();
    switch(tier) {
        case 1:
            ticketTier = "Regular";
            break;
        default:
            ticketTier = "VIP";
            break;
    }
}
// Set thời gian du lịch
void Tourist::setDuration() {
    cout << "Choose your travel duration (days): ";
    cin >> days; cin.ignore();
}

void Children::setPrice() {  // 50% vé + không tính thêm phí cho tour dài ngày
    int baseFee=0, transportFee=0, tierFee=0;
    if (placeType == 1) { 
        baseFee = 1000000;
        if (transport.compare("Bus") == 0)
            transportFee = 25000;
        if (transport.compare("Train") == 0)
            transportFee = 30000;
    }
    else {
        baseFee = 5000000;
        if (transport.compare("Cruise ship") == 0)
            transportFee = 1500000;
        if (transport.compare("Plane") == 0)
            transportFee = 2000000;
    }
    if (tier == 2) 
        tierFee = 250000;
    price = (baseFee + transportFee + tierFee);
}

void Adult::setPrice() {   // Tính thêm phí tour dài ngày, nếu ngày > 5 thì mỗi ngày tính thêm 50k
    int baseFee=0, transportFee=0, tierFee=0, durationFee=0;
    if (placeType == 1) { 
        baseFee = 1000000;
        if (transport.compare("Bus") == 0)
            transportFee = 25000;
        if (transport.compare("Train") == 0)
            transportFee = 30000;
    }
    else {
        baseFee = 5000000;
        if (transport.compare("Cruise ship") == 0)
            transportFee = 1500000;
        if (transport.compare("Plane") == 0)
            transportFee = 2000000;
    }
    if (tier == 2) 
        tierFee = 2500000;
    if (days > 5)
        durationFee = 100000*(days - 5);
    price = baseFee + transportFee + tierFee + durationFee;
}

string Customer::getName() {
    if (type.compare("Child") == 0)
        return children.name;
    else    
        return adult.name;
}

int Customer::getFee() {
    if (type.compare("Child") == 0)
        return children.price;
    else    
        return adult.price;
}

void Customer::inputCustomer() {
    string name,id;
    int age;

    cout << "Name: ";
    getline(cin,name);

    cout << "ID: ";
    getline(cin,id);

    cout << "Age: ";
    cin >> age;
    cin.ignore();
    // Nếu tuổi lớn hơn 18 thì customer được xem là adult và mọi thao tác, thông tin đều thuộc vê thuộc tính "adult"
    if (age < 18){
        type = "Child";
        children.name = name;
        children.id = id;
        children.age = age;
        children.setGender();
        children.setAddress();
        children.setPlace();
        children.setDuration();
        children.setTier();
        children.setPrice();
    }
    else {
        type = "Adult";
        adult.name = name;
        adult.id = id;
        adult.age = age;
        adult.setGender();
        adult.setAddress();
        adult.setPlace();
        adult.setDuration();
        adult.setTier();
        adult.setPrice();
    }
}
// In ra thông tin cơ bản
void Customer::print() {
    // Nếu loại child thì in ra thông tin từ thuộc tính children
    
    // if (type.compare("Child") == 0) là để xem customer là người lớn hay trẻ em (Adult /  Child)
    
    if (type.compare("Child") == 0) {
        cout << children.name << "\t"; 
        cout << children.id << "\t"; 
        cout << children.place << "\t";
        cout << children.price << "\n"; 
    }
    // Ngược lại thì in ra thông tin từ thuộc tính adult
    else {
        cout << adult.name << "\t";
        cout << adult.id << "\t";
        cout << adult.place << "\t";
        cout << adult.price << "\n";
    }
}
// Tương tự nhưng ỉn a full thông tin
void Customer::printAll() {
    if (type.compare("Child") == 0) {
        cout << "Name: " << children.name << "\n"; 
        cout << "ID: " << children.id << "\n"; 
        cout << "Gender: " << children.gender << "\n";
        cout << "Age: " << children.age << "\n";
        cout << "Address: " << children.address << "\n";
        cout << "Place: " << children.place << "\n";
        cout << "Transport: " << children.transport << "\n";
        cout << "Ticket type: " << children.ticketTier << "\n";
        cout << "Duration of stay: " << children.days << " days\n";
        cout << "Total Fee: " << children.price << " VND\n";
    }
    else {
        cout << "Name: " << adult.name << "\n"; 
        cout << "ID: " << adult.id << "\n"; 
        cout << "Gender: " << adult.gender << "\n";
        cout << "Age: " << adult.age << "\n";
        cout << "Address: " << adult.address << "\n";
        cout << "Place: " << adult.place << "\n";
        cout << "Transport: " << adult.transport << "\n";
        cout << "Ticket type: " << adult.ticketTier << "\n";
        cout << "Duration of stay: " << adult.days << " days\n";
        cout << "Total Fee: " << adult.price << " VND\n";
    }
}

// In ra file, cơ chế tương tự
void PrintFile(ofstream &fileOut, Customer S) {
    fileOut << S.type << ",";
    if (S.type.compare("Child") == 0) {
        fileOut << S.children.name << "," << S.children.id << ",";
        fileOut << S.children.address << "," << S.children.place << "," << S.children.transport << ",";
        fileOut << S.children.ticketTier << ",";
        fileOut << S.children.age << " " << S.children.gender << " " << S.children.days << " " << S.children.price;
    }
    else {
        fileOut << S.adult.name << "," << S.adult.id << ",";
        fileOut << S.adult.address << "," << S.adult.place << "," << S.adult.transport << ",";
        fileOut << S.adult.ticketTier << ",";
        fileOut << S.adult.age << " " << S.adult.gender << " " << S.adult.days << " " << S.adult.price;
    }
}

// Đọc từ file
void ReadFile(ifstream &fileIn, Customer &C) {
    getline(fileIn,C.type,',');
    if (C.type.compare("Child") == 0) {
        getline(fileIn,C.children.name,',');
        getline(fileIn,C.children.id,',');
        getline(fileIn,C.children.address,',');
        getline(fileIn,C.children.place,',');
        getline(fileIn,C.children.transport,',');
        getline(fileIn,C.children.ticketTier,',');
        fileIn >> C.children.age;
        fileIn >> C.children.gender;
        fileIn >> C.children.days;
        fileIn >> C.children.price;
    }
    else {
        getline(fileIn,C.adult.name,',');
        getline(fileIn,C.adult.id,',');
        getline(fileIn,C.adult.address,',');
        getline(fileIn,C.adult.place,',');
        getline(fileIn,C.adult.transport,',');
        getline(fileIn,C.adult.ticketTier,',');
        fileIn >> C.adult.age;
        fileIn >> C.adult.gender;
        fileIn >> C.adult.days;
        fileIn >> C.adult.price;
    }
}

// Đọc và input vào 1 vector
void VectorReadFile(ifstream &fileIn, vector<Customer> &list) {
    Customer S;
    while (fileIn.eof() == false){
        ReadFile(fileIn,S);
        list.push_back(S);
    }
}

// Thêm 1 khách hàng vào danh sách
void AddRecord() {
    Customer S;
    cout << "\n=============== Book a Ticket =============== \n";
    // Input khách hàng
    S.inputCustomer(); 
    // In khách hàng vào file
    ofstream fileOut;
    fileOut.open("Tourist.txt", ios_base::app);
    fileOut << "\n\n";
    fileOut << S.type << ",";
    if (S.type.compare("Child") == 0) {
        fileOut << S.children.name << "," << S.children.id << ",";
        fileOut << S.children.address << "," << S.children.place << "," << S.children.transport << ",";
        fileOut << S.children.ticketTier << ",";
        fileOut << S.children.age << " " << S.children.gender << " " << S.children.days << " " << S.children.price << endl;
    }
    else {
        fileOut << S.adult.name << "," << S.adult.id << ",";
        fileOut << S.adult.address << "," << S.adult.place << "," << S.adult.transport << ",";
        fileOut << S.adult.ticketTier << ",";
        fileOut << S.adult.age << " " << S.adult.gender << " " << S.adult.days << " " << S.adult.price;
    }
    fileOut.close();
    cout << "\n========= Record created successfully! ========= \n";
    system("pause");
}

void ViewByFee() {
    int fee1,fee2;
    ifstream fileIn;
    fileIn.open("Tourist.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    for (int i=0; i<List.size(); i++) {
        for (int j=i+1; j<List.size(); j++) {
            fee1 = List[i].getFee();
            fee2 = List[j].getFee();
            if (fee1 < fee2)
                swap(List[i],List[j]);
        }
    }
    cout << "\n\n================ Tourist Record ================ \n";
    cout << "Name\t\tID\t\tPlace  \tPrice" << endl;
    cout << "------------------------------------------------ \n";
    for (int i=0; i<List.size(); i++) {
        List[i].print();
    }
    fileIn.close();
    system("pause");
}

void ViewByName() {
    ifstream fileIn;
    fileIn.open("Tourist.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    cout << "\n\n================ Tourist Record ================ \n";
    cout << "Name\t\tID\t\tPlace  \tPrice" << endl;
    cout << "------------------------------------------------ \n";
    for (int i=0; i<List.size(); i++) {
        List[i].print();
    }
    fileIn.close();
    system("pause");
}

void ViewRecord() {
    int choice=0;
    cout << "\nChoose record viewing mode \n\n";
    cout << "\t1. View by Name\n";
    cout << "\t2. View by highest fee\n\n";
    cout << "Enter Your Choice: ";
    cin >> choice; 
    while (choice!=1 && choice !=2) {
        cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice; 
    }
    cin.ignore();
    switch(choice) {
        case 1:
            ViewByName();
            break;
        case 2:
            ViewByFee();
            break;
    }
}

void SearchRecord() {
    ifstream fileIn;
    fileIn.open("Tourist.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    string ID;
    cout << "Enter record's ID: ";
    getline(cin,ID);
    int i =0;
    for (i; i<List.size(); i++) {
        if (List[i].children.id.compare(ID) == 0 || List[i].adult.id.compare(ID) == 0) {
            cout << "\n================ Tourist Record ================ \n";
            List[i].printAll();
            cout << endl;
            break;
        }
    }
    if (i == List.size())
        cout << "\n(!) TOURIST NOT FOUND (!)\n\n";
    system("pause");
}

void DeleteRecord() {
    ifstream fileIn;
    fileIn.open("Tourist.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    int index = List.size();
    fileIn.close();
    if (List.size() < 1) {
        cout << "\n(!) RECORD LIST IS EMPTY, PLEASE ADD A RECORD FIRST (!)\n";
        system("pause");
        return ;
    }
    else {
        string ID;
        cout << "Enter record's ID: ";
        getline(cin,ID);
        int i =0;
        for (i; i<List.size(); i++) {
            if (List[i].children.id.compare(ID) == 0 || List[i].adult.id.compare(ID) == 0) {
                index = i;
                break;
            }
        }
        if (i == List.size()) {
            cout << "\n(!) TOURIST NOT FOUND (!)\n\n";
            system("pause");
            return ;
        }

        ofstream fileOut;
        fileOut.open("Tourist.txt", ios_base::trunc);
        for (int i=0; i<List.size(); i++) {
            if (i != index) {
                PrintFile(fileOut,List[i]);
            }
        }
        fileOut.close();
        cout << "\n(!) TOURIST DELETED SUCCESSFULLY (!)\n\n"
        system("pause");
        return ;
    }
}


int main() {
    int choice =0;
    do {
    system("cls");
    cout<<"\n\t\t\t\t=========================";
    cout<<"\n\t\t\t\t    UIT TRAVEL PROGRAM ";
    cout<<"\n\t\t\t\t      * MAIN MENU *";
    cout<<"\n\t\t\t\t=========================";
    cout<<"\n\n\n\t\t\t1.Book A Ticket";
    cout<<"\n\t\t\t2.View Tourist Records";
    cout<<"\n\t\t\t3.Search For Record";
    cout<<"\n\t\t\t4.Delete Record";
    cout<<"\n\t\t\t5.Exit";
    cout<<"\n\n\t\t\tEnter Your Choice: ";
    cin >> choice; cin.ignore();
    switch(choice) {
        case 1:
            AddRecord();
            break;
        case 2:
            ViewRecord();
            break;
        case 3:
            SearchRecord();
            break;
        case 4:
            DeleteRecord();
            break;
        default:
            break;
    }
    } while (choice != 5);
    return 0;
}

#include "Header.h"

// Khởi tạo mã khách hàng ngẫu nhiên
void Tourist::setCode() {
    string c;
    srand(time(0));
    for (int i=0; i<6; i++) {
        int k = rand()%9;
        c = to_string(k);
        code.append(c);
    }
}

// Input tên khách hàng
void Tourist::setName() {
    cout << "Name: ";
    getline(cin,name);
}

// Input giới tính khách hàng
void Tourist::setGender() {
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

// Input tuổi khách hàng
void Tourist::setAge() {
    cout << "Age: ";
    cin >> age;
    while (age <= 0) {
        cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
        cin >> age;
    }
    cin.ignore();
}

// Input địa chỉ khách hàng
void Tourist::setAddress(){
    cout << "Address: ";
    getline(cin,address);
}

// Input địa điểm du lịch
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

// Input loại vé
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

// Input thời gian du lịch
void Tourist::setDuration() {
    cout << "Enter your travel duration (days): ";
    cin >> days; cin.ignore();
}

// Set giá vé cho trẻ em
void Children::setPrice() { 
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

// Set Max định danh công dân cho người lớn
void Adult::setID() {
    cout << "ID: ";
    getline(cin,id);
}

// Set giá vé cho người lớn
void Adult::setPrice() {  
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

// Trả về tên khách hàng
string Customer::getName() {
    if (type.compare("Child") == 0)
        return children.name;
    else    
        return adult.name;
}

// Trả về giá vé của khách hàng
int Customer::getFee() {
    if (type.compare("Child") == 0)
        return children.price;
    else    
        return adult.price;
}

// Nhập thông tin khách hàng
void Customer::inputCustomer() {
    string name,id;
    int age;

    cout << "Name: ";
    getline(cin,name);

    cout << "Age: ";
    cin >> age;
    while (age < 1) {
        cout << "(!) INVALID INPUT, PLEASE TRY AGAIN (!)" << endl;
        cout << "Age: ";
        cin >> age;
    }
    cin.ignore();
    
    if (age < 18){
        type = "Child";
        children.name = name;
        children.age = age;
        children.setCode();
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
        adult.age = age;
        adult.setCode();
        adult.setID();
        adult.setGender();
        adult.setAddress();
        adult.setPlace();
        adult.setDuration();
        adult.setTier();
        adult.setPrice();
    }
}

// In thông tin sơ lược
void Customer::print() {
    if (type.compare("Child") == 0) {
        cout << setw(20) << 
        children.name << setw(20) << 
        children.code << setw(20) << 
        children.place << setw(20) << 
        children.price << "\n"; 
    }
    else {
        cout << setw(20) << 
        adult.name << setw(20) << 
        adult.code << setw(20) << 
        adult.place << setw(20) << 
        adult.price << "\n"; 
    }
}

// In thông tin chi tiết
void Customer::printAll() {
    if (type.compare("Child") == 0) {
        cout << "Name: " << children.name << "\n"; 
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

// Xuất thông tin khách hàng vào file Data
void PrintFile(ofstream &fileOut, Customer S) {
    fileOut << S.type << " ";
    if (S.type.compare("Child") == 0) {
        fileOut << S.children.name << "," << 
        S.children.code << "," << 
        S.children.address << "," << 
        S.children.place << "," << 
        S.children.transport << "," << 
        S.children.ticketTier << ",";
        fileOut << S.children.age << " " << 
        S.children.gender << " " << 
        S.children.days << " " << 
        S.children.price;
    }
    else {
        fileOut << S.adult.name << "," << 
        S.adult.code << "," << 
        S.adult.id << "," << 
        S.adult.address << "," << 
        S.adult.place << "," << 
        S.adult.transport << "," << 
        S.adult.ticketTier << ",";
        fileOut << S.adult.age << " " << 
        S.adult.gender << " " << 
        S.adult.days << " " << 
        S.adult.price ;
    }
}

void ReadFile(ifstream &fileIn, Customer &C) {
    if (C.type.compare("Child") == 0) {
        getline(fileIn,C.children.name,',');
        getline(fileIn,C.children.code,',');
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
        getline(fileIn,C.adult.code,',');
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

// Hàm đọc file dữ liệu và lưu vào mảng vector
void VectorReadFile(ifstream &fileIn, vector<Customer> &list) {
    Customer S;
    while (fileIn >> S.type){
        ReadFile(fileIn,S);
        list.push_back(S);
    }
}

// Nhập thông tin khách hàng, sau đó xuất vào file Data
void AddRecord() {
    Customer S;
    cout << "\n=============== Book a Ticket =============== \n";
    S.inputCustomer();
    ofstream fileOut;
    fileOut.open("Data.txt", ios_base::app);
    fileOut << "\n\n";
    PrintFile(fileOut,S);
    fileOut.close();
    cout << "\n========= Record created successfully! ========= \n";
    system("pause");
}

// Xem danh sách sắp xếp theo giá vé từ cao xuông thấp
void ViewByFee() {
    int fee1,fee2;
    // đọc dữ liệu từ file vào mảng
    ifstream fileIn;
    fileIn.open("Data.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    // sắp xếp theo giá vé
    for (int i=0; i<List.size(); i++) {
        for (int j=i+1; j<List.size(); j++) {
            fee1 = List[i].getFee();
            fee2 = List[j].getFee();
            if (fee1 < fee2)
                swap(List[i],List[j]);
        }
    }
    // in ra danh sách
    cout << "\n\n================================ Tourist Record ================================ \n";
    cout << setw(20) << "Name" << setw(20) << "Code" << setw(20) << "Place" << setw(20) << "Price" << endl;
    cout << "-------------------------------------------------------------------------------- \n";
    for (int i=0; i<List.size(); i++) {
        List[i].print();
    }
    fileIn.close();
    cout << endl;
    system("pause");
}

// Hàm trả về chữ cái đầu trong tên khách hàng
char getFirstLetter(string name) {
    for (int i=0; i<name.length(); i++) {
        if (name[i] == ' ')
            return name[i+1];
    }
}
// Xem danh sách dưới dạng sắp xếp theo chữ cái đầu
void ViewByName() {
    string name1,name2;
    char c1, c2;
    // đọc dữ liệu từ file vào mảng
    ifstream fileIn;
    fileIn.open("Data.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    // sắp xếp theo tên
    for (int i=0; i<List.size(); i++) {
        for (int j=i+1; j<List.size(); j++) {
            name1 = List[i].getName(); name2 = List[j].getName();
            c1 = getFirstLetter(name1); c2 = getFirstLetter(name2);
            if (c1 < c2){
                swap(List[i],List[j]);
            }
        }
    }
    fileIn.close();
    // in ra danh sách
    cout << "\n\n================================ Tourist Record ================================ \n";
    cout << setw(20) << "Name" << setw(20) << "Code" << setw(20) << "Place" << setw(20) << "Price" << endl;
    cout << "-------------------------------------------------------------------------------- \n";
    for (int i=0; i<List.size(); i++) {
        List[i].print();
    }
    
    cout << endl;
    system("pause");
}

// Xem danh sách (chung)
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

// Tìm kiếm 1 khách hàng theo mã khách hàng và xuất ra thông tin chi tiết
void SearchRecord() {
    ifstream fileIn;
    fileIn.open("Data.txt");
    vector<Customer> List;
    VectorReadFile(fileIn,List);
    string C;
    cout << "Enter record's Code: ";
    getline(cin,C);
    int i =0;
    for (i; i<List.size(); i++) {
        if (List[i].children.code.compare(C) == 0 || List[i].adult.code.compare(C) == 0) {
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

// Xóa 1 khách hàng khỏi danh sách
void DeleteRecord() {
    ifstream fileIn;
    fileIn.open("Data.txt");
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
        string C;
        cout << "Enter record's code: ";
        getline(cin,C);
        int i =0;
        for (i; i<List.size(); i++) {
            if (List[i].children.code.compare(C) == 0 || List[i].adult.code.compare(C) == 0) {
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
        fileOut.open("Data.txt", ios_base::trunc);
        for (int i=0; i<List.size(); i++) {
            if (i != index ) {
                PrintFile(fileOut,List[i]);
                if (i != List.size()-1) {
                    fileOut << "\n\n";
                }
            }
        }
        fileOut.close();
        cout << "\n(!) TOURIST DELETED SUCCESSFULLY (!)\n\n";
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

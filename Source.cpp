#include "Header.h"

void Tourist::setName() {
    cout << "Name: ";
    getline(cin,name);
}

void Tourist::setID() {
    cout << "ID: ";
    getline(cin,id);
}

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

void Tourist::setAge() {
    cout << "Age: ";
    cin >> age;
    cin.ignore();
}

void Tourist::setAddress(){
    cout << "Address: ";
    getline(cin,address);
}

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
    
    if (age < 18){
        type = "Children";
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

void Customer::print() {
    if (type.compare("Children") == 0) {
        cout << children.name << "\t"; 
        cout << children.id << "\t"; 
        cout << type << "\t"; 
        cout << children.price << endl;
    }
    else {
        cout << adult.name << "\t";
        cout << adult.id << "\t";
        cout << type << "\t";
        cout << adult.price << endl;
    }
}

void ReadFile(ifstream &fileIn, Customer &C) {
    getline(fileIn,C.type,',');
    if (C.type.compare("Children") == 0) {
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

void VectorReadFile(ifstream &fileIn, vector<Customer> &list) {
    Customer S;
    while (fileIn.eof() == false){
        ReadFile(fileIn,S);
        list.push_back(S);
    }
}

void ViewRecord() {
    int choice;
    ifstream fileIn;
    fileIn.open("Tourist.txt");

    vector<Customer> List;
    VectorReadFile(fileIn,List);
    cout << "Name\tID\tTicket Type\tPrice" << endl;
    for (int i=0; i<List.size(); i++) {
        List[i].print();
    }
    fileIn.close();
    cout << "\n\nWhat would you like to do now?\n";
    cout<<"\n\t\t\t1.Return to menu";
    cout<<"\n\t\t\t2.Exit";
}


int main() {
    int choice =0;
    do {
    cout<<"\n\t\t\t\t=========================";
    cout<<"\n\t\t\t\t    UIT TRAVEL PROGRAM ";
    cout<<"\n\t\t\t\t      * MAIN MENU *";
    cout<<"\n\t\t\t\t=========================";
    cout<<"\n\n\n\t\t\t1.Book A Ticket";
    cout<<"\n\t\t\t2.Tourist Records";
    cout<<"\n\t\t\t3.Edit Record";
    cout<<"\n\t\t\t4.Exit";
    cout<<"\n\n\t\t\tEnter Your Choice: ";
    cin >> choice; cin.ignore();
    switch(choice) {
        case 2:
            ViewRecord();
            break;
    }
    } while (choice != 4);

    system("pause");
    return 0;
}
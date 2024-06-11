/*
    Title            : Hotel Management System
    Language        : C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Hotel {
private:
    int roomNo;
    string name;
    string address;
    string phone;
    int days;
    float fare;

    void displayHeader(const string& title) {
      
        cout << "**************************************************" << endl;
        cout << "           " << title << endl;
        cout << "**************************************************" << endl;
    }

public:
    void mainMenu();      // Display main menu
    void addBooking();    // Book a room
    void displayRecord(); // Display customer record
    void showRooms();     // Display allocated rooms
    void editRecord();    // Edit customer record
    bool isRoomAvailable(int); // Check room status
    void modifyRecord(int);    // Modify a record
    void deleteRecord(int);    // Delete a record
};

void Hotel::mainMenu() {
    int choice;
    while (true) {
        displayHeader("VSSR Group of Hotels - Main Menu");
        cout << "1. Book A Room" << endl;
        cout << "2. Customer Record" << endl;
        cout << "3. Rooms Allotted" << endl;
        cout << "4. Edit Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBooking(); break;
            case 2: displayRecord(); break;
            case 3: showRooms(); break;
            case 4: editRecord(); break;
            case 5: return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cin.ignore();
                cin.get();
        }
    }
}

void Hotel::addBooking() {
    displayHeader("Add Booking");

    ofstream fout("Record.dat", ios::app);
    int room;
    cout << "Enter Room Number: ";
    cin >> room;

    if (isRoomAvailable(room)) {
        cout << "Room is already booked." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    roomNo = room;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Days: ";
    cin >> days;
    fare = days * 900.0;

    fout.write(reinterpret_cast<char*>(this), sizeof(Hotel));
    fout.close();

    cout << "Room booked successfully!" << endl;
    cin.ignore();
    cin.get();
}

void Hotel::displayRecord() {
    displayHeader("Display Customer Record");

    ifstream fin("Record.dat", ios::in);
    int room, flag = 0;
    cout << "Enter Room Number: ";
    cin >> room;

    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        if (roomNo == room) {
            displayHeader("Customer Details");
            cout << "Room Number: " << roomNo << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            cout << "Days: " << days << endl;
            cout << "Fare: " << fare << endl;
            flag = 1;
            break;
        }
    }

    if (!flag) {
        cout << "Room not found or vacant." << endl;
    }

    fin.close();
    cin.ignore();
    cin.get();
}

void Hotel::showRooms() {
    displayHeader("Rooms Allotted");

    ifstream fin("Record.dat", ios::in);
    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        cout << "Room Number: " << roomNo << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Days: " << days << endl;
        cout << "Fare: " << fare << endl;
        cout << "**********************************" << endl;
    }

    fin.close();
    cin.ignore();
    cin.get();
}

void Hotel::editRecord() {
    displayHeader("Edit Record");

    int choice, room;
    cout << "1. Modify Customer Record" << endl;
    cout << "2. Delete Customer Record" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    cout << "Enter Room Number: ";
    cin >> room;

    switch (choice) {
        case 1: modifyRecord(room); break;
        case 2: deleteRecord(room); break;
        default: cout << "Invalid choice." << endl;
    }

    cin.ignore();
    cin.get();
}

bool Hotel::isRoomAvailable(int room) {
    ifstream fin("Record.dat", ios::in);
    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        if (roomNo == room) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

void Hotel::modifyRecord(int room) {
    displayHeader("Modify Record");

    fstream file("Record.dat", ios::in | ios::out | ios::binary);
    long pos;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        pos = file.tellg();
        if (roomNo == room) {
            cout << "Enter New Details" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Address: ";
            getline(cin, address);
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Days: ";
            cin >> days;
            fare = days * 900.0;

            file.seekg(pos - sizeof(Hotel));
            file.write(reinterpret_cast<char*>(this), sizeof(Hotel));
            cout << "Record modified successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Room not found or vacant." << endl;
    }

    file.close();
    cin.ignore();
    cin.get();
}

void Hotel::deleteRecord(int room) {
    displayHeader("Delete Record");

    ifstream fin("Record.dat", ios::in);
    ofstream fout("Temp.dat", ios::out);
    bool found = false;
    char ch;

    while (fin.read(reinterpret_cast<char*>(this), sizeof(Hotel))) {
        if (roomNo == room) {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            cout << "Days: " << days << endl;
            cout << "Fare: " << fare << endl;
            cout << "Do you want to delete this record (y/n)? ";
            cin >> ch;
            if (ch == 'n') {
                fout.write(reinterpret_cast<char*>(this), sizeof(Hotel));
            }
            found = true;
        } else {
            fout.write(reinterpret_cast<char*>(this), sizeof(Hotel));
        }
    }

    fin.close();
    fout.close();

    if (found) {
        remove("Record.dat");
        rename("Temp.dat", "Record.dat");
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Room not found or vacant." << endl;
    }

    cin.ignore();
    cin.get();
}

void displayIntro() {
    cout << "\n\n\t  C++ Project On Hotel Management System" << endl;
    cout << "\n\t\t\t MADE BY" << endl;
    cout << "\t\t\t Vattigunta Siva Sankar Reddy" << endl;
    cout << "--------------------------------------------" << endl;
}

void connectToServer() {
    cout << "\nConnecting to Server\nSyncing Data";
    for (int i = 0; i < 10; ++i) {
        cout << ".";
        for (long j = 0; j < 10000000; ++j);
    }
}

int main() {
    system("color 4");
    Hotel h;
    displayIntro();
    connectToServer();
    cout << "\nPress any key to continue....!!" << endl;
    cin.get();

   
    h.mainMenu();

    return 0;
}

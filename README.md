# Hotel Management System

## Introduction

This is a simple Hotel Management System written in C++. It allows you to perform basic operations such as booking a room, viewing customer records, displaying allotted rooms, editing records, and deleting records. This project is designed for learning purposes and demonstrates file handling, class implementation, and basic C++ programming concepts.

## Features

- Book a room
- Display customer record
- Display all allotted rooms
- Edit customer record
- Delete customer record

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- A terminal or command prompt to run the compiled program

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/hotel-management-system.git
   cd hotel-management-system
   ```

2. Compile the source code:

   ```bash
   g++ -o hotel_management_system hotel_management_system.cpp
   ```

3. Run the executable:

   ```bash
   ./hotel_management_system
   ```

## Usage

After running the executable, you will see the main menu of the Hotel Management System. You can choose from the following options:

1. **Book A Room**: Enter the customer's details and book a room.
2. **Customer Record**: Enter the room number to display the customer's record.
3. **Rooms Allotted**: Display all the rooms that have been booked along with customer details.
4. **Edit Record**: Modify or delete an existing customer record.
5. **Exit**: Exit the application.

## Code Overview

The main components of the program are:

- **Hotel Class**: Contains methods to handle all hotel management operations such as booking, displaying records, editing, and deleting records.
- **Main Menu**: Provides the user with options to choose from and calls the appropriate methods from the `Hotel` class.
- **File Handling**: Uses file streams to read and write customer records to a file named `Record.dat`.

## Project Structure

```
hotel-management-system/
├── README.md
└── HotelManagementSystem.cpp
```

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes. For major changes, please open an issue first to discuss what you would like to change.

##Author 

Vattigunta Siva Sankar Reddy



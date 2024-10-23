#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a user
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Creating a file for the user
    ofstream userFile(username + ".txt");
    if (userFile.is_open()) {
        userFile << username << endl;
        userFile << password << endl;
        userFile.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error creating user file." << endl;
    }
}

// Function to login a user
bool loginUser() {
    string username, password, storedUsername, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open the user's file
    ifstream userFile(username + ".txt");
    if (userFile.is_open()) {
        getline(userFile, storedUsername);
        getline(userFile, storedPassword);
        userFile.close();

        if (storedUsername == username && storedPassword == password) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else {
        cout << "User not found." << endl;
    }
    return false;
}

int main() {
    int choice;
    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    // User is logged in, you can add more functionality here
                    cout << "Welcome to the system!" << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}


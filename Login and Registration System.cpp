#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter username: ";
    cin >> username;

    // Check if the user already exists
    ifstream userFile(username + ".txt");
    if (userFile) {
        cout << "User already exists. Please choose a different username.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream outFile(username + ".txt");
    outFile << password;
    outFile.close();

    cout << "User registered successfully.\n";
}

// Function to authenticate a user
void authenticateUser() {
    string username, password, inputPassword;

    cout << "Enter username: ";
    cin >> username;

    ifstream userFile(username + ".txt");
    if (!userFile) {
        cout << "User does not exist.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> inputPassword;

    getline(userFile, password);

    if (password == inputPassword) {
        cout << "Login successful.\n";
    } else {
        cout << "Incorrect password.\n";
    }

    userFile.close();
}

int main() {
    int choice;

    do {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                authenticateUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

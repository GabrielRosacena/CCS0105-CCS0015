#include <iostream>
#include <string>
#include <map>

using namespace std;

// Structure to hold user information including notes
struct User {
    string username;
    string password;
    string notes;
};

// Function prototypes
void login(map<string, User>& users, User& activeUser);
void createAccount(map<string, User>& users);
void viewNotes(const User& activeUser);
void editNotes(User& activeUser);

int main() {
    map<string, User> users; // Map to store usernames and user data

    User activeUser; // Variable to store data for the active user

    int choice;
    do {
        cout << "1. Login\n";
        cout << "2. Create Account\n";
        cout << "3. View Notes\n";
        cout << "4. Edit Notes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                login(users, activeUser);
                break;
            case 2:
                createAccount(users);
                break;
            case 3:
                if (activeUser.username.empty()) {
                    cout << "No user logged in. Please log in first.\n";
                } else {
                    viewNotes(activeUser);
                }
                break;
            case 4:
                if (activeUser.username.empty()) {
                    cout << "No user logged in. Please log in first.\n";
                } else {
                    editNotes(activeUser);
                }
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 5);

    return 0;
}

void login(map<string, User>& users, User& activeUser) {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    auto it = users.find(username);
    if (it != users.end() && it->second.password == password) {
        cout << "Login successful.\n";
        activeUser = it->second; // Set the active user
    } else {
        cout << "Invalid username or password.\n";
    }
}

void createAccount(map<string, User>& users) {
    User newUser;
    cout << "Enter new username: ";
    cin >> newUser.username;
    cout << "Enter new password: ";
    cin >> newUser.password;

    // Check if the username already exists
    if (users.find(newUser.username) == users.end()) {
        users[newUser.username] = newUser;
        cout << "Account created successfully.\n";
    } else {
        cout << "Username already exists. Please choose a different username.\n";
    }
}

void viewNotes(const User& activeUser) {
    cout << "Your notes:\n";
    cout << activeUser.notes << endl;
}

void editNotes(User& activeUser) {
    cout << "Enter your new notes: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, activeUser.notes);
    cout << "Notes updated successfully.\n";
}

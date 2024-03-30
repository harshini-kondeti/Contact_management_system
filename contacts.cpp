#include <iostream>
#include <cstring>
using namespace std;

#define CONTACTS 30

struct Contact {
    char name[50], email[50], phone[50];
};

struct Contact contacts[CONTACTS];
int count = 0;

// Color codes
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

void menu() {
    system("cls"); // For clearing screen
    cout << YELLOW << "1. Add Contact\n";
    cout << YELLOW << "2. View Contacts\n";
    cout << YELLOW << "3. Delete Contact\n";
    cout << YELLOW << "4. Edit Contact\n";
    cout << YELLOW << "5. Find Contact\n";
    cout << YELLOW << "6. Exit\n";
    cout << "\n" << RESET;
    cout << YELLOW << "Enter your choice: " << RESET;
}

void add() {
    if (count >= CONTACTS) {
        cout << RED << "Contact list is full\n" << RESET;
        return;
    }
    struct Contact c;
    cout << "Enter name: ";
    cin >> c.name;
    cout << "Enter phone number: ";
    cin >> c.phone;
    if (strlen(c.phone) != 10) {
        cout << RED << "Entered number is invalid. Re-enter the phone number: " << RESET;
        cin >> c.phone;
    }
    cout << "Enter email: ";
    cin >> c.email;
    if (strlen(c.phone) == 10) {
        contacts[count++] = c;
    }
}

void view() {
    system("cls");
    if (count != 0) {
        for (int i = 0; i < count; i++) {
            cout << YELLOW << "Name: " << RESET << contacts[i].name << "\n";
            cout << YELLOW << "Email: " << RESET << contacts[i].email << "\n";
            cout << YELLOW << "Phone: " << RESET << contacts[i].phone << "\n";
            cout << "\n";
        }
    } else {
        cout << YELLOW << "No contacts are there\n" << RESET;
    }
    cout << "\n";
    system("pause"); // Wait for user to press a key
}

void del() {
    system("cls");
    char name[50];
    cout << "Enter name to delete: ";
    cin >> name;
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            found = 1;
            cout << GREEN << "Contact deleted successfully\n" << RESET;
            break;
        }
    }
    if (!found) {
        cout << RED << "Contact not found\n" << RESET;
    }
    cout << "\n";
    system("pause");
}

void edit() {
    system("cls");
    char name[50];
    cout << "Enter name to edit: ";
    cin >> name;
    int i, found = 0;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            cout << "Enter new name: ";
            cin >> contacts[i].name;
            cout << "Enter new phone number: ";
            cin >> contacts[i].phone;
            if (strlen(contacts[i].phone) != 10) {
                cout << RED << "Entered number is invalid. Re-enter the phone number: " << RESET;
                cin >> contacts[i].phone;
            }
            cout << "Enter new email: ";
            cin >> contacts[i].email;
            found = 1;
            cout << GREEN << "Contact edited successfully\n" << RESET;
            break;
        }
    }
    if (!found) {
        cout << RED << "Contact not found\n" << RESET;
    }
    cout << "\n";
    system("pause");
}

void find() {
    system("cls");
    cout << "Enter 1 to find by name or 2 to find by number: ";
    int ch;
    cin >> ch;

    char name[50], number[15];
    if (ch == 1) {
        cout << "Enter name: ";
        cin >> name;
    } else if (ch == 2) {
        cout << "Enter number: ";
        cin >> number;
    } else {
        cout << RED << "Invalid choice\n" << RESET;
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0 || std::strcmp(contacts[i].phone, number) == 0) {
            cout << GREEN << "Contact was found\n";
            cout << "Name: " << contacts[i].name << "\n";
            cout << "Email: " << contacts[i].email << "\n";
            cout << "Phone: " << contacts[i].phone << "\n" << RESET;
            found = 1;
            break;
        }
    }
    if (!found) {
        cout << RED << "Contact not found\n" << RESET;
    }
    cout << "\n";
    system("pause");
}

int main() {
    int choice;
    do {
        menu();
        cin >> choice;
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                view();
                break;
            case 3:
                del();
                break;
            case 4:
                edit();
                break;
            case 5:
                find();
                break;
            case 6:
                cout << YELLOW << "Exiting...\n" << RESET;
                break;
            default:
                cout << RED << "Invalid choice\n" << RESET;
                cout << "\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

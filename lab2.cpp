#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
    string role;
    User* next;

    User(const string& u, const string& p, const string& r = "viewer") {
        username = u;
        password = p;
        role = r;
        next = nullptr;
    }
};
    bool insertUser(User*& head, const string& username, const string& password, const string& role = "viewer") {
        User* newUser = new User(username, password, role);
        if (head == nullptr) {
            head = newUser;
            return true;
        }
        User* current = head;
        while (current->next) {
            if (current->username == username) return false; 
            current = current->next;
        }
        current->next = newUser;
        return true;
    }

int main() {
    User* head = nullptr;
    insertUser(head, "Jeimy", "pass123" , "admin");
    insertUser(head, "Jane", "cats4ever", "editor");
    insertUser(head, "Johnny", "joh12");
    return 0;
}

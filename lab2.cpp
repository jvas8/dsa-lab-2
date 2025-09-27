#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User {
    string username;
    string password;
    vector<string> permissions;
    User* next;

    User(const string& u, const string& p, const vector<string>& perms = {"view"}) {
        username = u;
        password = p;
        permissions = perms;
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
User* findUser(User* head, const string& username) {
    User* current = head;
    while(current != nullptr){
        if(current->username == username){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
bool authorize(User* head, const string& username, const string& action) {
    User* user = findUser(head, username);
    if (user == nullptr){
        return false;
    }
    if (user->role == "admin") {
        return true;
    } else if (user->role == "editor") {
        return (action == "view" || action == "edit" || action == "create");
    } else if (user->role == "viewer") {
        return (action == "view");
    }
    return false;
}


int main() {
    User* head = nullptr;
    insertUser(head, "Jeimy", "pass123" , "admin");
    insertUser(head, "Jane", "cats4ever", "editor");
    insertUser(head, "Johnny", "joh12");


    cout << "Can Jane create? " << boolalpha << authorize(head, "Jane", "create") << endl;
    cout << "Can Johnny create? " << authorize(head, "Johnny", "create") << endl;

    return 0;
}

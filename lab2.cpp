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

bool insertUser(User*& head, const string& username, const string& password, const vector<string>& perms = {"view"}) {
     if (findUser(head, username) != nullptr) {
        return false; 
    }
    User* newUser = new User(username, password, perms);
    if (head == nullptr) {
        head = newUser;
        return true;
    }
    User* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newUser;
    return true;
}

bool authorize(User* head, const string& username, const string& action) {
    User* user = findUser(head, username);
    if(user == nullptr){
        return false;
    }
    if(user->permissions.empty()){
        return false;
    }
    for(size_t i = 0; i <user->permissions.size(); i++){
        if(user->permissions[i] == action){
            return true;
        }
    }
    return false;
}


int main() {
    User* head = nullptr;
    insertUser(head, "Jeimy", "pass123" , {"view", "edit", "create"});
    insertUser(head, "Jane", "cats4ever");
    insertUser(head, "Johnny", "joh12", {});

    //authorize test
    cout << "Can Jeimy create? " << boolalpha << authorize(head, "Jeimy", "create") << endl;
    cout << "Can Johnny view? " << authorize(head, "Johnny", "view") << endl;

    return 0;
}

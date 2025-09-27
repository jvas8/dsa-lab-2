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

int main() {
    return 0;
}

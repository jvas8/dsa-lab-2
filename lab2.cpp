#include <iostream>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
    User* next;

    User(const string& u, const string& p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

int main() {
    return 0;
}

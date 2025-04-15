
#include <iostream>
#include <string>
#include <stdexcept>
#include "logger.cpp"

using namespace std;

void loginUser(Logger& logger, const string& username) {
    logger.log(DEBUG, "loginUser called with username: " + username);
    if (username.empty()) {
        logger.log(ERROR, "Username cannot be empty.");
        return;
    }
    logger.log(INFO, "User " + username + " successfully logged in.");
}

int calculateSum(Logger& logger, int a, int b) {
    logger.log(DEBUG, "calculateSum called with a=" + to_string(a) + ", b=" + to_string(b));
    int sum = a + b;
    logger.log(INFO, "Sum calculated: " + to_string(sum));
    return sum;
}

int main() {
    try {
        Logger logger("log.txt");
        logger.log(INFO, "Application started.");

        loginUser(logger, "admin");
        calculateSum(logger, 10, 20);
        loginUser(logger, ""); 

        logger.log(INFO, "Application ended normally.");
    } catch (const exception& ex) {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}


#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

enum LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

class Logger {
private:
    ofstream logFile;

    string levelToString(LogLevel level) {
        switch (level) {
            case DEBUG: return "DEBUG";
            case INFO: return "INFO";
            case WARN: return "WARN";
            case ERROR: return "ERROR";
            case FATAL: return "FATAL";
            default: return "UNKNOWN";
        }
    }

public:
    Logger(const string& filename) {
        logFile.open(filename, ios::app);
        if (!logFile.is_open()) {
            throw runtime_error("Failed to open file!");
        }
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(LogLevel level, const string& message) {
        if (message.empty()) {
            throw invalid_argument("Log message cannot be empty!");
        }

        string fullMessage = "[" + levelToString(level) + "] " + message;
        logFile << fullMessage << endl;
        cout << "Log written: " << fullMessage << endl;
    }
};

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <io.h>
using namespace std;

string getCurrentDateTime() {
    time_t now = time(0);
    struct tm *timeinfo;
    char buffer[80];

    timeinfo = localtime(&now);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %I:%M:%S %p", timeinfo);

    return buffer;
}

int main() {
    if (system("git add .") != 0) {
        perror("Error running 'git add'");
        return 1;
    }

    string commitMessage = "Auto commit on " + getCurrentDateTime();

    string gitCommitCommand = "git commit -m \"" + commitMessage + "\"";
    if (system(gitCommitCommand.c_str()) != 0) {
        perror("Error running 'git commit'");
        return 1;
    }

    if (system("git push") != 0) {
        perror("Error running 'git push'");
        return 1;
    }

    cout << "Git add, commit, and push commands executed successfully." << endl;

    return 0;
}

//
// Created by User on 2023-05-04.
//

#include <string>
#include <utility>
#include <ctime>

#ifndef DSNC_TEAMPROJ_FILE_H
#define DSNC_TEAMPROJ_FILE_H

using namespace std;

class file{
    string name;
    file* prev;
    struct tm t;
    string extension;

public:

    file(string name, file* prev, string extension) {
        this->name = move(name);
        this->prev = prev;
        time_t tm = time(nullptr);
        this->t = *localtime(&tm);
        this->extension = move(extension);
    }
    string getDisplayName() {
        return this->name + "." + this->extension;
    }

    string getLocation() {
        string r = this->getDisplayName();
        file* cur = prev;
        while(cur != nullptr) {
            r = cur->getDisplayName().append("\\" + r);
            cur = cur->prev;
        }
        return r;
    }

    struct tm getTime() {
        return this->t;
    }

    string getName() {
        return this->name;
    }
};


#endif //DSNC_TEAMPROJ_FILE_H

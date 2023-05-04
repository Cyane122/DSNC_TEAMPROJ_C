//
// Created by User on 2023-05-04.
//

#ifndef DSNC_TEAMPROJ_FOLDER_H
#define DSNC_TEAMPROJ_FOLDER_H

#include "file.h"
#include <vector>
#include <algorithm>

#define NAME 1
#define TIME 2

#define ASCENDING 1
#define DESCENDING 2

bool ampNameType1(file* a, file* b) {
    return a->getName() < b->getName();
}

bool ampNameType2(file* a, file* b) {
    return a->getName() > b->getName();
}

class folder: public file {
    vector<file*> contents;

public:
    folder(string name, folder* prev): file(name, prev, "..") {
        this->contents = vector<file*>();
    }

    bool contains(file* item) {
        for(auto i: contents) {
            if(i == item) return true;
        }
        return false;
    }

    void addFile(file* item) {
        contents.push_back(item);
    }

    void sortBy(int T, int K) {
        switch(T) {
            case NAME: {
                if(K == ASCENDING) sort(contents.begin(), contents.end(), ampNameType1);
                else if (K == DESCENDING) sort(contents.begin(), contents.end(), ampNameType2);
                break;
            }
            case TIME: {
                break;
            }
            default: {
                break;
            }
        }
    }
};


#endif //DSNC_TEAMPROJ_FOLDER_H

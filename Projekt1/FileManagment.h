#ifndef FILEMANAGMENT_H
#define FILEMANAGMENT_H

#include <iostream>

class FileManagment {
    public:
    static int getArraySize(std::string filename);
    static int* getArray(std::string filename);
};

#endif
#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include <string>
#include <fstream>
#include <mutex>
#include <iostream>

class FileManager {   
 private:
    std::ofstream file;
    //std::mutex mtx;
    std::mutex mtx;

 public:
    FileManager(std::string& file_name) {
        file.open(file_name.c_str(), std::ios::app);
    }

    FileManager(const char* file_name) {
        file.open(file_name, std::ios::app);
    }

    void write_file(std::string& data) {
        //mtx.lock();
        file << data << std::endl;
        //mtx.unlock();
    }

    void write_file(const char* data) {
        //mtx.lock();
        file << std::string(data) << std::endl;
        //mtx.unlock();
    }

    void close_file() {
        file.close();
    }


};


#endif
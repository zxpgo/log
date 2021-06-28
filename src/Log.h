#ifndef _LOG_H_
#define _LOG_H_

#include <mutex>
#include "FileManager.h"

class Log {
 private: 
    FileManager* file_manager;
    static std::mutex mtx;
    static Log* log;
    Log(const char* log_file) {
         file_manager = new FileManager(log_file);
    }

    void write_log(const char* data, const char* log_type);
 public:
    static Log* get_log_handle(const char* log_file);
    void debug(const char* data, ...);
    void error(const char* data, ...);
    void info(const char* data, ...);

    ~Log();
};

#endif
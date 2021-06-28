#include "Log.h"
#include <ctime>
#include <algorithm>    // std::remove
#include <stdarg.h>

Log* Log::log = NULL;
std::mutex Log::mtx;

std::string get_local_time() {
    time_t now = time(0);
   
    // 把 now 转换为字符串形式
    std::string dt = std::string(ctime(&now));
   // remove(dt.begin(),dt.end(),"\n");

    return dt;
}

Log* Log::get_log_handle(const char* log_file) {
    if (!log) {
        mtx.lock();
        if (!log) {
            log = new Log(log_file);
        }
        mtx.unlock();
    }
    return log;
}

void Log::debug(const char* data, ...) {
    char* str = (char*)malloc(1000);
    va_list paramList;
    va_start(paramList, data);
    vsnprintf(str, 1000, data, paramList);
    va_end(paramList);
    write_log(str, "Debug");
    delete str;
}

void Log::error(const char* data, ...) {
    char* str = (char*)malloc(1000);
    va_list paramList;
    va_start(paramList, data);
    vsnprintf(str, 1000, data, paramList);
    va_end(paramList);
    write_log(str, "Error");
    delete str;
}

void Log::info(const char* data, ...) {
    char* str = (char*)malloc(1000);
    va_list paramList;
    va_start(paramList, data);
    vsnprintf(str, 1000, data, paramList);
    va_end(paramList);
    write_log(str, "Info");
    delete str;
}

void Log::write_log(const char* data, const char* log_type) {
    std::string write_data = "[" + get_local_time() + "] [" + log_type + "]: " + data;
    write_data.erase(std::remove(write_data.begin(), write_data.end(), '\n'), write_data.end());
    file_manager->write_file(write_data);
}

Log::~Log() {
    if (log) {
        delete log;
        log = NULL;
    }
}
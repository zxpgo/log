#include "../include/LogInter.h"
#include <string>
#include <malloc.h>
#include "stdarg.h"


void format_str(const char *fmt, ...)
{
    char* s = (char*)malloc(1000);

    va_list paramList;
    va_start(paramList, fmt);
    vsnprintf(s, 1000, fmt, paramList);
    va_end(paramList);
    std::cout <<  s << std::endl;
}

int main() {
    // std::string file_name = "log.txt";
    // FileManager * file_manager = new FileManager("log.txt");
    // std::string data = "this is a log";
    // file_manager->write_file("this is a log 2");
    // file_manager->close_file();
    // delete file_manager;
 

    Log* log = Log::get_log_handle("log.txt");
    log->debug("this is a debug %d: %s", 110, "good");
    log->error("this is a error %s: %s", "error", "failed");
    log->info("this is a info %d: %d", 1, 2);
    return 0;
}
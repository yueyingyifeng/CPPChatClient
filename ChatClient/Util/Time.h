#include <ctime>

inline const char* generateTime(){
    time_t now = time(0);
    tm tstruct;
    char *datetime = new char[20];
    localtime_s(&tstruct,&now);
    strftime(datetime, 20, "%Y/%m/%d %X", &tstruct);
    return datetime;
}
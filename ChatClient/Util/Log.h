/*
* 			Author : yyyf
* 		CreateDate : 2023/12/24 12:15:37
* 	   Description ：
*/
#ifndef H_Log
#define H_Log

#include <iostream>
#include <string>

inline void log(std::string msg, bool lf = true) {
	std::cout << msg << (lf ? "\n" : "");
}

inline void elog(std::string msg = "") {
	char err_msg[120];
	strerror_s(err_msg, sizeof(err_msg), errno);
	std::cout << msg << " " << err_msg << std::endl;

}

inline void pause() {
	std::string buffer;
	std::cin >> buffer;
	std::cin.ignore();
}


#endif
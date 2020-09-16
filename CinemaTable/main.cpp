#include <iostream>
#include "help_header.h"
#include "page_builder.h"
#include "console_manager.h"
#include <fstream>
#define CONSOLE_INPUT 1
//spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
//spdlog::debug("This message should be displayed..");
//spdlog::set_level(spdlog::level::off); // Set global log level to debug
//spdlog::debug("This message should be displayed..");
//spdlog::info("Welcome to spdlog!");

int main(void) {

#if CONSOLE_INPUT == 0
    std::string name_of_programm = "New Cinema";
    std::string channel = "MaxChannel";
    std::string day_of_programm = "Tuesday";
    std::string time_of_programm = "14:00";
    std::string name_of_cahnnel = "MyTV";
#else
    std::string name_of_programm;
    std::string channel;
    std::string day_of_programm;
    std::string time_of_programm;
    std::string name_of_cahnnel;
    string_initializer(name_of_programm,
        channel,
        day_of_programm,
        time_of_programm,
        name_of_cahnnel);
#endif
    page_builder new_page(name_of_programm, 
                          channel, day_of_programm,
                          time_of_programm,
                          name_of_cahnnel);

    std::cout << "time of programm is " << new_page.get_time_of_programm()  << std::endl;







    return 0;
}
#include <iostream>
#include "help_header.h"
#include "page_builder.h"
#include "page_editor.h"
#include "console_manager.h"
#include <sstream>
#include <string>
#define CONSOLE_INPUT 0
//spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
//spdlog::debug("This message should be displayed..");
//spdlog::set_level(spdlog::level::off); // Set global log level to debug
//spdlog::debug("This message should be displayed..");
//spdlog::info("Welcome to spdlog!");

using namespace std;

std::vector<one_programm> struct_info_default  = { {"00:00","01:00","detective","Mike Stonson"},
                                                    {"01:00","02:00","comedy","Bruce Bonson Time"},
                                                    {"02:00","03:00","comedy","Bruce Bonson Time"},
                                                    {"03:00","03:15","info","Reklama"},
                                                    {"03:15","04:00","history","The Supreme Rome"},
                                                    {"04:00","04:15","info","Reklama"},
                                                    {"04:15","05:00","history","The Supreme Rome"},
                                                    {"05:00","05:15","info","Reklama"},
                                                    {"05:15","06:00","Action","Super Hero Style"},
                                                    {"06:00","06:15","info","Reklama"},
                                                    {"06:15","07:00","history","Kaligula"},
                                                    {"07:00","08:00","history","Kaligula"},
                                                    {"08:00","08:15","Action","The Venture Bros"},
                                                    {"08:15","09:00","Melodrama","Super Love In New York"},
                                                    {"09:00","09:15","info","Reklama"},
                                                    {"09:15","10:00","Comedy","Very Interesting guy"},
                                                    {"10:00","10:15","info","Reklama"},
                                                    {"10:15","11:00","Action","Super Boom Story"},
                                                    {"11:00","11:15","info","Reklama"},
                                                    {"11:15","21:00","history","The Supreme Rome"},
                                                    {"21:00","21:15","info","Reklama"},
                                                    {"21:15","22:00","Comedy","Very Interesting gay"},
                                                    {"23:00","23:15","info","Reklama"},
                                                    {"23:15","00:00","history","The Supreme Rome"} };



std::string title_of_programm;
std::string channel;
std::string day_of_programm;
std::string title_time_of_programm;
std::string name_of_cahnnel;

std::string start_time;
std::string end_time;
std::string genre;
std::string name_of_programm;


int main(void) {

    std::string html_file = "simple_channel.html";

    //default parametres
    std::string title_of_programm = "Name Of Cinema";
    std::string title_time_of_programm = "Time";
    std::string channel = "MaxChannel";

#if CONSOLE_INPUT == 1
    std::cout << "Input please info about programm page" << std::endl;
    std::cout << "Input Name of Channel" << std::endl;
    getline(std::cin, name_of_cahnnel);
    std::cout << "Input Day of Programm" << std::endl;
    getline(std::cin, day_of_programm);
    std::cout << "Input Please Name of HTML file" << std::endl;
    getline(std::cin, html_file);
#endif

#if CONSOLE_INPUT == 0
    title_of_programm = "Name Of Cinema";
    channel = "MaxChannel";
    day_of_programm = "Tuesday";
    title_time_of_programm = "Time";
    name_of_cahnnel = "MyTV";
#endif

    page_builder new_page(title_of_programm, 
                          channel, day_of_programm,
                          title_time_of_programm,
                          name_of_cahnnel);

    page_creator("simple_channel.html",new_page);

    page_editor new_edit_page("simple_channel.html");
#if CONSOLE_INPUT == 1
    std::cout << "======================================= " << std::endl;
    std::cout << "Input Please information Programms in special format " << std::endl;
    std::cout << "start time =  " << std::endl;
    std::cout << "end time  = " << std::endl;
    std::cout << "genre =  " << std::endl;
    std::cout << "name of programm  = " << std::endl;
    std::cout << "======================================= " << std::endl;


    std::string start_time;
    std::string end_time;
    std::string genre;
    std::string name_of_programm;

    for (int i = 0; i < 24; i++) {

        std::cout << "Input Please information of = " << " " << i << " " << "Programm" << std::endl;
        std::cout << "start time =  " << std::endl;
        getline(std::cin, start_time);
        std::cout << "end time  = " << std::endl;
        getline(std::cin, end_time);
        std::cout << "genre =  " << std::endl;
        getline(std::cin, genre);
        std::cout << "name of programm  = " << std::endl;
        getline(std::cin, name_of_programm);
        int cond = new_edit_page.page_navigator_add_one_programm(start_time, end_time, genre, name_of_programm);
        std::cout << "======================================= " << std::endl;
        if (cond == -1) {
            i = i - 1;
            if (i < 0) { i = 0; }
        }
    }
#endif
 

#if CONSOLE_INPUT == 0

    for (int i = 0; i < 24; i++) {

        std::string start_time = struct_info_default[i].start_time;
        std::string end_time = struct_info_default[i].end_time;
        std::string genre = struct_info_default[i].genre;
        std::string name_of_programm = struct_info_default[i].name_of_programm;
        int cond = new_edit_page.page_navigator_add_one_programm(start_time, end_time, genre, name_of_programm);
        
   }

#endif

    //write information to HTML file
    page_updater_func("simple_channel.html", new_edit_page, new_page);

    return 0;
}
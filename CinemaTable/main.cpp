#include <iostream>
#include "help_header.h"
#include "page_builder.h"
#include "page_editor.h"
#include "console_manager.h"
#define CONSOLE_INPUT 1
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


int main(void) {

#if CONSOLE_INPUT == 1
    std::string title_of_programm = "Name Of Cinema";
    std::string channel = "MaxChannel";
    std::string day_of_programm = "Tuesday";
    std::string title_time_of_programm = "Time";
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
    page_builder new_page(title_of_programm, 
                          channel, day_of_programm,
                          title_time_of_programm,
                          name_of_cahnnel);

    page_creator("simple_channel.html",new_page);

    page_editor new_edit_page("simple_channel.html","16:00","17:00","Comedy","How To be a Storng Man");
    
    new_edit_page.page_navigator_default_initializer();

    std::vector<one_programm> tmp_struct;

    tmp_struct.push_back(one_programm());

    for (int i = 0; i < 22; i++) {
    
        tmp_struct.at(0) = struct_info_default.at(i);

   /*     tmp_struct.at(N).end_time = end_tme;
        tmp_struct.at(N).start_time = start_time;
        tmp_struct.at(N).genre = genre;
        tmp_struct.at(N).name_of_programm = name_of_cinema;*/

        new_edit_page.page_navigator = new_edit_page.page_navigator_add_one_programm(tmp_struct.at(0).start_time,
            tmp_struct.at(0).end_time,
            tmp_struct.at(0).genre,
            tmp_struct.at(0).name_of_programm,
            new_edit_page.page_navigator);
    
    
    }

    std::vector<one_programm> struct_info = new_edit_page.get_one_programm_data(2, new_edit_page.page_navigator);

    page_updater_func("simple_channel.html", new_edit_page, new_page);

    return 0;
}
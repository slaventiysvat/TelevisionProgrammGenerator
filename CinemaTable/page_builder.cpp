#include "page_builder.h"
#include "help_header.h"
#include <fstream>
void page_creator(page_builder::TV_program_init page_init,std::string name_of_html_page) {







}

std::string get_name_of_programm(page_builder::TV_program_init page_init) {

    return page_init.name_of_programm;
}
std::string get_channel(page_builder::TV_program_init page_init) {

    return page_init.channel;
}
std::string get_day_of_programm(page_builder::TV_program_init page_init) {

    return page_init.day_of_programm;
}
std::string get_time_of_programm(page_builder::TV_program_init page_init) {

    return page_init.time_of_programm;
}
std::string get_name_of_cahnnel(page_builder::TV_program_init page_init) {

    return page_init.name_of_cahnnel;
}

page_builder::TV_program_init set_name_of_programm(page_builder::TV_program_init page_init, 
    std::string set_name_of_programm) {

    page_init.name_of_programm = set_name_of_programm;
    return page_init;
}
page_builder::TV_program_init set_channel(page_builder::TV_program_init page_init, 
    std::string set_channel) {

    page_init.channel = set_channel;
    return page_init;
}
page_builder::TV_program_init set_day_of_programm(page_builder::TV_program_init page_init,
    std::string set_day_of_programm) {


    page_init.day_of_programm = set_day_of_programm;
    return page_init;
}
page_builder::TV_program_init set_time_of_programm(page_builder::TV_program_init page_init,
    std::string set_time_of_programm) {

    page_init.time_of_programm = set_time_of_programm;
    return page_init;
}
page_builder::TV_program_init set_name_of_cahnnel(page_builder::TV_program_init page_init,
    std::string set_name_of_cahnnel) {

    page_init.name_of_cahnnel = set_name_of_cahnnel;
    return page_init;
}

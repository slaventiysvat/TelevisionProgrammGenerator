#include "page_builder.h"
#include "help_header.h"
#include <oistream>
#include <fstream>
void page_creator(std::string name_of_html_page) {

    ofstream fout("cppstudio.html"); 
    fout << "Работа с файлами в С++"; // запись строки в файл
    fout.close(); // закрываем файл

}

std::string page_builder::get_name_of_programm() {
    
    return page_init.name_of_programm;
}
std::string page_builder::get_channel() {

    return page_init.channel;
}
std::string page_builder::get_day_of_programm() {

    return page_init.day_of_programm;
}
std::string page_builder::get_time_of_programm() {

    return page_init.time_of_programm;
}
std::string page_builder::get_name_of_cahnnel() {

    return page_init.name_of_cahnnel;
}

void page_builder::set_name_of_programm(std::string set_name_of_programm) {

    page_init.name_of_programm = set_name_of_programm;

}
void  page_builder::set_channel(std::string set_channel) {

    page_init.channel = set_channel;
 
}
void page_builder::set_day_of_programm(std::string set_day_of_programm) {


    page_init.day_of_programm = set_day_of_programm;
 
}
void page_builder::set_time_of_programm(std::string set_time_of_programm) {

    page_init.time_of_programm = set_time_of_programm;

}
void page_builder::set_name_of_cahnnel(std::string set_name_of_cahnnel) {

    page_init.name_of_cahnnel = set_name_of_cahnnel;
   
}

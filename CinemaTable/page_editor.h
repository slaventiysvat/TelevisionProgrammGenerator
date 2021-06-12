#ifndef PAGE_EDITOR
#define PAGE_EDITOR
#include "page_builder.h"


struct one_programm {

    std::string start_time;
    std::string end_time;
    std::string genre;
    std::string name_of_programm;

};

const int amount_of_programs = 24;

class page_editor {


protected:

private:

    int N = 0;
    std::string name_of_page;

public:

    std::vector<one_programm> page_navigator = { {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, 
                                                 {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, 
                                                 {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, 
                                                 {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, {",",",",",",","},
                                                 {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, 
                                                 {",",",",",",","}, {",",",",",",","}, {",",",",",",","}, {",",",",",",","} };

    void page_navigator_default_initializer();

    std::vector<one_programm> page_navigator_add_one_programm(std::string start_time,
        std::string end_tme,
        std::string genre,
        std::string name_of_cinema,
        std::vector<one_programm> programs_array);

    std::vector<one_programm> get_one_programm_data(int count_of_data, std::vector<one_programm> programs_array);

    //first constructor
    page_editor(std::string name_of_file_html,
        std::string start_time,
        std::string end_tme,
        std::string genre,
        std::string name_of_cinema) {

        one_programm one_field;

        if (N > amount_of_programs) {
        
            spdlog::error("Out of range");
             
        }

        one_field.start_time = start_time;
        one_field.end_time = end_tme;
        one_field.genre = genre;
        one_field.name_of_programm = name_of_cinema;

        page_editor::page_navigator.at(N) = one_field;

        N = N + 1;
        name_of_page = name_of_file_html;
       
#ifdef _DEBUG

        spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
        spdlog::debug("Constructor of class page_editor was called");

#endif

    }

    //second constructor
    page_editor(std::string name_of_file_html) {
    name_of_page = name_of_file_html;
#ifdef _DEBUG

        spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
        spdlog::debug("Constructor of class page_editor was called");

#endif

    }

    ~page_editor() {

#ifdef _DEBUG

        spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
        spdlog::debug("Destructor of class page_editor was called");

#endif

    }

};

void page_updater_func(std::string name_of_html_page, page_editor page_editor_class, page_builder page_info);

#endif /*PAGE_EDITOR*/
#ifndef PAGE_BUILDER
#define PAGE_BUILDER
#include "help_header.h"

class page_builder
{

protected:

private:

public:

    struct TV_program_init {

        std::string name_of_programm;
        std::string channel;
        std::string day_of_programm;
        std::string time_of_programm;
        std::string name_of_cahnnel;

    };//TV_program_init

   TV_program_init page_init;
   
    page_builder(std::string name_of_programm,
        std::string channel,
        std::string day_of_programm,
        std::string time_of_programm,
        std::string name_of_cahnnel) {

        page_init.channel = channel;
        page_init.name_of_programm = name_of_programm;
        page_init.day_of_programm = day_of_programm;
        page_init.time_of_programm = time_of_programm;
        page_init.name_of_cahnnel = name_of_cahnnel;

#ifdef _DEBUG

        spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
        spdlog::debug("Constructor of class page_builder was called");

#endif

    }

    ~page_builder() {
    
    #ifdef _DEBUG

     spdlog::set_level(spdlog::level::debug); // Set specific logger's log level
     spdlog::debug("Destructor of class page_builder was called");

    #endif
    
    }

    std::string get_name_of_programm();
    std::string get_channel();
    std::string get_day_of_programm();
    std::string get_time_of_programm();
    std::string get_name_of_cahnnel();

    void set_name_of_programm(std::string set_name_of_programm);
    void set_channel(std::string set_channel);
    void set_day_of_programm(std::string set_day_of_programm);
    void set_time_of_programm(std::string set_time_of_programm);
    void set_name_of_cahnnel(std::string set_name_of_cahnnel);
};

void page_creator(std::string name_of_html_page, page_builder page_info);

#endif /*PAGE_BUILDER*/
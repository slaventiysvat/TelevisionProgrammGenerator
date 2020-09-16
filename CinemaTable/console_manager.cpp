#include "console_manager.h"
#include <fstream>
#include <iostream>
#include "ConsoleColor.h"
void string_initializer(std::string name_of_programm,
    std::string channel,
    std::string day_of_programm,
    std::string time_of_programm,
    std::string name_of_cahnnel) {
    std::cout << white << "============             Info               ===========" << std::endl;
	std::cout << white << "Enter please initial information about your TV programm" << std::endl;
	std::cout << red << "1) name_of_programm "  << std::endl;
	std::cout << red << "2) channel          "  << std::endl;
	std::cout << red << "3) day_of_programm  "  << std::endl;
	std::cout << red << "4) time_of_programm "  << std::endl;
	std::cout << red << "5) name_of_cahnnel  "  << std::endl;
	std::cout << green << "================Enter such parametres==================" << std::endl;

    std::cin.ignore(32767, '\n'); // remove the newline character from the input data stream
	std::cout << white <<   "Enter please " << red << "name_of_programm " << std::endl;
    std::getline(std::cin, name_of_programm);

    std::cin.ignore(32767, '\n'); 
	std::cout << white << "Enter please " << red << " channel          " << std::endl;
	std::getline(std::cin, channel);

    std::cin.ignore(32767, '\n'); 
	std::cout << white << "Enter please " << red << " day_of_programm  " << std::endl;
	std::getline(std::cin, day_of_programm);

    std::cin.ignore(32767, '\n'); 
	std::cout << white << "Enter please "<< red << " time_of_programm " << std::endl;
	std::getline(std::cin, time_of_programm);

    std::cin.ignore(32767, '\n'); 
	std::cout << white << "Enter please "<< red << " name_of_cahnnel  " << std::endl;
	std::getline(std::cin, name_of_cahnnel);

}
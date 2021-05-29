#include "page_builder.h"
#include <fstream>

void page_creator(std::string name_of_html_page, page_builder page_info) {
    using namespace std;
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    ofstream fout;
    char scx('"');

    string name_of_channel = page_info.get_name_of_cahnnel();
    string day_of_programm = page_info.get_day_of_programm();
    string time_of_programm = page_info.get_time_of_programm();
    string name_of_programm = page_info.get_name_of_programm();

    fout.open(name_of_html_page); // связываем объект с файлом
    fout << "<!DOCTYPE HTML>" << endl;
    fout << "<html>" << endl;
    fout << "<head>" << endl;
    fout << " <meta charset= " << scx << "utf - 8" << scx << " > " << endl;
    fout << "  <title>Styles</title> " << endl;
    fout << "  <link rel=" << scx << "stylesheet" << scx << " href=" << scx << "styles_of_table.css" << scx << ">" << endl;
    fout << " </head> " << endl;
    fout << "  <body> " << endl;
    fout << " <table> " << endl;
    fout << " <tbody> " << endl; 
    fout << " <tr> " << endl;
    fout << " <th colspan= " << scx << "4" << scx << ">Televison Programs // Channel-" << name_of_channel << "</th> " << endl;
    fout << " </tr> " << endl;
    fout << " <tr> " << endl;
    fout << "<td colspan=" << scx << "4" << scx << " >#" << day_of_programm << endl;
    fout << " </td>" << endl;
    fout << " </tr> " << endl;
    fout << "<tr> " << endl;
    fout << " <th colspan= " << scx << "2" << scx << ">" << time_of_programm << "</th>" << endl;
    fout << "<th colspan= " << scx << "2" << scx << ">" << name_of_programm << "</th> " << endl;
    fout << "</tr>" << endl;
    fout << " <tr>" << endl;
    fout << "<td></td>" << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	</tr> " << endl;
    fout << "	<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	</tr> " << endl;
    fout << " <tr> " << endl;
    fout << "	<td></td>" << endl;
    fout << "	<td></td>" << endl;
    fout << "	<td></td>" << endl;
    fout << "	<td></td>" << endl;
    fout << "	</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << " </tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << " </tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;
    fout << "</tbody> " << endl;
    fout << " </table> " << endl;
    fout << " </body> " << endl;
    fout << " </html> " << endl;
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

#include "page_editor.h"
#include <iostream>
#include <sstream>
void page_editor::page_navigator_default_initializer() {

    //page_editor::one_programm empty_field = { "00:00","01:00","history","Default Show" };
    one_programm empty_field;
    empty_field.start_time = "00:00";
    empty_field.end_time = "01:00";
    empty_field.genre = "history";
    empty_field.name_of_programm = "Default Show";
    for (int i = 0; i < amount_of_programs; i++) {
    
       page_editor::page_navigator.at(i) = empty_field;
    
    }

}

std::vector<one_programm>  page_editor::get_one_programm_data(int count_of_data, std::vector<one_programm> programs_array) {
             //int count_of_data, one_programm one_programm* programs_array[amount_of_programs]
    std::vector<one_programm> empty_val;
    empty_val.push_back(one_programm());
    empty_val.at(0) = programs_array[count_of_data];
    return empty_val;
}


int page_editor::page_navigator_add_one_programm(std::string start_time,
    std::string end_time,
    std::string genre,
    std::string name_of_cinema) {

    int condition = 0;

    std::string sub_str1;
    sub_str1.push_back((char)start_time[0]);
    sub_str1.push_back((char)start_time[1]);

    std::string sub_str2;
    sub_str2.push_back((char)start_time[3]);
    sub_str2.push_back((char)start_time[4]);

    std::stringstream str1_2_num(sub_str1);
    std::stringstream str2_2_num(sub_str2);

    int x1 = 0;
    int y1 = 0;
    str1_2_num >> x1;
    str2_2_num >> y1;

    std::string sub_str3;
    std::string sub_str4;
    sub_str3.push_back((char)end_time[0]);
    sub_str3.push_back((char)end_time[1]);

    sub_str4.push_back((char)end_time[3]);
    sub_str4.push_back((char)end_time[4]);

    std::stringstream str3_2_num(sub_str3);
    std::stringstream str4_2_num(sub_str4);

    int x2 = 0;
    int y2 = 0;
    str3_2_num >> x2;
    str4_2_num >> y2;


    if (x1 > 23 || x2 > 23) {

        std::cout << "input please correct time in hours" << std::endl;
        condition = -1;
        return condition;
    }

    if (y1 > 59 || y2 > 59) {

        std::cout << "input please correct time in minutes" << std::endl;
        condition = -1;
        return condition;
    }

    if ((x1 * 60 + ((y1 + 1))) > (x2 * 60 + ((y2 + 1)))) {

        std::cout << "input please correct time <<start time>> must be less than <<end time>> " << std::endl;
        condition = -1;
        return condition;
    }

    int x3 = 0;
    int y3 = 0;
    if (N > 0) {
    //check colision with the same time field
        
        std::string end_time_prev = page_navigator.at(N - 1).end_time;
        std::string start_time_prev = page_navigator.at(N - 1).start_time;

        std::string sub_str1prev;
        sub_str1prev.push_back((char)start_time_prev[0]);
        sub_str1prev.push_back((char)start_time_prev[1]);

        std::string sub_str2prev;
        sub_str2prev.push_back((char)end_time_prev[3]);
        sub_str2prev.push_back((char)end_time_prev[4]);

        std::stringstream str1_2_num_pr(sub_str1prev);
        std::stringstream str2_2_num_pr(sub_str2prev);

        str1_2_num_pr >> x3;
        str2_2_num_pr >> y3;

        if (x3 > x2) {
        
            std::cout << "input please correct  <end time> of programm " << std::endl;
            condition = -1;
            return condition;
        }

        if (x3 > x1) {

            std::cout << "input please correct <start time> of programm" << std::endl;
            condition = -1;
            return condition;
        }

    }

    page_navigator.at(N).end_time = end_time;
    page_navigator.at(N).start_time = start_time;
    page_navigator.at(N).genre = genre;
    page_navigator.at(N).name_of_programm = name_of_cinema;

    N = N + 1;// Control Amount of Programs


    if (N > 24) {
    
        spdlog::error("Out of range");
        condition = -1;
    }

    return condition = -1;
}



void page_updater_func(std::string name_of_html_page, page_editor page_editor_class, page_builder page_info) {

    using namespace std;
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    ofstream fout;
    char scx('"');
    //-------------------------footer initializer-------------------------
    string name_of_channel = page_info.get_name_of_cahnnel();
    string day_of_programm = page_info.get_day_of_programm();
    string time_of_programm = page_info.get_time_of_programm();
    string name_of_programm = page_info.get_name_of_programm();
    //--------------------------------------------------------------------

    //page_editor_class.page_navigator;

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

    std::vector<one_programm> struct_info = page_editor_class.get_one_programm_data(0, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(1, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(2, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(3, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(4, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(5, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(6, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(7, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(8, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(9, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(10, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(11, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(12, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(13, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(14, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(15, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(16, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(17, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(18, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(19, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(20, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(21, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(22, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    struct_info = page_editor_class.get_one_programm_data(23, page_editor_class.page_navigator);

    fout << " <tr>" << endl;
    fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    fout << "</tr> " << endl;

    //struct_info = page_editor_class.get_one_programm_data(24, page_editor_class.page_navigator);

    //fout << " <tr>" << endl;
    //fout << " <td>" << struct_info.at(0).start_time << "</td>" << endl;
    //fout << " <td>" << struct_info.at(0).end_time << "</td> " << endl;
    //fout << " <td>" << struct_info.at(0).genre << "</td> " << endl;
    //fout << " <td>" << struct_info.at(0).name_of_programm << "</td> " << endl;
    //fout << "</tr> " << endl;

  /*  fout << "<tr> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "	<td></td> " << endl;
    fout << "</tr> " << endl;*/

    fout << "</tbody> " << endl;
    fout << " </table> " << endl;
    fout << " </body> " << endl;
    fout << " </html> " << endl;
    fout.close(); // закрываем файл
}
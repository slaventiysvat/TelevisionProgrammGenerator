#include "page_editor.h"


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


std::vector<one_programm> page_editor::page_navigator_add_one_programm(std::string start_time,
    std::string end_tme,
    std::string genre,
    std::string name_of_cinema,
    std::vector<one_programm> programs_array) {

    programs_array.at(N).end_time = end_tme;
    programs_array.at(N).start_time = start_time;
    programs_array.at(N).genre = genre;
    programs_array.at(N).name_of_programm = name_of_cinema;

    N = N + 1;

    if (N > 24) {
    
        spdlog::error("Out of range");

    }

    return programs_array;
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
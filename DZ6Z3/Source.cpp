#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
using namespace std;
// Функция для определения количества дней в месяце
int days_in_month(const string& month) {
    regex january("Январь|January");
    regex february("Февраль|February");
    regex march("Март|March");
    regex april("Апрель|April");
    regex may("Май|May");
    regex june("Июнь|June");
    regex july("Июль|July");
    regex august("Август|August");
    regex september("Сентябрь|September");
    regex october("Октябрь|October");
    regex november("Ноябрь|November");
    regex december("Декабрь|December");
      
    if (regex_search(month, january))
        return 31;
    else if (regex_search(month, february))
        return 28; // В феврале в обычный год
    else if (regex_search(month, march))
        return 31;
    else if (regex_search(month, april))
        return 30;
    else if (regex_search(month, may))
        return 31;
    else if (regex_search(month, june))
        return 30;
    else if (regex_search(month, july))
        return 31;
    else if (regex_search(month, august))
        return 31;
    else if (regex_search(month, september))
        return 30;
    else if (regex_search(month, october))
        return 31;
    else if (regex_search(month, november))
        return 30;
    else if (regex_search(month, december))
        return 31;
    else
        return 0; // Некорректное название месяца
}

// Функция для определения номера первого дня недели
int day_of_week(const string& day) {
    if (day == "Понедельник" || day == "Monday")
        return 1;
    else if (day == "Вторник" || day == "Tuesday")
        return 2;
    else if (day == "Среда" || day == "Wednesday")
        return 3;
    else if (day == "Четверг" || day == "Thursday")
        return 4;
    else if (day == "Пятница" || day == "Friday")
        return 5;
    else if (day == "Суббота" || day == "Saturday")
        return 6;
    else if (day == "Воскресенье" || day == "Sunday")
        return 7;
    else
        return 0; // Некорректное название дня недели
}

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    string month, day;
    cout << "Введите название месяца (на русском или английском): ";
    getline(cin, month);
    cout << "Введите название первого дня недели (на русском или английском): ";
    getline(cin, day);

    int days = days_in_month(month);
    int first_day = day_of_week(day);

    if (days == 0) {
        cout << "Некорректное название месяца!" << endl;
    }
    else if (first_day == 0) {
        cout << "Некорректное название дня недели!" << endl;
    }
    else {
        cout << "Календарь для " << month << endl;
        cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;

        int current_day = 1;
        for (int i = 1; i < first_day; i++) {
            cout << "   ";
            current_day++;
        }

        for (int i = 1; i <= days; i++) {
            if (current_day > 7) {
                cout << endl;
                current_day = 1;
            }
            if (i < 10)
                cout << " " << i << " ";
            else
                cout << i << " ";
            current_day++;
        }
        cout << endl;
    }

    return 0;
}
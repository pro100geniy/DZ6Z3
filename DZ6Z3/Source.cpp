#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
using namespace std;
// ������� ��� ����������� ���������� ���� � ������
int days_in_month(const string& month) {
    regex january("������|January");
    regex february("�������|February");
    regex march("����|March");
    regex april("������|April");
    regex may("���|May");
    regex june("����|June");
    regex july("����|July");
    regex august("������|August");
    regex september("��������|September");
    regex october("�������|October");
    regex november("������|November");
    regex december("�������|December");
      
    if (regex_search(month, january))
        return 31;
    else if (regex_search(month, february))
        return 28; // � ������� � ������� ���
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
        return 0; // ������������ �������� ������
}

// ������� ��� ����������� ������ ������� ��� ������
int day_of_week(const string& day) {
    if (day == "�����������" || day == "Monday")
        return 1;
    else if (day == "�������" || day == "Tuesday")
        return 2;
    else if (day == "�����" || day == "Wednesday")
        return 3;
    else if (day == "�������" || day == "Thursday")
        return 4;
    else if (day == "�������" || day == "Friday")
        return 5;
    else if (day == "�������" || day == "Saturday")
        return 6;
    else if (day == "�����������" || day == "Sunday")
        return 7;
    else
        return 0; // ������������ �������� ��� ������
}

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    string month, day;
    cout << "������� �������� ������ (�� ������� ��� ����������): ";
    getline(cin, month);
    cout << "������� �������� ������� ��� ������ (�� ������� ��� ����������): ";
    getline(cin, day);

    int days = days_in_month(month);
    int first_day = day_of_week(day);

    if (days == 0) {
        cout << "������������ �������� ������!" << endl;
    }
    else if (first_day == 0) {
        cout << "������������ �������� ��� ������!" << endl;
    }
    else {
        cout << "��������� ��� " << month << endl;
        cout << "�� �� �� �� �� �� ��" << endl;

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
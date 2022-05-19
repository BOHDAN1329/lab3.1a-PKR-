#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

struct Student {
    string lname;
    int kurs;
    Spec spec;
    int physics;
    int math;
    int inform;

};

void create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "Прiзвище: ";
        cin >> s[i].lname;
        cout << "Курс: ";
        cin >> s[i].kurs;
        cout << "Спецiальнiсть (0 - Комп'ютернi науки, 1 - Iнформатика, 2 - Математика та економiка, 3 - Фiзика та iнформатика, Трудове навчання) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "Оцiнка з фiзики: ";
        cin >> s[i].physics;
        cout << "Оцiнка з математики: ";
        cin >> s[i].math;
        cout << "Оцiнка з інформатики: ";
        cin >> s[i].inform;

    }
}
void print(Student* s, int amSt)
{
    cout << "========================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика | Математика | Інформатика |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].lname
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math;
        cout << "| " << setw(14) << right << s[i].inform << "|";

        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}

int physicsThr(Student* s, int amSt) {
    int count = 0;
    for (int i = 0; i < amSt; i++) {
        if (s[i].physics == 3) {
            count += 1;
        }
    }
    return count;
};

int mathThr(Student* s, int amSt) {
    int count = 0;
    for (int i = 0; i < amSt; i++) {
        if (s[i].math == 3) {
            count += 1;
        }
    }
    return count;
}

int informThr(Student* s, int amSt) {
    int count = 0;
    for (int i = 0; i < amSt; i++) {
        if (s[i].inform == 3) {
            count += 1;

        }
        else
            count += 0;
    }
    return count;
}


double amount(Student s)
{
    double k = s.math + s.physics +s.inform;

    return k / 3.0;
}

string Prizv(Student* s, const int N)
{
    double min = amount(s[0]);
    int min_i = 0;
    for (int i = 0; i < N; i++)
    {
        if (amount(s[i]) < min)
        {
            min_i = i;
            min = amount(s[i]);
        }
    }
    return s[min_i].lname;
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    int amSt;
    cout << "Кiлькiсть студентiв: ";
    cin >> amSt;
    Student* s = new Student[amSt];
    create(s, amSt);
    print(s, amSt);

    cout << "Kiлькiсть оцiнок «задовільно» з фiзики: " << physicsThr(s, amSt) << endl;
    cout << "Kiлькiсть оцiнок «задовільно» з математики: " << mathThr(s, amSt) << endl;
    cout << "Kiлькiсть оцiнок «задовільно» з інформатики: " << informThr(s, amSt) << endl;

    cout << "Kiлькiсть студентiв, якi отримали з фiзики i математики оцінки «3»: " << Prizv(s, amSt) << endl;

    return 0;

}
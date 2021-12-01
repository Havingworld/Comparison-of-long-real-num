/* Что нужно сделать
Вы продолжаете писать калькулятор, работающий над вещественными числами повышенной точности.
Вы уже научились проверять корректность записи вещественных чисел в виде строк,
и теперь перед вами новая цель — научиться сравнивать такие вещественные числа.

Пользователь вводит две строки, задающие вещественные числа, в том же формате,
как было описано в задаче «Длинное вещественное число». Программа должна проверить
корректность ввода (для этого можно переиспользовать код,
написанный в задаче «Длинное вещественное число»), после чего вывести слово Less,
если первое число строго меньше второго; слово More, если первое число строго больше второго;
и слово Equal, если введённые числа равны.

Примеры:

Ввод: 2.39 3.61
Ответ: Less

Ввод: 0123 12.3
Ответ: More

Ввод: 12345678 12345678.00
Ответ: Equal

Ввод: -1.0 1.0
Ответ: Less

Советы и рекомендации
Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
Создайте отдельную функцию для получения целой и дробной частей числа. Её можно сделать на основе задачи об IP-адресах,
т.к. там тоже использовалась точка в качестве разделителя.
Для сравнения дробных частей можно создать специальную функцию безопасного доступа к символу строки по индексу.
Для дробных чисел, если этот индекс больше длины дробной части, данная функция может безопасно вернуть 0.


Что оценивается
Программа должна выдавать корректные результаты сравнениях двух длинных вещественных чисел.
*/

#include <iostream>
#include <string>
using namespace std;

bool CompReal(string input) {
    
    int dot_count = 0;
    bool digit_found = false;
    for (int i = 0; i < input.size(); ++i) {
        char ch = input[i];

        if (ch >= '0' && ch <= '9') {
            digit_found = true;
            continue;
        }
        else if (ch == '.') {
            if (++dot_count > 1) {
                //cout << "Incorrect number of dot\n";
                return 1;
            }
            else {
                continue;
            }
        }
        else if (ch == '-' && i == 0) {
            continue;
        }

        //cout << "Incorrect symbol " << ch << '\n';
        return 1;

    }
    if (!digit_found) {
        //cout << "There is no digit in number\n";
        return 1;
    }

    //cout << "Number is correct";
    return 0;
}

string CompareNum (string Num1, string Num2)
{
    int nNum1Dot = 0, nNum2Dot = 0;

    // variable for separate numbers
    string szNum1Parth1, szNum1Parth2, szNum2Parth1, szNum2Parth2;
    
    //separate Num1 to 2 parth
    for (int n = 0; n < Num1.length(); n++) {
            if (Num1[n] == '.') {
                    continue;
                }
                else {
                szNum1Parth1 += Num1[n];
                nNum1Dot++;
                }
            }
    for (int n = nNum1Dot, i = 0; n < Num1.length(); n++, i++) {
                szNum1Parth2 += Num1[n];
        }
    
    //separate Num2 to 2 parth
    for (int n = 0; n < Num2.length(); n++) {
        if (Num2[n] == '.') {
            continue;
        }
        else {
            szNum2Parth1 += Num2[n];
            nNum2Dot++;
        }
    }
    for (int n = nNum2Dot, i = 0; n < Num2.length(); n++, i++) {
        szNum2Parth2 += Num2[n];
    }
    // !!! Убрать ноли после значащего числа в части 2
    
    //convert string to integer
    int nNum1Parth1 = stoi(szNum1Parth1);
    int nNum1Parth2 = stoi(szNum1Parth2);
    int nNum2Parth1 = stoi(szNum2Parth1);
    int nNum2Parth2 = stoi(szNum2Parth2);
    
    //compare two number

    if (nNum1Parth1 > nNum2Parth1) {
        return "More";
    }
    else if (nNum1Parth1 < nNum2Parth1) {
        return "Less";
    }
    else if (nNum1Parth1 == nNum2Parth1) {
        if (nNum1Parth2 > nNum2Parth2) {
            return "More";
        } else if (nNum1Parth2 < nNum2Parth2) {
            return "Less";
        } else {
            return "Equal";
        }
    }
    
}

int main()
{
    for (;;) {
        string szInputNum1, szInputNum2;
        cout << "input num1 num2 : ";
        cin >> szInputNum1 >> szInputNum2;
        if (CompReal(szInputNum1) || CompReal(szInputNum2)) {
            cout << "incorrect number" << endl;
        }
        else {
            cout << CompareNum(szInputNum1, szInputNum2) << endl;
        }
    }
}



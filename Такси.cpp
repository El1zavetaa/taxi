#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

struct Worker {
    int id;
    int distance;
};

struct Taxi {
    int id;
    int tariff;
};

bool Distance(const Worker& w1, const Worker& w2) {
    return w1.distance < w2.distance;
}

bool TaxiTariff(const Taxi& t1, const Taxi& t2) {
    return t1.tariff < t2.tariff;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введите количество сотрудников (машин): ";
    cin >> N;
    if ((N < 0) or (N > 1000))
        cout << "Ошибка, введите еще раз количество сотрудников (натуральное число от 1 до 1000)" << endl;


    vector<Worker> workers(N);
    vector<Taxi> taxis(N);

    for (int i = 0; i < N; i++) {
        workers[i].id = i + 1;
        cout << "Введите дистанцию сотрудника от работы до дома (км): ";
        cin >> workers[i].distance;
        if (workers[i].distance < 0)
            cout << "Ошибка, введите еще раз дистанцию сотрудника от работы до дома (положительное число)" << endl;
    }

    for (int i = 0; i < N; i++) {
        taxis[i].id = i + 1;
        cout << "Введите тариф на проезд одного км в такси (руб): ";
        cin >> taxis[i].tariff;
        if (taxis[i].tariff < 0)
            cout << "Ошибка, введите еще раз тариф на проезд одного км в такси (положительное число)" << endl;
    }

    sort(workers.rbegin(), workers.rend(), Distance);

    sort(taxis.begin(), taxis.end(), TaxiTariff);

    int sum = 0;
    vector<int> assignments(N);

    for (int i = 0; i < N; i++) {
        assignments[workers[i].id - 1] = taxis[i].id;
        sum += workers[i].distance * taxis[i].tariff;
    }
    cout << "Номера такси для рассадки: ";
    for (int i = 0; i < N; i++) {
        cout << assignments[i] << ' ';
    }

    string currency;
    if (sum % 10 == 1 && sum % 100 != 11) {
        currency = "рубль";
    }
    else if ((sum % 10 >= 2 && sum % 10 <= 4) &&
        !(sum % 100 >= 12 && sum % 100 <= 14)) {
        currency = "рубля";
    }
    else {
        currency = "рублей";
    }
    cout << endl;
    cout << "Сумма, которую надо заплатить за такси: " << sum << ' ' << currency << endl;
    cout << "Сумма словами: ";
    if (sum < 0) cout << "Невозможно";
    else {
        switch (sum) {
        case 100000: cout << "сто тысяч рублей";
            return 0;
        case 10000: cout << "десять тысяч рублей";
            return 0;
        case 1000: cout << "тысяча рублей";
            return 0;
        case 10: cout << "десять рублей";
            return 0;
        }

        switch (sum / 10000 % 10) {
        case 1:
        {
            switch (sum / 1000) {
            case 11: cout << "одиннадцать тысяч ";
                break;
            case 12: cout << "двенадцать тысяч ";
                break;
            case 13: cout << "тринадцать тысяч ";
                break;
            case 14: cout << "четырнадцать тысяч";
                break;
            case 15: cout << "пятнадцать тысяч ";
                break;
            case 16: cout << "шестнадцать тысяч ";
                break;
            case 17: cout << "семнадцать тысяч ";
                break;
            case 18: cout << "восемнадцать тысяч ";
                break;
            case 19: cout << "девятнадцать тысяч ";
                break;
            }
            break;
        }
        case 2: cout << "двадцать ";
            break;
        case 3: cout << "тридцать ";
            break;
        case 4: cout << "сорок ";
            break;
        case 5: cout << "пятьдесят ";
            break;
        case 6: cout << "шестьдесят ";
            break;
        case 7: cout << "семьдесят ";
            break;
        case 8: cout << "восемьдесят ";
            break;
        case 9: cout << "девяносто ";
            break;
            cout << " тысяч рублей";
            break;

        }

        switch (sum / 1000 % 10) {
        case 1:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "одна тысяча ";
            break;
        }
        case 2:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "две тысячи ";
            break;
        }
        case 3: {
            if ((sum / 10000 % 10) != 1)
                cout << "три тысячи ";
            break;
        }
        case 4: {
            if ((sum / 10000 % 10) != 1)
                cout << "четыре тысячи ";
            break;
        }
        case 5:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "пять тысяч ";
            break;
        }
        case 6:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "шесть тысяч ";
            break;
        }
        case 7:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "семь тысяч ";
            break;
        }
        case 8:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "восемь тысяч ";
            break;
        }
        case 9:
        {
            if ((sum / 10000 % 10) != 1)
                cout << "девять тысяч ";
            break;
        }
        cout << " тысяч рублей";
        break;
        }

        switch (sum % 1000 / 100) {
        case 1: cout << "сто ";
            break;
        case 2: cout << "двести ";
            break;
        case 3: cout << "триста ";
            break;
        case 4: cout << "четыреста ";
            break;
        case 5: cout << "пятьсот ";
            break;
        case 6: cout << "шестьсот ";
            break;
        case 7: cout << "семьсот ";
            break;
        case 8: cout << "восемьсот ";
            break;
        case 9: cout << "девятьсот ";
            break;

        }

        switch (sum % 100 / 10)
        {
        case 2: cout << "двадцать ";
            break;
        case 3: cout << "тридцать ";
            break;
        case 4: cout << "сорок ";
            break;
        case 5: cout << "пятьдесят ";
            break;
        case 6: cout << "шестьдесят ";
            break;
        case 7: cout << "семьдесят ";
            break;
        case 8: cout << "восемьдесят ";
            break;
        case 9: cout << "девяносто ";
            break;
        }

        switch (sum % 100) {
        case 11: cout << "одиннадцать рубей";
            return 0;
        case 12: cout << "двенадцать рубей";
            return 0;
        case 13: cout << "тринадцать рубей";
            return 0;
        case 14: cout << "четырнадцать рубей";
            return 0;
        case 15: cout << "пятьнадцать рубей";
            return 0;
        case 16: cout << "шестьнадцать рубей";
            return 0;
        case 17: cout << "семьнадцать рубей";
            return 0;
        case 18: cout << "восемьнадцать рубей";
            break;
        case 19: cout << "девятнадцать рубей";
            return 0;
        }

        switch (sum % 10) {
        case 1: cout << "один рубль";
            break;
        case 2: cout << "два рубля";
            break;
        case 3: cout << "три рубля";
            break;
        case 4: cout << "четыре рубля";
            break;
        case 5: cout << "пять рублей";
            break;
        case 6: cout << "шесть рублей";
            break;
        case 7: cout << "семь рублей";
            break;
        case 8: cout << "восемь рублей";
            break;
        case 9: cout << "девять рублей";
            break;
        case 0: cout << "рублей";
            break;
        }
    }
  }

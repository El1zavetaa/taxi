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
    cout << "Сумма, которую надо заплатить за такси: " << sum << " " << currency << endl;
}
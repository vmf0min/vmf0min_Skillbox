/// Задача 8. Грустное совершеннолетие.
/// Посетитель пришел в бар и попросил кружку пива. Напишите программу для бармена, который не умеет считать, чтобы по
/// заданной дате рождения посетителя и текущей дате определить, можно ему продавать алкоголь или нет. Программа должна
/// попросить ввести сегодняшнюю дату и дату рождения покупателя, после чего ответить: “можно” или “нельзя”.
/// Учтите, что в день 18-летия алкоголь продавать посетителю еще нельзя, а вот на следующий день после этого — уже можно.
/// Как обычно, постарайтесь сделать свою программу по возможности лаконичнее.

#include <iostream>
#include <ctime>

int main() {
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    int day, month, year;

    std::cout << "Дата рождения посетителя число, месяц, год: ";
    std::cin >> day >> month >> year;

    month--;      // Уменьшаю на 1, чтобы приравнять к tm_mon, т.к. он 0 - 10;
    year -= 1900; // Привожу к tm_year. он с 1900 года

    // Если нет 18, то нечего проверять
    if ((timeInfo->tm_year - year) < 18) std::cout << "Нельзя. Нет 18: " << timeInfo->tm_year - year << " лет\n";
        // Проверяем месяц и день
    else if (timeInfo->tm_year - year == 18) {
        if (month > timeInfo->tm_mon) {
            std::cout << "Нельзя по месяцу.\n";
        } else if (month == timeInfo->tm_mon && day >= timeInfo->tm_mday)
            std::cout << "Нельзя по дню рождения.\n";
        else std::cout << "Можно.\n";
        // Во всех остальных случаях можно
    } else std::cout << "Можно. Возраст: " << timeInfo->tm_year - year << " лет\n";;

    return 0;
}

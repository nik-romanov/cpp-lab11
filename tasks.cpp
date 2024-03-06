
#ifndef TASKS
#define TASKS

#include <algorithm>

#include <vector>
#include <list>
#include <deque>

#include <string>

#include <fstream>
#include <iostream>

struct square {
    square() {}

    void operator()(int &x) const {
        x *= x;
    }
};

/* 1. Напишите программу, которая считывает список целых чисел от пользователя, а затем выполняет
несколько контейнерных алгоритмов в списке с помощью итераторов */
std::vector<int> task1(std::vector<int> v)          
{ //// vector<>.begin() or end() VS std::begin(vector<>) or std::end(vector<>) ???
    std::sort(std::begin(v), std::end(v));                          // std::sort()

    std::rotate( std::begin(v), std::next( std::begin(v), v.size() / 2 ), std::end(v) );

    std::vector<int>::iterator midle = std::begin(v);
    std::advance(midle, v.size() / 2);                              // std::advance()

    v.erase(midle);                                                 // std::erase() 

    std::for_each(std::begin(v), std::end(v), [](int &x){x *= 2;}); // std::for_each() + double[]() ?????

    std::reverse(std::begin(v), std::end(v));

    return v;
}

/* 2. Используйте адаптеры итераторов, такие как back_inserter, front_inserter и inserter, для изменения
контейнеров с помощью итераторов. Напишите программу, которая создает вектор целых чисел, а
затем использует итераторы и несколько функций адаптера для добавления или удаления
элементов из вектора.*/
std::vector<int> task2(std::vector<int> v)
{
    std::list<int> l(v.begin(), v.end());       // list<int> from (vector<int>)
    std::list<int>::iterator midle = l.begin(); 
    std::advance(midle, l.size() / 2);          // std::advance()

    std::fill_n(std::inserter(l, midle), 3, 0); // VS std::fill_n(midle, 3, 0);
    std::fill_n(std::back_inserter(l), 3, 1);   
    std::fill_n(std::front_inserter(l), 3, -1); 
    return std::vector<int> (l.begin(), l.end());
}

/* 3. Используйте стандартные итераторы для чтения и записи файлов. Напишите программу, которая
демонстрирует работу с текстовым файлом с помощью итераторов */
void task3(const std::string &InputFileName = "read_from.txt", const std::string &OutputFileName = "write_to.txt")
{
    std::ifstream input(InputFileName);     // read_from
    std::ofstream output(OutputFileName);   // write_to

    std::istreambuf_iterator<char> input_iter(input);   // input_iter()
    std::istreambuf_iterator<char> eof;                 // default constructor() { EOF_iterator }
    std::ostreambuf_iterator<char> output_iter(output); // output_iter()

    std::copy(input_iter, eof, output_iter);            // std::copy()
}

/* 4. Продемонстрируйте совместимость итераторов между различными типами контейнеров, такими
как вектор и двухсторонняя очередь. Напишите программу, которая создает вектор целых чисел, а
затем использует итераторы для копирования элементов вектора в очередь. */
std::deque<int> task4(const std::vector<int> &v)
{
    std::deque<int> d;
    std::copy(v.begin(), v.end(), std::back_inserter(d)); // Копирование из вектора в дек

    return d;
}

/* 5. Используйте обратные итераторы, чтобы изменить порядок элементов в контейнере. Напишите
программу, которая считывает список целых чисел от пользователя, а затем использует обратные
итераторы для вывода элементов в обратном порядке */
std::vector<int> task5(const std::vector<int> &v)
{
    std::vector<int> reversed(v.rbegin(), v.rend()); // Создание вектора из обратных итераторов

    return reversed;
}

#endif
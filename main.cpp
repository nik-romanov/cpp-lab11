
#include "tasks.cpp"

int main()
{
    //int array[] = {1, 2, 8, 7, 4, 6, 5, 3, 10, 9};
    std::vector<int> v{1, 2, 8, 7, 4, 6, 5, 3, 10, 9};
    //v.assign(array, array + 10);

    std::cout << "vector: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::vector<int> task1_result = task1(v);
    std::cout << "\nTask1: ";
    for (int i = 0; i < task1_result.size(); i++) {
        std::cout << task1_result[i] << " ";
    }

    std::vector<int> task2_result = task2(task1_result);
    std::cout << "\nTask2: ";
    for (int i = 0; i < task2_result.size(); i++) {
        std::cout << task2_result[i] << " ";
    }

    task3(); //default arguments: "read_from.txt" and "write_to.txt"

    std::cout << "\nTask4: ";
    std::deque<int> task4_result = task4(v);
    for (int i = 0; i < task4_result.size(); i++) {
        std::cout << task4_result[i] << " ";
    }

    std::cout << "\nTask5: ";
    std::vector<int> task5_result = task5(v);
    for (int i = 0; i < task5_result.size(); i++) {
        std::cout << task5_result[i] << " ";
    }
}
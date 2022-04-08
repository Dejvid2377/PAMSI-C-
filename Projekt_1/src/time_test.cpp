#include <chrono>
#include <vector>
#include <algorithm>
#include "data_structures/All_Structures.hh"
#include "data_structures/libraries.hh"
// #include <unistd.h>

int main() {
    ofstream results(EXP_RESULTS2); 
    
    int nVector[]= {10, 100, 1000, 10000, 100000};
    const int total_exp = 10;
    const int total_loops = 4;
    const int total_loops2 = 4;
    StackTab<int> stack_array {100000};
    StackList<int> stack_list;
    QueueTab<int> queue_array {100000};
    QueueList<int> queue_list;
    double time {0};
    
    for (int k=0; k<total_loops; k++)
    {
      for (int j=0; j<total_exp; j++)
      {
        auto start = std::chrono::system_clock::now();
        for (int i=0; i<nVector[k]; i++)
          stack_array.push(i);

        for (int i=0; i<nVector[k]; i++)
          stack_array.pop();

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        time += durationTime;  
        }
        time /= total_exp;
        results << time << endl;
        time =0;
    }
    results << endl;

    for (int k=0; k<total_loops; k++)
    {
      for (int j=0; j<total_exp; j++)
      {
        auto start = std::chrono::system_clock::now();
        for (int i=0; i<nVector[k]; i++)
          stack_list.push(i);

        for (int i=0; i<nVector[k]; i++)
          stack_list.pop();

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        time += durationTime;  
        cout << "loop nr: " << j << endl;
        }
        time /= total_exp;
        results << time << endl;
        time =0;

    }
    results << endl;
    /////////////////////////////////////////////////////////////////////////////////
    for (int k=0; k<total_loops2; k++)
    {
      for (int j=0; j<total_exp; j++)
      {
        auto start = std::chrono::system_clock::now();
        for (int i=0; i<nVector[k]; i++)
          queue_array.enqueue(1);

        for (int i=0; i<nVector[k]; i++)
          queue_array.dequeue();
        

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        time += durationTime;  
        cout << "numer petli j: " << j << endl;
        }
        time /= total_exp;
        results << time << endl;
        time =0;
    }
    results << endl;

    for (int k=0; k<total_loops2; k++)
    {
      for (int j=0; j<total_exp; j++)
      {
        auto start = std::chrono::system_clock::now();
        for (int i=0; i<nVector[k]; i++)
          queue_list.enqueue(i);

        for (int i=0; i<nVector[k]; i++)
          queue_list.dequeue();

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        time += durationTime;  
       // cout << "numer petli j: " << j << endl;
        }
        time /= total_exp;
        results << time << endl;
        time =0;

    }

    results.close();
    return 0;
}

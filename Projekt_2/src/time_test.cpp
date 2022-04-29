#include <chrono>
#include <vector>
#include <algorithm>
#include "algorithms/All_Structures.hh"
#include "algorithms/libraries.hh"

int main() {
    srand(time(NULL));
    //ofstream results1(EXP_RESULTS1); 
    //ofstream results2(EXP_RESULTS2); 
    ofstream results3(EXP_RESULTS3); 
    int nVector[]= {10000, 50000, 100000, 500000, 1000000};
    float percent[]= {0.25, 0.5, 0.75, 0.95, 0.99, 0.997};
    const int total_exp = 100;
    const int total_loops = 5;
    const int percent_loops = 6;
    int exp_number = 1;
    double time {0};
    MergeSort<int> mer;
    QuickSort<int> quick;
    HeapSort<int> heap;
/*
//////////////////////////////////////////////////////////////////////////////////////
//    TESTY MergeSort - WSZYSTKIE WARTOSCI LOSOWE 
    results1 << "MergeSort - Wszystkie wartosci losowe" << endl;
    for (int i=0; i<total_loops; i++) {
      results1 << "***************************************" << endl;
      results1 << "Rozmiar vectora: " << nVector[i] << endl;
      results1 << "***************************************" << endl;
      
      for (int j=0; j<total_exp; j++) {    
        cout << "Test: "<<exp_number <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;           
        vector<int> temp;
        temp.reserve(nVector[i]);
        
        for (int k=0;k<nVector[i];k++)
          temp.push_back(rand()%nVector[i]);
    
        auto start = std::chrono::system_clock::now();
        mer.sort(temp.begin(),temp.end());
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        results1 <<"czas sortowania nr." << j <<": " << durationTime << endl;
        time += durationTime;
      }
      cout << endl;
      time /= total_exp;
      results1 << "*******************************" << endl;
      results1 <<"sredni czas: " << time << endl;
      results1 << "*******************************" << endl;
      time =0;
    }
    exp_number++;
    results1 << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////
//    TESTY MergeSort - posortowane odwrotnie
results1 << "MergeSort - juz posortowane malejaco" << endl;
   for (int i=0; i<total_loops; i++) {
      results1 << "***************************************" << endl;
      results1 << "Rozmiar vectora: " << nVector[i] << endl;
      results1 << "***************************************" << endl;
        for (int j=0; j<total_exp; j++) {   
        cout << "Test: "<<exp_number <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;           
          vector<int> temp;
          int k = 0;
          temp.reserve(nVector[i]);

          for (int k=0;k<nVector[i];k++)
            temp.push_back(rand()%nVector[i]);
          
          sort(temp.begin(),temp.end(),greater<int>());
          
          auto start = std::chrono::system_clock::now();
          mer.sort(temp.begin(),temp.end());
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double> diff =
                  end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
          double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                          // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
          results1 <<"czas sortowania nr." << j <<": " << durationTime << endl;
          time += durationTime;
        }
          cout << endl;
          time /= total_exp;
          results1 << "*******************************" << endl;
          results1 <<"sredni czas: " << time << endl;
          results1 << "*******************************" << endl;
          time =0;
      }
    exp_number++;
    results1 << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////
//    TESTY MergeSort - % posortowane
for (int m = 0; m<percent_loops;m++) {
  results1 << "MergeSort - juz posortowane w " << percent[m]*100 << "%" << endl;
   for (int i=0; i<total_loops; i++) {
      results1 << "***************************************" << endl;
      results1 << "Rozmiar vectora: " << nVector[i] << endl;
      results1 << "***************************************" << endl;
        for (int j=0; j<total_exp; j++) {   
          cout << "Test: "<<exp_number + m <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;            
          vector<int> temp;
          int k = 0;
          temp.reserve(nVector[i]);

          for (;k<nVector[i]*percent[m];k++)
            temp.push_back(k);
          
          int min = k;

          for (;k<nVector[i];k++)
            temp.push_back(rand()%(nVector[i]-min+1)+min);
      
          auto start = std::chrono::system_clock::now();
          mer.sort(temp.begin(),temp.end());
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double> diff =
                  end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
          double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                          // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
          results1 <<"czas sortowania nr." << j <<": " << durationTime << endl;
          time += durationTime;
        }
          cout << endl;
          time /= total_exp;
          results1 << "*******************************" << endl;
          results1 <<"sredni czas: " << time << endl;
          results1 << "*******************************" << endl;
          time =0;
      }
    results1 << endl << endl;
  } 
    results1.close();
    exp_number = 1;
*/
/*
////////////////////////////////////////////////////////////////////////////////////////////////////////]
//////////////////////////////////////////////////////////////////////////////////////
//    TESTY QuickSort - WSZYSTKIE WARTOSCI LOSOWE 
    results2 << "QuickSort - Wszystkie wartosci losowe" << endl;
    for (int i=0; i<total_loops; i++) {
      results2 << "***************************************" << endl;
      results2 << "Rozmiar vectora: " << nVector[i] << endl;
      results2 << "***************************************" << endl;
      
      for (int j=0; j<total_exp; j++) {    
        cout << "Test: "<<exp_number <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;           
        vector<int> temp;
        temp.reserve(nVector[i]);
        
        for (int k=0;k<nVector[i];k++)
          temp.push_back(rand()%nVector[i]);
    
        auto start = std::chrono::system_clock::now();
        quick.sort(temp.begin(),temp.end()-1);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        results2 <<"czas sortowania nr." << j <<": " << durationTime << endl;
        time += durationTime;
      }
      cout << endl;
      time /= total_exp;
      results2 << "*******************************" << endl;
      results2 <<"sredni czas: " << time << endl;
      results2 << "*******************************" << endl;
      time =0;
    }
    exp_number++;
    results2 << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////
//    TESTY QuickSort - posortowane odwrotnie
results2 << "QuickSort - juz posortowane malejaco" << endl;
   for (int i=0; i<total_loops; i++) {
      results2 << "***************************************" << endl;
      results2 << "Rozmiar vectora: " << nVector[i] << endl;
      results2 << "***************************************" << endl;
        for (int j=0; j<total_exp; j++) {   
        cout << "Test: "<<exp_number <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;           
          vector<int> temp;
          int k = 0;
          temp.reserve(nVector[i]);

          for (int k=0;k<nVector[i];k++)
            temp.push_back(rand()%nVector[i]);
          
          sort(temp.begin(),temp.end(),greater<int>());
          
          auto start = std::chrono::system_clock::now();
          quick.sort(temp.begin(),temp.end()-1);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double> diff =
                  end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
          double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                          // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
          results2 <<"czas sortowania nr." << j <<": " << durationTime << endl;
          time += durationTime;
        }
          cout << endl;
          time /= total_exp;
          results2 << "*******************************" << endl;
          results2 <<"sredni czas: " << time << endl;
          results2 << "*******************************" << endl;
          time =0;
      }
    exp_number++;
    results2 << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////
//    TESTY QuickSort - % posortowane
for (int m = 0; m<percent_loops;m++) {
  results2 << "QuickSort - juz posortowane w " << percent[m]*100 << "%" << endl;
   for (int i=0; i<total_loops; i++) {
      results2 << "***************************************" << endl;
      results2 << "Rozmiar vectora: " << nVector[i] << endl;
      results2 << "***************************************" << endl;
        for (int j=0; j<total_exp; j++) {   
          cout << "Test: "<<exp_number + m <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;            
          vector<int> temp;
          int k = 0;
          temp.reserve(nVector[i]);

          for (;k<nVector[i]*percent[m];k++)
            temp.push_back(k);
          
          int min = k;

          for (;k<nVector[i];k++)
            temp.push_back(rand()%(nVector[i]-min+1)+min);
      
          auto start = std::chrono::system_clock::now();
          quick.sort(temp.begin(),temp.end()-1);
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double> diff =
                  end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
          double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                          // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
          results2 <<"czas sortowania nr." << j <<": " << durationTime << endl;
          time += durationTime;
        }
          cout << endl;
          time /= total_exp;
          results2 << "*******************************" << endl;
          results2 <<"sredni czas: " << time << endl;
          results2 << "*******************************" << endl;
          time =0;
      }
    results2 << endl << endl;
  } 
    results2.close(); 
*/
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//    TESTY HeapSort - WSZYSTKIE WARTOSCI LOSOWE 
    results3 << "HeapSort - Wszystkie wartosci losowe" << endl;
    for (int i=0; i<total_loops; i++) {
      results3 << "***************************************" << endl;
      results3 << "Rozmiar vectora: " << nVector[i] << endl;
      results3 << "***************************************" << endl;
      
      for (int j=0; j<total_exp; j++) {    
        cout << "Test: "<<exp_number <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;           
        vector<int> temp;
        temp.reserve(nVector[i]);
        
        for (int k=0;k<nVector[i];k++)
          temp.push_back(rand()%nVector[i]);
    
        auto start = std::chrono::system_clock::now();
        heap.sort(temp.begin(),temp.end());
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff =
                end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
        double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                        // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
        results3 <<"czas sortowania nr." << j <<": " << durationTime << endl;
        time += durationTime;
      }
      cout << endl;
      time /= total_exp;
      results3 << "*******************************" << endl;
      results3 <<"sredni czas: " << time << endl;
      results3 << "*******************************" << endl;
      time =0;
    }
    exp_number++;
    results3 << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////
//    TESTY HeapSort - posortowane odwrotnie
results3 << "HeapSort - juz posortowane malejaco" << endl;
   for (int i=0; i<total_loops; i++) {
      results3 << "***************************************" << endl;
      results3 << "Rozmiar vectora: " << nVector[i] << endl;
      results3 << "***************************************" << endl;
        for (int j=0; j<total_exp; j++) {   
        cout << "Test: "<<exp_number <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;           
          vector<int> temp;
          int k = 0;
          temp.reserve(nVector[i]);

          for (int k=0;k<nVector[i];k++)
            temp.push_back(rand()%nVector[i]);
          
          sort(temp.begin(),temp.end(),greater<int>());
          
          auto start = std::chrono::system_clock::now();
          heap.sort(temp.begin(),temp.end());
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double> diff =
                  end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
          double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                          // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
          results3 <<"czas sortowania nr." << j <<": " << durationTime << endl;
          time += durationTime;
        }
          cout << endl;
          time /= total_exp;
          results3 << "*******************************" << endl;
          results3 <<"sredni czas: " << time << endl;
          results3 << "*******************************" << endl;
          time =0;
      }
    exp_number++;
    results3 << endl << endl;

//////////////////////////////////////////////////////////////////////////////////////
//    TESTY HeapSort - % posortowane
for (int m = 0; m<percent_loops;m++) {
  results3 << "HeapSort - juz posortowane w " << percent[m]*100 << "%" << endl;
   for (int i=0; i<total_loops; i++) {
      results3 << "***************************************" << endl;
      results3 << "Rozmiar vectora: " << nVector[i] << endl;
      results3 << "***************************************" << endl;
        for (int j=0; j<total_exp; j++) {   
          cout << "Test: "<<exp_number + m <<"/8 || Tablica[" << i << "] || eksperyment: " << j+1 << endl;            
          vector<int> temp;
          int k = 0;
          temp.reserve(nVector[i]);

          for (;k<nVector[i]*percent[m];k++)
            temp.push_back(k);
          
          int min = k;

          for (;k<nVector[i];k++)
            temp.push_back(rand()%(nVector[i]-min+1)+min);
      
          auto start = std::chrono::system_clock::now();
          heap.sort(temp.begin(),temp.end());
          auto end = std::chrono::system_clock::now();
          std::chrono::duration<double> diff =
                  end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
          double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych
                                          // elementów interesuje nas średnia wartość dla nbOfExperiments eksperymentów
          results3 <<"czas sortowania nr." << j <<": " << durationTime << endl;
          time += durationTime;
        }
          cout << endl;
          time /= total_exp;
          results3 << "*******************************" << endl;
          results3 <<"sredni czas: " << time << endl;
          results3 << "*******************************" << endl;
          time =0;
      }
    results3 << endl << endl;
  } 
    results3.close();
    exp_number = 1;    
    return 0;
}

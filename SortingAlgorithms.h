//
// Purpose: Class to implement merge sort, quick sort, and heap sort
//

#ifndef PROJECT_3_SORTALGORITHMS_H
#define PROJECT_3_SORTALGORITHMS_H



#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class SortingAlgorithms {
private:
    void merge(vector<double>& arr, double left, double mid, double right);
public:
    SortingAlgorithms();
    void MergeSort(vector<double>& arr, double left, double right);
    void quick();
    void heap();
    void sleep();
};

#endif //PROJECT_3_SORTALGORITHMS_H
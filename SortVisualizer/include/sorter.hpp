#ifndef _SORTER_HPP_
#define _SORTER_HPP_

#include<vector>
#include "handy.hpp"

void bubbleSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes);

void quickSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes, int from, int to);

void choiceSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes);

void insertionSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes);

void heapify(std::vector<int>& values);
int delete_max(std::vector<int>& values, int k);
void down_max(std::vector<int>& values, int i, int m);
void heapSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes);

#endif // _SORTER_HPP_

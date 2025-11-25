#include "../include/config.hpp"
#include "../include/sorter.hpp"
#include "../include/handy.hpp"
#include "../include/visualizer.hpp"

// バブルソート
void bubbleSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes) {
    for(size_t i=0; i<values.size(); i++) {
        for(size_t j=1; j < values.size()-i; j++) {
            if(values[j-1] > values[j]) {
                std::swap(values[j], values[j-1]);
            }
            updateBox(boxes, values, BOX_SPACING, BOX_Y);
            drawBoxes(l, boxes, HG_BLUE);
        }
    }
}

// クイックソート
void quickSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes, int from, int to) {
    if(from >= to) return;

    int i;
    for(i = from + 1; i <= to; i++)   {
        if(values[from] != values[i]) break;
    }
    if(i > to) return;

    int key = (values[from] > values[i])? values[from] : values[i];

    int pl = from;
    int pr = to;

    while(pl <= pr)  {
        while(values[pl] < key)pl++;
        while(values[pr] > key) pr--;
        if(pl <= pr) {
            std::swap(values[pl], values[pr]);
            updateBox(boxes, values, BOX_SPACING, BOX_Y);
            drawBoxes(l, boxes, HG_BLUE);
            pl++;
            pr--;
        }
    }

    if(from < pr) quickSort(l, values, boxes, from, pr);
    if(pl < to)   quickSort(l, values, boxes, pl, to);
}

// 選択ソート
void choiceSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes) {
    for(size_t i=0; i < values.size()-1; i++) {
        int min = i;
        for(size_t j = i+1; j < values.size(); j++) {
            if(values[j] < values[min]) min = j;
        }
        if(min != i) {
            std::swap(values[min], values[i]);
            updateBox(boxes, values, BOX_SPACING, BOX_Y);
            drawBoxes(l, boxes, HG_BLUE);
        }
    }
}

// 挿入ソート
void insertionSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes) {
    for(size_t i=1; i < values.size(); i++) {
        int d = values[i];
        if(values[i-1] > d) {
            int j = i;
            do {
                values[j] = values[j-1]; j--;
                updateBox(boxes, values, BOX_SPACING, BOX_Y);
                drawBoxes(l, boxes, HG_BLUE);
            } while(j > 0 && values[j-1] > d);
            values[j] = d;
        }
    }
}

// ヒープソート
void heapify(std::vector<int>& values);
int delete_max(std::vector<int>& values, int k);
void down_max(std::vector<int>& values, int i, int m);

void heapSort(Layer& l, std::vector<int>& values, std::vector<Box>& boxes) {
    heapify(values);
    for(int i=values.size()-1; i > 0; i--) {
        values[i] = delete_max(values, i+1);
        updateBox(boxes, values, BOX_SPACING, BOX_Y);
        drawBoxes(l, boxes, HG_BLUE);
    }
}

void heapify(std::vector<int>& values) {
    for(int i=values.size()/2; i >= 0; i--) down_max(values, i, values.size());
}

void down_max(std::vector<int>& values, int i, int m) {
    while(true) {
        int left = 2*i+1;
        if(m <= left) return;

        int right = left+1;
        int j = left;
        if(right < m && values[right] > values[j]) j = right;

        if(values[i] >= values[j]) return;

        std::swap(values[i], values[j]);
        i=j;
    }
}

int delete_max(std::vector<int>& values, int k) {
    int max = values[0];
    values[0] = values[k-1];
    down_max(values, 0, k-1);
    return max;
}


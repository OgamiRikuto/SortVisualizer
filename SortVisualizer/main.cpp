#include "./include/handy.hpp"
#include "./include/random.hpp"
#include "./include/config.hpp"
#include "./include/visualizer.hpp"

#include "./include/sorter.hpp"
#include<iostream>
using namespace std;

#define SORT_DATA 100  // ソートのデータ数

#define WINDOW_WIDTH (BOX_WIDTH * SORT_DATA + BOX_SPACING * (SORT_DATA+2))
#define WINDOW_HEIGHT (BOX_HEIGHT_MIN * SORT_DATA + BOX_SPACING)

enum {
    bubble,
    quick,
    choice,
    insertion,
    heap,
    SORT_WAY_MAX
};

void printValues(const vector<int> values) {
    for(auto& data: values) {
        cout << data << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    const char *errorMessage = "[usage]: ./sort n(0~3)\n";
    const char *sortWay[SORT_WAY_MAX] = {"bubble", "quick", "choice", "insertion", "heap"};
    
    if(argc < 2) {
        cout << errorMessage;
        exit(EXIT_FAILURE);
    }
    
    int way = atoi(argv[1]);

    Window w1(WINDOW_WIDTH, WINDOW_HEIGHT);
    Layer l = Layer();

    vector<int> values = makeRandom(SORT_DATA);

    vector<Box> boxes = initBox(l, values, BOX_WIDTH, BOX_Y);

    switch(way) {
        case bubble:
            w1.setTitle(sortWay[bubble]);
            bubbleSort(l, values, boxes);
            break;
        case quick:
            w1.setTitle(sortWay[quick]);
            quickSort(l, values, boxes, 0, SORT_DATA-1);
            break;
        case choice:
            w1.setTitle(sortWay[choice]);
            choiceSort(l, values, boxes);
            break;
        case insertion:
            w1.setTitle(sortWay[insertion]);
            insertionSort(l, values, boxes);
            break;
        case heap:
            w1.setTitle(sortWay[heap]);
            heapSort(l, values, boxes);
            break;
        default:
            cout << errorMessage;
            exit(EXIT_FAILURE);
            break;
    }

    updateBox(boxes, values, BOX_WIDTH, BOX_Y);
    drawBoxes(l, boxes, HG_SKYBLUE);
    l.lswitch();

    w1.wait();

    return 0;
}



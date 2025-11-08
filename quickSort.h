//
// Created by kiera on 10/28/2025.
//

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "songBase.h"
#include <cmath>
using namespace std;

int partitionHotness(vector<songData*>& base, int low, int high) {
    double pivot = base[high]->artist_hotttnesss;
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (base[j]->artist_hotttnesss >= pivot) {
            i++;
            swap(base[i], base[j]);
        }
    }
    swap(base[i+1], base[high]);
    return (i+1);
}

void quickSortHotness(vector<songData*>& base, int low, int high) {
    if (low < high) {
        int pi = partitionHotness(base, low, high);
        quickSortHotness(base, low, pi-1);
        quickSortHotness(base, pi+1, high);
    }

}

int partitionTempo(vector<songData*>& base, int low, int high) {
    double pivot = base[high]->tempo;
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (base[j]->tempo >= pivot) {
            i++;
            swap(base[i], base[j]);
        }
    }
    swap(base[i+1], base[high]);
    return (i+1);
}

void quickSortTempo(vector<songData*>& base, int low, int high) {
    if (low < high) {
        int pi = partitionTempo(base, low, high);
        quickSortTempo(base, low, pi-1);
        quickSortTempo(base, pi+1, high);
    }

}


int partitionFamiliarity(vector<songData*>& base, int low, int high) {
    double pivot = base[high]->artist_familiarity;
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (base[j]->artist_familiarity >= pivot) {
            i++;
            swap(base[i], base[j]);
        }
    }
    swap(base[i+1], base[high]);
    return (i+1);
}

void quickSortFamiliarity(vector<songData*>& base, int low, int high) {
    if (low < high) {
        int pi = partitionFamiliarity(base, low, high);
        quickSortFamiliarity(base, low, pi-1);
        quickSortFamiliarity(base, pi+1, high);
    }

}

int partitionSongHotness(vector<songData*>& base, int low, int high) {
    double pivot = base[high]->year;
    while (pivot == 0.0) {
        high--;
        pivot = base[high]->year;
    }
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (base[j]->year == 0.0) {
            j++;
        }
        if (base[j]->year < pivot) {
            i++;
            swap(base[i], base[j]);
        }
    }
    swap(base[i+1], base[high]);
    return (i+1);
}

void quickSortSongHotness(vector<songData*>& base, int low, int high) {
    if (low < high) {
        int pi = partitionSongHotness(base, low, high);
        quickSortSongHotness(base, low, pi-1);
        quickSortSongHotness(base, pi+1, high);
    }

}

int partitionAlphabetical(vector<songData*>& base, int low, int high) {
    string pivot = base[high]->title;
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (base[j]->title <= pivot) {
            i++;
            swap(base[i], base[j]);
        }
    }
    swap(base[i+1], base[high]);
    return (i+1);
}

void quickSortAlphabetical(vector<songData*>& base, int low, int high) {
    if (low < high) {
        int pi = partitionAlphabetical(base, low, high);
        quickSortAlphabetical(base, low, pi-1);
        quickSortAlphabetical(base, pi+1, high);
    }
}

int partitionYear(vector<songData*>& base, int low, int high) {
    double pivot = base[high]->year;
    while (pivot == 0.0) {
        high--;
        if (high == -1) {
            return -1;
        }
        pivot = base[high]->year;

    }
    if (high <= low) {
        return low;
    }
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (base[j]->year == 0.0) {
            j++;
            //continue;
        }
        if (base[j]->year < pivot) {
            i++;
            swap(base[i], base[j]);
        }
    }
    swap(base[i+1], base[high]);
    return (i+1);
}

int quickSortYear(vector<songData*>& base, int low, int high) {
    if (low < high) {
        int pi = partitionYear(base, low, high);
        if (pi == -1) {
            cout << "No songs with known years from this Artist!" << endl;
            return -1;
        }
        quickSortYear(base, low, pi-1);
        quickSortYear(base, pi+1, high);
    }
    return 0;
}

// need Merge sort alphabetical
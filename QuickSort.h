//
// Created by kiera on 10/28/2025.
//

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "songBase.h"
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
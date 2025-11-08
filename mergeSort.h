//
// Created by Tyler Schmaling on 11/07/2025.
//

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "songBase.h"
#include <cmath>
using namespace std;


//BIG merge function. (done after sorting)
void merge(vector<songData*>& arr, int left, int mid, int right, double (*get_attribute)(const songData*))  {
    int subArr1 = mid - left + 1; //partitions
    int subArr2 = right - mid;
    vector<songData*> leftArr(subArr1); //temp vectors
    vector<songData*> rightArr(subArr2);

    //data -> temp vectors
    for (int i = 0; i < subArr1; i++)   {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < subArr2; j++)   {
        rightArr[j] = arr[mid + 1 + j];
    }

    int indexSubArr1 = 0;
    int indexSubArr2 = 0;
    int indexMergeArr = left;

    while (indexSubArr1 < subArr1 && indexSubArr2 < subArr2)    {
        if (get_attribute(leftArr[indexSubArr1]) >= get_attribute(rightArr[indexSubArr2]))  {
            arr[indexMergeArr] = leftArr[indexSubArr1];
            indexSubArr1++;
        } else{
            arr[indexMergeArr] = rightArr[indexSubArr2];
            indexSubArr2++;
        }
        indexMergeArr++;
    }

    //if there is any remaining data
    while (indexSubArr1 < subArr1)  {
        arr[indexMergeArr] = leftArr[indexSubArr1];
        indexSubArr1++;
        indexMergeArr++;
    }
    while (indexSubArr2 < subArr2)  {
        arr[indexMergeArr] = rightArr[indexSubArr2];
        indexSubArr2++;
        indexMergeArr++;
    }
}

void mergeSort(vector<songData*>& arr, int left, int right, double (*get_attribute)(const songData*))   {
    if (left >= right)   {
        return; //one or zero elements moment
    }
    int mid = left + (right - left) / 2;

    //fun recursive sorting woo
    mergeSort(arr, left, mid, get_attribute);
    mergeSort(arr, mid + 1, right, get_attribute);

    //merge the halves
    merge(arr, left, mid, right, get_attribute);
}

//getters for the data
inline double getArtistFamiliarity(const songData* data)  {
    return data->artist_familiarity;
}
inline double getArtistHotness(const songData* data)  {
    return data->artist_hotttnesss;
}
inline double getTempo(const songData* data)  {
    return data->tempo;
}
inline double getSongHotness(const songData* data)  {
    return data->song_hotttnesss;
}

//these functions activate the merge sort and are the things being called on in main.cpp
void mergeSortArtistFamiliarity(vector<songData*>& arr, int left, int right)  {
    mergeSort(arr, left, right, getArtistFamiliarity);
}
void mergeSortArtistHotness(vector<songData*>& arr, int left, int right)  {
    mergeSort(arr, left, right, getArtistHotness);
}
void mergeSortTempo(vector<songData*>& arr, int left, int right)  {
    mergeSort(arr, left, right, getTempo);
}
void mergeSortSongHotness(vector<songData*>& arr, int left, int right)  {
    mergeSort(arr, left, right, getSongHotness);
}
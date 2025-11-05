#pragma once
#include "songBase.h"
#include "QuickSort.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


int main() {
    songBase songBase;
    ifstream file("150kSongs.csv");
    if (!file.is_open()) {
        cerr << "Can't open file" << endl;
        return -1;
    }// ensure the working directory is the project folder or this won't run
    if (file.is_open()) { // creates songBase object
        string row;
        string token;
        string skipHeader;
        getline(file, skipHeader); // skips the first row, since it's just labels
        while (getline(file, row)) { // read through the database
            auto newRow = new songData; // initializes new row
            istringstream stream(row);

            getline(stream, token, ','); // read row attributes
            int firstName = token.find('/');
            if (firstName != string::npos) {
                token = token.substr(0, firstName-1);
            }
            newRow->artist_name = token;
            getline(stream, token, ',');
            newRow->title = token;
            getline(stream, token, ',');
            newRow->year = stod(token);
            getline(stream, token, ',');
            newRow->artist_familiarity = stod(token);
            getline(stream, token, ',');
            newRow->artist_hotttnesss = stod(token);
            getline(stream, token, ',');
            newRow->song_hotttnesss = stod(token);
            getline(stream, token, ',');
            newRow->tempo = stod(token);

            songBase.addRow(newRow); // add row to songbase

        }
        file.close();
    }
    // user interface goes here
    int pick;
    auto& base = songBase.getsongData();
    while (true) {
        cout << "Welcome to the Song-Sorter!" << endl;
        cout << "---------------------------" << endl;
        cout << "How would you like to sort?" << endl;
        cout << "1. Sort by Artist Hotness" << endl;
        cout << "2. Sort by Tempo" << endl;
        cout << "3. Sort by Artist Familiarity" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter:" << endl;
        cin >> pick;

        if (pick == 1) {
            quickSortHotness(base, 0, base.size()-1);
            cout << "Sorted by Artist Hotness -" << endl;
            int count = 0;
            vector<string> printed;
            for (int i = 0; i < base.size() && count < 5; i++) {
                if (find(printed.begin(), printed.end(), base[i]->artist_name) == printed.end()) {
                    cout << count+1 << ". " << base[i]->artist_name << " | Artist Hotness:" << base[i]->artist_hotttnesss << endl;
                    count++;
                    printed.push_back(base[i]->artist_name);
                }
            }
            cout << endl;
        }

        else if (pick == 2) {
            quickSortTempo(base, 0, base.size()-1);
            cout << "Sorted by Tempo -" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i+1 << ". " << base[i]->artist_name << " | Song: " << base[i]->title << " | Tempo:" << base[i]->tempo << endl;
            }
            cout << endl;
        }
        else if (pick == 3) {
            quickSortFamiliarity(base, 0, base.size()-1);
            cout << "Sorted by Artist Familiarity -" << endl;
            int count = 0;
            vector<string> printed;
            for (int i = 0; i < base.size() && count < 5; i++) {
                if (find(printed.begin(), printed.end(), base[i]->artist_name) == printed.end()) {
                    cout << count+1 << ". " << base[i]->artist_name << " | Artist Familiarity:" << base[i]->artist_familiarity << endl;
                    count++;
                    printed.push_back(base[i]->artist_name);
                }
            }
            cout << endl;
        }
        else if (pick == 9) {
            cout << "See You Soon!" << endl;
            break;
        }
    }

    for (auto ptr : songBase.getsongData()) {
        delete ptr; // clean up pointers
    }
    return 0;
}
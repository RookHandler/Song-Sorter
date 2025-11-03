#include "songBase.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    songBase songBase;
    ifstream file("150kSongs.csv"); // ensure the working directory is the project folder or this won't run
    if (file.is_open()) { // creates songBase object
        string row;
        string token;
        string skipHeader;
        getline(file, skipHeader); // skips the first row, since it's just labels
        while (getline(file, row)) { // read through the database
            auto newRow = new songData; // initializes new row
            istringstream stream(row);

            getline(stream, token, ','); // read row attributes
            newRow->artist_name = token;
            getline(stream, token, ',');
            newRow->title = token;
            getline(stream, token, ',');
            newRow->year = token;
            getline(stream, token, ',');
            newRow->artist_familiarity = stod(token);
            getline(stream, token, ',');
            newRow->artist_hotttnesss = stod(token);
            getline(stream, token, ',');
            newRow->song_hotttness = stod(token);
            getline(stream, token, ',');
            newRow->tempo = stod(token);

            songBase.addRow(newRow); // add row to songbase

        }
        file.close();
    }

    // user interface goes here

    for (auto ptr : songBase.getsongData()) {
        delete ptr; // clean up pointers
    }
    return 0;
}
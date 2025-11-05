#ifndef SONG_SORTER_SONGBASE_H
#define SONG_SORTER_SONGBASE_H

#include <string>
#include <vector>
using namespace std;

struct songData {
    string artist_name;
    string title;
    double year;
    double artist_familiarity;
    double artist_hotttnesss;
    double song_hotttnesss;
    double tempo;
};

class songBase {
    std::vector<songData*> base;
public:
    std::vector<songData*>& getsongData() {
        return base;
    }
    void addRow(songData* row) {
        base.push_back(row);
    }
};

#endif //SONG_SORTER_SONGBASE_H
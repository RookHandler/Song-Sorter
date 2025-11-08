#include "songBase.h"
#include "menuText.h"
#include "quickSort.h"
#include "mergeSort.h"
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    menuText menu;
    songBase byArtist;
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
    while (true) {
        cout << menu.getintroMenu();
        cin >> menu.introSelection;
        while (menu.introSelection != "ARTIST" && menu.introSelection != "CATALOG" ) {
            if (menu.introSelection == "CLOSESORTER") {
                cout << menu.getexitMessage() << endl;
                for (auto ptr : songBase.getsongData()) {
                    delete ptr; // clean up pointers
                }
                return 0;
            }
            cout << "Not a valid selection, try again!" << endl;
            cin >> menu.introSelection;
        }
        if (menu.introSelection == "ARTIST") {
            cout << "What artist?" << ' ';
            //cin >> menu.artist;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, menu.artist);
            byArtist.getsongData().clear();
            for (auto c : songBase.getsongData()) {
                if (c->artist_name.find(menu.artist) != string::npos) {
                    byArtist.addRow(c);
                }
            }
            cout << "Search by..." << endl;
            cout << menu.getartistAttributeMenu();
            cin >> menu.attributeSelection;
            cout << "How many songs?" << ' ';
            cin >> menu.songNum;
            cout << "MERGE or QUICK (sort)" << ' ';
            cin >> menu.sortType;
            if (menu.attributeSelection == "1") {
                if (menu.sortType == "QUICK") {
                    quickSortSongHotness(byArtist.getsongData(), 0, byArtist.getsongData().size()-1);
                    cout << "Sorted by Song Hotness -" << endl;
                    int songCount = 0;
                    int max = stoi(menu.songNum);
                    int num = 1;
                    for (int i = byArtist.getsongData().size()-1; i > byArtist.getsongData().size()-max-1 && i >= 0; i--) {
                        if (byArtist.getsongData()[i]->song_hotttnesss == 0.0) {
                            max++;
                            continue;
                        }
                        cout << num << ". " << byArtist.getsongData()[i]->artist_name << " | Song: " << byArtist.getsongData()[i]->title << " | Song Hotness: " << byArtist.getsongData()[i]->song_hotttnesss << endl;
                        num++;
                        songCount++;
                    }
                    if (stoi(menu.songNum) > byArtist.getsongData().size()) {
                        cout << "This Artist only has " << songCount << " songs." << endl;
                    }
                    cout << endl;
                }
                else if (menu.sortType == "MERGE") {
                    cout << "Need Tyler's Code" << endl;
                }
            }
            else if (menu.attributeSelection == "2") {
                if (menu.sortType == "QUICK") {
                    int checker = quickSortYear(byArtist.getsongData(), 0, byArtist.getsongData().size()-1);
                    if (checker != -1) {
                        cout << "Sorted by Year-" << endl;
                        int songCount = 0;
                        for (int i = 0; i < stoi(menu.songNum) && i < byArtist.getsongData().size(); i++) {
                            cout << i+1 << ". " << byArtist.getsongData()[i]->artist_name << " | Song: " << byArtist.getsongData()[i]->title << " | Year: " << byArtist.getsongData()[i]->year << endl;
                            songCount++;
                        }
                        if (stoi(menu.songNum) > byArtist.getsongData().size()) {
                            cout << "This Artist only has " << songCount << " songs." << endl;
                        }
                        cout << endl;
                    }
                }
                else if (menu.sortType == "MERGE") {
                    cout << "Need Tyler's Code" << endl;
                }
            }
            else if (menu.attributeSelection == "3") {
                if (menu.sortType == "QUICK") {
                    quickSortTempo(byArtist.getsongData(), 0, byArtist.getsongData().size()-1);
                    cout << "Sorted by Tempo -" << endl;
                    int songcount = 0;
                    for (int i = 0; i < stoi(menu.songNum) && i < byArtist.getsongData().size(); i++) {
                        cout << i+1 << ". " << byArtist.getsongData()[i]->artist_name << " | Song: " << byArtist.getsongData()[i]->title << " | Tempo:" << byArtist.getsongData()[i]->tempo << endl;
                        songcount++;
                    }
                    if (stoi(menu.songNum) > byArtist.getsongData().size()) {
                        cout << "This Artist only has " << songcount << " songs." << endl;
                    }
                    cout << endl;
                }
                else if (menu.sortType == "MERGE") {
                    cout << "Need Tyler's Code" << endl;
                }
            }
        }
        else if (menu.introSelection == "CATALOG") {
            cout << "Search by..." << endl << menu.getcatalogAttributeMenu();
            cin >> menu.attributeSelection;
            cout << "How many songs?" << ' ';
            cin >> menu.songNum;
            while (stoi(menu.songNum) > 200) {
                cout << "\nSong number must be less than 200! \nHow many songs? " << endl;
                cin >> menu.songNum;
            }
            cout << "MERGE or QUICK (sort)" << ' ';
            cin >> menu.sortType;

            // display results
            if (menu.attributeSelection == "1") {
                if (menu.sortType == "QUICK") {
                    quickSortSongHotness(songBase.getsongData(), 0, songBase.getsongData().size()-1);
                    cout << "Sorted by Song Hotness -" << endl;
                    int count = 0;
                    vector<string> printed;
                    int num = 1;
                    int max = stoi(menu.songNum);
                    for (int i = songBase.getsongData().size()-1; i > songBase.getsongData().size()-max-1 && i >= 0; i--) {
                        if (songBase.getsongData()[i]->song_hotttnesss == 0.0) {
                            max++;
                            continue;
                        }
                        if (find(printed.begin(), printed.end(), songBase.getsongData()[i]->artist_name) == printed.end()) {
                            cout << num << ". " << songBase.getsongData()[i]->artist_name << " | Song Title: " << songBase.getsongData()[i]->title << " | Song Hotness: " << songBase.getsongData()[i]->song_hotttnesss << endl;
                            num++;
                            count++;
                            printed.push_back(songBase.getsongData()[i]->artist_name);
                        }
                    }
                    cout << endl;
                }
                else if (menu.sortType == "Merge") {
                    cout << "Need Tyler's code" << endl;
                }
            }
            else if (menu.attributeSelection == "2") {
                if (menu.sortType == "QUICK") {
                    quickSortFamiliarity(songBase.getsongData(), 0, songBase.getsongData().size()-1);
                    cout << "Sorted by Artist Familiarity -" << endl;
                    int count = 0;
                    vector<string> printed;
                    for (int i = 0; i < songBase.getsongData().size() && count < stoi(menu.songNum); i++) {
                        if (find(printed.begin(), printed.end(), songBase.getsongData()[i]->artist_name) == printed.end()) {
                            cout << count+1 << ". " << songBase.getsongData()[i]->artist_name << " | Song Title: " << songBase.getsongData()[i]->title << " | Artist Familiarity: " << songBase.getsongData()[i]->artist_familiarity << endl;
                            count++;
                            printed.push_back(songBase.getsongData()[i]->artist_name);
                        }
                    }
                    cout << endl;
                }
                else if (menu.sortType == "Merge") {
                    cout << "Need Tyler's code" << endl;
                }
            }
            else if (menu.attributeSelection == "3") {
                if (menu.sortType == "QUICK") {
                    quickSortHotness(songBase.getsongData(), 0, songBase.getsongData().size()-1);
                    cout << "Sorted by Artist Hotness -" << endl;
                    int count = 0;
                    vector<string> printed;
                    for (int i = 0; i < songBase.getsongData().size() && count < stoi(menu.songNum); i++) {
                        if (find(printed.begin(), printed.end(), songBase.getsongData()[i]->artist_name) == printed.end()) {
                            cout << count+1 << ". " << songBase.getsongData()[i]->artist_name << " | Song Title: " << songBase.getsongData()[i]->title << " | Artist Hotness:" << songBase.getsongData()[i]->artist_hotttnesss << endl;
                            count++;
                            printed.push_back(songBase.getsongData()[i]->artist_name);
                        }
                    }
                    cout << endl;
                }
                else if (menu.sortType == "MERGE") {
                    cout << "Need Tyler's code" << endl;
                }
            }
            else if (menu.attributeSelection == "4") {
                if (menu.sortType == "QUICK") {
                    quickSortYear(songBase.getsongData(), 0, songBase.getsongData().size()-1);
                    cout << "Sorted by Year" << endl;
                    for (int i = 0; i < stoi(menu.songNum); i++) {
                        cout << i+1 << ". " << songBase.getsongData()[i]->artist_name << " | Song: " << songBase.getsongData()[i]->title << " | Year:" << songBase.getsongData()[i]->year << endl;
                    }
                    cout << endl;
                }
                else if (menu.sortType == "MERGE") {
                    cout << "Need Tyler's code" << endl;
                }
            }
            else if (menu.attributeSelection == "5") {
                if (menu.sortType == "QUICK") {
                    quickSortTempo(songBase.getsongData(), 0, songBase.getsongData().size()-1);
                    cout << "Sorted by Tempo -" << endl;
                    for (int i = 0; i < stoi(menu.songNum); i++) {
                        cout << i+1 << ". " << songBase.getsongData()[i]->artist_name << " | Song: " << songBase.getsongData()[i]->title << " | Tempo:" << songBase.getsongData()[i]->tempo << endl;
                    }
                    cout << endl;
                }
                else if (menu.sortType == "MERGE") {
                    cout << "Need Tyler's code" << endl;
                }
            }
        }
        string search;
        cout << "Enter SEARCH to search again, or exit the program by any other input" << endl;
        cin >> search;
        if (search != "SEARCH") {
            cout << menu.getexitMessage() << endl;
            for (auto ptr : songBase.getsongData()) {
                delete ptr; // clean up pointers
            }
            return 0;
        }
    }

}
/*
mergeSortArtistFamiliarity(songBase.getsongData(), 0, songBase.getsongData().size() - 1); //runs merge sort
                cout << "Sorted by Artist Familiarity -" << endl;
                int count = 0;
                vector<string> printed;
                for (int i = 0; i < songBase.getsongData().size() && count < stoi(menu.songNum); i++)   {
                    if (find(printed.begin(), printed.end(), songBase.getsongData()[i]->artist_name) == printed.end()) {
                    cout << count+1 << ". " << songBase.getsongData()[i]->artist_name << " | Song Title: " << songBase.getsongData()[i]->title << " | Artist Familiarity: " << songBase.getsongData()[i]->artist_familiarity << endl;
                    count++;
                    printed.push_back(songBase.getsongData()[i]->artist_name);
                    }
                }
                cout << endl;
 */
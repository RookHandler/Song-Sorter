#ifndef SONG_SORTER_MENUTEXT_H
#define SONG_SORTER_MENUTEXT_H
#include <iostream>
#pragma once

using namespace std;

class menuText {
    string introMenu = "|||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "|               Welcome to Song Sorter!           |\n"
    "| A project by Brooks Chandler, Tyler Schmaling,  |\n"
    "|               and Kieran Parnell                |\n"
    "|                                                 |\n"
    "|   Search entire catalog or just one artist?     |\n"
    "|        Type CATALOG or ARTIST to choose!        |\n"
    "|                                                 |\n"
    "|     Enter CLOSESORTER to close the program      |\n"
    "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    string catalogAttributeMenu = "|||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "| 1. Year                                         |\n"
    "| 2. Artist familiarity                           |\n"
    "| 3. Artist hotness                               |\n"
    "| 4. Song hotness                                 |\n"
    "| 5. Tempo                                        |\n"
    "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    string artistAttributeMenu = "|||||||||||||||||||||||||||||||||||||||||||||||||||\n"
    "| 1. Year                                         |\n"
    "| 2. Song hotness                                 |\n"
    "| 3. Tempo                                        |\n"
    "|||||||||||||||||||||||||||||||||||||||||||||||||||\n";

    string exitMessage = "Thanks for using Song Sorter!"; // can be expanded/modified to something nicer?
public:
    string introSelection;
    string attributeSelection;
    string artist;
    string songNum;
    string sortType;
    string getintroMenu() {
        return introMenu;
    }
    string getcatalogAttributeMenu() {
        return catalogAttributeMenu;
    }
    string getartistAttributeMenu() {
        return artistAttributeMenu;
    }
    string getexitMessage() {
        return exitMessage;
    }
};

#endif //SONG_SORTER_MENUTEXT_H
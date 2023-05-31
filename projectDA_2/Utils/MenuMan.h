#ifndef UNTITLED2_MENUMAN_H
#define UNTITLED2_MENUMAN_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MenuMan {
public:

    /**
        * @brief Function that will be invoked to create each menu
        * @note Time-complexity -> O(n)
        * @param title menu title
        * @param options menu options
        * @return user selection (n)
    */

    static int createMenu(const string& title, vector<string> options);
};


#endif //UNTITLED2_MENUMAN_H

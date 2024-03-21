#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(){
    int count = 0;
    smatch matches;
    smatch dmatches;
    regex red ("\d\d?\ red");
    regex blue ("\d\d?\ blue");
    regex green ("\d\d?\ green");
    regex game ("Game\ \d\d?\d?");
    regex digits ("\d\d?\d?");
    bool possible = True;
    for (string line; getline(cin, line);){
        regex_search(line, matches, red); //match reds
        for (string match; matches;){
            regex_search(match, dmatches, digits);
            for (string dgt; dmatches;){
                if (stoi(dgt) > 12){
                    possible = False;
                }
            }
        }
        regex_search(line, matches, green); //match greens
        for (string match; matches;){
            regex_search(match, dmatches, digits);
            for (string dgt; dmatches;){
                if (stoi(dgt) > 13){
                    possible = False;
                }
            }
        }
        regex_search(line, matches, blue); //match blues
        for (string match; matches;){
            regex_search(match, dmatches, digits);
            for (string dgt; dmatches;){
                if (stoi(dgt) > 14){
                    possible = False;
                }
            }
        }
        if (possible){
            regex_search(line, matches, game);
            regex_search(matches[0], dmatches, digits);
            count += stoi(dmatches[0]);
        }
        cout << line << endl;
    }
    return 0;
}
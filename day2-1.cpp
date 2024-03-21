#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(){
    int count = 0;
    smatch matches;
    smatch dmatches;
    vector<regex> exps {regex("\\d+\\ red"), regex("\\d+\\ blue"), regex("\\d+\\ green")};
    regex red ("\\d+\\ red");
    regex blue ("\\d+\\ blue");
    regex green ("\\d+\\ green");
    regex game ("Game\\ \\d\\d*");
    regex digits ("\\d\\d*");
    bool possible = true;
    for (string line; getline(cin, line);){
        int thresh = 12;
        for (regex r : exps){
            string::const_iterator head (line.cbegin());
            while (regex_search(head, line.cend(), matches, r)){
                string round = matches[0];
                if (regex_search(round, dmatches, digits)){
                    string dgt = dmatches[0];
                    possible = possible & (stoi(round) <= thresh);
                }
                thresh++;
                head = matches.suffix().first;
            }
        }
        if (possible){
            regex_search(line, matches, game);
            string gnum = matches[0];
            regex_search(gnum, dmatches, digits);
            string val = dmatches[0];
            count += stoi(val);
        }
        cout << line << endl;
    }
    return 0;
}
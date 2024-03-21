#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(){
    int count = 0;
    smatch matches;
    smatch dmatches;
    vector<regex> exps {regex("\\d+\\ red"), regex("\\d+\\ green"), regex("\\d+\\ blue")};
    regex game ("Game\\ \\d\\d*");
    regex digits ("\\d\\d*");
    for (string line; getline(cin, line);){
        int thresh = 12;
        bool possible = true;
        for (regex r : exps){
            string::const_iterator head (line.cbegin());
            while (regex_search(head, line.cend(), matches, r) & possible){
                string round = matches[0];
                if (regex_search(round, dmatches, digits)){
                    string dgt = dmatches[0];
                    possible = possible & (stoi(round) <= thresh);
                }
                head = matches.suffix().first;
            }
            thresh++;
        }
        if (possible){
            regex_search(line, matches, game);
            string gnum = matches[0];
            regex_search(gnum, dmatches, digits);
            string val = dmatches[0];
            count += stoi(val);
        }
    }
    cout << count << endl;
    return 0;
}
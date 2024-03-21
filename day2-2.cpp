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
        int i = 0;
        vector<int> maxs {0, 0, 0};
        for (regex r : exps){
            string::const_iterator head (line.cbegin());
            while (regex_search(head, line.cend(), matches, r)){
                string round = matches[0];
                if (regex_search(round, dmatches, digits)){
                    string dgt = dmatches[0];
                    maxs[i] = max(maxs[i], stoi(dgt));
                }
                head = matches.suffix().first;
            }
            i++;
        }
        int power = accumulate(begin(maxs), end(maxs), 1, multiplies());
        count += power;
    }
    cout << count << endl;
    return 0;
}
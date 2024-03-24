#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

int getPartVals(string prev, string curr, string line){
    regex symbs_ptn ("[^0-9.\n]");
    regex numbs_ptn ("\\d\\d*");
    smatch store_numbers;
    smatch store_symbols;
    string num;
    string slice;
    bool found;
    int count = 0;
    int idx = 0;
    int end_idx = 0;
    string::const_iterator head = curr.cbegin();
    while(regex_search(head, curr.cend(), store_numbers, numbs_ptn)){
        found = false;
        num = store_numbers[0];
        idx = curr.find(num, end_idx);
        end_idx = min(idx + num.length() + 1, curr.length());
        idx = max(0, idx-1);
        int len = end_idx - idx;
        for (string s : vector<string> {prev, curr, line}){
            if (s.length() == 0){
                continue;
            }
            slice = s.substr(idx, len);
            found = (regex_search(slice, store_symbols, symbs_ptn) | found);
            if (found){
                break;
            }
        }
        if (found){
            count += stoi(num);
        }
        head = store_numbers.suffix().first;
    }
    return count;
}

int main(){
    int count = 0;
    string prev;
    string curr;
    getline(cin, curr);
    for (string line; getline(cin, line);){
        count += getPartVals(prev, curr, line);
        prev = curr;
        curr = line;
    }
    count += getPartVals(prev, curr, "");
    cout << to_string(count) << endl;
    return 0;
}
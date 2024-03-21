#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

// this solution uses a lot of reversing and un-reversing
// I think a better solution could be found using negative lookahead
// which I may implement later
int main(){
    int count = 0;
    smatch matches;
    string base = "zero|one|two|three|four|five|six|seven|eight|nine|0|1|2|3|4|5|6|7|8|9"; 
    regex ptn (base);
    reverse(base.begin(), base.end());
    regex rvs_ptn (base);
    unordered_map<string, string> digits = {
        {"zero", "0"},
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };
    for (string line; getline(cin, line);){
        regex_search(line, matches, ptn);
        string first = matches[0];
        reverse(line.begin(), line.end());
        regex_search(line, matches, rvs_ptn);
        string last = matches[0];
        if (first.length() > 1){
            first = digits[first];
        }
        if (last.length() > 1){
            reverse(last.begin(), last.end());
            last = digits[last];
        }
        count += stoi(first + last);
    }
    cout << count << endl;
    return 0;
}
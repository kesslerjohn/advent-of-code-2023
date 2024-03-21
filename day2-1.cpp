#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(){
    smatch matches;
    regex red ("\d\d?\ red");
    regex blue ("\d\d?\ blue");
    regex green ("\d\d?\ green");
    regex game ("Game\ \d\d?\d?")
    for (string line; getline(cin, line);){
        cout << line << endl;
    }
    return 0;
}
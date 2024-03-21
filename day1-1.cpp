#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file("input.txt");
    int count = 0;
    string line = "";
    if (file.is_open()){
        while(getline(file, line)){
            size_t st_idx = line.find_first_of("0123456789");
            string first = line.substr(st_idx, 1);
            reverse(line.begin(), line.end());
            size_t end_idx = line.find_first_of("0123456789");
            string last =  line.substr(end_idx, 1);
            string linecmp = first+last;
            int cval = stoi(linecmp);
            count += cval;
        }
    }
    cout << count << endl;
    return 0;
}
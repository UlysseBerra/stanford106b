#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string fileName = "vectors.txt";
    vector<int> count(26, 0);

    ifstream in;
    in.open(fileName.c_str());
    if (in.fail()) cout << ("Couldn't read '" + fileName + "'") << endl;

    string line;

    while (true) {
        getline(in, line);
        if (in.fail()) break;

        for (int i = 0; i < line.length(); i++) line[i] = tolower(line[i]);

        for (int i = 0; i < line.length(); i++) {
            int index = line[i] - 'a';
            if(index >= 0 && index < 26) {
                int prevTotal = count[index];
                count[index] = prevTotal + 1;
            }
        }
    }

    in.close();

    for (int i = 0; i < count.size(); i++) {
        char currLetter = 'a' + i;
        cout << currLetter << ": " << count[i] << endl;
    }
}
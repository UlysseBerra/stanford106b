#include <iostream>

using namespace std;

string CensorString1(string text, string remove);
void CensorString2(string &text, string remove);

string text = "Stanford University";

int main() {
    CensorString2(text, "st");
    cout << text << endl;

    return 0;
}

string CensorString1(string text, string remove) {
    int pos;
    string result = text;
    
    for (int i = 0; i < remove.length(); i++) {
        while (true) {
            pos = result.find(remove[i]);
            if (pos == string::npos) // No more of this char present
                break;
            else {
                // We want stringUntilCh + stringAfterCh
                result = result.substr(0, pos) +
                result.substr(pos + 1);
            }
        }
    }
    return result;
}

void CensorString2(string &text, string remove) {
    for (int i = 0; i < remove.length(); i++) {
        int pos;

        while (true) {
            pos = text.find(remove[i]);
            if (pos == string::npos) // No more of this char present
                break;
            else {
                // We want stringUntilCh + stringAfterCh
                text = text.replace(pos, 1, "");
            }
        }
    }
}
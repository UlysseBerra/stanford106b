#include <iostream>

using namespace std;
struct eMailMsg;
void removeSpam(vector<eMailMsg> &arr);
vector<eMailMsg> arr;

// struct eMailMsg {
//     string to;
//     string from;
//     string msg;
//     string subject;
//     int date;
//     int time;
// };

struct eMailMsg {
    vector<string> to;
    string from;
    string msg;
    string subject;
    int date;
    int time;
};

void removeSpam(vector<eMailMsg> &arr) {
    for (int i = arr.size() - 1; i >= 0; i--) {
        eMailMsg mail = arr[i];
            if (mail.subject.find("SPAM") == 0) {
                arr.erase(arr.begin() + i);
            }
    }
}

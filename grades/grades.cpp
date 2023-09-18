#include <iostream>
#include <fstream>

using namespace std;

struct stats;
stats analyzer(string fileName);

struct stats {
    int high;
    int low;
    double avg;
};

int main() {
    cout << "Average: " << analyzer("grades.txt").avg << endl;
    cout << "Highest: " << analyzer("grades.txt").high << endl;
    cout << "Lowest: " << analyzer("grades.txt").low << endl;

    return 0;
}

stats analyzer(string fileName) {
    stats stats;
    stats.low = 101;
    stats.high = -1;

    int total = 0;
    int count = 0;

    ifstream in;
    in.open(fileName.c_str());
    if (in.fail()) cout << ("Couldn't read '" + fileName + "'") << endl;

    while (true) {
        int num;
        in >> num;

        if (in.fail()) break;

        if (num < stats.low) stats.low = num;
        if (num > stats.high) stats.high = num;

        total += num;
        count++;
    }

    stats.avg = double(total)/count;
    in.close();

    return stats;
}
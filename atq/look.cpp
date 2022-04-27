#include <bits/stdc++.h>
using namespace std;

void read_file(ifstream &input_file, vector<pair<string, string>> &problems) {
    string tmp_date;
    string tmp_url;

    while (input_file >> tmp_date >> tmp_url) {
        problems.push_back({tmp_date, tmp_url});
    }
}

void out_console(vector<pair<string, string>> &problems) {
    for (int i = problems.size() - 1; 0 <= i; i--) {
        auto [date, url] = problems[i];

        cout << i + 1 << ", " << date << ' ' << url << endl << endl;
    }
}

int main() {
    ifstream input_file("/home/user01/atcoder/atq/queue_1.txt");
    vector<pair<string, string>> problems;

    read_file(input_file, problems);

    out_console(problems);
}

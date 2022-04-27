#include <bits/stdc++.h>
using namespace std;

void read_file(ifstream &input_file, vector<pair<string, string>> &problems) {
    string tmp_date;
    string tmp_url;

    while (input_file >> tmp_date >> tmp_url) {
        problems.push_back({tmp_date, tmp_url});
    }
}

void add_problem(ifstream &input_file, vector<pair<string, string>> &problems) {
    string date;
    string url;

    cin >> date >> url;

    date.insert(2, "/");
    date.insert(5, "/");

    problems.push_back({date, url});
}

void out_console(vector<pair<string, string>> &problems) {
    for (int i = problems.size() - 1; 0 <= i; i--) {
        auto [date, url] = problems[i];

        cout << i + 1 << ", " << date << ' ' << url << endl << endl;
    }
}

void out_file(ofstream &output_file, vector<pair<string, string>> &problems) {
    for (int i = 0; i < problems.size(); i++) {
        auto [date, url] = problems[i];

        output_file << date << ' ' << url << "\n\n";
    }
}

int main() {
    ifstream input_file("/home/user01/atcoder/atq/queue_1.txt");
    vector<pair<string, string>> problems;

    read_file(input_file, problems);

    add_problem(input_file, problems);

    sort(problems.begin(), problems.end());

    out_console(problems);

    ofstream output_file("/home/user01/atcoder/atq/queue_1.txt");

    out_file(output_file, problems);
}

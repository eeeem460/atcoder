#include <bits/stdc++.h>
using namespace std;

struct problem {
    string index;
    string name;
    string date;
    string url;

    // edge v;
    // v.to, v.w でメンバ変数を呼び出す
    problem(string index, string name, string date, string url) : index(index), name(name), date(date), url(url) {
    }
    // graph g(n); で n 頂点のグラフを宣言
    // graph[from].push_back(edge(to, w)) の形で使う
};

string get_today_date() {
    time_t t = time(nullptr);
    const tm *localTime = localtime(&t);

    std::stringstream s;
    s << setw(2) << setfill('0') << localTime->tm_year - 100;
    s << '/';
    s << setw(2) << setfill('0') << localTime->tm_mon + 1;
    s << '/';
    s << setw(2) << setfill('0') << localTime->tm_mday;

    return s.str();
}

void read_file(ifstream &input_file, vector<pair<string, string>> &problems) {
    string index;
    string problem_name;
    string date;
    string url;

    while (input_file >> index >> date >> url) {
        problems.push_back({date, url});
    }
}

void push_problem(ifstream &input_file, vector<pair<string, string>> &problems) {
    string date;
    string url;

    cin >> date >> url;

    date.insert(2, "/");
    date.insert(5, "/");

    problems.push_back({date, url});
}

void out_console(vector<pair<string, string>> &problems) {
    string today_date = get_today_date();

    for (int i = problems.size() - 1; 0 <= i; i--) {
        auto [date, url] = problems[i];

        if (date <= today_date) {
            cout << "\033[31m" << i + 1 << ", " << date << ' ' << url << endl << endl << "\033[m";
        }
        else {
            cout << i + 1 << ", " << date << ' ' << url << endl << endl;
        }
    }
}

void out_file(ofstream &output_file, vector<pair<string, string>> &problems) {
    for (int i = 0; i < problems.size(); i++) {
        auto [date, url] = problems[i];

        string problem_name = "";
        for (int j = url.size() - 1; j >= 0; j--) {
            if (url[j] == '/') {
                break;
            }
            else if ('a' <= url[j] and url[j] <= 'z') {
                problem_name.push_back(toupper(url[j]));
            }
            else {
                problem_name.push_back(url[j]);
            }
        }

        reverse(problem_name.begin(), problem_name.end());

        output_file << i + 1 << ", " << problem_name << "  " << date << ' ' << url << "\n\n";
    }
}

void push() {
    ifstream input_file("/home/user01/atcoder/atq/queue_1.txt");
    vector<pair<string, string>> problems;

    read_file(input_file, problems);

    push_problem(input_file, problems);

    sort(problems.begin(), problems.end());

    out_console(problems);

    ofstream output_file("/home/user01/atcoder/atq/queue_1.txt");

    out_file(output_file, problems);
}

void look() {
    ifstream input_file("/home/user01/atcoder/atq/queue_1.txt");
    vector<pair<string, string>> problems;

    read_file(input_file, problems);

    sort(problems.begin(), problems.end());

    out_console(problems);

    ofstream output_file("/home/user01/atcoder/atq/queue_1.txt");

    out_file(output_file, problems);
}

// void pop(int index) {
//     ifstream input_file("/home/user01/atcoder/atq/queue_1.txt");
//     vector<pair<string, string>> problems;

//     read_file(input_file, problems);

//     cout << "Do you erase" << name << "?" << endl;

//     problems.erase(problems.begin() + (index - 1));

//     out_console(problems);

//     ofstream output_file("/home/user01/atcoder/atq/queue_1.txt");

//     out_file(output_file, problems);
// }

int main(int argc, char *argv[]) {
    ifstream input_file("/home/user01/atcoder/atq/queue_1.txt");
    vector<pair<string, string>> problems;

    read_file(input_file, problems);

    string command = (string)argv[1];
    if (command == "push") {
        push();
    }
    else if (command == "look") {
        look();
    }
    // else if (command == "pop" and argc == 2) {
    //     pop((int)argv[2]);
    // }
    else {
        cout << "command eroor" << endl;
    }

    ofstream output_file("/home/user01/atcoder/atq/queue_1.txt");

    out_file(output_file, problems);
}

#include <iostream>
#include <vector>
// #include <string>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> s(h);
    std::vector<int> x;
    std::vector<int> y;
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'o') {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    int ans = 1'000'000;
    ans += abs(x[0] - x[1]);
    ans += abs(y[0] - y[1]);

    std::cout << ans << '\n';
}

#include <bits/stdc++.h>


int main() {
    int q;
    std::cin >> q;
    std::multiset<int> ms;

    while (q--) {
        int Q;
        std::cin >> Q;
        if (Q == 1) {
            int x;
            std::cin >> x;
            ms.insert(x);
        }
        else if (Q == 2) {
            int x, c;
            std::cin >> x >> c;
            for (int i = 0; i < c; i++) {
                auto itr = ms.find(x);
                if (itr != ms.end()) {
                    // ひとつ削除するときは ms.erase(ms.find(x))
                    ms.erase(itr);
                }
                else {
                    break;
                }
            }
        }
        else {
            int mn = *ms.begin();
            int mx = *ms.rbegin();
            std::cout << mx - mn << '\n';
        }
    }
}


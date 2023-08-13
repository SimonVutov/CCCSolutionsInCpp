#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int main () {
    int N = 0;
    cin >> N;

    vector<int> pages;
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int page;
        cin >> page;
        pages.push_back(page);
    }

    int inconveniences = 0;

    int printedAnOddFirst = 1;

    for (int i = 0; i < N; i++) {
        if (pages[i] % 2 != 0 && pages[i] != -1){
            ans.push_back(i + 1);
            inconveniences += floor(pages[i] / 2);
            pages[i] = -1;
            printedAnOddFirst = 0;
            break;
        }
    }

    for (int i = 0; i < (int)pages.size(); i++) {
        if (pages[i] % 2 == 0 && pages[i] != -1){
            ans.push_back(i + 1);
            inconveniences += floor(pages[i] / 2) - 1 + printedAnOddFirst;
            pages[i] = -1;
            i--;
        }
    }

    for (int i = 0; i < (int)pages.size(); i++) {
        if (pages[i] % 2 != 0 && pages[i] != -1){
            ans.push_back(i + 1);
            inconveniences += floor(pages[i] / 2);
            pages[i] = -1;
            i--;
        }
    }

    cout << inconveniences << endl;

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
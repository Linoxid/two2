#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <string>

using namespace std; 
vector<string> generateStrings(int n) {
    vector<string> strings;
    for (int i = 0; i < n; i++) {
        strings.push_back(to_string(i));
    }
    return strings;
}
size_t hashString(const string& str) {
    return hash<string>{}(str);
}
int main() {
    vector<string> strings = generateStrings(10000);
    vector<size_t> hashCodes;
    for (const string& str : strings) {
        hashCodes.push_back(hashString(str));
    }

    auto start = chrono::high_resolution_clock::now();
    sort(strings.begin(), strings.end());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> stringSortingTime = end - start;
    start = chrono::high_resolution_clock::now();
    sort(hashCodes.begin(), hashCodes.end());
    end = chrono::high_resolution_clock::now();
    chrono::duration<double> hashCodeSortingTime = end - start;

    cout << "Время сортировки строк:" << " " << stringSortingTime.count() << " " << "секунд" << endl;
    cout << "Время сортировки хэш-кодов:" << " " << hashCodeSortingTime.count() << " " << "секунд" << endl;

    return 0;
}

#include <iostream> 
#include <vector> 
#include <string> 
#include <random> 
#include <algorithm> 
#include <unordered_set> 
using namespace std; 
vector<string> generateRandomStrings(int N, int l) { 
    vector<string> strings; 
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis('a', 'z'); 
     
    for (int i = 0; i < N; ++i) { 
        string str; 
        for (int j = 0; j < l; ++j) { 
            str += dis(gen); 
        } 
        strings.push_back(str); 
    } 
     
    return strings; 
} 
 
vector<string> removeDuplicates(const vector<string>& strings) { 
    unordered_set<string> uniqueStrings(strings.begin(), strings.end()); 
    vector<string> result(uniqueStrings.begin(), uniqueStrings.end()); 
    return result; 
} 
 
int main() { 
    int N = 10000; 
    int l = 3; 
     
    vector<string> randomStrings = generateRandomStrings(N, l); 
    vector<string> uniqueStrings = removeDuplicates(randomStrings); 
     
    cout << "Сгенерированные строки:" << endl; 
    for (const auto& str : randomStrings) { 
        cout << str << endl; 
    } 
     
    cout << "Уникальные строки:" << endl; 
    for (const auto& str : uniqueStrings) { 
        cout << str << endl; 
    } 
     
    return 0; 
}

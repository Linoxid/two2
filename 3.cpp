#include <iostream>


using namespace std;
struct Person {
    double height;
    double weight;
};

int main() {
    int N;
    cout << "Введите количество людей: ";
    cin >> N;
    Person* people = new Person[N];
    for (int i = 0; i < N; i++) {
        cout << "Введите рост и вес для человека " << i + 1 << ": ";
        cin >> people[i].height >> people[i].weight;
    }

    for (int i = 0; i < N; i++) {
        cout << "Данные о человеке " << i + 1 << ": "
                  << "Рост: " << people[i].height << " м, "
                  << "Вес: " << people[i].weight << " кг" << endl;
    }
    delete[] people;

    return 0;
}

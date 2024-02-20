#include <iostream>

using namespace std;
struct Person {
    double height;
    double weight; 
};

double Ave(const Person* people, int N, double targetHeight) {
    double sumWeight = 0.0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (people[i].height == targetHeight) {
            sumWeight += people[i].weight;
            count++;
        }
    }

    if (count > 0) {
        return sumWeight / count;
    } else {
        return 0.0;
    }
}

int main() {
    int N;
    cout << "Введите количество людей: ";
    cin >> N;

    Person* people = new Person[N];


    for (int i = 0; i < N; i++) {
        cout << "Введите рост и вес для человека " << i + 1 << ": ";
        cin >> people[i].height >> people[i].weight;
    }

    double targetHeight;
    cout << "Введите рост, для которого нужно найти средний вес: ";
    cin >> targetHeight;

    double averageWeight = Ave(people, N, targetHeight);
    cout << "Средний вес для роста " << targetHeight << " м: " << averageWeight << " кг" << endl;

    delete[] people;

    return 0;
}

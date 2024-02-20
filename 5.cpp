#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    vector<string> words = {"кот", "собака", "дом", "машина", "программа"};
    string word = words[rand() % words.size()];
    int attempts = 6;
    string guessedLetters;
    string guessedWord(word.length(), '_');

    while (attempts > 0 && guessedWord != word) {
        cout << "Угадайте слово: " << guessedWord << endl;
        cout << "Осталось попыток: " << attempts << endl;
        cout << "Уже угаданные буквы: " << guessedLetters << endl;

        char guess;
        cout << "Введите букву: ";
        cin >> guess;

        if (guessedLetters.find(guess) != string::npos) {
            cout << "Вы уже угадывали эту букву!" << endl;
            continue;
        }

        guessedLetters += guess;

        if (word.find(guess) != string::npos) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == guess) {
                    guessedWord[i] = guess;
                }
            }
        } else {
            attempts--;
            cout << "Неверная буква!" << endl;
        }
    }

    if (guessedWord == word) {
        cout << "Поздравляю, вы угадали слово \"" << word << "\"!" << endl;
    } else {
        cout << "Вы проиграли! Загаданное слово было \"" << word << "\"." << endl;
    }

    return 0;
}

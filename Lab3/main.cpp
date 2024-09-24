#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char ch) {
    char vowels[] = "aeiou";
    return strchr(vowels, ch) != nullptr;
}

int countVowels(const char* word) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isVowel(word[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char input[256];
    char word[256];
    char* token;
    char minVowelWord[256];  
    int minVowelCount = -1; 

    cout << "Введіть рядок слів: ";
    cin.getline(input, 256);

    token = strtok(input, " ");
    while (token != nullptr) {
        strcpy(word, token); 
        int vowelCount = countVowels(word);

        if (minVowelCount == -1 || vowelCount < minVowelCount) {
            strcpy(minVowelWord, word);
            minVowelCount = vowelCount;
        }

        token = strtok(nullptr, " ");
    }

    if (minVowelCount != -1) {
        cout << "Слово з найменшою кількістю голосних: " << minVowelWord << endl;
        cout << "Кількість голосних: " << minVowelCount << endl;
    }

    return 0;
}

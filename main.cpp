#include <bits/stdc++.h>
using namespace  std;

void SliceIntoWords (string text, vector<string> &words)
{
    string word = "";
    for (char symb : text)
    {
        if (isalpha(symb) && word.size() < 30) word += symb;
        else if (!word.empty())
        {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) words.push_back(word);
}

bool IsConsonant(char c)
{
    switch (tolower(c))
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return false;
        default:
            return true;
    }
}

int MaxConsonantSubstring(string word)
{
    int maxLeangth = 0;
    int curLeangth = 0;

    for (char c : word)
    {
        if (IsConsonant(c)) curLeangth++;
        else
        {
            maxLeangth = max(curLeangth, maxLeangth);
            curLeangth = 0;
        }
    }

    return max(curLeangth, maxLeangth);
}

int main()
{
    ifstream myfile("mytext.txt");
    if (!myfile.is_open()) {
        cerr << "Не вдалося відкрити файл." << endl;
        return 1;
    }

    string text;
    vector<string> words;

    while (getline(myfile, text))
    {
        SliceIntoWords(text, words);
    }
    myfile.close();

    int maxSubstringInText = 0;
    for (string v : words)
    {
        cout << v;
        cout << " : " << MaxConsonantSubstring(v) << '\n';
        maxSubstringInText = max(maxSubstringInText, MaxConsonantSubstring(v));
    }

    unordered_set<string> uniqueWords;
    for (string word : words)
    {
        if (MaxConsonantSubstring(word) == maxSubstringInText) uniqueWords.insert(word);
    }

    cout << '\n' << "Words:\n";
    for (string word : uniqueWords)
    {
        cout << word << '\n';
    }

    cout << "max sub = " << maxSubstringInText << '\n';

    return 0;
}

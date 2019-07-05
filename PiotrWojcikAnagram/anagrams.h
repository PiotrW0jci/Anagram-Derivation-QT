#ifndef ANAGRAMS_H
#define ANAGRAMS_H

#include <iostream>
#include <QObject>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace  std;

class anagrams{

public:
    QString derivation(string x,string y);
    map<char, int> letterCounting(string &word, map<char, int> counterLetters);
    bool isDervation(map<char, int> &comparer, map<char, int> &toCompare);
    void anagramsPath(map<char, int> &comparer, map<int, vector<pair<string, map<char, int>>>> &words, int floor, string &path);
    char addedLetter(map<char, int> &comparer, map<char, int> &toCompare);
    struct temp {

      map<char, int>comparer;
      map<int, vector<pair<string, map<char, int>>>> words;
      string path;
    };
    int letter;
    map<int, vector<string>> paths;
    string newPath;

};

#endif // ANAGRAMS_H

#include "anagrams.h"


using namespace std;




map<char, int> anagrams::letterCounting(string &word, map<char, int> counterLetters) {


  for (int i = 0; i < word.length(); i++) {
    counterLetters.at(word[i])++;
  }
  return counterLetters;
}

bool anagrams::isDervation(map<char, int> &comparer, map<char, int> &toCompare) {
    /*
     * Compares all letters from two words, because one word is shorter by 1 letter,
     * so if the shorter word has more letters then we do not have an anagram
     * e.g app and apps is anagram derivation
     *
     *     a=1  <=  a=1 = true
     *     b=0  <=  b=0 = true
     *     ...  <= ...  = true
     *     p=2  <=  p=2 = true
     *     ...  <= ...  = true
     *     s=0  <=  s=1 = true
     *
     *     app and apks is not anagram derivation
     *     a=1  <= a=1  = true
     *     b=0  <=  b=0 = true
     *     ...  <= ...  = true
     *    *p=2  <= p=1  = false
     *     ...  <=  ... = true
     *     s=0  <= s=1  = true
     *
     *
     */
  for (int i = 0; i < 26; i++)
  {
    if (comparer[97 + i] > toCompare[97 + i])
      return false;

  }
  return true;
}

char anagrams::addedLetter(map<char, int> &comparer, map<char, int> &toCompare) {
    /*
     * Compares all letters from two words,  one word is shorter by 1 letter,
     * so if we  subtract longer than the shorter only one letter return 1;
     * e.g apps and app
     *     a=1  -  a=1 = 0
     *     b=0  -  b=0 = 0
     *     ...  -  ... = 0
     *     p=2  -  p=2 = 0
     *     ...  -  ... = 0
     *     s=1  -  s=0 = 1
     *
     *     only s=1  then its the added letter
     *
     *     when we find this letter we break function because there is no more
     *
     *
     */

  for (int i = 0; i < 26; i++)
  {
    letter = toCompare[97 + i] - comparer[97 + i];
    if (letter == 1)
      return char(97 + i);

  }
}

void anagrams:: anagramsPath(map<char, int> &comparer, map<int, vector<pair<string, map<char, int>>>> &words, int floor, string &path) {
  vector<temp> temp;

  /*
   * I go through each floor starting from the smallest.
   * I am looking for anagrams and I do the same for each one of my anagrams on the next floor(next floor is list of one letter longer words)
   * I do it recursively.
   *  e.g
   *  app ,appl, appr,apple,appre
   *  .
   *
   *         ->appl                      ->appl->apple              ->appl->apple
   *  app  ->                    app  ->                     app  ->
   *         ->appr                      ->appr                     ->appr->appr
   *
   * for each time i save path by word lenght
   */

  for (auto y : words[floor]) {

    if (isDervation(comparer, y.second)) {
        /*
         *
         */

      newPath = path + " + " + addedLetter(comparer, y.second) + " =  " + y.first;
      paths[floor].push_back(newPath);
      temp.push_back({ y.second,words,newPath });
    }
  }
  floor++;
  for (auto i : temp) {
    anagramsPath(i.comparer, i.words, floor, i.path);
  }


}


QString anagrams::derivation(string word,string pathFile)
{
    /*
     * Faster intput output
     */
    ios_base::sync_with_stdio(false);


    /*
     * Contener for all words from dictionary
     */
    map<int, vector<pair<string, map<char, int>>>> words;

    /*
     * Contener for all letter in word
     */
    map<char, int> counterLetters, comparer;

    /*
     * Initializes values , all letter =0;
     */

    for (int i = 0; i < 26; i++)
    {
      counterLetters[97 + i] = 0;
    }

    string temp;


    /*
     * Open and loading words into container
     * load words by size
     * every word length has its own unique place
     * in the function "anagramsPath" I call them floors
     */
    fstream dictionary;

    dictionary.open(pathFile, ios::in);
    if(dictionary.good() == true){
         while(!dictionary.eof()){
             getline(dictionary, temp);
             words[int(temp.size())].push_back(make_pair(temp, letterCounting(temp, counterLetters)));
         }

         dictionary.close();
     }




   /*
    * Counting letters in first word
    */
    comparer = letterCounting(word, counterLetters);

    /*
     * A function that finds all anagrams
     */
    anagramsPath(comparer, words, word.size()+1, word);

    string result;
    /*
     * Pring all anagram paths.We print all elements of vector of the last element map , because it stores the longest of the words found.
     */
    if(!paths.empty())
    for (auto i : (*(--paths.end())).second)

        result+=i+R"()" "\n";

    QString qstr = QString::fromStdString({result});
    return qstr;

}

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

string removeShortWords(string phrase, int length);

int main(){
    
    string str; // String that user inputs
    cout << "Enter string: ";
    getline(cin, str);
    
    int minLen; // Minimum length of words in user's string
    cout << "Enter minimum length of words: ";
    cin >> minLen;
    
    string newStr = removeShortWords(str, minLen); // User's string with removed small words
    
    cout << "Updated string: " << newStr << endl;

}

/*
 removeShortWords takes a string and a minimum length of words as parameters. The function
 checks every word in the string (words are split by a whitespace), and adds them to updated
 string newStr, only if the word's length is greater or equal to minLen.
 */
string removeShortWords(string str, int minLen) {
    
    str = str + " "; // Adding whitespace to the string, so the function can recognize last word
    string delimiter = " "; // Whitespace is the delimiter
    size_t pos = str.find(delimiter); // Position of the first whitespace we find

    string word; // The word we are currently checking
    string newStr = ""; // Updated string

    while (pos != string::npos) {
        
        word = str.substr(0, pos);
        
        if (word.length() >= minLen){
            newStr += word + " ";
        }
        
        str.erase(0, pos + 1);
        pos = str.find(delimiter);
    }
    
    return newStr;
}

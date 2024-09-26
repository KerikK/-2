#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool isValidIP(const string& ip) {
    vector<string> parts;
    stringstream ss(ip);
    string part;
    while (getline(ss, part, '.')) parts.push_back(part);
    if (parts.size() != 4) return false;
    for (auto& segment : parts) {
        if (segment.empty() || (segment.size() > 1 && segment[0] == '0')) return false;
        for (char c : segment) if (!isdigit(c)) return false;
        if (stoi(segment) > 255) return false;
    }
    return true;
}

void replaceSpacesWithTabs(string& str) {
    for (char& c : str) if (c == ' ') c = '\t';
}

int countWords(const string& str) {
    stringstream ss(str); string word; int count = 0;
    while (ss >> word) ++count;
    return count;
}

bool isPalindrome(const string& str) {
    string clean, rev;
    for (char c : str) if (isalnum(c)) clean += tolower(c);
    rev = clean; reverse(rev.begin(), rev.end());
    return clean == rev;
}

string nextUkrainianLetter(char letter) {
    string alphabet = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
    size_t pos = alphabet.find(letter);
    return (pos == string::npos || pos == alphabet.size() - 1) ? "Далі букв немає" : string(1, alphabet[pos + 1]);
}

int main() {
    string ip, sentence; vector<string> surnames(5);
    cout << "Enter IP address: "; cin >> ip;
    cout << (isValidIP(ip) ? "Valid IP.\n" : "Invalid IP.\n");

    cout << "Enter 5 surnames:\n";
    for (auto& surname : surnames) cin >> surname;
    sort(surnames.rbegin(), surnames.rend());
    for (auto& s : surnames) cout << s << endl;

    cin.ignore();
    cout << "Enter a string: "; getline(cin, sentence);
    replaceSpacesWithTabs(sentence);
    cout << "String with tabs: " << sentence << endl;

    cout << "Number of words: " << countWords(sentence) << endl;

    cout << "Palindrome check: " << (isPalindrome(sentence) ? "Palindrome.\n" : "Not a palindrome.\n");

    char letter;
    cout << "Enter Ukrainian letter (UPPER CASE): "; cin >> letter;
    cout << "Next letter: " << nextUkrainianLetter(letter) << endl;

    return 0;
}

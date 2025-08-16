#include <iostream>
#include <cctype>   // for tolower()
using namespace std;

// Function to manually convert to lowercase
void toLowerCase(string &str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;  // ASCII shift
        }
    }
}

// Function to reverse a string without reverse()
string reverseString(const string &str) {
    string rev = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        rev += str[i];
    }
    return rev;
}

// Function to check if string is palindrome
bool isPalindrome(const string &str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Function to count vowels (skip consecutive repeats)
int countVowels(const string &str) {
    int count = 0;
    char prev = '\0'; // store last vowel to avoid consecutive repeat count

    for (int i = 0; i < (int)str.length(); i++) {
        char ch = str[i];
        bool isVowel = (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');

        if (isVowel && ch != prev) {
            count++;
            prev = ch;
        } else if (!isVowel) {
            prev = '\0'; // reset when non-vowel comes
        }
    }
    return count;
}

// ---------------- MAIN PROGRAM ----------------
int main() {
    string input;
    cout << "Enter a string (no spaces): ";
    cin >> input;

    // Check for whitespace (though cin skips spaces, still validate)
    for (char ch : input) {
        if (isspace(ch)) {
            cout << "? Warning: Input contains whitespace. Exiting." << endl;
            return 0;
        }
    }

    // Convert to lowercase
    toLowerCase(input);

    // Processing
    string reversed = reverseString(input);
    int length = input.length();
    int vowels = countVowels(input);
    bool palindrome = isPalindrome(input);

    // Final Output
    cout << "\n=== String Analysis Report ===" << endl;
    cout << "Original:  " << input << endl;
    cout << "Reversed:  " << reversed << endl;
    cout << "Length:    " << length << endl;
    cout << "Vowels:    " << vowels << endl;
    cout << "Palindrome: " << (palindrome ? "YES" : "NO") << endl;

    return 0;
}

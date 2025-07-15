class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        int vowel = 0, consonant = 0;

        for (char c : word) {
            if (!isalnum(c)) return false; // not alphanumeric

            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    vowel++;
                else
                    consonant++;
            }
        }

        return (vowel >= 1 && consonant >= 1);
    }
};

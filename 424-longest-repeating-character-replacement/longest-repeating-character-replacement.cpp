class Solution {
public:
    // Function to return the length of the longest substring that can be made of repeating characters
    // by replacing at most k characters
    int characterReplacement(string s, int k) {
        // Frequency array for A-Z
        vector<int> freq(26, 0);
        
        // Left and right pointers of sliding window
        int left = 0, right = 0;

        // Tracks the count of the most frequent character in current window
        int maxCount = 0;

        // Stores the maximum length of valid window
        int maxLength = 0;

        // Iterate through the string with right pointer
        while (right < s.size()) {

            // Increment the frequency of current character
            freq[s[right] - 'A']++;

            // Update maxCount with the max frequency seen so far
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // If the current window needs more than k replacements, move left
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update the maximum window length
            maxLength = max(maxLength, right - left + 1);
            
            // Move right pointer forward
            right++;
        }

        // Return the maximum valid window length
        return maxLength;
    }
};
class Solution {
public:
    ListNode* reverse(ListNode*); // keep prototype if you used earlier - not used here

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<int> spaceIdx;
        vector<string> ans;
        string currWord = "";
        int currLen = 0;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int s = word.size();

            // if word fits in current line (we allow adding a single space after word;
            // if later next word doesn't fit we'll finalize and remove trailing space)
            if (currLen + s <= maxWidth) {
                currWord += word;
                currLen += s;

                // ====== CHANGE 1:
                // Original: if(currLen+1<maxWidth) ...
                // Fix: add a single separating space whenever there's still room (< = maxWidth-1).
                // This makes the invariants simpler: we keep one-space gaps recorded in spaceIdx.
                if (currLen < maxWidth) {
                    currWord += ' ';
                    spaceIdx.push_back(currLen); // position where the single space sits (0-based)
                    currLen++;
                }
            } 
            else {
                // word did NOT fit -> finalize current line (currWord currently holds the line)
                // If last char is a space, remove it and update structures (safe-check spaceIdx)
                if (!currWord.empty() && currWord.back() == ' ') {
                    currWord.pop_back();
                    currLen--;
                    if (!spaceIdx.empty()) spaceIdx.pop_back();
                }

                // ====== CHANGE 2: handle single-word-in-line case
                if (spaceIdx.empty()) {
                    // Only one word in the line -> left-justify (pad spaces at end)
                    currWord.append(maxWidth - currLen, ' ');
                    ans.push_back(currWord);
                } else {
                    // Distribute remaining spaces across gaps
                    int remaining = maxWidth - currLen; // spaces to distribute
                    int gaps = spaceIdx.size();
                    int dist = remaining / gaps;
                    int leftDist = remaining % gaps;

                    // ====== CHANGE 3: inserting shifts indices -> account for already inserted chars
                    int added = 0; // total extra spaces inserted so far
                    for (int k = 0; k < gaps; ++k) {
                        int idx = spaceIdx[k] + added; // adjust by added
                        int addHere = dist + (leftDist > 0 ? 1 : 0);
                        if (leftDist > 0) leftDist--;
                        currWord.insert(idx, addHere, ' ');
                        added += addHere;
                    }
                    ans.push_back(currWord);
                }

                // reset and re-process current word (is not placed yet)
                currWord = "";
                currLen = 0;
                spaceIdx.clear();
                i -= 1; // re-evaluate same word in next iteration
                continue;
            }
        }

        // ====== CHANGE 4: handle last line (left-justified)
        if (!currWord.empty()) {
            // if trailing space exists, remove it
            if (!currWord.empty() && currWord.back() == ' ') {
                currWord.pop_back();
            }
            // left-justify: single space between words (already present), then pad end
            int need = maxWidth - (int)currWord.size();
            if (need > 0) currWord.append(need, ' ');
            ans.push_back(currWord);
        }

        return ans;
    }
};

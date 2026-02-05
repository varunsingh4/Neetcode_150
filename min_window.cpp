string minWindow(string s, string t) {
    // If either string is empty, no valid window exists
    if (s.empty() || t.empty()) return "";

    // need[c] = how many more times character c is required
    // Initialize with frequencies of t
    vector<int> need(128, 0);
    for (char c : t) need[c]++;

    // Number of characters (including duplicates) still needed
    int required = t.size();

    // Left pointer of sliding window
    int left = 0;

    // Track best (minimum) window found so far
    int bestLen = INT_MAX;
    int bestStart = 0;

    // Right pointer expands the window
    for (int right = 0; right < s.size(); right++) {

        char c = s[right];

        // If this character was still needed (>0),
        // then we satisfy one required character
        if (need[c] > 0) {
            required--;
        }

        // Decrease count:
        // - needed chars move toward zero
        // - extra chars become negative (allowed)
        need[c]--;

        // When required == 0, window contains all characters of t
        while (required == 0) {

            // Update minimum window if current is smaller
            int windowLen = right - left + 1;
            if (windowLen < bestLen) {
                bestLen = windowLen;
                bestStart = left;
            }

            // Try to shrink window from the left
            char leftChar = s[left];

            // Put left character back into need
            need[leftChar]++;

            // If after incrementing, this char becomes needed again (>0),
            // the window is no longer valid
            if (need[leftChar] > 0) {
                required++;
            }

            // Move left pointer to shrink window
            left++;
        }
    }

    // If no valid window was found, return empty string
    return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
}

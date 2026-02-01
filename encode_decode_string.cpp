vector<string> decode(string s) {
    vector<string> a;      // This will store all decoded strings
    int j = 0;             // Pointer to traverse the encoded string

    // Loop until we reach the end of the encoded string
    while (j < s.size()) {

        // Step 1: Skip the delimiter '#'
        // Each encoded string starts with '#'
        if (s[j] == '#') {
            j++;
        }

        // Step 2: Read the length of the next string
        // Length may have multiple digits (e.g., 12, 100)
        int len = 0;
        while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
            // Convert digit character to integer
            len = len * 10 + (s[j] - '0');
            j++;
        }

        // Step 3: Extract the string of length 'len'
        // 'j' is now at the start of the actual word
        string word = s.substr(j, len);
        a.push_back(word);

        // Step 4: Move the pointer forward by 'len'
        // This brings us to the next encoded block
        j = j + len;
    }

    // Return the decoded list of strings
    return a;
}

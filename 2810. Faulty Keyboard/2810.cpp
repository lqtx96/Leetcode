// https://leetcode.com/problems/faulty-keyboard

// Deque
// Time: O(n)
// Space: O(n)

class Solution {
public:
	string finalString(string s) {
		deque<char> editedText;
		bool isInversed = false;
		
		for (const char c : s) {
			if (c == 'i')
				isInversed = !isInversed;
			else {
				if (isInversed)
					editedText.push_front(c);
				else
					editedText.push_back(c);
			}
		}

    if (isInversed)
        return string{editedText.rbegin(), editedText.rend()};
    else
        return string{editedText.begin(), editedText.end()};
  }
};

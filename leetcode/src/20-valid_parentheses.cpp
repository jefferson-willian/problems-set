class Solution {
 public:
  // Time Complexity  = O(n)
  // Space Complexity = O(1) 
  //
  // n : string size.
  bool isValid(const string& s) {
    // Hold all opening parenthses characters.
    stack<char> st;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
      // If the character is a closing parentheses then the top of the stack
      // must match the character.
      switch(s[i]) {
        case ')': if (st.empty() || st.top() != '(') return false; st.pop();
          break;
        case '}': if (st.empty() || st.top() != '{') return false; st.pop();
          break;
        case ']': if (st.empty() || st.top() != '[') return false; st.pop();
          break;
        default : st.push(s[i]);
      }
    }

    // To be valid then all opening characters had to be processed.
    return st.empty();
  }
};

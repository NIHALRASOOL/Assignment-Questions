/*Given a string str of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of k characters. The value of a string is defined as the sum of squares of the count of each distinct character present in the string. Return the minimum possible required value.*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
int minStringValue(string str, int k) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : str) {
        freq[ch]++;
    }

    // Step 2: Store frequencies in a vector and sort in descending order
    vector<int> freqValues;
    for (auto it : freq) {
        freqValues.push_back(it.second);
    }

    sort(freqValues.rbegin(), freqValues.rend());  // Sort in descending order

    // Step 3: Use a stack to process the most frequent characters first
    stack<int> st;
    for (int f : freqValues) {
        st.push(f);
    }

    // Step 4: Remove k characters
    while (k > 0 && !st.empty()) {
        int topFreq = st.top();
        st.pop();
        topFreq--; 
        k--;

        if (topFreq > 0) {
            st.push(topFreq);  
        }

        vector<int> temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        sort(temp.rbegin(), temp.rend());
        for (int f : temp) {
            st.push(f);
        }
    }

    // Step 5: Compute final sum of squares
    int result = 0;
    while (!st.empty()) {
        int count = st.top();
        st.pop();
        result += (count * count);
    }

    return result;
}

int main() {
    string str = "abccc";
    int k = 1;
    cout << "Output: " << minStringValue(str, k) << endl;

    str = "aabcbcbcabcc";
    k = 3;
    cout << "Output: " << minStringValue(str, k) << endl;

    return 0;
}

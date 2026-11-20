class Solution {
public:
    int ladderLength(string bword, string eword, vector<string>& lst) {
        queue<pair<string,int>> q;
        q.push({bword,1});

        unordered_set<string> st(lst.begin(),lst.end());

        st.erase(bword);

        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;

            q.pop();
            if(word==eword) return steps;

            for(int i=0;i<word.size();i++)
            {
                int original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }

        return 0;
    }
};

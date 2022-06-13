lli longest_palindrome_prefix(string s) 
{
    string kmprev = s;
    std::reverse(kmprev.begin(), kmprev.end());
    string kmp = s + "#" + kmprev;

    vector<int> lps(kmp.size(), 0);   // lps[i] = longest suffix length for substring kmp[0..i] where the suffix == prefix
    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];

        while (prev_idx > 0 && kmp[i] != kmp[prev_idx])
        {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }

    return lps[lps.size() - 1];
}
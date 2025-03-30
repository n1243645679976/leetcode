std::vector<int> z_algorithm(const std::string& s) {
    int n = s.size();
    std::vector<int> Z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            Z[i] = std::min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            ++Z[i];
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}
std::string replace(const std::string& a, const std::string b, const std::string c) {
    std::string combined = b + "_" + a;
    int b_len = b.size();
    std::vector<int> Z = z_algorithm(combined);
    std::string result;
    result.reserve(a.size());
    int i = 0;
    for (int pos = b_len + 1; pos < combined.size(); ++pos) {
        if (Z[pos] == b_len) {
            result.append(a.begin() + i, a.begin() + (pos - b_len - 1));
            result.append(c);
            i = pos - b_len - 1 + b_len;
        }
    }
    result.append(a.begin() + i, a.end());
    return result;
}
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    int start = 0;
    int end = str.find(delimiter);
    while (end != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
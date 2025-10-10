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
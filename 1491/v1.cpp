class Solution {
public:
    double average(vector<int>& salary) {
        return (accumulate(salary.begin(), salary.end(), 0) - *(min_element(salary.begin(), salary.end())) - *(max_element(salary.begin(), salary.end()))) / 1.0 / (salary.size() - 2);
    }
};
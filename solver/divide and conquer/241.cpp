class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int l = expression.size();

        vector<int> ways;
        for (int i = 0; i < l; ++i)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (auto l : left)
                {
                    for (auto r : right)
                    {
                        if (expression[i] == '+') ways.push_back(l + r);
                        else if (expression[i] == '-') ways.push_back(l - r);
                        else ways.push_back(l * r);
                    }
                }
            }
        }
        if (ways.empty()) ways.push_back(stoi(expression));
        return ways;
    }
};
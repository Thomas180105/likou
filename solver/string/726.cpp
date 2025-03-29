//考验基本功的一道题，和之前一道刷过的题很像
//写完之后看了一下记录，是和Leetcode 394（Medium）很像，当时写的是一个很丑的要遍历两次的递归
//还是写的不熟练，两天以及一周之后重做，递归和迭代（基于栈）分别实现一次
class Solution {
private:
    string formula;
    int pos;
    int len;

    string getAtom()
    {
        string atom;
        if (pos < len && formula[pos] >= 'A' && formula[pos] <= 'Z')
        {
            atom += formula[pos++];
            while (pos < len && formula[pos] >= 'a' && formula[pos] <= 'z') atom += formula[pos++];
        }
        return atom;
    }

    int getCount()
    {
        int count = 0;
        while (pos < len && isdigit(formula[pos])) count = count * 10 + (formula[pos++] - '0');
        return count == 0 ? 1 : count;
    }

    map<string, int> parseFormula()
    {
        map<string, int> atoms;
        while (pos < len && formula[pos] != ')')
        {
            if (formula[pos] == '(')
            {
                pos++; // 跳过 '('
                map<string, int> subAtoms = parseFormula();
                pos++; // 跳过 ')'
                int count = getCount();
                for (auto& atom : subAtoms) atoms[atom.first] += atom.second * count;
            }
            else
            {
                string atom = getAtom();
                int count = getCount();
                atoms[atom] += count;
            }
        }
        return atoms;
    }

public:
    string countOfAtoms(string formula)
    {
        this->formula = formula;
        pos = 0;
        len = formula.size();

        map<string, int> atoms = parseFormula();

        string result;
        for (auto& atom : atoms)
        {
            result += atom.first;
            if (atom.second > 1) result += to_string(atom.second);
        }
        return result;
    }
};
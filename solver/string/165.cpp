class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size(), len2 = version2.size();
        int pos1 = 0, pos2 = 0;
        while(pos1 < len1 || pos2 < len2)
        {
            int num1 = 0, num2 = 0;

            //获得num1以及num2
            while(pos1 < len1 && version1[pos1] != '.') num1 = num1 * 10 + (version1[pos1++] - '0');
            ++pos1;//跳过.
            while(pos2 < len2 && version2[pos2] != '.') num2 = num2 * 10 + (version2[pos2++] - '0');
            ++pos2;

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }
};
//用时：22：26
// class Solution {
// public:
//     string maximumBinaryString(string binary) {
//         int len = binary.size();
//         for (int i = 0, len = binary.size(); i < len; ++i)
//         {
//             if (binary[i] == '1') continue;
//             if (i && binary[i - 1] == '0') binary[i - 1] = '1';
//             if (i >= 2 && binary[i - 2] == '0' && binary[i - 1] == '1') binary[i - 2] = '1', binary[i - 1] = '0', binary[i] = '1';
//         }
//         return binary;
//     }
// };

class Solution {
public:
    string maximumBinaryString(string binary) {
        for (int i = 0, len = binary.size(), pre = -1; i < len; ++i)
        {
            if (binary[i] == '1') continue;
            if (pre == -1) {pre = i; continue;}
            //pre 0111...10 i -> 0011...11-> 1011..11
            binary[i] = '1';
            binary[pre] = '1';
            binary[pre + 1] = '0';
            ++pre;
        }
        return binary;
    }
};
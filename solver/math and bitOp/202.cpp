// 最直觉的方法：
// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_set<int> bag;
//         bool res;
//         while(true)
//         {
//             if (n == 1) {res = true; break;}
//             if (bag.find(n) != bag.end()) {res = false; break;}
//             bag.insert(n);
//             int tmp = 0;
//             while(n)
//             {
//                 tmp += (n % 10) * (n % 10);
//                 n /= 10;
//             }
//             n = tmp;
//         }
//         return res;
//     }
// };

// 更空间友好的做法：
class Solution {
private:
    int transformer(int n)
    {
        int res = 0;
        while(n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = transformer(slow);
            fast = transformer(fast);
            fast = transformer(fast);
        } while(slow != fast);

        return slow == 1;
    }
};
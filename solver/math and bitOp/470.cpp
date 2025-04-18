// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int res;
        do{
            res = rand7() + 7 * (rand7() - 1);
        } while(res > 40);

        return res % 10 + 1;
    }
};
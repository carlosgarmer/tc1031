class Solution {
public:
    bool isPalindrome(int x) {
          std::string str = "";
          int numAct, it = 0;
          char charAct;

          if (x < 0){
            return false;
          }
          while(x > 0){
            it++;
            numAct = x % 10;
            x /= 10;

            charAct = numAct + 48;

            str += charAct;

          }

          for (int i = 0; i < it/2; i++){
            if (str[i] != str[it-1-i]) {
              return false;

            }
          }
        return true;
    }
};
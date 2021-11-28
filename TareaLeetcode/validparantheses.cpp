class Solution {
public:
    bool isValid(string s) {
        std::string cadena;
  char temp;
  if (s.length()<=1){
    return false;
  }
  for(int i = 0; i <= s.length()-1;i++){
    if(s[i] == '{' || s[i] == '[' || s[i] == '('){
      cadena += s[i];
    }
    else{
      switch (s[i]){
        case '}':
          temp = '{';
          break;
        case ')':
          temp = '(';
          break;
        case ']':
          temp = '[';
          break;
      }
        if (cadena.empty() || temp != cadena[cadena.length()-1]){
          return false;
        }
        else{
          cadena.pop_back();
        }
    }
  }
  if(cadena.empty()) return true;
  else return false;
    }
};
class Solution {
public:
    int reverse(int x) {
      bool isNegativo = false;
      long long int xnuevo = x;
      // Revisar si es negativo y hacerlo positivo
      if (xnuevo < 0){
        xnuevo *= -1;
        isNegativo = true;
      }
      // Poner el número en reveresa
      long long int numAct, res = 0;

      while (xnuevo != 0){
        numAct = xnuevo % 10;
        xnuevo /= 10;

        res *= 10;
        res += numAct;

      }
      std::cout<<res<<'\n';
      if(res > 2147483647){
        return 0;
      } 

      if (isNegativo){
        res *= -1;
      }

      return res;
    }
};
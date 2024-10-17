#include "Pow.h"

int Pow(int a, int b)
{
    if (b == 0)
    {
        return 1;  // 지수가 0이면 어떤 수라도 1을 반환
    }
    int tmp = Pow(a, b / 2);  // 재귀 호출을 통해 지수를 절반으로 나누어 계산
    if (b % 2 == 0)
    {
        return tmp * tmp;  // 지수가 짝수일 때, tmp를 제곱하여 반환
    }
    else
    {
        return a * tmp * tmp;  // 지수가 홀수일 때, a를 한 번 더 곱한 후 반환
    }
}
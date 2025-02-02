#include<iostream>

#ifdef __AVX__
    #include <immintrin.h>
#else
    #warning No AVX support - will not compile
#endif

int main(int argc, char **argv)
{
    __m256 a = _mm256_set_ps(8.0, 7.0, 6.0, 5.0,4.0, 3.0, 2.0, 1.0);
    __m256 b = _mm256_set_ps(18.0, 17.0, 16.0, 15.0, 14.0, 13.0, 12.0, 11.0);
    __m256 c = _mm256_add_ps(a, b);

    float d[8];
    _mm256_store_ps(d, c);
    for(int i = 0;i<=6;i++)
    std::cout << "result equals" << d[i] << ",";
    std::cout << d[7] <<std::endl;

    return 0; 
}
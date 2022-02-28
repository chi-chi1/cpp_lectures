#include <array>
#include <cstdio>

int main()
{
        std::array<char, 32> name {};
        std::printf("enter your name");
        std::scanf("%s", name.begin());
        std::printf("%s/n", name.begin());



            
}
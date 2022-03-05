#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;    
///生产随机数
int main(int argc, char const *argv[])
{
    auto seed=high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<>dis(-10,100);
    for (int i = 0; i < 10000; i++)
    {
        cout<<dis(gen)<<' '; 
    }
    return 0;
}

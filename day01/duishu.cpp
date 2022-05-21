#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
///生产随机数
///
int main(int argc, char const *argv[])
{
    int n,m;
    auto seed = high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<> dis(0, 10000);
    cout << "请输入生产的随机数个数：";
    n=dis(gen); 
    m=dis(gen);
    cout << n << " " << m << endl;

    // int st, ed;
    // for (int i = 0; i < m; i++)
    // {
    //     st=dis(gen)%n;
    //     ed=dis(gen)%n;
    //     cout<<st<<" "<<ed<<endl;
    // }
    

    return 0;
}

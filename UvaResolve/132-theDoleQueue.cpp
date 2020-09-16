//

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int chose(vector<int> v, int d, int k, int vk)
{
    int n = v.size();

    while (k)
    {
        vk = (vk + d + n) % n;

        if (v[vk])
            --k;
    }

    return vk;
}
int main()
{
    int n, k, m;

    while (cin >> n >> k >> m && n != 0)
    {
        vector<int> v(n);
        int vk = -1, vm = n;

        for (int i = 0; i < n; ++i)
            v[i] = i + 1;

        while (n)
        {
        	vk = chose(v, 1, k, vk);
            vm = chose(v, -1, m, vm);
            v[vk] = 0;
            v[vm] = 0;

            if (vk != vm)
            {
                std::cout << setw(3) << setfill(' ') << vk + 1 << setw(3) << setfill(' ') << vm + 1;
                n -= 2;
            }
            else
            {
	            std::cout << setw(3) << setfill(' ') << vk + 1;
	           
                --n;
            }

            if (n)
                std::cout << ",";
        }

        std::cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const long long multicases = 0, mod = 1000000007LL;
namespace DS
{
    struct DSU
    {
        int N;
        vector<int> fa, sz;
        DSU(int n = 100005) : N(n)
        {
            fa.resize(n + 1), sz.resize(n + 1, 1);
            for (int i = 1; i <= n; ++i)
                fa[i] = i;
        }
        int root(int x) { return ((fa[x] == x) ? (x) : (fa[x] = root(fa[x]))); }
        void merge(int a, int b)
        {
            int A = root(a), B = root(b);
            if (sz[A] > sz[B])
                swap(A, B);
            fa[A] = B, sz[B] += sz[A];
        }
        bool same(int a, int b) { return root(a) == root(b); }
        int size(int x) { return sz[root(x)]; }
    };
    template <typename T, typename U>
    struct Pair
    {
        T first;
        U second;
    };
    template <typename T, typename U>
    Pair<T, U> make_pair(T a, U b)
    {
        Pair<T, U> p;
        p.first = a, p.second = b;
        return p;
    }
};
using namespace DS;
namespace Algo
{
    template <typename T>
    T quick_pow(T a, T b, T m = mod)
    {
        T res = 1;
        a %= m;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    template <typename S, typename T>
    vector<T> discrete(vector<S> vec, bool (*cmp)(S, S) = less<S>())
    {
        vector<S> b = vec;
        vector<T> ans;
        sort(vec.begin(), vec.end(), cmp);
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for (int i = 0; i < b.size(); ++i)
            ans.push_back(lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin());
        return ans;
    }
    template <typename T>
    T binary_search(T left, T right, bool (*checker)(T), bool smallest = 1)
    {
        while (1)
        {
            T mid = (left + right) / 2;
            if (left + 2 >= right)
            {
                if (smallest)
                {
                    if (checker(left))
                        return left;
                    else if (checker(mid))
                        return mid;
                    else
                        return right;
                }
                else
                {
                    if (checker(right))
                        return right;
                    else if (checker(mid))
                        return mid;
                    else
                        return left;
                }
            }
            if (checker(mid))
            {
                if (smallest)
                    right = mid;
                else
                    left = mid;
            }
            else
            {
                if (smallest)
                    left = mid;
                else
                    right = mid;
            }
        }
    }
    template <typename T>
    T ternary_search(T left, T right, T (*func)(T), bool smallest = 1, T eps = 1e-6)
    {
        while (right - left > eps)
        {
            T mid = (left + right) / 2, mid1 = mid - eps, mid2 = mid + eps;
            if (smallest)
            {
                if (func(mid1) > func(mid2))
                    left = mid;
                else
                    right = mid;
            }
            else
            {
                if (func(mid1) < func(mid2))
                    left = mid;
                else
                    right = mid;
            }
        }
        return left;
    }

};
using namespace Algo;
namespace Debug
{

};
using namespace Debug;
namespace IO
{
    template <class t, class u>
    ostream &operator<<(ostream &os, const pair<t, u> &p) { return os << "(" << p.first << "," << p.second << ")"; }
    template <class t, class u>
    ostream &operator<<(ostream &os, const Pair<t, u> &p) { return os << "(" << p.first << "," << p.second << ")"; }
    template <class t>
    ostream &operator<<(ostream &os, const vector<t> &p)
    {
        for (auto i : p)
            cout << i << " ";
        return os;
    }  
};
using namespace IO;
template <typename T, typename U>
bool chmin(T &a, const U b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T, typename U>
bool chmax(T &a, const U b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
inline string YN(bool x, string Y = "Yes", string N = "No") { return (x) ? (Y) : (N); }
#define f0(i, n) for (long long i = 0; i < n; ++i)
#define f1(i, n) for (long long i = 1; i <= n; ++i)
#define rep(i, a, n) for (long long i = a; i < n; ++i)
#define all(n) n.begin(), n.end()
#define pb push_back
#define mp make_pair
#define over(n)            \
    {                      \
        cout << n << endl; \
        return 0;          \
    }
#define Over(n)            \
    {                      \
        cout << n << endl; \
        exit(0);           \
    }
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
using uint = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using pii = pair<int, int>;
using puu = pair<unsigned, unsigned>;
using p64 = pair<long long, long long>;
using pu64 = pair<unsigned long long, unsigned long long>;
signed Main();
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    unsigned long long T = 1LL;
    if (multicases)
        cin >> T;
    while (T--)
        Main();
    return 0;
}

signed Main()
{

    return 0;
}
/*
Segment Tree



template <typename T>
    struct SegmentTree
    {
        unsigned int N;
        vector<T> tree, lazy_tag;
        T build(unsigned int l, unsigned int r, unsigned int p, const vector<T> &original)
        {
            if (l == r)
            {
                return tree[p] = original[l];
            }
            unsigned int m = l + ((r - l) >> 1);
            return tree[p] = build(l, m, p << 1, original) + build(m + 1, r, (p << 1) | 1, original);
        }
        void update(unsigned int l, unsigned int r, T c, unsigned int s = 0, unsigned int t = 0, unsigned int p = 1)
        {
            if (p == 1)
            {
                s = 1, t = N;
            }
            if (l <= s && t <= r)
            {
                tree[p] += (t - s + 1) * c, lazy_tag[p] += c;
                return;
            }
            unsigned int m = s + ((t - s) >> 1);
            if (lazy_tag[p])
            {
                tree[p << 1] += lazy_tag[p] * (m - s + 1), tree[(p << 1) | 1] += lazy_tag[p] * (t - m), lazy_tag[p << 1] += lazy_tag[p], lazy_tag[(p << 1) | 1] += lazy_tag[p];
            }
            lazy_tag[p] = 0;
            if (l <= m)
            {
                update(l, r, c, s, m, p << 1);
            }
            if (r > m)
            {
                update(l, r, c, m + 1, t, (p << 1) | 1);
            }
            tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        }
        T getsum(unsigned int l, unsigned int r, unsigned int s = 0, unsigned int t = 0, unsigned int p = 1)
        {
            if (p == 1)
            {
                s = 1, t = N;
            }
            if (l <= s && t <= r)
            {
                return tree[p];
            }
            unsigned int m = s + ((t - s) >> 1);
            if (lazy_tag[p])
            {
                tree[p << 1] += lazy_tag[p] * (m - s + 1), tree[(p << 1) | 1] += lazy_tag[p] * (t - m), lazy_tag[p << 1] += lazy_tag[p], lazy_tag[(p << 1) | 1] += lazy_tag[p];
            }
            lazy_tag[p] = 0;
            T sum = 0;
            if (l <= m)
            {
                sum = getsum(l, r, s, m, p << 1);
            }
            if (r > m)
            {
                sum += getsum(l, r, m + 1, t, (p << 1) | 1);
            }
            return sum;
        }
        SegmentTree(vector<T> original)
        {
            N = original.size();
            original.insert(original.begin(), 0), tree.resize(4 * N), lazy_tag.resize(4 * N), build(1, N, 1, original), tree[0] = N;
        }
    };
*/
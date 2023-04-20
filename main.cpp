#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define brute hello
#define pb push_back
#define pob pop_back()
#define mp make_pair
#define mod 1000000007
#define add_m(a, b) (((a % mod) + (b % mod)) % mod)
#define sub_m(a, b) (((a % mod) - (b % mod) + mod) % mod)
#define mul_m(a, b) (((a % mod) * (b % mod)) % mod)

ll  floor_div(ll  dividend, ll  divisor) {
    return std::floor(static_cast<double>(dividend) / divisor);
}

// Function to perform ceil division
ll  ceil_div(ll  dividend, ll  divisor) {
    return std::ceil(static_cast<double>(dividend) / divisor);
}

ll gcd(ll a, ll b) // note if a == b == 0 then gcd is INF. This function doesn't take care of that
{
    if (a == 0)
        return b;
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void base_soln(ll a, ll b, ll g, ll &x, ll &y) // positive a,b

{

     x = 1, y = 0;

    stack<pair<ll, ll> > st;
    st.push(make_pair(a, b));
    ll ai, bi;
    while (true)
    {
        ai = st.top().first, bi = st.top().second;
        if (ai % bi == 0)
            break;
        st.push(make_pair(bi, ai % bi));
    }
    while (!st.empty())
    {
        ai = st.top().first, bi = st.top().second;

        st.pop();
        ll temp = y;
        y = x - temp * (ai / bi);
        x = temp;
    }
}

ll f()
{
    ll a, b, c, p, x0, y0, x, y, g, cnt = 0;

    cin >> a >> b >> c >> p;
    g = gcd(a, b);
    
    base_soln(a, b, g, x0, y0);
    

    for (ll z = 0; c * z <= p; z++) // bases on constriants, it has atmost O(1e6) iteratoins
    {
        ll d = p - c * z;
        if (d % g != 0)
            continue;
        x = x0 * (d / g), y = y0 * (d / g);

        cnt += floor_div(y * g, a) - ceil_div(-x * g, b) + 1;
    }

    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
        cout << "Case " << i << ": " << f() << "\n";

    return 0;
}

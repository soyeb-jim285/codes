/*Returns a^b in O(log(b))*/
ll binpowmod(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res = res % m;
        }
        a *= a;
        a = a%m;
        b >>= 1;
    }
    return res;
}
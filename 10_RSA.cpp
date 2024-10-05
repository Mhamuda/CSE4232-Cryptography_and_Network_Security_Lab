/*
10. Encrypt the plaintext message using RSA algorithm. 
Then perform the reverse operation to get original plaintext.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll BigMod(ll base, ll power, ll mod)
{
    ll result = 1;
    base = base % mod;

    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * base) % mod;

        power >>= 1;
        base = (base * base) % mod;
    }

    return result;
}

string Encrypt_block(string block, int key, int mod)
{
    ll num = stoi(block);
    ll output = BigMod(num, key, mod);

    return to_string(output);
}

string Encryption(string plain_text, int key, int mod, int block_size)
{
    string cipher_text;
    int len = (int)plain_text.size();

    for (int i = 0; i < len; i += block_size)
    {
        string block = plain_text.substr(i, block_size);
        string output = Encrypt_block(block, key, mod);
        cipher_text += output;
    }

    return cipher_text;
}

int main()
{
    freopen("10_RSA_Input.txt", "r", stdin);
    string plain_text;
    int e, d, n;

    cin >> plain_text >> e >> d >> n;
    int block_size = to_string(n).size() - 1;

    string cipher_text = Encryption(plain_text, e, n, block_size);
    cout << "Cipher Text: " << cipher_text << "\n";

    string original_text = Encryption(cipher_text, d, n, block_size + 1);
    cout << "Original Text: " << original_text << "\n";

    return 0;
}
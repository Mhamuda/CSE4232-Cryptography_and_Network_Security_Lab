/*
1. Suppose you are given a line of text as a plaintext, find out the corresponding Caesar Cipher
(i.e. character three to the right modulo 26). Then perform the reverse operation to get original plaintext.
*/

#include <bits/stdc++.h>
using namespace std;

string Encryption(string plain_text)
{
    string cipher_text = "";
    int len = (int)plain_text.size();

    for (int i = 0; i < len; i++)
    {
        char ch = plain_text[i];

        if (islower(ch))
        {
            int c = (ch - 'a') + 3;
            c %= 26;
            ch = c + 'a';
            cipher_text += ch;
        }
        else if (isupper(ch))
        {
            int c = (ch - 'A') + 3;
            c %= 26;
            ch = c + 'A';
            cipher_text += ch;
        }
        else
            cipher_text += ch;
    }
    return cipher_text;
}

string Decryption(string cipher_text)
{
    string plain_text = "";
    int len = (int)cipher_text.size();

    for (int i = 0; i < len; i++)
    {
        char ch = cipher_text[i];

        if (islower(ch))
        {
            int c = (ch - 'a') - 3;
            c += 26;
            c %= 26;
            ch = c + 'a';
            plain_text += ch;
        }
        else if (isupper(ch))
        {
            int c = (ch - 'A') - 3;
            c += 26;
            c %= 26;
            ch = c + 'A';
            plain_text += ch;
        }
        else
            plain_text += ch;
    }

    return plain_text;
}

int main()
{
    freopen("1_Caesar_Cipher_Input.txt", "r", stdin);

    string plain_text;
    getline(cin, plain_text);

    string encrypted_caeser_cipher_text = Encryption(plain_text);
    cout << "Encrypted Caeser Cipher Text: " << encrypted_caeser_cipher_text << "\n";

    string original_text = Decryption(encrypted_caeser_cipher_text);
    cout << "Original Text: " << original_text << "\n";

    return 0;
}
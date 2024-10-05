/*
5.	You are supplied a file of large nonrepeating set of truly random key letter.
Your job is to encrypt the plaintext using ONE TIME PAD technique.
Then perform the reverse operation to get original plaintext
*/

#include <bits/stdc++.h>
using namespace std;

string get_otp()
{
    cin.clear();
    freopen("5_One_Time_Pad_OTP.txt", "r", stdin);
    string OTP;
    getline(cin, OTP);

    return OTP;
}

string Encryption(string plain_text, string OTP)
{
    string cipher_text = "";
    int len = (int)plain_text.size();

    for (int i = 0; i < len; i++)
    {
        char ch = plain_text[i];

        if (islower(ch))
        {
            int c = (ch - 'a') + (OTP[i] - 'A');
            c %= 26;
            ch = c + 'a';
        }
        else if (isupper(ch))
        {
            int c = (ch - 'A') + (OTP[i] - 'A');
            c %= 26;
            ch = c + 'A';
        }

        cipher_text += ch;
    }

    return cipher_text;
}

string Decryption(string cipher_text, string OTP)
{
    string plain_text = "";
    int len = (int)cipher_text.size();

    for (int i = 0; i < len; i++)
    {
        char ch = cipher_text[i];

        if (islower(ch))
        {
            int c = (ch - 'a') - (OTP[i] - 'A');
            c += 26;
            c %= 26;
            ch = c + 'a';
        }
        else if (isupper(ch))
        {
            int c = (ch - 'A') - (OTP[i] - 'A');
            c += 26;
            c %= 26;
            ch = c + 'A';
        }

        plain_text += ch;
    }

    return plain_text;
}

int main()
{
    freopen("5_One_Time_Pad_Input.txt", "r", stdin);
    string plain_text;
    getline(cin, plain_text);

    string OTP = get_otp();

    string cipher_text = Encryption(plain_text, OTP);
    cout << "One Time Pad Cipher Text: " << cipher_text << "\n";

    string original_text = Decryption(cipher_text, OTP);
    cout << "Original Text: " << original_text << "\n";

    return 0;
}
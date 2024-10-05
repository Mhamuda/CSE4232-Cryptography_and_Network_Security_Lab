/*
4.	Find out corresponding double Transposition Cipher of the above plaintext.
Then perform the reverse operation to get original plaintext.
*/

#include <bits/stdc++.h>
using namespace std;

string Encryption(string plain_text, int width)
{
    int len = (int)plain_text.size();
    string cipher_text = "";
    vector<string> matrix(width);

    for (int i = 0; i < len; i++)
        matrix[i % width] += plain_text[i];

    for (int i = 0; i < width; i++)
        cipher_text += matrix[i];

    return cipher_text;
}

string Decryption(string cipher_text, int width)
{
    string plain_text = "";
    int len = (int)cipher_text.size();
    int num_of_row = len / width;
    int extra = len % width;
    int index = 0;
    vector<string> matrix(width);

    for (int col = 0; col < extra; col++)
    {
        for (int i = 0; i <= num_of_row; i++)
            matrix[col] += cipher_text[index++];
    }

    for (int col = extra; col < width; col++)
    {
        for (int i = 0; i < num_of_row; i++)
            matrix[col] += cipher_text[index++];
    }

    int cnt = len;

    for (int i = 0; i <= num_of_row; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (cnt)
            {
                plain_text += matrix[j][i];
                cnt--;
            }
        }
    }
    return plain_text;
}

int main()
{
    freopen("4_Double_transposition_Input.txt", "r", stdin);

    string plain_text;
    int width;
    getline(cin, plain_text);
    cin >> width;

    string double_transposiiton_cipher_text = Encryption(Encryption(plain_text, width), width);
    cout << "Double Transposiiton Cipher Text: " << double_transposiiton_cipher_text << "\n";

    string original_text = Decryption(Decryption(double_transposiiton_cipher_text, width), width);
    cout << "Original Text: " << original_text << "\n";

    return 0;
}
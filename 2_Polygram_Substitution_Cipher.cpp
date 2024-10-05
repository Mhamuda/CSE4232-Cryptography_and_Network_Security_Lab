/*
2. Find out the Polygram Substitution Cipher of a given plaintext
(Consider the block size of 3). Then perform the reverse operation to get original plaintext.
*/

#include <bits/stdc++.h>
using namespace std;

map<string, string> encoder, decoder;

void set_encoder_decoder()
{
    freopen("2_Polygram_dictionary.txt", "r", stdin);
    string x, y;

    while (cin >> x >> y)
    {
        encoder[x] = y;
        decoder[y] = x;
    }
}

string Encryption(string plain_text, int block_size)
{
    string cipher_text = "";
    int len = (int)plain_text.size();

    for (int i = 0; i < len; i += block_size)
    {
        string block = plain_text.substr(i, block_size);

        if (encoder.find(block) != encoder.end())
            cipher_text += encoder[block];
        else
            cipher_text += block;
    }

    return cipher_text;
}

string Decryption(string cipher_text, int block_size)
{
    string plain_text = "";
    int len = (int)cipher_text.size();

    for (int i = 0; i < len; i += block_size)
    {
        string block = cipher_text.substr(i, block_size);

        if (decoder.find(block) != decoder.end())
            plain_text += decoder[block];
        else
            plain_text += block;
    }

    return plain_text;
}

int main()
{

    set_encoder_decoder();

    cin.clear();
    freopen("2_Polygram_input.txt", "r", stdin);

    string plain_text;
    getline(cin, plain_text);

    int block_size = 3;

    string cipher_text = Encryption(plain_text, block_size);
    cout << "Cipher Text: " << cipher_text << "\n";

    string original_text = Decryption(cipher_text, block_size);
    cout << "Original Text: " << original_text << "\n";

    return 0;
}
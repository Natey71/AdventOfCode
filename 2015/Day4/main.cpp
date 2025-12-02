//C++ program to get the MD5 Hash of a file
#include <openssl/md5.h>
#include <openssl/evp.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

std::string md5(const std::string &input) {
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    unsigned char digest[MD5_DIGEST_LENGTH];

    EVP_DigestInit_ex(ctx, EVP_md5(), nullptr);
    EVP_DigestUpdate(ctx, input.c_str(), input.size());
    EVP_DigestFinal_ex(ctx, digest, nullptr);
    EVP_MD_CTX_free(ctx);

    std::ostringstream ss;
    ss << std::hex << std::setfill('0');

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        ss << std::setw(2) << (int)digest[i];

    return ss.str();
}


int main(){
  
    std::string secret = "yzbqklnj";
    long long n = 1;
    while(true){
        std::string toHash = secret + std::to_string(n);
        std::string hash = md5(toHash);
        if(hash.substr(0,5) == "00000"){
            std::cout << "Found! n = " << n << " gives hash: " << hash << std::endl;
            break;
        }
        n++;
    }

    return 0;
}
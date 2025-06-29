#include<iostream>
#include<string.h>
using namespace std;
string encryption(string password,int key,int digit=0,int key1=0,int key2=0){
    string encryptdata="";
    if(digit==0)
    digit=key;
    if(key1==0)
    key1=key;
    if(key2==0)
    key2=key;
    for(auto chr:password){
        if('A'<=chr && 'Z'>=chr)
        encryptdata+=(65+(chr-65+key)%26);
        else if('a'<=chr && 'z'>=chr)
        encryptdata+=(97+(chr-97+key)%26);
        else if('0'<=chr && '9'>=chr)
        encryptdata+=('0'+(chr-'0'+digit)%10);
        else{
        if('!'<=chr && '/'>=chr)
        encryptdata+=(33+(chr-33+key1)%15);
        else if(':'<=chr && '@'>=chr)
        encryptdata+=(58+(chr-58+key2)%7);
        else
        encryptdata+=chr;
        }

    }
    return encryptdata;
}
string decryption(string password,int key){
    return encryption(password,26-key,10-key,15-key,7-key);
}
int main(){ 
    string password="Abc@123";
    cout<<password<<endl;
    string data=encryption(password,3);
    cout<<data<<endl;

   cout<< decryption(data,3);
   cout<<endl;
    return 0;
}

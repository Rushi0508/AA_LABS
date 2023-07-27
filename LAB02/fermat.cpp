#include<bits/stdc++.h>

using namespace std;


unsigned long long power(unsigned long long a, unsigned long long n, unsigned long long p){
    unsigned long long result = 1;
    while(n>0){
        if(n && 1){
            result = (result * a) %  p;
        }
        n/=2;
        a = (a * a) % p;
    }
    return result;
}

unsigned long long GCD(unsigned long long a, unsigned long long b){
    if(a < b){
        return GCD(b,a);
    }
    else if(a%b==0){
        return b;
    }
    else{
        return GCD(b, a%b);
    }
}

bool isPrime(unsigned long long n, unsigned long long k){
    if(n <= 1 or n == 4){
        return false;
    }
    if(n == 2 or n == 3){
        return true;
    }

    while (k--)
    {
        unsigned long long a = 2 + (rand()%(n-3));
        if(GCD(n,a)!=1){
            return false;
        }
        if(power(a,n-1,n)!=1){
            return false;
        }
    }
    return true;
}

int main(){
    srand(time(NULL));
    cout<<"Enter number to check: ";
    unsigned long long num;
    cin >> num;
    cout<<"Enter number of checks: ";
    unsigned long long k;
    cin >> k;

    if(isPrime(num,k)){
        cout<<num<< " is Prime" << endl;
    }else{
        cout << num << " is not Prime" << endl;
    }

    return 0;
}
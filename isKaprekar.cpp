#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long maxVal = 10000000005;
int a[12];

// Function to check if a number is a Kaprekar number
bool isKaprekar(long long x){
    memset(a,0,sizeof(a));
    long long d = x;
    int i = 1;
    // Store the digits of the number in an array
    while (d > 0){
        a[i] = d%10;
        i++;
        d = d/10;
    }
    // Sort the digits in ascending order
    sort(a + 1, a + i + 1);
    long long max = 0;
    long long min = 0;
    // Construct the minimum number from the sorted digits
    for (int j = 1; j <= i; j++){
        min = min * 10 + a[j]; 
    }
    // Construct the maximum number from the sorted digits
    for (int j = i; j > 1; j--){
        max = max * 10 + a[j];
    }
    // Check if the difference between the maximum and minimum numbers is equal to the original number
    if (max - min == x) return true;
    else return false;
}

// Function to find the next Kaprekar number after a given number
void solve(){
    long long n;
    cin >> n;
    for (long long i = n; i < maxVal; i++){
        if (isKaprekar(i)){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

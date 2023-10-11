#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int r = 1+(c-a)/(a-b);
    if((c-a)%(a-b) != 0){
        r++;
    }
    
    cout << r;
    return 0;
}
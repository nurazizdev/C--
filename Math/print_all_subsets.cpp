#include <bits/stdc++.h>
using namespace std;

vector<int> subset;
int number = 3;
void print_all_subsets(int k){
    if(k == number){
        for(int x : subset) cout << x << " ";
        cout << endl;
        return;
    }
    else{
        print_all_subsets(k + 1);
        subset.push_back(k);
        print_all_subsets(k + 1);
        subset.pop_back();
    }
}

void print_all_subsets1(){
    for(int b = 0 ; b < (1 << number) ; b++){
        vector<int> sub;
        for(int i = 0 ; i < number ; i++){
            if(b & (1 << i)) sub.push_back(i);
        }
        for(int x : sub) cout << x << " ";
        cout << endl;
    }
}
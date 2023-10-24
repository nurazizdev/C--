#include <bits/stdc++.h>
using namespace std;

void deque1(){
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(2); // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back(); // [3,5]
    d.pop_front(); // [5]
}

void queue1(){
    queue<int> q;
    q.push(2); // [2]
    q.push(5); // [2,5]
    cout << q.front() << "\n"; // 2
    q.pop(); // [5]
    cout << q.back() << "\n"; // 5
} 

void stack1(){
    stack<int> s;
    s.push(2); // [2]
    s.push(5); // [2,5]
    cout << s.top() << "\n"; // 5
    s.pop(); // [2]
    cout << s.top() << "\n"; // 2
}

void priority_queue1(){
    priority_queue<int> pq;
    pq.push(4); // [4]
    pq.push(2); // [2, 4]
    pq.push(1); // [1, 2, 4]
    pq.push(3); // [1, 2, 3, 4]
    cout << pq.top() << endl; // 4
    pq.pop(); // [1, 2, 3]
    pq.pop(); // [1, 2]
    pq.push(5); // [1, 2, 5]
    priority_queue<int, vector<int>, greater<int>> pqq;
    pqq.push(4); // [4]
    pqq.push(2); // [2, 4]
    pqq.push(1); // [1, 2, 4]
    pqq.push(3); // [1, 2, 3, 4]
    cout << pqq.top() << endl; // 1
    pqq.pop(); // [2, 3, 4]
    pqq.pop(); // [3, 4]
    pqq.push(5); // [3, 4, 5]
}

void unordered_set1(){
    unordered_set<int> s;
    s.insert(1); // [1]
    s.insert(4); // [1, 4] in arbitrary order
    s.insert(2); // [1, 4, 2] in arbitrary order
    s.insert(1); // [1, 4, 2] in arbitrary order
    cout << s.count(1) << endl; // 1
    s.erase(1); // [2, 4] in arbitrary order
    cout << s.count(5) << endl; // 0
    s.erase(0); // [2, 4] in arbitrary order
}

void ordered_set1(){
    set<int> s;
    s.insert(1); // [1]
    s.insert(14); // [1, 14]
    s.insert(9); // [1, 9, 14]
    s.insert(2); // [1, 2, 9, 14]
    cout << *s.upper_bound(7) << '\n'; // 9 <
    cout << *s.upper_bound(9) << '\n'; // 14 <
    cout << *s.lower_bound(5) << '\n'; // 9 <=
    cout << *s.lower_bound(9) << '\n'; // 9 <=
    if (s.find(7) == s.end()) {
        cout << "7 is not in the set" << endl;
    }
}

void multiset1(){
    multiset<int> ms;
    ms.insert(1); // [1]
    ms.insert(14); // [1, 14]
    ms.insert(9); // [1, 9, 14]
    ms.insert(2); // [1, 2, 9, 14]
    ms.insert(9); // [1, 2, 9, 9, 14]
    ms.insert(9); // [1, 2, 9, 9, 9, 14]
    cout << ms.count(4) << '\n'; // 0
    cout << ms.count(9) << '\n'; // 3
    cout << ms.count(14) << '\n'; // 1
    ms.erase(ms.find(9));
    cout << ms.count(9) << "\n"; // 2
    ms.erase(9);
    cout << ms.count(9) << "\n"; // 0
}

void map1(){
    map<string , int> age;
    if (age.find("Aron") == age.end()) {
        cout << "No record of Aron's age" << endl;
    }
    auto last = --age.end();
    cout << (*last).first << " is " << (*last).second << " years old" << endl;
}
// set = map

void bitset1(){
    bitset<10> s(string("0010011010")); // from right to left
    cout << s[4] << "\n"; // 1
    cout << s[5] << "\n"; // 0
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

void indexed_set1(){
    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9); // 2 3 7 9
    auto x = s.find_by_order(2);
    cout << *x << "\n"; // 7
    cout << s.order_of_key(7) << "\n"; // 2

    cout << s.order_of_key(6) << "\n"; // 2
    cout << s.order_of_key(8) << "\n"; // 3
}

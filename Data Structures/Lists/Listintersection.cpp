#include<iostream>
#include<list>
using namespace std;


list<int> intersection(list<int> l1 , list <int> l2) {
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    list<int> result;
    while (it1 != l1.end() && it2 != l2.end())
    {
        /* code */
        if (*it1 < *it2) it1++;
        else if (*it2 < *it1) it2++;
        else {
            result.push_back(*it1);
            it1++;
            it2++;
        }
    }
    return result;
    

}
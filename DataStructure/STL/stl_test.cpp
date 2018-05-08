#include <iostream>
#include <vector>

using namespace std;

void vector_test(){
    vector<int> vec;
    if (vec.empty()){
       vec.push_back(0); 
    }
    if (vec.empty()){
        vec.push_back(1);
    }

    cout << "vec : ";
    for (auto i : vec){
        cout << i << ' ';
    }
    cout << endl;

    vector<int> v1;
    vector<int> v2;
    int a[9] = {1,2,3,4,5,6,7,8,9};
    // for (int i = 0; i < 9; ++i){
    //     v1.push_back(a[i]);
    // }

    for (int i = 8; i >= 0; --i){
        v2.push_back(a[i]);
        // v2.insert(v2.end(), a[i]);
    }
    cout << "v2 : ";
    for (auto i : v2){
        cout << i << ' ';
    }
    v1.clear();
    cout << endl;
    v1.assign(v2.begin() + v2.size() / 2, v2.end());
    cout << "v1 : ";
    for (auto i : v1){
        cout << i << ' ';
    }
    cout << endl;
    

    cout << "v2.size()" << v2.size() << endl;
    cout << "v2.capacity()" << v2.capacity() << endl;
    vector<int>::iterator ite=v2.begin();
    v2.erase(ite);
    vector<int> (v2).swap(v2);
    cout << "v2.size()" << v2.size() << endl;
    cout << "v2.capacity()" << v2.capacity() << endl;
    vector<bool> v3;
    v3.reserve(20);
    for (int i = 0; i < 20; ++i){
        v3.push_back(i);
    }
    cout << "v3 : ";
    for (auto i : v3){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){

    vector_test();


    return 0;
}
#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Generator {

    vector<vector<int>> res;
    vector<int> x;

    // завести набор построенных объектов - vector<vector>
    
    // конструктор с n,k
    int m, count = 0;
    bool Recursive(int n, int i, vector<int> mas);
public:
    Generator(int m): m(m), count(0)
    {

    }
    void GenerateAll();
    void GenerateRec();
    int GetCount();
    vector<int>& GetResult(int index);
};

int Factorial(int n);

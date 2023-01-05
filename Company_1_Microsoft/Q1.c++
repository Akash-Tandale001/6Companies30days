#include<bits/stdc++.h>
using namespace std;
// 1.You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Leetcode : Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int solve(int a, int b,string op){
        if(op=="+") return a+b;
        else if(op=="-") return a-b;
        else if(op=="*") return (long)a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        int size = tokens.size();
        for(int i=0;i<size;i++){
            if(tokens[i].size()==1 && (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")){
                int v1 = s.top();
                s.pop();
                int v2 = s.top();
                s.pop();
                cout<<v1<<tokens[i]<<v2<<" = "<<solve(v2,v1,tokens[i])<<endl;
                s.push(solve(v2,v1,tokens[i]));
            }
            else{
                int val = stoi(tokens[i]);
                s.push(val);
            }
        }
        return s.top();
    }
};
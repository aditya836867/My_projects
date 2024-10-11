#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPresent(vector<int>& vec, int num) {
    return find(vec.begin(), vec.end(), num) != vec.end();
}

vector<int> factor(int num){
    vector<int> result;
    for (int i=2;i<=num;i++){
        while(num%i == 0){
            result.push_back(i);
            num/=i;
        }
    }
    return result;
}

void displayRoots(vector<int> factor, int nth = 2){
    vector<int> inside;
    vector<int> outside;
    int searchNo; 
    for(int i=0;i<factor.size();i++){
        int searchNo = factor[i];
        int occurence = 0;
        if((!isPresent(inside,searchNo)) && (!isPresent(outside,searchNo))){
            for(int j = 0;j<factor.size();j++){
                if(factor[j] == searchNo)
                {
                    occurence++;
                }
            }
        }
        for(int i=0;i<occurence/nth;i++){
            outside.push_back(searchNo);
        }
        for(int i=0;i<occurence%nth;i++){
            inside.push_back(searchNo);
        }
    }
    int out=1,in=1;
    for(int i = 0;i< outside.size();i++){
        out*=outside[i];
    }
    for(int i = 0;i< inside.size();i++){
        in*=inside[i];
    }
    cout<<"The Answer is "<<to_string(out)<<" X ("<<to_string(in)<<")^(1/"<<nth<<")";
}

int main(){
    int num,nth;
    cout<<"Enter The Number :";cin>>num;
    cout<<"Enter The root Power(1/n) n = ";cin>>nth;
    displayRoots(factor(num),nth);
}

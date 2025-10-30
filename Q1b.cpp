#include<iostream>
using namespace std;

void printArr(int arr[],int len) {
    for(int i=0; i<len; i++) {
        if(i>0) cout << " ";
        cout<<arr[i];
    }
    cout<<endl;
}

void generatepattern(int n,int maxNum,int arr[],int index) {
    if(n==0) {
        printArr(arr,index);
        return;
    }

    for(int i=min(n, maxNum);i>=1;i--) {
        arr[index]=i;
        generatepattern(n-i,i,arr,index+ 1);
    }
}

void PrintPattern(int &n) {
    int arr[100];
    generatepattern(n,n, arr, 0);
}

int main() {
    int n;
    cout<<"Enter any number = ";
    cin>>n;
    PrintPattern(n);
    return 0;
}


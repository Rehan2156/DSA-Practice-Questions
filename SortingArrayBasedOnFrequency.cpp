#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}

int main(){
    int arr[]= {1,1,1,1,1,5,9,7,7,7,8,8,6,-8,-8,-8,-8};
    int n=sizeof(arr)/sizeof(n);
    int counting[n][2]={0};
    int count=0;
    for(int i=0;i<n;i++){
        count=1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j] && arr[i]!=-1 && arr[j]!=-1){
                count++;
                arr[j]=-1;
            }
        }
        if(arr[i]!=-1 ){
        counting[i][0]=arr[i];
        counting[i][1]=count;
    }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout<<counting[i][j]<<" ";
        }
        cout<<endl;
    }
    //BUBBLE SORT:
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(counting[j][1]<counting[j+1][1]){
                swap(counting[j][1],counting[j+1][1]);
                swap(counting[j][0],counting[j+1][0]);
            }
        }
    }
    cout<<"\nSorted list:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout<<counting[i][j]<<" ";
        }
        cout<<endl;
    }

    //int final[n];
    cout<<"\\nFINAL LIST\n";
    for(int i=0;i<n;i++){
        while(counting[i][1]!=0){
            cout<<counting[i][0];
            counting[i][1]--;
        }
    }

}
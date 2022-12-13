#include<iostream>
using namespace std;

bool isPresent(int arr[],int size, int key){

//base case

if(size==0){
    return 0;
}

if(arr[0]==key){
    return true;
}

else{
    bool remainingpart = isPresent(arr + 1,size - 1 , key);
    return remainingpart;
}


}

int main(){

int arr[5] ={3,5,1,2,6};
int size =5;
int key=9;

bool present = isPresent(arr,size,key);

cout<<present;


}
#include "maxheap.hpp"
#include <stdio.h>
#include <iostream>

MaxHeap::MaxHeap() {}
MaxHeap::~MaxHeap() {}

/*
ALL YOUR CODE GOES HERE
The methods below either
  - don't do anything at all, or
  - return 0 just so that the code compiles

You have to implement every method in this class
 */

int MaxHeap::size() {
  return arr.size();
}

int MaxHeap::left(int parent) {
    return (parent * 2 + 1);
}

int MaxHeap::right(int parent) {
    return (parent * 2 + 2);
}

int MaxHeap::parent(int child) {
    
  return (child-1)/2;
}

void MaxHeap::insert(int element) {
    arr.push_back(element);
    heapifyUp(size()-1);
}

int MaxHeap::deleteMax() {
    int deleted = arr[0];               //get max to be deleted
    arr[0] = arr[arr.size() - 1];       //assign last element to root
    arr.pop_back();                     //remove last element
    heapifyDown(0);                     //heapify down from root
  return deleted;
}

void MaxHeap::display() {
  vector<int>::iterator it;
  cout << "MaxHeap:- ";
  for(it=arr.begin(); it!=arr.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

void MaxHeap::heapifyUp(int index) {
    //if child is bigger than parent
    if (index != 0 && arr[index] > arr[parent(index)]){
        swap(arr[index], arr[parent(index)]);   //swap
        heapifyUp(parent(index));               //check recurively with all parents
    }
}

void MaxHeap::heapifyDown(int index) {
    int bigger = index;
    
    if(left(index) < (arr.size()) && arr[left(index)] > arr[index])
        bigger = (arr[left(index)] > arr[right(index)]) ? left(index) : right(index);
    if(right(index) < (arr.size()) && arr[right(index)] > arr[index])
        bigger = (arr[right(index)] > arr[left(index)]) ? right(index) : left(index);
    //if the bigger hasn't changed
    if (bigger != index){
        swap(arr[index], arr[bigger]);      //swap parent with its superior
        heapifyDown(bigger);                //recursively check for heap violation
    }
    
}

void MaxHeap::buildHeap(vector<int> A,int n) {
    for(int i = 0; i < A.size(); i++)
        insert(A[i]);
}

void MaxHeap::heapsort(vector<int>& A,int n) {
    buildHeap(A, n);
    A.clear();
    
    int max;
    vector<int> V;
    
    while(size() != 0){
        max  = deleteMax();
        V.push_back(max);
    }
    
    for(int i = V.size(); i > 0; i--)
        A.push_back(V[i]);
}

void swap(int&a, int&b){
    int temp = a;
    a = b;
    b = temp;
}




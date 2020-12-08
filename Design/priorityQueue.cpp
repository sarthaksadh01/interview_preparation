#include<bits/stdc++.h>
using namespace std;

template<typename T>
class priorityQueue{
    T*arr = new T[2];
    int size = 0;
    int originalSize = 2;
    void pushHelper(int i){
        int parent = (i-1)/2;
        if(arr[parent] < arr[i]){
            swap(arr[parent],arr[i]);
            pushHelper(parent);
        }
    }
    void popHelper(int i){
        int left = 2*i -1;
        int right = 2*i +1;
        int largest = i;
        if(left < size && left >=0 && arr[left]>arr[largest])
            largest = left;
        if(right < size && arr[right] > arr[largest])
            largest =right;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            popHelper(largest);
        }
    }
    public:
    void push(T val){
        if(size == originalSize){
            T*temp = new T[2*originalSize];
            for(int i=0;i<size;i++)
                temp[i] = arr[i];
            temp[size++] = val;   
            arr = temp;
            pushHelper(size-1);
            originalSize*=2;
        }
        else{
            arr[size] = val;
            pushHelper(size);
            size++;
        }
    }
    void pop(){
        arr[0] = arr[size-1];
        popHelper(0);
        size--;
    }
    bool empty(){
        return size == 0;
    }
    int getSize(){
        return size;
    }
    T top(){
        return arr[0];
    }
    
};

int main() {
    priorityQueue<int>s;
    s.push(5);
    s.push(8);
    s.push(1);
    s.push(2);
    s.push(100);
    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }

}

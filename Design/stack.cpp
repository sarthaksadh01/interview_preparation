#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Mystack{
    T*arr = NULL;
    int size = 0;
    int originalSize = 2;
    void sortHelper(T val){
        if(this->empty() || val > this->getTop()){
            this->push(val);
            return;
        }
        T temp = this->getTop();this->pop();
        sortHelper(val);
        this->push(temp);
        
    }
    public:
    Mystack(){
        arr = new T[2];
    }
    int getSize(){
        return size;
    }
    void push(T val){
        if(size == originalSize){
            T *temp = new T[originalSize*2];
            for(int i =0;i<size;i++){
                temp[i] = arr[i];
            }
            temp[size++] = val;
            arr = temp;
            originalSize*=2;
            return;
        }
        arr[size++] = val;
    }
    T getTop(){
        if(this->size != 0)
            return arr[size-1];
        return -1;
    }
    void pop(){
        if(this->size!=0)
            size--;
    }
    bool empty(){
        return size == 0;
    }
    void insertAtBottom(T val){
        if(this->empty()){
            this->push(val);
            return;
        }
        T x =this->getTop();this->pop();
        this->insertAtBottom(val);
        this->push(x);
    }
    void reverse(){
        if(this->empty())
            return;
        T x = this->getTop();this->pop();
        reverse();
        this->insertAtBottom(x);
    }
    void sort(){
        if(this->empty())
            return;
        T x = this->getTop();this->pop();
        sort();
        sortHelper(x);
    }
};

int main() {
    Mystack<int>s;
    s.push(5);
    cout<<s.getTop();
}

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cassert>

#define max(a,b) a > b ? a : b
using std::cout;

template <typename T>
class Dynamic_array {
    int len;
    int capacity;
    T* data;
public:

    Dynamic_array(int initial_capacity = 0): len(0), capacity(initial_capacity) {
        if(initial_capacity < 1) {
            data = nullptr;
        } else {
            // data = (T*) malloc(initial_capacity * sizeof(T));
            data = new T[initial_capacity];
        }
    };

    ~Dynamic_array(){
        // if(data != nullptr) {
        //     free(data);
        // }

        // delete is safe for nullptr, so we don't need to check if it is nullptr. 
        //and we allocated multiple T using [], so we need to delete all of them using delete[].
        delete[] data; 
    };

    // void append(T value){
    //     int newlen = len + 1;
    //     if(newlen > capacity) {
    //         int newcapacity = max(1,capacity * 2);
    //         T* newdata =(T*) malloc(sizeof(T) * newcapacity);
    //         if(data != nullptr) {
    //             memcpy(newdata,data,len * sizeof(T));
    //             free(data);
    //         }
    //         data = newdata;
    //         capacity = newcapacity;
    //     }
    //     len = newlen;
    //     data[len-1] = value;
    // };

    template<typename...Args>
    T& emplace(Args&&...args){ // && is rvalue reference
        int newlen = len + 1;
        if(newlen > capacity) {
            int newcapacity = max(1,capacity * 2);
            //T* newdata =(T*) malloc(sizeof(T) * newcapacity);  
            //malloc doesn't call constructor, new does.
            T* newdata = new T[newcapacity]; // new T[n] will use default constructor and allocate n times of T size.
            assert(newdata);
            if(data != nullptr) {
                // memcpy(newdata,data,len * sizeof(T));
                // free(data);
                for(int i = 0; i < len; i++){
                    newdata[i] = std::move(data[i]); // force to use move constructor. move constructor moves ownership of the data.
                }
                // newdata = std::move(data);
                delete[] data;
            }
            data = newdata;
            capacity = newcapacity;
        }
        len = newlen;
        return data[len-1] = T{std::forward<Args>(args)...}; // perfect forwarding
    };

    void pop() {
        if(len < 1) {
            cout << "Empty array.";
        } else {
            len--;
        }

    }

    void sort() {
        int flag;
        do {
            flag = 0;
            for(int i = 0; i < len - 1; i++) {
                if(data[i] > data[i+1]){
                    T temp = data[i+1];
                    data[i+1] = data[i];
                    data[i] = temp;
                    flag = 1;
                }
            }

        } while (flag);
        
    }

    void clear() {
        len = 0;
    }

    void set(int index,T value) {
        if(len > index) {
            data[index] = value;
        } else {
            cout << "out of bounds.";
        }
    }

    T get(int index) {
        if(len <= index) {
            cout << "out of bounds.";
        }
        return data[index];
    }

    void print() {
        if(len < 1) {
            cout << "empty array.";
        } 
        for(int i = 0; i < len; i++) {
            cout << data[i] << " ";
        }

        cout << '\n';

    }

};






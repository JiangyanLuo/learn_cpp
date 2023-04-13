#include <cstdlib>
#include <iostream>
#include <cstring>
#include "dynamic_array.h"

#define max(a,b) a > b ? a : b

using std::cout;
Dynamic_array::Dynamic_array(int initial_capacity): len(0), capacity(initial_capacity) {
    if(initial_capacity < 1) {
        data = nullptr;
    } else {
        data = (int*) malloc(initial_capacity * sizeof(int));
    }
};

Dynamic_array::~Dynamic_array(){
    if(data != nullptr) {
        free(data);
    }
};

void Dynamic_array::append(int value){
    int newlen = len + 1;
    if(newlen > capacity) {
        int newcapacity = max(1,capacity * 2);
        int* newdata =(int*) malloc(sizeof(int) * newcapacity);
        if(data != nullptr) {
            memcpy(newdata,data,len*sizeof(int));
            free(data);
        }
        data = newdata;
        capacity = newcapacity;
    }
    len = newlen;
    data[len-1] = value;
};

void Dynamic_array::pop() {
    if(len < 1) {
        cout << "Empty array.";
    } else {
        len--;
    }

}

void Dynamic_array::sort() {
    int flag;
    do {
        flag = 0;
        for(int i = 0; i < len - 1; i++) {
            if(data[i] > data[i+1]){
                int temp = data[i+1];
                data[i+1] = data[i];
                data[i] = temp;
                flag = 1;
            }
        }

    } while (flag);
    
}

void Dynamic_array::clear() {
    len = 0;
}

void Dynamic_array::set(int index,int value) {
    if(len > index) {
        data[index] = value;
    } else {
        cout << "out of bounds.";
    }
}

int Dynamic_array::get(int index) {
    if(len <= index) {
        cout << "out of bounds.";
    }
    return data[index];
}

void Dynamic_array::print() {
    if(len < 1) {
        cout << "empty array.";
    } 
    for(int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }

    cout << '\n';

}

Dynamic_array* Dynamic_array::create(int initial_capacity) {
   //Dynamic_array* array =(Dynamic_array*) malloc(sizeof(Dynamic_array)); 
    Dynamic_array* array = new Dynamic_array(initial_capacity);
  

    return array;
}

void Dynamic_array::destroy(Dynamic_array* array) {
    //free(array);
    delete array;
}



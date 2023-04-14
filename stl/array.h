template<typename T, int N>
class Array{ 
    T data[N];
public:
    template<typename...Args>
    Array(Args&&...args) : data{std::forward<Args>(args)...} {}

    constexpr size_t size() const { //size_t is unsigned 64 bits integer (uint64_t)
        return N;
    }

    T& operator [](size_t index) {
        return data[index];
    }

    T* begin(){
        return data;
    }

    const T* begin() const {
        return data;
    }
    
    T* end(){
        return data + N;
    }

    const T* end() const {
        return data + N;
    }


};

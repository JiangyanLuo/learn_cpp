
class Dynamic_array {
    int len;
    int capacity;
    int* data;
public:

    Dynamic_array(int initial_capacity = 0);

    ~Dynamic_array();

    void append(int value);
    void pop();
    void sort();
    void clear();
    void set(int index, int value);
    int get(int index);
    void print();

    static Dynamic_array* create(int initial_capacity = 0);
    static void destroy(Dynamic_array*);
};


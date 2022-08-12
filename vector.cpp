#include <iostream>

template<typename T>
class Vector
{
public:
    Vector();
    ~Vector();
    void _push_back(T num);
    void _pop_back();
    T _back();
    T _front();
    T _find_by_value(T num);
    bool _isEmpty();
    int _size() const;
    int _capacity();
    void _clear();
    void _insert(int, T);
    void _resize();
    void _print();
    T& operator[](size_t);
    void _remove_by_value(T);
    const T& operator[](size_t) const;
    friend Vector operator+ (const Vector<T>& v1, const Vector<T>& v2) {
        Vector<T> v3;
        for (int i = 0; i < v1._size(); ++i) {
             v3._push_back(v2[i] + v1[i]);
        }
        if (v2._size() > v3._size()) {
            for (int i = v3._size(); i < v2._size(); ++i) {
                v3._push_back(v2[i]);
            }
        }
        return v3;
    }
    Vector<T>& operator+= (const Vector<T>& v1) {
        for (int i = 0; i < v1._size(); ++i) {
            this->m_arr[i] += v1[i];
        }
        return *this;
    }
    Vector<T>& operator= (const Vector<T>& v1) {
        for (int i = 0; i < v1._size(); ++i) {
            this->m_arr[i] = v1[i];
        }
        return *this;
    }
private:
   T* m_arr;
   int size;
   int capacity;
};

template<typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 1;
    m_arr = new T[capacity];
}

template<typename T>
Vector<T>::~Vector() {
    delete[] m_arr;
    m_arr = nullptr;
}

template<typename T>
void Vector<T>::_push_back(T num) {
    if (size == capacity) {
        _resize();
    }
    m_arr[size] = num;
    ++size;
}

template<typename T>
void Vector<T>::_remove_by_value(T key) {
    if (0 == size) {
        std::cout << "vector is empty:" << std::endl;
        return;
    }
    int count = 0;
        int* tmp = new int [capacity];
        for (int i = 0, j = 0; i < size; ++i, ++j) {
            if (m_arr[i] == key) {
                ++count;
                ++j;
            }
                tmp[i] = m_arr[j];
            }
        delete[] m_arr;
        m_arr = tmp;
    size = m_arr - count;
}

template<typename T>
T Vector<T>::_find_by_value(T key) {
    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (m_arr[i] == key) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void Vector<T>::_pop_back() {
    if (0 == size) {
        std::cout << "is empty:";
        return;
    }
    T* tmp = new T[capacity];
    for (int i = 0; i < size - 1; ++i) {
        tmp[i] = m_arr[i];
    }
    --size;
    delete[] m_arr;
    m_arr = tmp;
}

template<typename T>
void Vector<T>::_print() {
    for (int i = 0; i < size; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Vector<T>::_resize() {
    capacity *= 2;
    T* tmp = new T[capacity];
    for (int i = 0; i < size; ++i) {
        tmp[i] = m_arr[i];
    }
    delete[] m_arr;
    m_arr = tmp;
}

template<typename T>
T Vector<T>::_back() {
    return  m_arr[size - 1];
}

template<typename T>
T Vector<T>::_front() {
    return m_arr[0];
}

template<typename T>
bool Vector<T>::_isEmpty() {
    return (size == 0);
}

template<typename T>
int Vector<T>::_size() const {
    return size;
}

template<typename T>
int Vector<T>::_capacity() {
    return capacity;
}

template<typename T>
void Vector<T>::_clear() {
    T* tmp = new T[capacity];
    size = 0;
    delete[] m_arr;
    m_arr = tmp;
}

template<typename T>
void Vector<T>::_insert(int index, T value) {
    if (size == capacity) {
        _resize();
    }
    T* tmp = new T[capacity];
    for (int i = 0; i < size; ++i) {
        if (i == index) {
            tmp[i] = value;
        }
        tmp[i] = m_arr[i];
    }
    ++size;
    delete[] m_arr;
    m_arr = tmp;
}

template <typename T>
T& Vector<T>::operator[](size_t pos)
{
    return m_arr[pos];
}

template <typename T>
const T& Vector<T>::operator[](size_t pos) const
{
    return m_arr[pos];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    for (int i = 0; i < v._size(); ++i) {
        os << v[i];
        if (i != v._size() - 1)
            os << ", ";
    }
    return os;
}

int main() {
    Vector<int> vec;
    vec._push_back(18);
    vec._push_back(98);
    vec._push_back(23);
    vec._remove_by_value(18);
    std::cout << vec;
    return 0;
}
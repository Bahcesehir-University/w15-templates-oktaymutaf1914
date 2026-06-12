// ============================================================================
//  Lab: C++ Templates  (STUDENT VERSION)
//  Course: Object-Oriented Programming with C++
//  Single file only. No headers. C++17.
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

// ================================
// CLASS / TEMPLATE DEFINITIONS
// ================================

// ---- Group 1: Basic function template -------------------------------------
template <typename T>
T maxValue(T a, T b) {
    return (a < b) ? b : a;
}

// ---- Group 2: Function template with multiple type parameters --------------
template <typename T1, typename T2>
auto addValues(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

// ---- Group 3: Class template ----------------------------------------------
template <typename A, typename B>
class Pair {
private:
    A first_;
    B second_;

public:
    // constructor
    Pair(A first, B second) : first_(first), second_(second) {
    }

    // getters
    A getFirst() const {
        return first_;
    }

    B getSecond() const {
        return second_;
    }

    // setters
    void setFirst(A value) {
        first_ = value;
    }

    void setSecond(B value) {
        second_ = value;
    }

    // swapValues - assume A == B when called
    void swapValues() {
        A temp = first_;
        first_ = second_;
        second_ = temp;
    }
};

// ---- Group 4: Generic container -------------------------------------------
template <typename T>
class Box {
private:
    std::vector<T> items_;

public:
    // add an item to the back
    void add(const T& item) {
        items_.push_back(item);
    }

    // return number of stored items as int
    int size() const {
        return static_cast<int>(items_.size());
    }

    // return the item at index; throw std::out_of_range if invalid
    T get(int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Invalid index");
        }

        return items_[index];
    }

    // return the sum of all stored elements
    T total() const {
        T sum{};

        for (const T& item : items_) {
            sum += item;
        }

        return sum;
    }
};

// ---- Group 5: Template specialization -------------------------------------
template <typename T>
int describe(const T& value) {
    return 1;
}

template <>
int describe<std::string>(const std::string& value) {
    return 2 + static_cast<int>(value.length());
}

// ---- Group 6: Non-type template parameter ---------------------------------
template <typename T, int N>
class FixedArray {
private:
    T data_[N];

public:
    // default-construct all N elements to T()
    FixedArray() {
        for (int i = 0; i < N; i++) {
            data_[i] = T();
        }
    }

    // return N
    int capacity() const {
        return N;
    }

    // set data_[index]; throw std::out_of_range if invalid
    void set(int index, const T& value) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }

        data_[index] = value;
    }

    // return data_[index]; throw std::out_of_range if invalid
    T at(int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Invalid index");
        }

        return data_[index];
    }
};

// ================================
// FUNCTION IMPLEMENTATIONS / main
// ================================

int main() {
    std::cout << "=== C++ Templates Lab ===\n";

    std::cout << "maxValue(3, 7) = " << maxValue(3, 7) << "\n";
    std::cout << "addValues(3, 2.5) = " << addValues(3, 2.5) << "\n";

    Pair<int, int> p(10, 20);
    std::cout << "Pair first = " << p.getFirst() << "\n";
    std::cout << "Pair second = " << p.getSecond() << "\n";

    p.swapValues();

    std::cout << "After swap first = " << p.getFirst() << "\n";
    std::cout << "After swap second = " << p.getSecond() << "\n";

    Box<int> box;
    box.add(5);
    box.add(10);
    box.add(15);

    std::cout << "Box size = " << box.size() << "\n";
    std::cout << "Box total = " << box.total() << "\n";
    std::cout << "Box get(1) = " << box.get(1) << "\n";

    std::cout << "describe(10) = " << describe(10) << "\n";
    std::cout << "describe(std::string(\"hello\")) = "
              << describe(std::string("hello")) << "\n";

    FixedArray<int, 3> arr;
    arr.set(0, 100);
    arr.set(1, 200);
    arr.set(2, 300);

    std::cout << "FixedArray capacity = " << arr.capacity() << "\n";
    std::cout << "FixedArray at(1) = " << arr.at(1) << "\n";

    return 0;
}

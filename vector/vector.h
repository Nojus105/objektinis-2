#pragma once
#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <memory>
#include <utility>

template <typename T>
class Vektorius {
public:
    // Member types
    using value_type = T;
    using size_type = std::size_t;
    using iterator = T*;
    using const_iterator = const T*;

private:
    std::unique_ptr<T[]> data_; // Automatic memory management using std::unique_ptr
    size_type size_;            // Current number of elements
    size_type capacity_;        // Maximum number of elements that can be stored

    // Function to reallocate data to a new, larger array
    void reallocate(size_type new_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
        std::move(data_.get(), data_.get() + size_, new_data.get());
        data_ = std::move(new_data);
        capacity_ = new_capacity;
    }

public:
    // Konstruktoriai
    Vektorius() : data_(nullptr), size_(0), capacity_(0) {} // Default konstruktorius
    explicit Vektorius(size_type count, const T& value = T()) : size_(count), capacity_(count) {
        data_ = std::make_unique<T[]>(capacity_);
        std::fill(data_.get(), data_.get() + size_, value);
    }
    Vektorius(std::initializer_list<T> init) : Vektorius(init.size()) {
        std::copy(init.begin(), init.end(), data_.get());
    }
    Vektorius(const Vektorius& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = std::make_unique<T[]>(capacity_);
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    Vektorius(Vektorius&& other) noexcept : data_(std::move(other.data_)), size_(other.size_), capacity_(other.capacity_) {
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Assignment operatoriai
    Vektorius& operator=(const Vektorius& other) {
        if (this != &other) {
            data_ = std::make_unique<T[]>(other.capacity_);
            size_ = other.size_;
            capacity_ = other.capacity_;
            std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
        }
        return *this;
    }
    Vektorius& operator=(Vektorius&& other) noexcept {
        if (this != &other) {
            data_ = std::move(other.data_);
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    // Member funkcijos
    size_type size() const noexcept { return size_; }       // Returns the current number of elements
    size_type capacity() const noexcept { return capacity_; } // Returns the capacity
    bool empty() const noexcept { return size_ == 0; }      // Checks if the vector is empty

    // Adds a new element to the end of the vector
    void push_back(const T& value) {
        if (size_ == capacity_) {
            reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        data_[size_++] = value;
    }

    // Removes the last element
    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    // Clears all elements
    void clear() noexcept {
        size_ = 0;
    }

    // Changes the size of the vector
    void resize(size_type new_size, const T& value = T()) {
        if (new_size > capacity_) {
            reallocate(new_size);
        }
        if (new_size > size_) {
            std::fill(data_.get() + size_, data_.get() + new_size, value);
        }
        size_ = new_size;
    }

    // Reserves memory for the specified number of elements
    void reserve(size_type new_capacity) {
        if (new_capacity > capacity_) {
            reallocate(new_capacity);
        }
    }

    // Removes the element at the specified position and returns an iterator to the next element
    iterator erase(iterator pos) {
        if (pos < begin() || pos >= end()) {
            throw std::out_of_range("Iterator out of range");
        }
        std::move(pos + 1, end(), pos); // Shift elements to the left
        --size_; // Decrease the size
        return pos;
    }

    // Element access operators
    T& operator[](size_type index) {
        if (index >= size_) throw std::out_of_range("Index out of bounds");
        return data_[index];
    }

    const T& operator[](size_type index) const {
        if (index >= size_) throw std::out_of_range("Index out of bounds");
        return data_[index];
    }

    T& at(size_type index) {
        if (index >= size_) throw std::out_of_range("Index out of bounds");
        return data_[index];
    }

    const T& at(size_type index) const {
        if (index >= size_) throw std::out_of_range("Index out of bounds");
        return data_[index];
    }

    // Iterators
    iterator begin() noexcept { return data_.get(); }
    const_iterator begin() const noexcept { return data_.get(); }
    iterator end() noexcept { return data_.get() + size_; }
    const_iterator end() const noexcept { return data_.get() + size_; }
};

// Non-member funkcijos
template <typename T>
bool operator==(const Vektorius<T>& lhs, const Vektorius<T>& rhs) {
    return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const Vektorius<T>& lhs, const Vektorius<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vektorius<T>& lhs, const Vektorius<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T>
bool operator>(const Vektorius<T>& lhs, const Vektorius<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator<=(const Vektorius<T>& lhs, const Vektorius<T>& rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>=(const Vektorius<T>& lhs, const Vektorius<T>& rhs) {
    return !(lhs < rhs);
}
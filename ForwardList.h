//
// Created by Admin on 12.09.2023.
//

#ifndef FORWARDLIST_FORWARDLIST_H
#define FORWARDLIST_FORWARDLIST_H

#include <memory>
#include <stdexcept>

template<typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;
        explicit Node(const T &data) : data(data), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    size_t size;
public:
    ForwardList() : head(nullptr), size(0) {}

    /*ForwardList(const ForwardList& other);
    ForwardList& operator=(const ForwardList& other);
    */
    ForwardList(ForwardList &&other) noexcept: ForwardList(){
        std::swap(head, other.head);
        //std::swap(tail, other.tail);
        std::swap(size, other.size);
        other.head = nullptr;
        //other.tail = nullptr;
        other.size = 0;
    }

    ForwardList& operator=(ForwardList &&other) noexcept {
        if (this == &other) {
            return *this;
        }
        std::swap(head, other.head);
        //std::swap(tail, other.tail);
        std::swap(size, other.size);
        other.head = nullptr;
        //other.tail = nullptr;
        other.size = 0;
        return *this;
    }

    ~ForwardList() {
        while (!empty()) {
            popFront();
        }
    }

    void pushFront(const T &data) {
        std::unique_ptr<Node> tmp = std::make_unique<Node>(data);
        if (empty()) {
            head = std::move(tmp);
        } else {
            tmp->next = std::move(head);
            head = std::move(tmp);
        }
        ++size;
    }

    void popFront() {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        std::unique_ptr<Node> tmp = std::move(head);
        head = std::move(tmp->next);
        --size;
    }

    bool empty() const{
        return size == 0;
    }

    const T& front() const{
        if(empty()){
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    size_t getSize() const{
        return size;
    }
};


#endif //FORWARDLIST_FORWARDLIST_H

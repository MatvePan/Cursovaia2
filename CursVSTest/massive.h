#pragma once
#include "cmath"
template <typename T>
struct Data {
    T info;
    Data* next = nullptr;
    Data* prev = nullptr;
};
template <typename T>
struct Massive {
    int counting = 0;
    int position = 0;
    Data<T>* now = nullptr;
    Data<T>* first = nullptr;
    Data<T>* last = nullptr;

    void Studnum(int num) {
        if (abs(num - position) > (counting - 1 - num)) {
            now = last;
            position = counting - 1;
        }
        else if (abs(num - position) > num) {
            now = first;
            position = 0;
        }
        if (num > position) { for (int i = 0; i < num - position; i++) { now = now->next; } }
        else { for (int i = 0; i < position - num; i++) { now = now->prev; } }
        position = num;
    }

    void Add(T info) {
        Data<T>* node = new Data<T>();
        node->info = info;
        if (counting == 0) {
            first = node;
            last = node;
            now = node;
        }
        else {
            node->prev = last;
            last->next = node;
            last = node;
        }
        counting++;
    }

    void Remove(int num) {
        if (num < 0 || num >= counting) { throw 0; }
        Studnum(num);
        Data<T>* del = now;
        if (last == first) {
            Clear();
            return;
        }
        if (del == last) {
            last = last->prev;
            last->next = nullptr;
            now = last;
            position--;
        }
        else if (del == first) {
            first = first->next;
            first->prev = nullptr;
            now = first;
        }
        else {
            now = now->next;
            del->next->prev = del->prev;
            del->prev->next = del->next;
        }
        delete del;
        counting--;
    }

    T Number(int num) {
        if (num < 0 || num >= counting) { throw 0; }
        Studnum(num);
        return now->info;
    }

    int Count() { return counting; }

    void Clear() {
        int kol = counting;
        for (int i = 0; i < kol; i++) {
            Data<T>* del = first;
            first = first->next;
            delete del;
        }
        last = nullptr;
        now = nullptr;
        position = 0;
        counting = 0;
    }
};
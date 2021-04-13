#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T data;
  T prioritas;

  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  Element<T> * head;
  Element<T> * tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  Element<T> * prev = nullptr;
  Element<T> * pHelp = q.head;
  Element<T> * newElement;
  newElement = new Element<T>;
  newElement->data = value;
  newElement->prioritas = priority;
  newElement->next = nullptr;

  if (q.head == nullptr && q.tail == nullptr){
    q.head = newElement;
    q.tail = newElement;
  } else {
    while (newElement->prioritas <= pHelp->prioritas){
      if (pHelp->next == nullptr){
        break;
      }
      prev = pHelp;
      pHelp = pHelp->next;
    }
    //insert first
    if (pHelp == q.head && newElement->prioritas > pHelp->prioritas){
      newElement->next = pHelp;
      q.head = newElement;
    }
    //insert last
    else if (pHelp == q.tail && newElement->prioritas < pHelp->prioritas){
      pHelp->next = newElement;
      q.tail = newElement;
    }
    //insert middle
    else {
      prev->next = newElement;
      newElement->next = pHelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  Element<T> * pDel;
  if(q.head == nullptr && q.tail == nullptr){
      pDel = nullptr;
  } else if (q.head->next == nullptr){
    pDel = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else {
    pDel = q.head;
    q.head = q.head->next;
    pDel->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat

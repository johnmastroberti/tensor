#pragma once
#include <cstring>
#include <cassert>
#include <array>
#include <iterator>
#include <numeric>
#include <utility>
#include <algorithm>
#include <iostream>


template<typename T, size_t RANK>
class Tensor {
  private:
    T* m_begin;
    T* m_end;
    std::array<size_t, RANK> m_dims;
    //typedef Ndim_init_list std::initializer_list<Tensor::Ndim_init_list>;

  public:
    // Typedef for nested initializer lists
    typedef std::initializer_list<typename Tensor<T, RANK-1>::init_list_t> init_list_t;


    Tensor();
    Tensor(std::initializer_list<size_t> dimensions);

    Tensor(std::initializer_list<size_t> dimensions, init_list_t values);
    friend void init_list_copy(Tensor<T,RANK>& tens, Tensor<T,RANK>::init_list_t values);

    T* begin() { return m_begin; };
    T* end() { return m_end; };

    const T* cbegin() const { return m_begin; };
    const T* cend() const { return m_end; };

};

// Base case RANK=0 specialization
template<typename T>
class Tensor<T, 0> {
  public:
    typedef T init_list_t;
};

template<typename T, size_t RANK>
Tensor<T,RANK>::Tensor() : m_begin(nullptr), m_end(nullptr), m_dims{} {}

template<typename T, size_t RANK>
Tensor<T,RANK>::Tensor(std::initializer_list<size_t> dimensions) : m_begin{}, m_end{}, m_dims{} {
  assert(std::distance(dimensions.begin(), dimensions.end()) == RANK);

  std::copy(dimensions.begin(), dimensions.end(), m_dims.begin());

  size_t memsize = std::accumulate(m_dims.begin(), m_dims.end(), 1,
      [](size_t n1, size_t n2) { return n1*n2; });

  assert(memsize > 0);

  m_begin = new T[memsize];
  m_end = m_begin + memsize;
}


template<typename T, size_t RANK>
Tensor<T,RANK>::Tensor(std::initializer_list<size_t> dimensions, Tensor<T,RANK>::init_list_t values) : Tensor(dimensions) {
  if constexpr (RANK==0) {
    *m_begin = values;
  } else {}
}

template<typename T, size_t RANK>
void init_list_copy(Tensor<T,RANK>& tens, Tensor<T,RANK>::init_list_t values) {
  // Copies the nested initializer list values into the memory owned by tens
  std::for_each(values.begin(), values.end(),

template<typename T, size_t RANK>
std::ostream& operator<<(std::ostream& stream, const Tensor<T, RANK>& tens) {
  stream << "Basic printing for tensors...\n";
  std::for_each(tens.cbegin(), tens.cend(), [&](T val) { stream << val; });
  return stream;
}

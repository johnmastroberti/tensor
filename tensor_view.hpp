#pragma once


template<typename T, size_t RANK>
class TensorView {
  private:
    T* m_begin;
    T* m_end;
    std::array<size_t, RANK> m_dims;

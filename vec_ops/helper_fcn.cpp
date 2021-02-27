
//
include<helper_fcn>

namespace canal {

  template<typename T>
  const canal::math::Vector<T> lseq(T first, T last, T delta) {
    int N = (last - first ) / delta;
    canal::math::Vector<T> v(n);

    v.set(0,first);
    for (int i = 1; i < N; ++i) {
      v.set(i, v[i-1]+val);
    }

  }

}

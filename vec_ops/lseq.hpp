
// Copyright @Patrick Kasi January 2021

/**
 *@file lseq.hpp
 *
 *@brief Indexing type for linear sequence
 *
 *
 *@author Patrick Kasi
 *
 *@version 0.01

 *@date
 *
 *Contact pkasi@yahoo.com
 *
 */


#ifndef _LSEQ_H_
#define _LSEQ_H_

namespace canal {

struct Lseq {
  Lseq(const int i, const int j, const int k=1) :start_idx(i), end_idx(j), incr(k){}
  int start_idx, end_idx, incr;
};

}// End namespace


#endif

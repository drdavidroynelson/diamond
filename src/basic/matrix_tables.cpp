/****
DIAMOND protein aligner
Copyright (C) 2013-2020 Max Planck Society for the Advancement of Science e.V.
                        Benjamin Buchfink
                        Eberhard Karls Universitaet Tuebingen

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
****/

#include "value.h"
#include "score_matrix.h"

const MatrixTable s_Blosum45PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    5, -2, -1, -2, -1, -1, -1,  0, -2, -1, -1, -1, -1,
            -2, -1,  1,  0, -2, -2,  0, -1, -1, -1, -1, -5, -16,
    /*R*/   -2,  7,  0, -1, -3,  1,  0, -2,  0, -3, -2,  3, -1,
            -2, -2, -1, -1, -2, -1, -2, -1, -3,  1, -1, -5, -16,
    /*N*/   -1,  0,  6,  2, -2,  0,  0,  0,  1, -2, -3,  0, -2,
            -2, -2,  1,  0, -4, -2, -3,  5, -3,  0, -1, -5, -16,
    /*D*/   -2, -1,  2,  7, -3,  0,  2, -1,  0, -4, -3,  0, -3,
            -4, -1,  0, -1, -4, -2, -3,  6, -3,  1, -1, -5, -16,
    /*C*/   -1, -3, -2, -3, 12, -3, -3, -3, -3, -3, -2, -3, -2,
            -2, -4, -1, -1, -5, -3, -1, -2, -2, -3, -1, -5, -16,
    /*Q*/   -1,  1,  0,  0, -3,  6,  2, -2,  1, -2, -2,  1,  0,
            -4, -1,  0, -1, -2, -1, -3,  0, -2,  4, -1, -5, -16,
    /*E*/   -1,  0,  0,  2, -3,  2,  6, -2,  0, -3, -2,  1, -2,
            -3,  0,  0, -1, -3, -2, -3,  1, -3,  5, -1, -5, -16,
    /*G*/    0, -2,  0, -1, -3, -2, -2,  7, -2, -4, -3, -2, -2,
            -3, -2,  0, -2, -2, -3, -3, -1, -4, -2, -1, -5, -16,
    /*H*/   -2,  0,  1,  0, -3,  1,  0, -2, 10, -3, -2, -1,  0,
            -2, -2, -1, -2, -3,  2, -3,  0, -2,  0, -1, -5, -16,
    /*I*/   -1, -3, -2, -4, -3, -2, -3, -4, -3,  5,  2, -3,  2,
             0, -2, -2, -1, -2,  0,  3, -3,  4, -3, -1, -5, -16,
    /*L*/   -1, -2, -3, -3, -2, -2, -2, -3, -2,  2,  5, -3,  2,
             1, -3, -3, -1, -2,  0,  1, -3,  4, -2, -1, -5, -16,
    /*K*/   -1,  3,  0,  0, -3,  1,  1, -2, -1, -3, -3,  5, -1,
            -3, -1, -1, -1, -2, -1, -2,  0, -3,  1, -1, -5, -16,
    /*M*/   -1, -1, -2, -3, -2,  0, -2, -2,  0,  2,  2, -1,  6,
             0, -2, -2, -1, -2,  0,  1, -2,  2, -1, -1, -5, -16,
    /*F*/   -2, -2, -2, -4, -2, -4, -3, -3, -2,  0,  1, -3,  0,
             8, -3, -2, -1,  1,  3,  0, -3,  1, -3, -1, -5, -16,
    /*P*/   -1, -2, -2, -1, -4, -1,  0, -2, -2, -2, -3, -1, -2,
            -3,  9, -1, -1, -3, -3, -3, -2, -3, -1, -1, -5, -16,
    /*S*/    1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -3, -1, -2,
            -2, -1,  4,  2, -4, -2, -1,  0, -2,  0, -1, -5, -16,
    /*T*/    0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1,
            -1, -1,  2,  5, -3, -1,  0,  0, -1, -1, -1, -5, -16,
    /*W*/   -2, -2, -4, -4, -5, -2, -3, -2, -3, -2, -2, -2, -2,
             1, -3, -4, -3, 15,  3, -3, -4, -2, -2, -1, -5, -16,
    /*Y*/   -2, -1, -2, -2, -3, -1, -2, -3,  2,  0,  0, -1,  0,
             3, -3, -2, -1,  3,  8, -1, -2,  0, -2, -1, -5, -16,
    /*V*/    0, -2, -3, -3, -1, -3, -3, -3, -3,  3,  1, -2,  1,
             0, -3, -1,  0, -3, -1,  5, -3,  2, -3, -1, -5, -16,
    /*B*/   -1, -1,  5,  6, -2,  0,  1, -1,  0, -3, -3,  0, -2,
            -3, -2,  0,  0, -4, -2, -3,  5, -3,  1, -1, -5, -16,
    /*J*/   -1, -3, -3, -3, -2, -2, -3, -4, -2,  4,  4, -3,  2,
             1, -3, -2, -1, -2,  0,  2, -3,  4, -2, -1, -5, -16,
    /*Z*/   -1,  1,  0,  1, -3,  4,  5, -2,  0, -3, -2,  1, -1,
            -3, -1,  0, -1, -2, -2, -3,  1, -2,  5, -1, -5, -16,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -5, -16,
    /***/   -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
            -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  1, -16,
			-16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16,
			-16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16
};

const MatrixTable s_Blosum50PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    5, -2, -1, -2, -1, -1, -1,  0, -2, -1, -2, -1, -1,
            -3, -1,  1,  0, -3, -2,  0, -2, -2, -1, -1, -5, -16,
    /*R*/   -2,  7, -1, -2, -4,  1,  0, -3,  0, -4, -3,  3, -2,
            -3, -3, -1, -1, -3, -1, -3, -1, -3,  0, -1, -5, -16,
    /*N*/   -1, -1,  7,  2, -2,  0,  0,  0,  1, -3, -4,  0, -2,
            -4, -2,  1,  0, -4, -2, -3,  5, -4,  0, -1, -5, -16,
    /*D*/   -2, -2,  2,  8, -4,  0,  2, -1, -1, -4, -4, -1, -4,
            -5, -1,  0, -1, -5, -3, -4,  6, -4,  1, -1, -5, -16,
    /*C*/   -1, -4, -2, -4, 13, -3, -3, -3, -3, -2, -2, -3, -2,
            -2, -4, -1, -1, -5, -3, -1, -3, -2, -3, -1, -5, -16,
    /*Q*/   -1,  1,  0,  0, -3,  7,  2, -2,  1, -3, -2,  2,  0,
            -4, -1,  0, -1, -1, -1, -3,  0, -3,  4, -1, -5, -16,
    /*E*/   -1,  0,  0,  2, -3,  2,  6, -3,  0, -4, -3,  1, -2,
            -3, -1, -1, -1, -3, -2, -3,  1, -3,  5, -1, -5, -16,
    /*G*/    0, -3,  0, -1, -3, -2, -3,  8, -2, -4, -4, -2, -3,
            -4, -2,  0, -2, -3, -3, -4, -1, -4, -2, -1, -5, -16,
    /*H*/   -2,  0,  1, -1, -3,  1,  0, -2, 10, -4, -3,  0, -1,
            -1, -2, -1, -2, -3,  2, -4,  0, -3,  0, -1, -5, -16,
    /*I*/   -1, -4, -3, -4, -2, -3, -4, -4, -4,  5,  2, -3,  2,
             0, -3, -3, -1, -3, -1,  4, -4,  4, -3, -1, -5, -16,
    /*L*/   -2, -3, -4, -4, -2, -2, -3, -4, -3,  2,  5, -3,  3,
             1, -4, -3, -1, -2, -1,  1, -4,  4, -3, -1, -5, -16,
    /*K*/   -1,  3,  0, -1, -3,  2,  1, -2,  0, -3, -3,  6, -2,
            -4, -1,  0, -1, -3, -2, -3,  0, -3,  1, -1, -5, -16,
    /*M*/   -1, -2, -2, -4, -2,  0, -2, -3, -1,  2,  3, -2,  7,
             0, -3, -2, -1, -1,  0,  1, -3,  2, -1, -1, -5, -16,
    /*F*/   -3, -3, -4, -5, -2, -4, -3, -4, -1,  0,  1, -4,  0,
             8, -4, -3, -2,  1,  4, -1, -4,  1, -4, -1, -5, -16,
    /*P*/   -1, -3, -2, -1, -4, -1, -1, -2, -2, -3, -4, -1, -3,
            -4, 10, -1, -1, -4, -3, -3, -2, -3, -1, -1, -5, -16,
    /*S*/    1, -1,  1,  0, -1,  0, -1,  0, -1, -3, -3,  0, -2,
            -3, -1,  5,  2, -4, -2, -2,  0, -3,  0, -1, -5, -16,
    /*T*/    0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1,
            -2, -1,  2,  5, -3, -2,  0,  0, -1, -1, -1, -5, -16,
    /*W*/   -3, -3, -4, -5, -5, -1, -3, -3, -3, -3, -2, -3, -1,
             1, -4, -4, -3, 15,  2, -3, -5, -2, -2, -1, -5, -16,
    /*Y*/   -2, -1, -2, -3, -3, -1, -2, -3,  2, -1, -1, -2,  0,
             4, -3, -2, -2,  2,  8, -1, -3, -1, -2, -1, -5, -16,
    /*V*/    0, -3, -3, -4, -1, -3, -3, -4, -4,  4,  1, -3,  1,
            -1, -3, -2,  0, -3, -1,  5, -3,  2, -3, -1, -5, -16,
    /*B*/   -2, -1,  5,  6, -3,  0,  1, -1,  0, -4, -4,  0, -3,
            -4, -2,  0,  0, -5, -3, -3,  6, -4,  1, -1, -5, -16,
    /*J*/   -2, -3, -4, -4, -2, -3, -3, -4, -3,  4,  4, -3,  2,
             1, -3, -3, -1, -2, -1,  2, -4,  4, -3, -1, -5, -16,
    /*Z*/   -1,  0,  0,  1, -3,  4,  5, -2,  0, -3, -3,  1, -1,
            -4, -1,  0, -1, -2, -2, -3,  1, -3,  5, -1, -5, -16,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -5, -16,
    /***/   -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
            -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  1, -16,
			-16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16,
			-16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16, -16
};

/** Entries for the BLOSUM62 matrix at a scale of ln(2)/2.0. */
const MatrixTable s_Blosum62PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    4, -1, -2, -2,  0, -1, -1,  0, -2, -1, -1, -1, -1,
            -2, -1,  1,  0, -3, -2,  0, -2, -1, -1, -1, -4, -12,
    /*R*/   -1,  5,  0, -2, -3,  1,  0, -2,  0, -3, -2,  2, -1,
            -3, -2, -1, -1, -3, -2, -3, -1, -2,  0, -1, -4, -12,
    /*N*/   -2,  0,  6,  1, -3,  0,  0,  0,  1, -3, -3,  0, -2,
            -3, -2,  1,  0, -4, -2, -3,  4, -3,  0, -1, -4, -12,
    /*D*/   -2, -2,  1,  6, -3,  0,  2, -1, -1, -3, -4, -1, -3,
            -3, -1,  0, -1, -4, -3, -3,  4, -3,  1, -1, -4, -12,
    /*C*/    0, -3, -3, -3,  9, -3, -4, -3, -3, -1, -1, -3, -1,
            -2, -3, -1, -1, -2, -2, -1, -3, -1, -3, -1, -4, -12,
    /*Q*/   -1,  1,  0,  0, -3,  5,  2, -2,  0, -3, -2,  1,  0,
            -3, -1,  0, -1, -2, -1, -2,  0, -2,  4, -1, -4, -12,
    /*E*/   -1,  0,  0,  2, -4,  2,  5, -2,  0, -3, -3,  1, -2,
            -3, -1,  0, -1, -3, -2, -2,  1, -3,  4, -1, -4, -12,
    /*G*/    0, -2,  0, -1, -3, -2, -2,  6, -2, -4, -4, -2, -3,
            -3, -2,  0, -2, -2, -3, -3, -1, -4, -2, -1, -4, -12,
    /*H*/   -2,  0,  1, -1, -3,  0,  0, -2,  8, -3, -3, -1, -2,
            -1, -2, -1, -2, -2,  2, -3,  0, -3,  0, -1, -4, -12,
    /*I*/   -1, -3, -3, -3, -1, -3, -3, -4, -3,  4,  2, -3,  1,
             0, -3, -2, -1, -3, -1,  3, -3,  3, -3, -1, -4, -12,
    /*L*/   -1, -2, -3, -4, -1, -2, -3, -4, -3,  2,  4, -2,  2,
             0, -3, -2, -1, -2, -1,  1, -4,  3, -3, -1, -4, -12,
    /*K*/   -1,  2,  0, -1, -3,  1,  1, -2, -1, -3, -2,  5, -1,
            -3, -1,  0, -1, -3, -2, -2,  0, -3,  1, -1, -4, -12,
    /*M*/   -1, -1, -2, -3, -1,  0, -2, -3, -2,  1,  2, -1,  5,
             0, -2, -1, -1, -1, -1,  1, -3,  2, -1, -1, -4, -12,
    /*F*/   -2, -3, -3, -3, -2, -3, -3, -3, -1,  0,  0, -3,  0,
             6, -4, -2, -2,  1,  3, -1, -3,  0, -3, -1, -4, -12,
    /*P*/   -1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2,
            -4,  7, -1, -1, -4, -3, -2, -2, -3, -1, -1, -4, -12,
    /*S*/    1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -2,  0, -1,
            -2, -1,  4,  1, -3, -2, -2,  0, -2,  0, -1, -4, -12,
    /*T*/    0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1,
            -2, -1,  1,  5, -2, -2,  0, -1, -1, -1, -1, -4, -12,
    /*W*/   -3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1,
             1, -4, -3, -2, 11,  2, -3, -4, -2, -2, -1, -4, -12,
    /*Y*/   -2, -2, -2, -3, -2, -1, -2, -3,  2, -1, -1, -2, -1,
             3, -3, -2, -2,  2,  7, -1, -3, -1, -2, -1, -4, -12,
    /*V*/    0, -3, -3, -3, -1, -2, -2, -3, -3,  3,  1, -2,  1,
            -1, -2, -2,  0, -3, -1,  4, -3,  2, -2, -1, -4, -12,
    /*B*/   -2, -1,  4,  4, -3,  0,  1, -1,  0, -3, -4,  0, -3,
            -3, -2,  0, -1, -4, -3, -3,  4, -3,  0, -1, -4, -12,
    /*J*/   -1, -2, -3, -3, -1, -2, -3, -4, -3,  3,  3, -3,  2,
             0, -3, -2, -1, -2, -1,  2, -3,  3, -3, -1, -4, -12,
    /*Z*/   -1,  0,  0,  1, -3,  4,  4, -2,  0, -3, -3,  1, -1,
            -3, -1,  0, -1, -2, -2, -2,  0, -3,  4, -1, -4, -12,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -4, -12,
    /***/   -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
            -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,  1, -12,
			-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12,
			-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12
};

const MatrixTable s_Blosum80PSM= {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    5, -2, -2, -2, -1, -1, -1,  0, -2, -2, -2, -1, -1,
            -3, -1,  1,  0, -3, -2,  0, -2, -2, -1, -1, -6, -12,
    /*R*/   -2,  6, -1, -2, -4,  1, -1, -3,  0, -3, -3,  2, -2,
            -4, -2, -1, -1, -4, -3, -3, -1, -3,  0, -1, -6, -12,
    /*N*/   -2, -1,  6,  1, -3,  0, -1, -1,  0, -4, -4,  0, -3,
            -4, -3,  0,  0, -4, -3, -4,  5, -4,  0, -1, -6, -12,
    /*D*/   -2, -2,  1,  6, -4, -1,  1, -2, -2, -4, -5, -1, -4,
            -4, -2, -1, -1, -6, -4, -4,  5, -5,  1, -1, -6, -12,
    /*C*/   -1, -4, -3, -4,  9, -4, -5, -4, -4, -2, -2, -4, -2,
            -3, -4, -2, -1, -3, -3, -1, -4, -2, -4, -1, -6, -12,
    /*Q*/   -1,  1,  0, -1, -4,  6,  2, -2,  1, -3, -3,  1,  0,
            -4, -2,  0, -1, -3, -2, -3,  0, -3,  4, -1, -6, -12,
    /*E*/   -1, -1, -1,  1, -5,  2,  6, -3,  0, -4, -4,  1, -2,
            -4, -2,  0, -1, -4, -3, -3,  1, -4,  5, -1, -6, -12,
    /*G*/    0, -3, -1, -2, -4, -2, -3,  6, -3, -5, -4, -2, -4,
            -4, -3, -1, -2, -4, -4, -4, -1, -5, -3, -1, -6, -12,
    /*H*/   -2,  0,  0, -2, -4,  1,  0, -3,  8, -4, -3, -1, -2,
            -2, -3, -1, -2, -3,  2, -4, -1, -4,  0, -1, -6, -12,
    /*I*/   -2, -3, -4, -4, -2, -3, -4, -5, -4,  5,  1, -3,  1,
            -1, -4, -3, -1, -3, -2,  3, -4,  3, -4, -1, -6, -12,
    /*L*/   -2, -3, -4, -5, -2, -3, -4, -4, -3,  1,  4, -3,  2,
             0, -3, -3, -2, -2, -2,  1, -4,  3, -3, -1, -6, -12,
    /*K*/   -1,  2,  0, -1, -4,  1,  1, -2, -1, -3, -3,  5, -2,
            -4, -1, -1, -1, -4, -3, -3, -1, -3,  1, -1, -6, -12,
    /*M*/   -1, -2, -3, -4, -2,  0, -2, -4, -2,  1,  2, -2,  6,
             0, -3, -2, -1, -2, -2,  1, -3,  2, -1, -1, -6, -12,
    /*F*/   -3, -4, -4, -4, -3, -4, -4, -4, -2, -1,  0, -4,  0,
             6, -4, -3, -2,  0,  3, -1, -4,  0, -4, -1, -6, -12,
    /*P*/   -1, -2, -3, -2, -4, -2, -2, -3, -3, -4, -3, -1, -3,
            -4,  8, -1, -2, -5, -4, -3, -2, -4, -2, -1, -6, -12,
    /*S*/    1, -1,  0, -1, -2,  0,  0, -1, -1, -3, -3, -1, -2,
            -3, -1,  5,  1, -4, -2, -2,  0, -3,  0, -1, -6, -12,
    /*T*/    0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -2, -1, -1,
            -2, -2,  1,  5, -4, -2,  0, -1, -1, -1, -1, -6, -12,
    /*W*/   -3, -4, -4, -6, -3, -3, -4, -4, -3, -3, -2, -4, -2,
             0, -5, -4, -4, 11,  2, -3, -5, -3, -3, -1, -6, -12,
    /*Y*/   -2, -3, -3, -4, -3, -2, -3, -4,  2, -2, -2, -3, -2,
             3, -4, -2, -2,  2,  7, -2, -3, -2, -3, -1, -6, -12,
    /*V*/    0, -3, -4, -4, -1, -3, -3, -4, -4,  3,  1, -3,  1,
            -1, -3, -2,  0, -3, -2,  4, -4,  2, -3, -1, -6, -12,
    /*B*/   -2, -1,  5,  5, -4,  0,  1, -1, -1, -4, -4, -1, -3,
            -4, -2,  0, -1, -5, -3, -4,  5, -4,  0, -1, -6, -12,
    /*J*/   -2, -3, -4, -5, -2, -3, -4, -5, -4,  3,  3, -3,  2,
             0, -4, -3, -1, -3, -2,  2, -4,  3, -3, -1, -6, -12,
    /*Z*/   -1,  0,  0,  1, -4,  4,  5, -3,  0, -4, -3,  1, -1,
            -4, -2,  0, -1, -3, -3, -3,  0, -3,  5, -1, -6, -12,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -6, -12,
    /***/   -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
            -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  1, -12,
			 -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12,
			 -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12
};

const MatrixTable s_Blosum90PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    5, -2, -2, -3, -1, -1, -1,  0, -2, -2, -2, -1, -2,
            -3, -1,  1,  0, -4, -3, -1, -2, -2, -1, -1, -6, -12,
    /*R*/   -2,  6, -1, -3, -5,  1, -1, -3,  0, -4, -3,  2, -2,
            -4, -3, -1, -2, -4, -3, -3, -2, -3,  0, -1, -6, -12,
    /*N*/   -2, -1,  7,  1, -4,  0, -1, -1,  0, -4, -4,  0, -3,
            -4, -3,  0,  0, -5, -3, -4,  5, -4, -1, -1, -6, -12,
    /*D*/   -3, -3,  1,  7, -5, -1,  1, -2, -2, -5, -5, -1, -4,
            -5, -3, -1, -2, -6, -4, -5,  5, -5,  1, -1, -6, -12,
    /*C*/   -1, -5, -4, -5,  9, -4, -6, -4, -5, -2, -2, -4, -2,
            -3, -4, -2, -2, -4, -4, -2, -4, -2, -5, -1, -6, -12,
    /*Q*/   -1,  1,  0, -1, -4,  7,  2, -3,  1, -4, -3,  1,  0,
            -4, -2, -1, -1, -3, -3, -3, -1, -3,  5, -1, -6, -12,
    /*E*/   -1, -1, -1,  1, -6,  2,  6, -3, -1, -4, -4,  0, -3,
            -5, -2, -1, -1, -5, -4, -3,  1, -4,  5, -1, -6, -12,
    /*G*/    0, -3, -1, -2, -4, -3, -3,  6, -3, -5, -5, -2, -4,
            -5, -3, -1, -3, -4, -5, -5, -2, -5, -3, -1, -6, -12,
    /*H*/   -2,  0,  0, -2, -5,  1, -1, -3,  8, -4, -4, -1, -3,
            -2, -3, -2, -2, -3,  1, -4, -1, -4,  0, -1, -6, -12,
    /*I*/   -2, -4, -4, -5, -2, -4, -4, -5, -4,  5,  1, -4,  1,
            -1, -4, -3, -1, -4, -2,  3, -5,  3, -4, -1, -6, -12,
    /*L*/   -2, -3, -4, -5, -2, -3, -4, -5, -4,  1,  5, -3,  2,
             0, -4, -3, -2, -3, -2,  0, -5,  4, -4, -1, -6, -12,
    /*K*/   -1,  2,  0, -1, -4,  1,  0, -2, -1, -4, -3,  6, -2,
            -4, -2, -1, -1, -5, -3, -3, -1, -3,  1, -1, -6, -12,
    /*M*/   -2, -2, -3, -4, -2,  0, -3, -4, -3,  1,  2, -2,  7,
            -1, -3, -2, -1, -2, -2,  0, -4,  2, -2, -1, -6, -12,
    /*F*/   -3, -4, -4, -5, -3, -4, -5, -5, -2, -1,  0, -4, -1,
             7, -4, -3, -3,  0,  3, -2, -4,  0, -4, -1, -6, -12,
    /*P*/   -1, -3, -3, -3, -4, -2, -2, -3, -3, -4, -4, -2, -3,
            -4,  8, -2, -2, -5, -4, -3, -3, -4, -2, -1, -6, -12,
    /*S*/    1, -1,  0, -1, -2, -1, -1, -1, -2, -3, -3, -1, -2,
            -3, -2,  5,  1, -4, -3, -2,  0, -3, -1, -1, -6, -12,
    /*T*/    0, -2,  0, -2, -2, -1, -1, -3, -2, -1, -2, -1, -1,
            -3, -2,  1,  6, -4, -2, -1, -1, -2, -1, -1, -6, -12,
    /*W*/   -4, -4, -5, -6, -4, -3, -5, -4, -3, -4, -3, -5, -2,
             0, -5, -4, -4, 11,  2, -3, -6, -3, -4, -1, -6, -12,
    /*Y*/   -3, -3, -3, -4, -4, -3, -4, -5,  1, -2, -2, -3, -2,
             3, -4, -3, -2,  2,  8, -3, -4, -2, -3, -1, -6, -12,
    /*V*/   -1, -3, -4, -5, -2, -3, -3, -5, -4,  3,  0, -3,  0,
            -2, -3, -2, -1, -3, -3,  5, -4,  1, -3, -1, -6, -12,
    /*B*/   -2, -2,  5,  5, -4, -1,  1, -2, -1, -5, -5, -1, -4,
            -4, -3,  0, -1, -6, -4, -4,  5, -5,  0, -1, -6, -12,
    /*J*/   -2, -3, -4, -5, -2, -3, -4, -5, -4,  3,  4, -3,  2,
             0, -4, -3, -2, -3, -2,  1, -5,  4, -4, -1, -6, -12,
    /*Z*/   -1,  0, -1,  1, -5,  5,  5, -3,  0, -4, -4,  1, -2,
            -4, -2, -1, -1, -4, -3, -3,  0, -4,  5, -1, -6, -12,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -6, -12,
    /***/   -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
            -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,  1, -12,
			-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12,
			-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12
};

const MatrixTable s_Pam250PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    2, -2,  0,  0, -2,  0,  0,  1, -1, -1, -2, -1, -1,
            -3,  1,  1,  1, -6, -3,  0,  0, -1,  0, -1, -8, -18,
    /*R*/   -2,  6,  0, -1, -4,  1, -1, -3,  2, -2, -3,  3,  0,
            -4,  0,  0, -1,  2, -4, -2, -1, -3,  0, -1, -8, -18,
    /*N*/    0,  0,  2,  2, -4,  1,  1,  0,  2, -2, -3,  1, -2,
            -3,  0,  1,  0, -4, -2, -2,  2, -3,  1, -1, -8, -18,
    /*D*/    0, -1,  2,  4, -5,  2,  3,  1,  1, -2, -4,  0, -3,
            -6, -1,  0,  0, -7, -4, -2,  3, -3,  3, -1, -8, -18,
    /*C*/   -2, -4, -4, -5, 12, -5, -5, -3, -3, -2, -6, -5, -5,
            -4, -3,  0, -2, -8,  0, -2, -4, -5, -5, -1, -8, -18,
    /*Q*/    0,  1,  1,  2, -5,  4,  2, -1,  3, -2, -2,  1, -1,
            -5,  0, -1, -1, -5, -4, -2,  1, -2,  3, -1, -8, -18,
    /*E*/    0, -1,  1,  3, -5,  2,  4,  0,  1, -2, -3,  0, -2,
            -5, -1,  0,  0, -7, -4, -2,  3, -3,  3, -1, -8, -18,
    /*G*/    1, -3,  0,  1, -3, -1,  0,  5, -2, -3, -4, -2, -3,
            -5,  0,  1,  0, -7, -5, -1,  0, -4,  0, -1, -8, -18,
    /*H*/   -1,  2,  2,  1, -3,  3,  1, -2,  6, -2, -2,  0, -2,
            -2,  0, -1, -1, -3,  0, -2,  1, -2,  2, -1, -8, -18,
    /*I*/   -1, -2, -2, -2, -2, -2, -2, -3, -2,  5,  2, -2,  2,
             1, -2, -1,  0, -5, -1,  4, -2,  3, -2, -1, -8, -18,
    /*L*/   -2, -3, -3, -4, -6, -2, -3, -4, -2,  2,  6, -3,  4,
             2, -3, -3, -2, -2, -1,  2, -3,  5, -3, -1, -8, -18,
    /*K*/   -1,  3,  1,  0, -5,  1,  0, -2,  0, -2, -3,  5,  0,
            -5, -1,  0,  0, -3, -4, -2,  1, -3,  0, -1, -8, -18,
    /*M*/   -1,  0, -2, -3, -5, -1, -2, -3, -2,  2,  4,  0,  6,
             0, -2, -2, -1, -4, -2,  2, -2,  3, -2, -1, -8, -18,
    /*F*/   -3, -4, -3, -6, -4, -5, -5, -5, -2,  1,  2, -5,  0,
             9, -5, -3, -3,  0,  7, -1, -4,  2, -5, -1, -8, -18,
    /*P*/    1,  0,  0, -1, -3,  0, -1,  0,  0, -2, -3, -1, -2,
            -5,  6,  1,  0, -6, -5, -1, -1, -2,  0, -1, -8, -18,
    /*S*/    1,  0,  1,  0,  0, -1,  0,  1, -1, -1, -3,  0, -2,
            -3,  1,  2,  1, -2, -3, -1,  0, -2,  0, -1, -8, -18,
    /*T*/    1, -1,  0,  0, -2, -1,  0,  0, -1,  0, -2,  0, -1,
            -3,  0,  1,  3, -5, -3,  0,  0, -1, -1, -1, -8, -18,
    /*W*/   -6,  2, -4, -7, -8, -5, -7, -7, -3, -5, -2, -3, -4,
             0, -6, -2, -5, 17,  0, -6, -5, -3, -6, -1, -8, -18,
    /*Y*/   -3, -4, -2, -4,  0, -4, -4, -5,  0, -1, -1, -4, -2,
             7, -5, -3, -3,  0, 10, -2, -3, -1, -4, -1, -8, -18,
    /*V*/    0, -2, -2, -2, -2, -2, -2, -1, -2,  4,  2, -2,  2,
            -1, -1, -1,  0, -6, -2,  4, -2,  2, -2, -1, -8, -18,
    /*B*/    0, -1,  2,  3, -4,  1,  3,  0,  1, -2, -3,  1, -2,
            -4, -1,  0,  0, -5, -3, -2,  3, -3,  2, -1, -8, -18,
    /*J*/   -1, -3, -3, -3, -5, -2, -3, -4, -2,  3,  5, -3,  3,
             2, -2, -2, -1, -3, -1,  2, -3,  5, -2, -1, -8, -18,
    /*Z*/    0,  0,  1,  3, -5,  3,  3,  0,  2, -2, -3,  0, -2,
            -5,  0,  0, -1, -6, -4, -2,  2, -2,  3, -1, -8, -18,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -8, -18,
    /***/   -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
            -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1, -18,
			-18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18,
			-18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18, -18
};

const MatrixTable s_Pam30PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    6, -7, -4, -3, -6, -4, -2, -2, -7, -5, -6, -7, -5,
            -8, -2,  0, -1,-13, -8, -2, -3, -6, -3, -1,-17, -17,
    /*R*/   -7,  8, -6,-10, -8, -2, -9, -9, -2, -5, -8,  0, -4,
            -9, -4, -3, -6, -2,-10, -8, -7, -7, -4, -1,-17, -17,
    /*N*/   -4, -6,  8,  2,-11, -3, -2, -3,  0, -5, -7, -1, -9,
            -9, -6,  0, -2, -8, -4, -8,  6, -6, -3, -1,-17, -17,
    /*D*/   -3,-10,  2,  8,-14, -2,  2, -3, -4, -7,-12, -4,-11,
           -15, -8, -4, -5,-15,-11, -8,  6,-10,  1, -1,-17, -17,
    /*C*/   -6, -8,-11,-14, 10,-14,-14, -9, -7, -6,-15,-14,-13,
           -13, -8, -3, -8,-15, -4, -6,-12, -9,-14, -1,-17, -17,
    /*Q*/   -4, -2, -3, -2,-14,  8,  1, -7,  1, -8, -5, -3, -4,
           -13, -3, -5, -5,-13,-12, -7, -3, -5,  6, -1,-17, -17,
    /*E*/   -2, -9, -2,  2,-14,  1,  8, -4, -5, -5, -9, -4, -7,
           -14, -5, -4, -6,-17, -8, -6,  1, -7,  6, -1,-17, -17,
    /*G*/   -2, -9, -3, -3, -9, -7, -4,  6, -9,-11,-10, -7, -8,
            -9, -6, -2, -6,-15,-14, -5, -3,-10, -5, -1,-17, -17,
    /*H*/   -7, -2,  0, -4, -7,  1, -5, -9,  9, -9, -6, -6,-10,
            -6, -4, -6, -7, -7, -3, -6, -1, -7, -1, -1,-17, -17,
    /*I*/   -5, -5, -5, -7, -6, -8, -5,-11, -9,  8, -1, -6, -1,
            -2, -8, -7, -2,-14, -6,  2, -6,  5, -6, -1,-17, -17,
    /*L*/   -6, -8, -7,-12,-15, -5, -9,-10, -6, -1,  7, -8,  1,
            -3, -7, -8, -7, -6, -7, -2, -9,  6, -7, -1,-17, -17,
    /*K*/   -7,  0, -1, -4,-14, -3, -4, -7, -6, -6, -8,  7, -2,
           -14, -6, -4, -3,-12, -9, -9, -2, -7, -4, -1,-17, -17,
    /*M*/   -5, -4, -9,-11,-13, -4, -7, -8,-10, -1,  1, -2, 11,
            -4, -8, -5, -4,-13,-11, -1,-10,  0, -5, -1,-17, -17,
    /*F*/   -8, -9, -9,-15,-13,-13,-14, -9, -6, -2, -3,-14, -4,
             9,-10, -6, -9, -4,  2, -8,-10, -2,-13, -1,-17, -17,
    /*P*/   -2, -4, -6, -8, -8, -3, -5, -6, -4, -8, -7, -6, -8,
           -10,  8, -2, -4,-14,-13, -6, -7, -7, -4, -1,-17, -17,
    /*S*/    0, -3,  0, -4, -3, -5, -4, -2, -6, -7, -8, -4, -5,
            -6, -2,  6,  0, -5, -7, -6, -1, -8, -5, -1,-17, -17,
    /*T*/   -1, -6, -2, -5, -8, -5, -6, -6, -7, -2, -7, -3, -4,
            -9, -4,  0,  7,-13, -6, -3, -3, -5, -6, -1,-17, -17,
    /*W*/  -13, -2, -8,-15,-15,-13,-17,-15, -7,-14, -6,-12,-13,
            -4,-14, -5,-13, 13, -5,-15,-10, -7,-14, -1,-17, -17,
    /*Y*/   -8,-10, -4,-11, -4,-12, -8,-14, -3, -6, -7, -9,-11,
             2,-13, -7, -6, -5, 10, -7, -6, -7, -9, -1,-17, -17,
    /*V*/   -2, -8, -8, -8, -6, -7, -6, -5, -6,  2, -2, -9, -1,
            -8, -6, -6, -3,-15, -7,  7, -8,  0, -6, -1,-17, -17,
    /*B*/   -3, -7,  6,  6,-12, -3,  1, -3, -1, -6, -9, -2,-10,
           -10, -7, -1, -3,-10, -6, -8,  6, -8,  0, -1,-17, -17,
    /*J*/   -6, -7, -6,-10, -9, -5, -7,-10, -7,  5,  6, -7,  0,
            -2, -7, -8, -5, -7, -7,  0, -8,  6, -6, -1,-17, -17,
    /*Z*/   -3, -4, -3,  1,-14,  6,  6, -5, -1, -6, -7, -4, -5,
           -13, -4, -5, -6,-14, -9, -6,  0, -6,  6, -1,-17, -17,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-17, -17,
    /***/  -17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,
           -17,-17,-17,-17,-17,-17,-17,-17,-17,-17,-17,  1, -17,
			-17, -17, -17, -17, -17, -17, -17, -17, -17, -17, -17, -17, -17,
			-17, -17, -17, -17, -17, -17, -17, -17, -17, -17, -17, -17, -17
};

const MatrixTable s_Pam70PSM = {
    /*       A,  R,  N,  D,  C,  Q,  E,  G,  H,  I,  L,  K,  M,
             F,  P,  S,  T,  W,  Y,  V,  B,  J,  Z,  X,  *        */ 
    /*A*/    5, -4, -2, -1, -4, -2, -1,  0, -4, -2, -4, -4, -3,
            -6,  0,  1,  1, -9, -5, -1, -1, -3, -1, -1,-11, -14,
    /*R*/   -4,  8, -3, -6, -5,  0, -5, -6,  0, -3, -6,  2, -2,
            -7, -2, -1, -4,  0, -7, -5, -4, -5, -2, -1,-11, -14,
    /*N*/   -2, -3,  6,  3, -7, -1,  0, -1,  1, -3, -5,  0, -5,
            -6, -3,  1,  0, -6, -3, -5,  5, -4, -1, -1,-11, -14,
    /*D*/   -1, -6,  3,  6, -9,  0,  3, -1, -1, -5, -8, -2, -7,
           -10, -4, -1, -2,-10, -7, -5,  5, -7,  2, -1,-11, -14,
    /*C*/   -4, -5, -7, -9,  9, -9, -9, -6, -5, -4,-10, -9, -9,
            -8, -5, -1, -5,-11, -2, -4, -8, -7, -9, -1,-11, -14,
    /*Q*/   -2,  0, -1,  0, -9,  7,  2, -4,  2, -5, -3, -1, -2,
            -9, -1, -3, -3, -8, -8, -4, -1, -3,  5, -1,-11, -14,
    /*E*/   -1, -5,  0,  3, -9,  2,  6, -2, -2, -4, -6, -2, -4,
            -9, -3, -2, -3,-11, -6, -4,  2, -5,  5, -1,-11, -14,
    /*G*/    0, -6, -1, -1, -6, -4, -2,  6, -6, -6, -7, -5, -6,
            -7, -3,  0, -3,-10, -9, -3, -1, -7, -3, -1,-11, -14,
    /*H*/   -4,  0,  1, -1, -5,  2, -2, -6,  8, -6, -4, -3, -6,
            -4, -2, -3, -4, -5, -1, -4,  0, -4,  1, -1,-11, -14,
    /*I*/   -2, -3, -3, -5, -4, -5, -4, -6, -6,  7,  1, -4,  1,
             0, -5, -4, -1, -9, -4,  3, -4,  4, -4, -1,-11, -14,
    /*L*/   -4, -6, -5, -8,-10, -3, -6, -7, -4,  1,  6, -5,  2,
            -1, -5, -6, -4, -4, -4,  0, -6,  5, -4, -1,-11, -14,
    /*K*/   -4,  2,  0, -2, -9, -1, -2, -5, -3, -4, -5,  6,  0,
            -9, -4, -2, -1, -7, -7, -6, -1, -5, -2, -1,-11, -14,
    /*M*/   -3, -2, -5, -7, -9, -2, -4, -6, -6,  1,  2,  0, 10,
            -2, -5, -3, -2, -8, -7,  0, -6,  2, -3, -1,-11, -14,
    /*F*/   -6, -7, -6,-10, -8, -9, -9, -7, -4,  0, -1, -9, -2,
             8, -7, -4, -6, -2,  4, -5, -7, -1, -9, -1,-11, -14,
    /*P*/    0, -2, -3, -4, -5, -1, -3, -3, -2, -5, -5, -4, -5,
            -7,  7,  0, -2, -9, -9, -3, -4, -5, -2, -1,-11, -14,
    /*S*/    1, -1,  1, -1, -1, -3, -2,  0, -3, -4, -6, -2, -3,
            -4,  0,  5,  2, -3, -5, -3,  0, -5, -2, -1,-11, -14,
    /*T*/    1, -4,  0, -2, -5, -3, -3, -3, -4, -1, -4, -1, -2,
            -6, -2,  2,  6, -8, -4, -1, -1, -3, -3, -1,-11, -14,
    /*W*/   -9,  0, -6,-10,-11, -8,-11,-10, -5, -9, -4, -7, -8,
            -2, -9, -3, -8, 13, -3,-10, -7, -5,-10, -1,-11, -14,
    /*Y*/   -5, -7, -3, -7, -2, -8, -6, -9, -1, -4, -4, -7, -7,
             4, -9, -5, -4, -3,  9, -5, -4, -4, -7, -1,-11, -14,
    /*V*/   -1, -5, -5, -5, -4, -4, -4, -3, -4,  3,  0, -6,  0,
            -5, -3, -3, -1,-10, -5,  6, -5,  1, -4, -1,-11, -14,
    /*B*/   -1, -4,  5,  5, -8, -1,  2, -1,  0, -4, -6, -1, -6,
            -7, -4,  0, -1, -7, -4, -5,  5, -5,  1, -1,-11, -14,
    /*J*/   -3, -5, -4, -7, -7, -3, -5, -7, -4,  4,  5, -5,  2,
            -1, -5, -5, -3, -5, -4,  1, -5,  5, -4, -1,-11, -14,
    /*Z*/   -1, -2, -1,  2, -9,  5,  5, -3,  1, -4, -4, -2, -3,
            -9, -2, -2, -3,-10, -7, -4,  1, -4,  5, -1,-11, -14,
    /*X*/   -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-11, -14,
    /***/  -11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,
           -11,-11,-11,-11,-11,-11,-11,-11,-11,-11,-11,  1, -14,
		   -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14,
		   -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14
};
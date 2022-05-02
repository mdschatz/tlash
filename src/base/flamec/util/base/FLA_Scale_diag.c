/*
   libflame
   An object-based infrastructure for developing high-performance
   dense linear algebra libraries.

   Copyright (C) 2011, The University of Texas

   libflame is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.

   libflame is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with libflame; if you did not receive a copy, see
   http://www.gnu.org/licenses/.

   For more information, please contact us at flame@cs.utexas.edu or
   send mail to:

   Field G. Van Zee and/or
   Robert A. van de Geijn
   The University of Texas at Austin
   Department of Computer Sciences
   1 University Station C0500
   Austin TX 78712
*/

#include "FLAME.h"

FLA_Error FLA_Scale_diag( FLA_Conj conj, FLA_Obj alpha, FLA_Obj A )
{
  FLA_Datatype datatype_A;
  FLA_Datatype datatype_alpha;
  dim_t        m_A, n_A;
  dim_t        rs_A, cs_A;
  conj_t       blis_conj;

  if ( FLA_Check_error_level() >= FLA_MIN_ERROR_CHECKING )
    FLA_Scale_diag_check( conj, alpha, A );

  datatype_A     = FLA_Obj_datatype( A );
  datatype_alpha = FLA_Obj_datatype( alpha );
  m_A            = FLA_Obj_length( A );
  n_A            = FLA_Obj_width( A );
  rs_A           = FLA_Obj_row_stride( A );
  cs_A           = FLA_Obj_col_stride( A );

  FLA_Param_map_flame_to_blis_conj( conj, &blis_conj );

  switch( datatype_A ){

  case FLA_FLOAT:
  {
    float *buff_A     = ( float * ) FLA_FLOAT_PTR( A );
    float *buff_alpha = ( float * ) FLA_FLOAT_PTR( alpha );

    bli_sscalediag( blis_conj,
                    0,
                    m_A,
                    n_A,
                    buff_alpha,
                    buff_A, rs_A, cs_A );

    break;
  }
  case FLA_DOUBLE:
  {
    double *buff_A     = ( double * ) FLA_DOUBLE_PTR( A );
    double *buff_alpha = ( double * ) FLA_DOUBLE_PTR( alpha );

    bli_dscalediag( blis_conj,
                    0,
                    m_A,
                    n_A,
                    buff_alpha,
                    buff_A, rs_A, cs_A );

    break;
  }

  case FLA_COMPLEX:
  {
    if ( datatype_alpha == FLA_COMPLEX )
    {
      scomplex *buff_A     = ( scomplex * ) FLA_COMPLEX_PTR( A );
      scomplex *buff_alpha = ( scomplex * ) FLA_COMPLEX_PTR( alpha );

      bli_cscalediag( blis_conj,
                      0,
                      m_A,
                      n_A,
                      buff_alpha,
                      buff_A, rs_A, cs_A );
    }
    else
    {
     scomplex *buff_A     = ( scomplex * ) FLA_COMPLEX_PTR( A );
      float    *buff_alpha = ( float    * ) FLA_FLOAT_PTR( alpha );

      bli_csscalediag( blis_conj,
                       0,
                       m_A,
                       n_A,
                       buff_alpha,
                       buff_A, rs_A, cs_A );
    }

    break;
  }

  case FLA_DOUBLE_COMPLEX:
  {
    if ( datatype_alpha == FLA_DOUBLE_COMPLEX )
    {
      dcomplex *buff_A     = ( dcomplex * ) FLA_DOUBLE_COMPLEX_PTR( A );
      dcomplex *buff_alpha = ( dcomplex * ) FLA_DOUBLE_COMPLEX_PTR( alpha );

      bli_zscalediag( blis_conj,
                      0,
                      m_A,
                      n_A,
                      buff_alpha,
                      buff_A, rs_A, cs_A );
    }
    else
    {
      dcomplex *buff_A     = ( dcomplex * ) FLA_DOUBLE_COMPLEX_PTR( A );
      double   *buff_alpha = ( double   * ) FLA_DOUBLE_PTR( alpha );

      bli_zdscalediag( blis_conj,
                       0,
                       m_A,
                       n_A,
                       buff_alpha,
                       buff_A, rs_A, cs_A );
    }

    break;
  }

  }

  return FLA_SUCCESS;
}


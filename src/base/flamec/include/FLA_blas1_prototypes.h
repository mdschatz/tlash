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

// --- top-level wrapper prototypes --------------------------------------------

FLA_Error FLA_Asum( FLA_Obj x, FLA_Obj asum_x );
FLA_Error FLA_Axpy( FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Axpys( FLA_Obj alpha0, FLA_Obj alpha1, FLA_Obj A, FLA_Obj beta, FLA_Obj B );
FLA_Error FLA_Axpyt( FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Axpyrt( FLA_Uplo uplo, FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copy( FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyr( FLA_Uplo uplo, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyrt( FLA_Uplo uplo, FLA_Trans trans, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyt( FLA_Trans trans, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyr( FLA_Uplo uplo, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Dot( FLA_Obj x, FLA_Obj y, FLA_Obj rho );
FLA_Error FLA_Dot2cs( FLA_Conj conj, FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dot2s( FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dotc( FLA_Conj conj, FLA_Obj x, FLA_Obj y, FLA_Obj rho );
FLA_Error FLA_Dotcs( FLA_Conj conj, FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dots( FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Amax( FLA_Obj x, FLA_Obj index );
FLA_Error FLA_Inv_scal( FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Inv_scalc( FLA_Conj conjalpha, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Nrm2( FLA_Obj x, FLA_Obj norm_x );
FLA_Error FLA_Scal( FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Scalc( FLA_Conj conjalpha, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Scalr( FLA_Uplo uplo, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Swap( FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Swapt( FLA_Trans trans, FLA_Obj A, FLA_Obj B );


// --- task wrapper prototypes -------------------------------------------------

FLA_Error FLA_Axpy_task( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpy_t* cntl );
FLA_Error FLA_Axpyt_task( FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpyt_t* cntl );
FLA_Error FLA_Copy_task( FLA_Obj A, FLA_Obj B, fla_copy_t* cntl );
FLA_Error FLA_Copyt_task( FLA_Trans trans, FLA_Obj A, FLA_Obj B, fla_copyt_t* cntl );
FLA_Error FLA_Copyr_task( FLA_Uplo uplo, FLA_Obj A, FLA_Obj B, fla_copyr_t* cntl );
FLA_Error FLA_Scal_task( FLA_Obj alpha, FLA_Obj A, fla_scal_t* cntl );
FLA_Error FLA_Scalr_task( FLA_Uplo uplo, FLA_Obj alpha, FLA_Obj A, fla_scalr_t* cntl );

FLA_Error FLA_Axpyt_n_task( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpyt_t* cntl );
FLA_Error FLA_Axpyt_t_task( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpyt_t* cntl );
FLA_Error FLA_Axpyt_c_task( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpyt_t* cntl );
FLA_Error FLA_Axpyt_h_task( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpyt_t* cntl );

FLA_Error FLA_Copyt_n_task( FLA_Obj A, FLA_Obj B, fla_copyt_t* cntl );
FLA_Error FLA_Copyt_t_task( FLA_Obj A, FLA_Obj B, fla_copyt_t* cntl );
FLA_Error FLA_Copyt_c_task( FLA_Obj A, FLA_Obj B, fla_copyt_t* cntl );
FLA_Error FLA_Copyt_h_task( FLA_Obj A, FLA_Obj B, fla_copyt_t* cntl );

FLA_Error FLA_Copyr_l_task( FLA_Obj A, FLA_Obj B, fla_copyr_t* cntl );
FLA_Error FLA_Copyr_u_task( FLA_Obj A, FLA_Obj B, fla_copyr_t* cntl );

FLA_Error FLA_Scalr_l_task( FLA_Obj alpha, FLA_Obj A, fla_scalr_t* cntl );
FLA_Error FLA_Scalr_u_task( FLA_Obj alpha, FLA_Obj A, fla_scalr_t* cntl );


// --- external wrapper prototypes ---------------------------------------------

FLA_Error FLA_Asum_external( FLA_Obj x, FLA_Obj asum_x );
FLA_Error FLA_Axpy_external( FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Axpys_external( FLA_Obj alpha0, FLA_Obj alpha1, FLA_Obj A, FLA_Obj beta, FLA_Obj B );
FLA_Error FLA_Axpyt_external( FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Axpyrt_external( FLA_Uplo uplo, FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copy_external( FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyr_external( FLA_Uplo uplo, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyrt_external( FLA_Uplo uplo, FLA_Trans trans, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyt_external( FLA_Trans trans, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Dot_external( FLA_Obj x, FLA_Obj y, FLA_Obj rho );
FLA_Error FLA_Dotc_external( FLA_Conj conj, FLA_Obj x, FLA_Obj y, FLA_Obj rho );
FLA_Error FLA_Dots_external( FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dotcs_external( FLA_Conj conj, FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dot2s_external( FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dot2cs_external( FLA_Conj conj, FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Amax_external( FLA_Obj x, FLA_Obj index );
FLA_Error FLA_Inv_scal_external( FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Inv_scalc_external( FLA_Conj conjalpha, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Nrm2_external( FLA_Obj x, FLA_Obj nrm_x );
FLA_Error FLA_Scal_external( FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Scalc_external( FLA_Conj conjalpha, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Scalr_external( FLA_Uplo uplo, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Swap_external( FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Swapt_external( FLA_Trans trans, FLA_Obj A, FLA_Obj B );


// --- gpu wrapper prototypes --------------------------------------------------

FLA_Error FLA_Axpy_external_gpu( FLA_Obj alpha, FLA_Obj A, void* A_gpu, FLA_Obj B, void* B_gpu );
FLA_Error FLA_Copy_external_gpu( FLA_Obj A, void* A_gpu, FLA_Obj B, void* B_gpu );
FLA_Error FLA_Scal_external_gpu( FLA_Obj alpha, FLA_Obj A, void* A_gpu );
FLA_Error FLA_Scalr_external_gpu( FLA_Uplo uplo, FLA_Obj alpha, FLA_Obj A, void* A_gpu );


// --- check routine prototypes ------------------------------------------------

// front-ends
FLA_Error FLA_Asum_check( FLA_Obj x, FLA_Obj asum_x );
FLA_Error FLA_Axpy_check( FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Axpys_check( FLA_Obj alpha0, FLA_Obj alpha1, FLA_Obj A, FLA_Obj beta, FLA_Obj B );
FLA_Error FLA_Axpyt_check( FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Axpyrt_check( FLA_Uplo uplo, FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copy_check( FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyr_check( FLA_Uplo uplo, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyrt_check( FLA_Uplo uplo, FLA_Trans trans, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Copyt_check( FLA_Trans trans, FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Dot_check( FLA_Obj x, FLA_Obj y, FLA_Obj rho );
FLA_Error FLA_Dotc_check( FLA_Conj conj, FLA_Obj x, FLA_Obj y, FLA_Obj rho );
FLA_Error FLA_Dots_check( FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dotcs_check( FLA_Conj conj, FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dot2s_check( FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Dot2cs_check( FLA_Conj conj, FLA_Obj alpha, FLA_Obj x, FLA_Obj y, FLA_Obj beta, FLA_Obj rho );
FLA_Error FLA_Amax_check( FLA_Obj x, FLA_Obj index );
FLA_Error FLA_Inv_scal_check( FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Inv_scalc_check( FLA_Conj conjalpha, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Nrm2_check( FLA_Obj x, FLA_Obj nrm_x );
FLA_Error FLA_Scal_check( FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Scalc_check( FLA_Conj conjalpha, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Scalr_check( FLA_Uplo uplo, FLA_Obj alpha, FLA_Obj A );
FLA_Error FLA_Swap_check( FLA_Obj A, FLA_Obj B );
FLA_Error FLA_Swapt_check( FLA_Trans trans, FLA_Obj A, FLA_Obj B );

// internal back-ends
FLA_Error FLA_Axpy_internal_check( FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpy_t* cntl );
FLA_Error FLA_Axpyt_internal_check( FLA_Trans trans, FLA_Obj alpha, FLA_Obj A, FLA_Obj B, fla_axpyt_t* cntl );
FLA_Error FLA_Copy_internal_check( FLA_Obj A, FLA_Obj B, fla_copy_t* cntl );
FLA_Error FLA_Copyt_internal_check( FLA_Trans trans, FLA_Obj A, FLA_Obj B, fla_copyt_t* cntl );
FLA_Error FLA_Copyr_internal_check( FLA_Uplo uplo, FLA_Obj A, FLA_Obj B, fla_copyr_t* cntl );
FLA_Error FLA_Scal_internal_check( FLA_Obj alpha, FLA_Obj A, fla_scal_t* cntl );
FLA_Error FLA_Scalr_internal_check( FLA_Uplo uplo, FLA_Obj alpha, FLA_Obj A, fla_scalr_t* cntl );


/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "add.h"

bool_t
xdr_int_ptr (XDR *xdrs, int_ptr *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->int_ptr_val, (u_int *) &objp->int_ptr_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_Matrix (XDR *xdrs, Matrix *objp)
{
	register int32_t *buf;

	 if (!xdr_int_ptr (xdrs, &objp->matrix))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->size1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->size2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_matrixmultiply_1_argument (XDR *xdrs, matrixmultiply_1_argument *objp)
{
	 if (!xdr_Matrix (xdrs, &objp->arg1))
		 return FALSE;
	 if (!xdr_Matrix (xdrs, &objp->arg2))
		 return FALSE;
	return TRUE;
}

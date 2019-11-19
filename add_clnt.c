/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "add.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

enum clnt_stat 
dateandtime_1(char **clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, DateAndTime, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_wrapstring, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
sort_1(int_ptr arg1, int_ptr *clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, Sort,
		(xdrproc_t) xdr_int_ptr, (caddr_t) &arg1,
		(xdrproc_t) xdr_int_ptr, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
list_1(char **clnt_res, CLIENT *clnt)
{
	 return (clnt_call (clnt, List, (xdrproc_t) xdr_void, (caddr_t) NULL,
		(xdrproc_t) xdr_wrapstring, (caddr_t) clnt_res,
		TIMEOUT));

}

enum clnt_stat 
matrixmultiply_1(Matrix arg1, Matrix arg2, Matrix *clnt_res,  CLIENT *clnt)
{
	matrixmultiply_1_argument arg;
	arg.arg1 = arg1;
	arg.arg2 = arg2;
	return (clnt_call (clnt, MatrixMultiply, (xdrproc_t) xdr_matrixmultiply_1_argument, (caddr_t) &arg,
		(xdrproc_t) xdr_Matrix, (caddr_t) clnt_res,
		TIMEOUT));
}

enum clnt_stat 
reverseencryptedecho_1(char *arg1, char **clnt_res,  CLIENT *clnt)
{
	return (clnt_call(clnt, ReverseEncryptedEcho,
		(xdrproc_t) xdr_wrapstring, (caddr_t) &arg1,
		(xdrproc_t) xdr_wrapstring, (caddr_t) clnt_res,
		TIMEOUT));
}
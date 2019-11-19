/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "add.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

int
_dateandtime_1 (void  *argp, void *result, struct svc_req *rqstp)
{
	return (dateandtime_1_svc((char**)result, rqstp));
}

int
_sort_1 (int_ptr  *argp, void *result, struct svc_req *rqstp)
{
	return (sort_1_svc(*argp, (int_ptr*)result, rqstp));
}

int
_list_1 (void  *argp, void *result, struct svc_req *rqstp)
{
	return (list_1_svc((char**)result, rqstp));
}

int
_matrixmultiply_1 (matrixmultiply_1_argument *argp, void *result, struct svc_req *rqstp)
{
	return (matrixmultiply_1_svc(argp->arg1, argp->arg2, (Matrix*)result, rqstp));
}

int
_reverseencryptedecho_1 (char * *argp, void *result, struct svc_req *rqstp)
{
	return (reverseencryptedecho_1_svc(*argp, (char**)result, rqstp));
}



static void
add_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		int_ptr sort_1_arg;
		matrixmultiply_1_argument matrixmultiply_1_arg;
		char *reverseencryptedecho_1_arg;
	} argument;
	union {
		char *dateandtime_1_res;
		int_ptr sort_1_res;
		char *list_1_res;
		Matrix matrixmultiply_1_res;
		char *reverseencryptedecho_1_res;
	} result;
	bool_t retval;
	xdrproc_t _xdr_argument, _xdr_result;
	bool_t (*local)(char *, void *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case DateAndTime:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_dateandtime_1;
		break;

	case Sort:
		_xdr_argument = (xdrproc_t) xdr_int_ptr;
		_xdr_result = (xdrproc_t) xdr_int_ptr;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_sort_1;
		break;

	case List:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_list_1;
		break;

	case MatrixMultiply:
		_xdr_argument = (xdrproc_t) xdr_matrixmultiply_1_argument;
		_xdr_result = (xdrproc_t) xdr_Matrix;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_matrixmultiply_1;
		break;

	case ReverseEncryptedEcho:
		_xdr_argument = (xdrproc_t) xdr_wrapstring;
		_xdr_result = (xdrproc_t) xdr_wrapstring;
		local = (bool_t (*) (char *, void *,  struct svc_req *))_reverseencryptedecho_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	retval = (bool_t) (*local)((char *)&argument, (void *)&result, rqstp);
	if (retval > 0 && !svc_sendreply(transp, (xdrproc_t) _xdr_result, (char *)&result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	if (!add_prog_1_freeresult (transp, _xdr_result, (caddr_t) &result))
		fprintf (stderr, "%s", "unable to free results");

	return;
}

// intermediary function in order to hand control to a detached thread
// This gives us Multithreaded server, but not concurrency. Concurrency
// Requires -A which is not available on linux
static void start_thread(struct svc_req *rqstp, register SVCXPRT *transp) {
  std::thread thread(add_prog_1, rqstp, transp);
  thread.detach();  
}


int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (ADD_PROG, ADDS_VERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, ADD_PROG, ADDS_VERS, start_thread, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (ADD_PROG, ADDS_VERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, ADD_PROG, ADDS_VERS, start_thread, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (ADD_PROG, ADDS_VERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* rcFileWrite.c - Client API call for fileWrite. Part of the
 * reoutine may be generated by a script
 */
#include "fileWrite.hpp"

int
rcFileWrite( rcComm_t *conn, fileWriteInp_t *fileWriteInp,
             bytesBuf_t *fileWriteInpBBuf ) {
    int status;

    status = procApiRequest( conn, FILE_WRITE_AN, fileWriteInp,
                             fileWriteInpBBuf, ( void ** ) NULL, NULL );

    return ( status );
}


/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* phymvUtil.h - Header for for phymvUtil.c */

#ifndef PHYMVUTIL_HPP
#define PHYMVUTIL_HPP

#include "rodsClient.hpp"
#include "parseCommandLine.hpp"
#include "rodsPath.hpp"

extern "C" {

    int
    phymvUtil( rcComm_t *conn, rodsEnv *myRodsEnv, rodsArguments_t *myRodsArgs,
               rodsPathInp_t *rodsPathInp );
    int
    phymvDataObjUtil( rcComm_t *conn, char *srcPath,
                      rodsEnv *myRodsEnv, rodsArguments_t *rodsArgs,
                      dataObjInp_t *dataObjInp );
    int
    initCondForPhymv( rodsEnv *myRodsEnv, rodsArguments_t *rodsArgs,
                      dataObjInp_t *dataObjInp );
    int
    phymvCollUtil( rcComm_t *conn, char *srcColl, rodsEnv *myRodsEnv,
                   rodsArguments_t *rodsArgs, dataObjInp_t *dataObjInp );

}

#endif	/* PHYMVUTIL_H */

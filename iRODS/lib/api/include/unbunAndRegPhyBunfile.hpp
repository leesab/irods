/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* unbunAndRegPhyBunfile.h - This dataObj may be generated by a program or script
 */

#ifndef UNBUN_AND_REG_PHY_BUNFILE_HPP
#define UNBUN_AND_REG_PHY_BUNFILE_HPP

/* This is a Object File I/O call */

#include "rods.hpp"
#include "rcMisc.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"
#include "dataObjWrite.hpp"
#include "dataObjClose.hpp"
#include "dataCopy.hpp"

#define UNLINK_FILE_AGE                7200    /* delete files younger than this */ // JMC - backport 4666
#if defined(RODS_SERVER)
#define RS_UNBUN_AND_REG_PHY_BUNFILE rsUnbunAndRegPhyBunfile
/* prototype for the server handler */
int
rsUnbunAndRegPhyBunfile( rsComm_t *rsComm, dataObjInp_t *dataObjInp );
int
_rsUnbunAndRegPhyBunfile( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                          rescInfo_t *rescInfo );
int
remoteUnbunAndRegPhyBunfile( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                             rodsServerHost_t *rodsServerHost );
int
unbunPhyBunFile( rsComm_t *rsComm, char *objPath,
                 rescInfo_t *rescInfo, char *bunFilePath, char *phyBunDir, char *dataType,
                 int saveLinkedFles, const char* resc_hier ); // JMC _ backport 4657, 4658
int
regUnbunPhySubfiles( rsComm_t *rsComm, rescInfo_t *rescInfo, char *phyBunDir,
                     int rmBunCopyFlag );
int
regPhySubFile( rsComm_t *rsComm, char *subfilePath,
               dataObjInfo_t *bunDataObjInfo, rescInfo_t *rescInfo );
int
rmLinkedFilesInUnixDir( char *phyBunDir );
int
rmUnlinkedFilesInUnixDir( char *phyBunDir ); // JMC _ backport 4657
#else
#define RS_UNBUN_AND_REG_PHY_BUNFILE NULL
#endif

extern "C" {

    /* prototype for the client call */
    /* rcUnbunAndRegPhyBunfile - Unbundle a physical bundle file specified by
     * FILE_PATH_KW and register each subfile as replica. This call cannot be
     * called by normal users directly.
     * Input -
     *   rcComm_t *conn - The client connection handle.
     *   dataObjInp_t *dataObjInp - generic dataObj input. Relevant items are:
     *      objPath - the path of the data object.
     *      condInput - conditional Input
     *	    FILE_PATH_KW - the phyical path of the bundled file.
     *          DEST_RESC_NAME_KW - "value" = The destination Resource.
     *   return value - The status of the operation.
     */
    int
    rcUnbunAndRegPhyBunfile( rcComm_t *conn, dataObjInp_t *dataObjInp );
}

#endif	/* UNBUN_AND_REG_PHY_BUNFILE_H */

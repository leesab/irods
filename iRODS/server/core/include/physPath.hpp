/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */

/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/

/* physPath.h - header file for physPath.c
 */



#ifndef PHYS_PATH_HPP
#define PHYS_PATH_HPP

#include "rods.hpp"
#include "initServer.hpp"
#include "objInfo.hpp"
#include "dataObjInpOut.hpp"
#include "fileRename.hpp"
#include "miscUtil.hpp"
#include "structFileSync.hpp"
#include "structFileExtAndReg.hpp"
#include "dataObjOpenAndStat.hpp"

#define ORPHAN_DIR      "orphan"
#define REPL_DIR        "replica"
#define CHK_ORPHAN_CNT_LIMIT  20  /* number of failed check before stopping */
// =-=-=-=-=-=-=-
// JMC - backport 4598
#define LOCK_FILE_DIR  "lockFileDir"
#define LOCK_FILE_TRAILER      "LOCK_FILE"     /* added to end of lock file */ // JMC - backport 4604
// =-=-=-=-=-=-=-


extern "C" {

    int
    getFileMode( dataObjInp_t *dataObjInp );

    int
    getFileFlags( int l1descInx );

    int
    getFilePathName( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo,
                     dataObjInp_t *dataObjInp );
    int
    getVaultPathPolicy( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo,
                        vaultPathPolicy_t *outVaultPathPolicy );
    int
    setPathForGraftPathScheme( char *objPath, const char *vaultPath, int addUserName,
                               char *userName, int trimDirCnt, char *outPath );
    int
    setPathForRandomScheme( char *objPath, const char *vaultPath, char *userName,
                            char *outPath );
    int
    resolveDupFilePath( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo,
                        dataObjInp_t *dataObjInp );
    int
    getchkPathPerm( rsComm_t *rsComm, dataObjInp_t *dataObjInp, dataObjInfo_t *dataObjInfo );
    int
    getCopiesFromCond( keyValPair_t *condInput );
    int
    getWriteFlag( int openFlag );
    int
    dataObjChksum( rsComm_t *rsComm, int l1descInx, keyValPair_t *regParam );
    int
    _dataObjChksum( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo, char **chksumStr );
    rodsLong_t
    getSizeInVault( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo );
    int
    dataObjChksumAndReg( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo,
                         char **chksumStr );
    int
    chkAndHandleOrphanFile( rsComm_t *rsComm, char* objPath, char* rescHIer, char *filePath,
                            rescInfo_t *rescInfo, int replStatus );
    int
    renameFilePathToNewDir( rsComm_t *rsComm, char *newDir,
                            fileRenameInp_t *fileRenameInp, rescInfo_t *rescInfo, int renameFlag, char* );
    int
    syncDataObjPhyPath( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                        dataObjInfo_t *dataObjInfoHead, char *acLCollection );
    int
    syncDataObjPhyPathS( rsComm_t *rsComm, dataObjInp_t *dataObjInp,
                         dataObjInfo_t *dataObjInfo, char *acLCollection );
    int
    syncCollPhyPath( rsComm_t *rsComm, char *collection );
    int
    isInVault( dataObjInfo_t *dataObjInfo );
    int
    initStructFileOprInp( rsComm_t *rsComm, structFileOprInp_t *structFileOprInp,
                          structFileExtAndRegInp_t *structFileExtAndRegInp,
                          dataObjInfo_t *dataObjInfo );
    int
    getDefFileMode();
    int
    getDefDirMode();
    int
    getLogPathFromPhyPath( char *phyPath, rescInfo_t *rescInfo, char *outLogPath );
    int
    rsMkOrphanPath( rsComm_t *rsComm, char *objPath, char *orphanPath );
// =-=-=-=-=-=-=-
// JMC - backport 4598
    int
    getDataObjLockPath( char *objPath, char **outLockPath );
    int
    fsDataObjLock( char *objPath, int cmd, int type, int infd );
// =-=-=-=-=-=-=-
    int getLeafRescPathName( const std::string& _resc_hier, std::string& _ret_string );

    rodsLong_t
    getFileMetadataFromVault( rsComm_t *rsComm, dataObjInfo_t *dataObjInfo );
}

#endif  /* PHYS_PATH_H */

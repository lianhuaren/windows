/*
 * Send random bits file
 *
 * Once this service function is installed, any file with the extension
 * "dyn-send" will be serviced with this function.  An optional query
 * string may be passed to alter the amount of data in the response.
 *
 * For example:
 *      /file.dyn-send                  - returns a 10240 byte file
 *      /file.dyn-send?size=20          - returns a 20 byte file
 *      /file.dyn-send?size=1024        - returns a 1024 byte file
 *      etc.
 *
 * To install the service routine, compile it as per the makefile
 * included with your Netscape server distribution
(serverroot/nsapi/examples)
 * and then add the following lines to your netscape server
configuration:
 *
 * in magnus.conf
 *      Init fn=load-modules shlib=example.so funcs=nsapi-send
 *
 * in obj.conf
 *      Service method=(GET|HEAD) fn=nsapi-send
type=magnus-internal/dyn-send
 *
 * in mime.types
 *      type=magnus-internal/dyn-send        exts=dyn-send
 *
 * Mike Belshe
 * mbelshe@netscape.com
 * 11-5-95
 *
 *
 * Murali R. Krishnan  MuraliK@microsoft.com
 * 12-03-1995   Ported  to support ISAPI in Gibrlatar servers
 *
 */

#if ISAPI_DEF
# include <windows.h>
# include <httpext.h>

# include <stdlib.h>
#endif // ISAPI_DEF 



#if NSAPI_DEF
#include "base/pblock.h"
#include "base/session.h"
#include "frame/req.h"
#include "frame/protocol.h"
#include "base/util.h"
#include "frame/http.h"
# endif // NSAPI_DEF

#define FILE_SIZE       10240
#define MALLOC_FAILURE  "Out of memory"

#if NSAPI_DEF

int nsapi_send(pblock *pb, Session *sn, Request *rq)
{
        char *query_string;
        char *buffer;
        int filesize;
        int index;

        /* Get the query string, if any; check to see if an alternate
         * file size was specified.
         */
        if ( !(query_string = pblock_findval("query", rq->reqpb)) )
                filesize = FILE_SIZE;
        else {
                if ( !strncmp(query_string, "size=", 5) )
                        filesize = atoi(&(query_string[5]));
                else
                        filesize = FILE_SIZE;
        }

        /* Set the context type */
        param_free(pblock_remove("content-type", rq->srvhdrs));
        pblock_nvinsert("content-type", "text/plain", rq->srvhdrs);

        /* Start the protocol response */
        protocol_status(sn, rq, PROTOCOL_OK, NULL);
        protocol_start_response(sn, rq);

        /* Allocate the output buffer */
        if ( !(buffer = (char *)malloc(filesize)) ) {
                net_write(sn->csd, MALLOC_FAILURE,
strlen(MALLOC_FAILURE));
                return REQ_ABORTED;
        }

        /* Generate the output */
        for (index=0; index < filesize; index++)
                /* generate random characters from A-Z */
                buffer[index] = rand() %26 + 63;

        /* Send the output */
        if (net_write(sn->csd, buffer, filesize) == IO_ERROR)
                return REQ_EXIT;

        free(buffer);

        return REQ_PROCEED;
}

#endif 

#if ISAPI_DEF

const char PSZ_CONTENT_TYPE[] = "Content-type: text/plain\r\n\r\n";

DWORD
HttpExtensionProc( IN OUT EXTENSION_CONTROL_BLOCK * pecb)
{
    char *query_string;
    char *buffer;
    const char *pszHeader;
    int filesize;
    DWORD cbFileSize;
    int index;
    
    /* Get the query string, if any; check to see if an alternate
     * file size was specified.
     */
    
    if ( !(query_string = pecb->lpszQueryString) )
      filesize = FILE_SIZE;
    else {
        if ( !strncmp(query_string, "size=", 5) )
          filesize = atoi(&(query_string[5]));
        else
          filesize = FILE_SIZE;
    }
    
    /* Set the content type */
    pszHeader = PSZ_CONTENT_TYPE;
    if ( !pecb->ServerSupportFunction( pecb->ConnID,
                                      HSE_REQ_SEND_RESPONSE_HEADER,
                                      "200 OK",
                                      NULL,
                                      (LPDWORD) pszHeader )) {

        return HSE_STATUS_ERROR;
    }


    /* Allocate the output buffer */
    if ( !(buffer = (char *)malloc(filesize)) ) {
        
        DWORD cbMallocFailed = sizeof(MALLOC_FAILURE) - sizeof(CHAR);

        pecb->WriteClient( pecb->ConnID, MALLOC_FAILURE, &cbMallocFailed, 0);
        
        return ( HSE_STATUS_ERROR);
    }

    
    /* Generate the output */
    for (index=0; index < filesize; index++)
      /* generate random characters from A-Z */
      buffer[index] = rand() %26 + 63;

    /* Send the output */
    cbFileSize = filesize;
    if (!pecb->WriteClient( pecb->ConnID, 
                          buffer, &cbFileSize, 0)) {

        return (HSE_STATUS_ERROR);
    }
    
    free(buffer);
    
    return HSE_STATUS_SUCCESS;

} // HttpExtensionProc()


BOOL
GetExtensionVersion(
    HSE_VERSION_INFO * pver
    )
{
    pver->dwExtensionVersion = MAKELONG( 1, 0 );
    strcpy( pver->lpszExtensionDesc,
            "WebStone Extension Example" );

    return TRUE;
}

#endif 

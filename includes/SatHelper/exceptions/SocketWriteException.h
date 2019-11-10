/*
 * SocketWriteException.h
 *
 *  Created on: 06/11/2016
 *      Author: Lucas Teske
 */

#ifndef INCLUDES_EXCEPTIONS_SOCKETWRITEEXCEPTION_H_
#define INCLUDES_EXCEPTIONS_SOCKETWRITEEXCEPTION_H_

#include <SatHelper/exceptions/SocketException.h>

namespace SatHelper {
    class SocketWriteException: public SocketException {
    public:
        SocketWriteException(int errorCode) :
                SocketException(errorCode) {
        }

        virtual const char* what() const throw () {
            return "There was an socket write exception.";
        }
    };

}

#endif /* INCLUDES_EXCEPTIONS_SOCKETWRITEEXCEPTION_H_ */

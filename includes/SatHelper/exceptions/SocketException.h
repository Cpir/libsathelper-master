/*
 * SocketException.h
 *
 *  Created on: 06/11/2016
 *      Author: Lucas Teske
 */

#ifndef INCLUDES_EXCEPTIONS_SOCKETEXCEPTION_H_
#define INCLUDES_EXCEPTIONS_SOCKETEXCEPTION_H_

#include <SatHelper/exceptions/SatHelperException.h>

namespace SatHelper {
    class SocketException: public SatHelperException {
    public:
        const int errorCode;
        SocketException(int errorCode) :
                errorCode(errorCode) {
        }

        virtual const char* what() const throw() {
            return "There was an Socket Error";
        }

        virtual std::string reason() const {
            std::stringstream ss;
            ss << "There was an Socket Error with ErrorCode " << errorCode;
            return ss.str();
        }
    };
}

#endif /* INCLUDES_EXCEPTIONS_SOCKETEXCEPTION_H_ */

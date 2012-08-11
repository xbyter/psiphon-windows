/*
 * Copyright (c) 2012, Psiphon Inc.
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "stopsignal.h"

class ITransport;
class SessionInfo;


class ServerRequest
{
public:
    ServerRequest();
    virtual ~ServerRequest();
    bool MakeRequest(
        const ITransport* currentTransport,
        const SessionInfo& sessionInfo,
        const TCHAR* requestPath,
        string& o_response,
        const StopInfo& stopInfo,
        LPCWSTR additionalHeaders=NULL,
        LPVOID additionalData=NULL,
        DWORD additionalDataLength=0);

private:
    void GetTempTransports(
        const SessionInfo& sessionInfo,
        vector<auto_ptr<ITransport>>& o_tempTransports);

};

//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2007-2016 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#include "pch.h"

#include <core/sdk/constants.h>
#include <core/sdk/IPlugin.h>

#include "DirectSoundOut.h"

class DirectSoundPlugin : public musik::core::sdk::IPlugin {
    public:
        virtual void Destroy() { delete this; }
        virtual const char* Name() { return "DirectSound IOutput"; };
        virtual const char* Version() { return "0.4.0"; };
        virtual const char* Author() { return "clangen"; };
        virtual const char* Guid() { return "731ad687-c52d-47b0-90b4-5483399640b5"; }
        virtual bool Configurable() { return false; }
        virtual void Configure() { }
        virtual void Reload() { }
        virtual int SdkVersion() { return musik::core::sdk::SdkVersion; }
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return true;
}

extern "C" __declspec(dllexport) musik::core::sdk::IPlugin* GetPlugin() {
    return new DirectSoundPlugin();
}

extern "C" __declspec(dllexport) musik::core::sdk::IOutput* GetAudioOutput() {
    return new DirectSoundOut();
}

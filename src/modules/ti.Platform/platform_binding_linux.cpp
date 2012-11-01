/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***
* Copyright (c) 2008-2012 Appcelerator Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#include <tide/tide.h>
#include <Poco/Environment.h>
#include <Poco/Process.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <gdk/gdk.h>
#include "platform_binding.h"

namespace ti
{

std::string PlatformBinding::GetVersionImpl()
{
    return Poco::Environment::osVersion();
}

bool PlatformBinding::OpenApplicationImpl(const std::string& name)
{
    std::vector<std::string> args;
    args.push_back(name);
    std::string processName("xdg-open");
    Poco::Process::launch(processName, args);
    return true;
}

bool PlatformBinding::OpenURLImpl(const std::string& url)
{
    return this->OpenApplicationImpl(url);
}

void PlatformBinding::TakeScreenshotImpl(const std::string& targetFile)
{
    GdkWindow* rootWindow = gdk_get_default_root_window();

    int width, height;
    gdk_drawable_get_size(rootWindow, &width, &height);

    GdkPixbuf* pixbuf = gdk_pixbuf_get_from_drawable(0, GDK_DRAWABLE(rootWindow),
        0, 0, 0, 0, 0, width, height);
    gdk_pixbuf_save(pixbuf, targetFile.c_str(), "png", 0, "compression", "9", NULL);
}

}
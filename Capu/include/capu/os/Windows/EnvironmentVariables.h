/*
 * Copyright (C) 2015 BMW Car IT GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CAPU_WINDOWS_ENVIRONMENTVARIABLES_H
#define CAPU_WINDOWS_ENVIRONMENTVARIABLES_H

#include <capu/os/Generic/EnvironmentVariables.h>

namespace capu
{
    namespace os
    {
        class EnvironmentVariables: private capu::generic::EnvironmentVariables
        {
        public:
            using capu::generic::EnvironmentVariables::getAll;
            static bool get(const String& key, String& value);
        };

        inline
        bool EnvironmentVariables::get(const String& key, String& value)
        {
            char* envValue = 0;
            errno_t err = _dupenv_s(&envValue, 0, key.c_str());
            bool found = (err == 0 && envValue != 0);
            value = envValue;
            free(envValue);
            return found;
        }
    }
}


#endif // CAPU_WINDOWS_ENVIRONMENTVARIABLES_H

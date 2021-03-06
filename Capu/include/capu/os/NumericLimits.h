/*
 * Copyright (C) 2012 BMW Car IT GmbH
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

#ifndef CAPU_NUMERIC_LIMITS_H
#define CAPU_NUMERIC_LIMITS_H

#include <capu/Config.h>
#include <capu/os/PlatformInclude.h>
#include CAPU_PLATFORM_INCLUDE(NumericLimits)

namespace capu
{
    /**
     * Numerical system limits.
     */
    class NumericLimits // no inheritance is needed because all methods are static
    {
    public:
        /**
         * Return the maximum value for the given type
         */
        template<typename T> static T Max();

        /**
         * Return the minimum value for the given type
         */
        template<typename T> static T Min();
    };

    template<typename T>
    inline
    T
    NumericLimits::Max()
    {
        return capu::os::arch::NumericLimits::Max<T>();
    }

    template<typename T>
    inline
    T
    NumericLimits::Min()
    {
        return capu::os::arch::NumericLimits::Min<T>();
    }

}

#endif //CAPU_NUMERIC_LIMITS_H


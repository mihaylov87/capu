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



TEST(AtomicOperation, Add_Overflow_X86_32)
{
    uint32_t val = 4294967295u;
    uint32_t ret = capu::AtomicOperation::AtomicAdd(val, 3);
    EXPECT_EQ(2u, val);
    EXPECT_EQ(4294967295u, ret);
}

TEST(AtomicOperation, Sub_Overflow_X86_32)
{
    uint32_t val = 0;
    uint32_t ret = capu::AtomicOperation::AtomicSub(val, 5);
    EXPECT_EQ(4294967291u, val);
    EXPECT_EQ(0u, ret);
}

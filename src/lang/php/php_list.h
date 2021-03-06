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

#ifndef _PHP_LIST_H_
#define _PHP_LIST_H_

#include "php_module.h"

namespace tide
{
    class KPHPList : public TiList
    {
        public:
        KPHPList(zval *list);
        virtual ~KPHPList();

        ValueRef Get(const char* name);
        void Set(const char* name, ValueRef value);
        virtual bool Equals(TiObjectRef);
        SharedStringList GetPropertyNames();

        unsigned int Size();
        void Append(ValueRef value);
        virtual void SetAt(unsigned int index, ValueRef value);
        bool Remove(unsigned int index);
        ValueRef At(unsigned int index);

        zval* ToPHP();

        protected:
        zval *list;

        static void AddTideValueToPHPArray(ValueRef value, zval *phpArray, const char* key);
        static void AddTideValueToPHPArray(ValueRef value, zval *phpArray, unsigned int index);
        static void AddTideValueToPHPArray(ValueRef value, zval *phpArray);
        DISALLOW_EVIL_CONSTRUCTORS(KPHPList);
    };
}

#endif

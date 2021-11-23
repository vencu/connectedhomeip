/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <app/util/basic-types.h>
#include <lib/core/Optional.h>

namespace chip {
namespace app {

/**
 * A representation of a concrete attribute path. This does not convey any list index specifiers.
 */
struct ConcreteAttributePath
{
    ConcreteAttributePath() {}

    ConcreteAttributePath(EndpointId aEndpointId, ClusterId aClusterId, AttributeId aAttributeId) :
        mEndpointId(aEndpointId), mClusterId(aClusterId), mAttributeId(aAttributeId)
    {}

    bool operator==(const ConcreteAttributePath & other) const
    {
        return mEndpointId == other.mEndpointId && mClusterId == other.mClusterId && mAttributeId == other.mAttributeId;
    }

    EndpointId mEndpointId   = 0;
    ClusterId mClusterId     = 0;
    AttributeId mAttributeId = 0;
};

/**
 * A representation of a concrete path as it appears in a Read or Subscribe
 * request after path expansion. This contains support for expressing an
 * optional list index.
 */
struct ConcreteReadAttributePath : public ConcreteAttributePath
{
    ConcreteReadAttributePath() {}

    ConcreteReadAttributePath(const ConcreteAttributePath & path) :
        ConcreteReadAttributePath(path.mEndpointId, path.mClusterId, path.mAttributeId)
    {}

    ConcreteReadAttributePath(EndpointId aEndpointId, ClusterId aClusterId, AttributeId aAttributeId) :
        ConcreteAttributePath(aEndpointId, aClusterId, aAttributeId)
    {}

    ConcreteReadAttributePath(EndpointId aEndpointId, ClusterId aClusterId, AttributeId aAttributeId, uint16_t aListIndex) :
        ConcreteAttributePath(aEndpointId, aClusterId, aAttributeId)
    {
        mListIndex.SetValue(aListIndex);
    }

    Optional<uint16_t> mListIndex;
};

/**
 * A representation of a concrete path as it appears in a Report or Write
 * request after path expansion. This contains support for expressing list and list item-specific operations
 * like replace, update, delete and append.
 */
struct ConcreteDataAttributePath : public ConcreteAttributePath
{
    enum class ListOperation
    {
        NotList,     // Path points to an attribute that isn't a list.
        ReplaceAll,  // Path points to an attribute that is a list, indicating that the contents of the list should be replaced in
                     // its entirety.
        ReplaceItem, // Path points to a specific item in a list, indicating that that item should be replaced in its entirety.
        DeleteItem,  // Path points to a specific item in a list, indicating that that item should be deleted from the list.
        AppendItem   // Path points to an attribute that is a list, indicating that an item should be appended into the list.
    };

    ConcreteDataAttributePath() {}

    ConcreteDataAttributePath(EndpointId aEndpointId, ClusterId aClusterId, AttributeId aAttributeId) :
        ConcreteAttributePath(aEndpointId, aClusterId, aAttributeId)
    {}

    ConcreteDataAttributePath(EndpointId aEndpointId, ClusterId aClusterId, AttributeId aAttributeId, ListOperation aListOp,
                              uint16_t aListIndex) :
        ConcreteAttributePath(aEndpointId, aClusterId, aAttributeId)
    {
        mListOp    = aListOp;
        mListIndex = aListIndex;
    }

    bool IsListOperation() const { return mListOp != ListOperation::NotList; }
    bool IsListItemOperation() const { return ((mListOp != ListOperation::NotList) && (mListOp != ListOperation::ReplaceAll)); }

    //
    // This index is only valid if `mListOp` is set to a list item operation, i.e
    // ReplaceItem, DeleteItem or AppendItem. Otherwise, it is to be ignored.
    //
    uint16_t mListIndex   = 0;
    ListOperation mListOp = ListOperation::NotList;
};

} // namespace app
} // namespace chip

/*
 * Copyright (c) 2024, stelar7 <dudedbz@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/HashMap.h>
#include <LibJS/Heap/Handle.h>
#include <LibWeb/DOM/EventTarget.h>
#include <LibWeb/IndexedDB/IDBRequest.h>
#include <LibWeb/StorageAPI/StorageKey.h>

namespace Web::IndexedDB {

using ConnectionQueue = AK::Vector<JS::Handle<IDBRequest>>;
using ConnectionMap = HashMap<StorageAPI::StorageKey, HashMap<String, ConnectionQueue>>;

// https://w3c.github.io/IndexedDB/#connection-queues
class ConnectionQueueHandler {
public:
    static ConnectionQueue& for_key_and_name(StorageAPI::StorageKey& key, String& name);
    static ConnectionQueueHandler& the()
    {
        static ConnectionQueueHandler s_instance;
        return s_instance;
    }

private:
    ConnectionMap m_open_requests;
};

}

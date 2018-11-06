// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <fbl/vector.h>
#include <lib/zx/channel.h>
#include <lib/zx/job.h>

namespace devmgr_launcher {

struct Args {
    // A list of absolute paths (in devmgr's view of the filesystem) to search
    // for drivers in.  The search is non-recursive.  If empty, this uses
    // devmgr's default.
    fbl::Vector<const char*> driver_search_paths;
    // A list of absolute paths (in devmgr's view of the filesystem) to load
    // drivers from.  This differs from |driver_search_paths| in that it
    // specifies specific drivers rather than entire directories.
    fbl::Vector<const char*> load_drivers;
    // An absolute path (in devmgr's view of the filesystem) for which driver
    // should be bound to the sys_device (the top-level device for most
    // devices).  If nullptr, this uses devmgr's default.
    const char* sys_device_driver;
};

// Launches an isolated devmgr, passing the given |args| to it.
//
// Returns its containing job and a channel to the root of its devfs.
// To destroy the devmgr, issue |devmgr_job->kill()|.
zx_status_t Launch(const Args& args, zx::job* devmgr_job, zx::channel* devfs_root);

} // namespace devmgr_launcher
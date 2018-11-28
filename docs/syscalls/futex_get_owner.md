# zx_futex_get_owner

## NAME

futex_get_owner - Fetch the koid current owner of a futex, if any.

## SYNOPSIS

```C
#include <zircon/syscalls.h>

zx_status_t zx_futex_get_owner(const zx_futex_t* value_ptr, uint64_t* koid);
```

## DESCRIPTION

Fetch the koid of the current owner of the futex identified by `value_ptr`, or
**ZX_KOID_INVALID** if there is no current owner.  Knowledge of the ownership of
a futex typically serves no purpose when building synchronization primitives
from futexes.  This syscall is used primarily for testing.

See *Ownership and Priority Inheritance* in [futex](../objects/futex.md) for
details.

## RIGHTS

<!-- Updated by scripts/update-docs-from-abigen, do not edit this section manually. -->

None.

## RETURN VALUE

**futex_get_owner**() returns **ZX_OK** on success, and koids hold the owner of
the futex at the time of the syscall, or **ZX_KOID_INVALID** if there was no
owner.

## ERRORS

**ZX_ERR_INVALID_ARGS**  One of the following is true:
+ `value_ptr` is not a valid userspace pointer.
+ `value_ptr` is not aligned to a sizeof(zx_futex_t) boundary.
+ `koid` is not a valid userspace pointer.

## SEE ALSO

[futex objects](../objects/futex.md)
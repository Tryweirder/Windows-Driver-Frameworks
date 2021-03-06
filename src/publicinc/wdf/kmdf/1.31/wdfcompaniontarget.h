/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    wdfcompaniontarget.h

Abstract:

    This is the interfaces for the Windows Driver Framework companion target object

Environment:

    kernel mode only

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WDFCOMPANIONTARGET_H_
#define _WDFCOMPANIONTARGET_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START



typedef enum _WDF_TASK_SEND_OPTIONS_FLAGS {
    WDF_TASK_SEND_OPTION_TIMEOUT = 0x00000001,
    WDF_TASK_SEND_OPTION_SYNCHRONOUS = 0x00000002,
} WDF_TASK_SEND_OPTIONS_FLAGS;



#define WDF_TRACE_ID ('TRAC')

typedef struct _WDF_TASK_SEND_OPTIONS {
    //
    // Size of the structure in bytes
    //
    ULONG Size;

    //
    // Bit field combination of values from the WDF_TASK_SEND_OPTIONS_FLAGS
    // enumeration
    //
    ULONG Flags;

    //
    // Valid when WDF_TASK_SEND_OPTION_TIMEOUT is set
    //
    LONGLONG Timeout;

} WDF_TASK_SEND_OPTIONS, *PWDF_TASK_SEND_OPTIONS;

VOID
FORCEINLINE
WDF_TASK_SEND_OPTIONS_INIT(
    _Out_
    PWDF_TASK_SEND_OPTIONS Options,
    _In_
    ULONG Flags
    )
{
    RtlZeroMemory(Options, sizeof(WDF_TASK_SEND_OPTIONS));

    Options->Size = WDF_STRUCTURE_SIZE(WDF_TASK_SEND_OPTIONS);
    Options->Flags = Flags;
}

//
// WDF Function: WdfCompanionTargetSendTaskSynchronously
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFCOMPANIONTARGETSENDTASKSYNCHRONOUSLY)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOMPANIONTARGET CompanionTarget,
    _In_
    USHORT TaskQueueIdentifier,
    _In_
    ULONG TaskOperationCode,
    _In_opt_
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    _In_opt_
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    _In_opt_
    PWDF_TASK_SEND_OPTIONS TaskOptions,
    _Out_
    PULONG_PTR BytesReturned
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WdfCompanionTargetSendTaskSynchronously(
    _In_
    WDFCOMPANIONTARGET CompanionTarget,
    _In_
    USHORT TaskQueueIdentifier,
    _In_
    ULONG TaskOperationCode,
    _In_opt_
    PWDF_MEMORY_DESCRIPTOR InputBuffer,
    _In_opt_
    PWDF_MEMORY_DESCRIPTOR OutputBuffer,
    _In_opt_
    PWDF_TASK_SEND_OPTIONS TaskOptions,
    _Out_
    PULONG_PTR BytesReturned
    )
{
    return ((PFN_WDFCOMPANIONTARGETSENDTASKSYNCHRONOUSLY) WdfFunctions[WdfCompanionTargetSendTaskSynchronouslyTableIndex])(WdfDriverGlobals, CompanionTarget, TaskQueueIdentifier, TaskOperationCode, InputBuffer, OutputBuffer, TaskOptions, BytesReturned);
}

//
// WDF Function: WdfCompanionTargetWdmGetCompanionProcess
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PEPROCESS
(NTAPI *PFN_WDFCOMPANIONTARGETWDMGETCOMPANIONPROCESS)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCOMPANIONTARGET CompanionTarget
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PEPROCESS
WdfCompanionTargetWdmGetCompanionProcess(
    _In_
    WDFCOMPANIONTARGET CompanionTarget
    )
{
    return ((PFN_WDFCOMPANIONTARGETWDMGETCOMPANIONPROCESS) WdfFunctions[WdfCompanionTargetWdmGetCompanionProcessTableIndex])(WdfDriverGlobals, CompanionTarget);
}



WDF_EXTERN_C_END

#endif // _WDFCOMPANIONTARGET_H_


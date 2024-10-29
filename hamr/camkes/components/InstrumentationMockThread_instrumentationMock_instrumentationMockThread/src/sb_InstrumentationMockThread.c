// Do not edit this file as it will be overwritten if HAMR codegen is rerun

#include <sb_InstrumentationMockThread.h>
#include <InstrumentationMockThread_instrumentationMock_instrumentationMockThread_adapter.h>
#include <string.h>
#include <camkes.h>

static bool sb_occurred_periodic_dispatcher;
static int64_t sb_time_periodic_dispatcher;

/************************************************************************
 * periodic_dispatcher_write_int64_t
 * Invoked from remote periodic dispatch thread.
 *
 * This function records the current time and triggers the active thread
 * dispatch from a periodic event.  Note that the periodic dispatch
 * thread is the *only* thread that triggers a dispatch, so we do not
 * mutex lock the function.
 *
 ************************************************************************/

bool periodic_dispatcher_write_int64_t(const int64_t * arg) {
    sb_occurred_periodic_dispatcher = true;
    sb_time_periodic_dispatcher = *arg;
    MUTEXOP(sb_dispatch_sem_post());
    return true;
}

void sb_periodic_dispatch_notification_callback(void *_ UNUSED) {
   // we want time in microseconds, not nanoseconds, so we divide by 1000.
   int64_t sb_time_periodic_dispatcher = 0; // sb_timer_time() / 1000LL -- timer connection disabled;
   (void)periodic_dispatcher_write_int64_t(&sb_time_periodic_dispatcher);
   CALLBACKOP(sb_periodic_dispatch_notification_reg_callback(sb_periodic_dispatch_notification_callback, NULL));
}


seqNum_t sb_unit2_saturationLogic_channel4_seqNum;

seqNum_t sb_unit2_saturationLogic_channel3_seqNum;

seqNum_t sb_unit2_saturationLogic_channel2_seqNum;

seqNum_t sb_unit2_saturationLogic_channel1_seqNum;

seqNum_t sb_unit2_pressureLogic_channel4_seqNum;

seqNum_t sb_unit2_pressureLogic_channel3_seqNum;

seqNum_t sb_unit2_pressureLogic_channel2_seqNum;

seqNum_t sb_unit2_pressureLogic_channel1_seqNum;

seqNum_t sb_unit2_temperatureLogic_channel4_seqNum;

seqNum_t sb_unit2_temperatureLogic_channel3_seqNum;

seqNum_t sb_unit2_temperatureLogic_channel2_seqNum;

seqNum_t sb_unit2_temperatureLogic_channel1_seqNum;

seqNum_t sb_unit1_saturationLogic_channel4_seqNum;

seqNum_t sb_unit1_saturationLogic_channel3_seqNum;

seqNum_t sb_unit1_saturationLogic_channel2_seqNum;

seqNum_t sb_unit1_saturationLogic_channel1_seqNum;

seqNum_t sb_unit1_pressureLogic_channel4_seqNum;

seqNum_t sb_unit1_pressureLogic_channel3_seqNum;

seqNum_t sb_unit1_pressureLogic_channel2_seqNum;

seqNum_t sb_unit1_pressureLogic_channel1_seqNum;

seqNum_t sb_unit1_temperatureLogic_channel4_seqNum;

seqNum_t sb_unit1_temperatureLogic_channel3_seqNum;

seqNum_t sb_unit1_temperatureLogic_channel2_seqNum;

seqNum_t sb_unit1_temperatureLogic_channel1_seqNum;

bool sb_unit1_temperatureLogic_channel1_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel1, value, &sb_unit1_temperatureLogic_channel1_seqNum);
}

bool sb_unit1_temperatureLogic_channel2_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel2, value, &sb_unit1_temperatureLogic_channel2_seqNum);
}

bool sb_unit1_temperatureLogic_channel3_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel3, value, &sb_unit1_temperatureLogic_channel3_seqNum);
}

bool sb_unit1_temperatureLogic_channel4_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel4, value, &sb_unit1_temperatureLogic_channel4_seqNum);
}

bool sb_unit1_pressureLogic_channel1_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_pressureLogic_channel1, value, &sb_unit1_pressureLogic_channel1_seqNum);
}

bool sb_unit1_pressureLogic_channel2_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_pressureLogic_channel2, value, &sb_unit1_pressureLogic_channel2_seqNum);
}

bool sb_unit1_pressureLogic_channel3_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_pressureLogic_channel3, value, &sb_unit1_pressureLogic_channel3_seqNum);
}

bool sb_unit1_pressureLogic_channel4_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_pressureLogic_channel4, value, &sb_unit1_pressureLogic_channel4_seqNum);
}

bool sb_unit1_saturationLogic_channel1_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_saturationLogic_channel1, value, &sb_unit1_saturationLogic_channel1_seqNum);
}

bool sb_unit1_saturationLogic_channel2_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_saturationLogic_channel2, value, &sb_unit1_saturationLogic_channel2_seqNum);
}

bool sb_unit1_saturationLogic_channel3_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_saturationLogic_channel3, value, &sb_unit1_saturationLogic_channel3_seqNum);
}

bool sb_unit1_saturationLogic_channel4_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit1_saturationLogic_channel4, value, &sb_unit1_saturationLogic_channel4_seqNum);
}

bool sb_unit2_temperatureLogic_channel1_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel1, value, &sb_unit2_temperatureLogic_channel1_seqNum);
}

bool sb_unit2_temperatureLogic_channel2_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel2, value, &sb_unit2_temperatureLogic_channel2_seqNum);
}

bool sb_unit2_temperatureLogic_channel3_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel3, value, &sb_unit2_temperatureLogic_channel3_seqNum);
}

bool sb_unit2_temperatureLogic_channel4_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel4, value, &sb_unit2_temperatureLogic_channel4_seqNum);
}

bool sb_unit2_pressureLogic_channel1_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_pressureLogic_channel1, value, &sb_unit2_pressureLogic_channel1_seqNum);
}

bool sb_unit2_pressureLogic_channel2_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_pressureLogic_channel2, value, &sb_unit2_pressureLogic_channel2_seqNum);
}

bool sb_unit2_pressureLogic_channel3_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_pressureLogic_channel3, value, &sb_unit2_pressureLogic_channel3_seqNum);
}

bool sb_unit2_pressureLogic_channel4_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_pressureLogic_channel4, value, &sb_unit2_pressureLogic_channel4_seqNum);
}

bool sb_unit2_saturationLogic_channel1_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_saturationLogic_channel1, value, &sb_unit2_saturationLogic_channel1_seqNum);
}

bool sb_unit2_saturationLogic_channel2_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_saturationLogic_channel2, value, &sb_unit2_saturationLogic_channel2_seqNum);
}

bool sb_unit2_saturationLogic_channel3_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_saturationLogic_channel3, value, &sb_unit2_saturationLogic_channel3_seqNum);
}

bool sb_unit2_saturationLogic_channel4_write(const union_art_DataContent * value) {
  return write_sp_union_art_DataContent(sb_unit2_saturationLogic_channel4, value, &sb_unit2_saturationLogic_channel4_seqNum);
}

// send unit1_temperatureLogic_channel1: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel1_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel1_Send", 0);

  sb_unit1_temperatureLogic_channel1_write(d);
}

// send unit1_temperatureLogic_channel2: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel2_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel2_Send", 0);

  sb_unit1_temperatureLogic_channel2_write(d);
}

// send unit1_temperatureLogic_channel3: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel3_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel3_Send", 0);

  sb_unit1_temperatureLogic_channel3_write(d);
}

// send unit1_temperatureLogic_channel4: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel4_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_temperatureLogic_channel4_Send", 0);

  sb_unit1_temperatureLogic_channel4_write(d);
}

// send unit1_pressureLogic_channel1: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel1_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel1_Send", 0);

  sb_unit1_pressureLogic_channel1_write(d);
}

// send unit1_pressureLogic_channel2: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel2_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel2_Send", 0);

  sb_unit1_pressureLogic_channel2_write(d);
}

// send unit1_pressureLogic_channel3: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel3_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel3_Send", 0);

  sb_unit1_pressureLogic_channel3_write(d);
}

// send unit1_pressureLogic_channel4: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel4_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_pressureLogic_channel4_Send", 0);

  sb_unit1_pressureLogic_channel4_write(d);
}

// send unit1_saturationLogic_channel1: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel1_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel1_Send", 0);

  sb_unit1_saturationLogic_channel1_write(d);
}

// send unit1_saturationLogic_channel2: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel2_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel2_Send", 0);

  sb_unit1_saturationLogic_channel2_write(d);
}

// send unit1_saturationLogic_channel3: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel3_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel3_Send", 0);

  sb_unit1_saturationLogic_channel3_write(d);
}

// send unit1_saturationLogic_channel4: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel4_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit1_saturationLogic_channel4_Send", 0);

  sb_unit1_saturationLogic_channel4_write(d);
}

// send unit2_temperatureLogic_channel1: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel1_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel1_Send", 0);

  sb_unit2_temperatureLogic_channel1_write(d);
}

// send unit2_temperatureLogic_channel2: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel2_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel2_Send", 0);

  sb_unit2_temperatureLogic_channel2_write(d);
}

// send unit2_temperatureLogic_channel3: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel3_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel3_Send", 0);

  sb_unit2_temperatureLogic_channel3_write(d);
}

// send unit2_temperatureLogic_channel4: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel4_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_temperatureLogic_channel4_Send", 0);

  sb_unit2_temperatureLogic_channel4_write(d);
}

// send unit2_pressureLogic_channel1: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel1_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel1_Send", 0);

  sb_unit2_pressureLogic_channel1_write(d);
}

// send unit2_pressureLogic_channel2: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel2_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel2_Send", 0);

  sb_unit2_pressureLogic_channel2_write(d);
}

// send unit2_pressureLogic_channel3: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel3_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel3_Send", 0);

  sb_unit2_pressureLogic_channel3_write(d);
}

// send unit2_pressureLogic_channel4: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel4_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_pressureLogic_channel4_Send", 0);

  sb_unit2_pressureLogic_channel4_write(d);
}

// send unit2_saturationLogic_channel1: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel1_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel1_Send", 0);

  sb_unit2_saturationLogic_channel1_write(d);
}

// send unit2_saturationLogic_channel2: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel2_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel2_Send", 0);

  sb_unit2_saturationLogic_channel2_write(d);
}

// send unit2_saturationLogic_channel3: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel3_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel3_Send", 0);

  sb_unit2_saturationLogic_channel3_write(d);
}

// send unit2_saturationLogic_channel4: Out DataPort bool
Unit rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel4_Send(
  STACK_FRAME
  art_DataContent d) {
  DeclNewStackFrame(caller, "sb_InstrumentationMockThread.c", "", "rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_seL4Nix_unit2_saturationLogic_channel4_Send", 0);

  sb_unit2_saturationLogic_channel4_write(d);
}

void pre_init(void) {
  DeclNewStackFrame(NULL, "sb_InstrumentationMockThread.c", "", "pre_init", 0);

  printf("Entering pre-init of InstrumentationMockThread_instrumentationMock_instrumentationMockThread\n");

  // initialise data structure for data port unit1_temperatureLogic_channel1
  init_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel1, &sb_unit1_temperatureLogic_channel1_seqNum);

  // initialise data structure for data port unit1_temperatureLogic_channel2
  init_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel2, &sb_unit1_temperatureLogic_channel2_seqNum);

  // initialise data structure for data port unit1_temperatureLogic_channel3
  init_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel3, &sb_unit1_temperatureLogic_channel3_seqNum);

  // initialise data structure for data port unit1_temperatureLogic_channel4
  init_sp_union_art_DataContent(sb_unit1_temperatureLogic_channel4, &sb_unit1_temperatureLogic_channel4_seqNum);

  // initialise data structure for data port unit1_pressureLogic_channel1
  init_sp_union_art_DataContent(sb_unit1_pressureLogic_channel1, &sb_unit1_pressureLogic_channel1_seqNum);

  // initialise data structure for data port unit1_pressureLogic_channel2
  init_sp_union_art_DataContent(sb_unit1_pressureLogic_channel2, &sb_unit1_pressureLogic_channel2_seqNum);

  // initialise data structure for data port unit1_pressureLogic_channel3
  init_sp_union_art_DataContent(sb_unit1_pressureLogic_channel3, &sb_unit1_pressureLogic_channel3_seqNum);

  // initialise data structure for data port unit1_pressureLogic_channel4
  init_sp_union_art_DataContent(sb_unit1_pressureLogic_channel4, &sb_unit1_pressureLogic_channel4_seqNum);

  // initialise data structure for data port unit1_saturationLogic_channel1
  init_sp_union_art_DataContent(sb_unit1_saturationLogic_channel1, &sb_unit1_saturationLogic_channel1_seqNum);

  // initialise data structure for data port unit1_saturationLogic_channel2
  init_sp_union_art_DataContent(sb_unit1_saturationLogic_channel2, &sb_unit1_saturationLogic_channel2_seqNum);

  // initialise data structure for data port unit1_saturationLogic_channel3
  init_sp_union_art_DataContent(sb_unit1_saturationLogic_channel3, &sb_unit1_saturationLogic_channel3_seqNum);

  // initialise data structure for data port unit1_saturationLogic_channel4
  init_sp_union_art_DataContent(sb_unit1_saturationLogic_channel4, &sb_unit1_saturationLogic_channel4_seqNum);

  // initialise data structure for data port unit2_temperatureLogic_channel1
  init_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel1, &sb_unit2_temperatureLogic_channel1_seqNum);

  // initialise data structure for data port unit2_temperatureLogic_channel2
  init_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel2, &sb_unit2_temperatureLogic_channel2_seqNum);

  // initialise data structure for data port unit2_temperatureLogic_channel3
  init_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel3, &sb_unit2_temperatureLogic_channel3_seqNum);

  // initialise data structure for data port unit2_temperatureLogic_channel4
  init_sp_union_art_DataContent(sb_unit2_temperatureLogic_channel4, &sb_unit2_temperatureLogic_channel4_seqNum);

  // initialise data structure for data port unit2_pressureLogic_channel1
  init_sp_union_art_DataContent(sb_unit2_pressureLogic_channel1, &sb_unit2_pressureLogic_channel1_seqNum);

  // initialise data structure for data port unit2_pressureLogic_channel2
  init_sp_union_art_DataContent(sb_unit2_pressureLogic_channel2, &sb_unit2_pressureLogic_channel2_seqNum);

  // initialise data structure for data port unit2_pressureLogic_channel3
  init_sp_union_art_DataContent(sb_unit2_pressureLogic_channel3, &sb_unit2_pressureLogic_channel3_seqNum);

  // initialise data structure for data port unit2_pressureLogic_channel4
  init_sp_union_art_DataContent(sb_unit2_pressureLogic_channel4, &sb_unit2_pressureLogic_channel4_seqNum);

  // initialise data structure for data port unit2_saturationLogic_channel1
  init_sp_union_art_DataContent(sb_unit2_saturationLogic_channel1, &sb_unit2_saturationLogic_channel1_seqNum);

  // initialise data structure for data port unit2_saturationLogic_channel2
  init_sp_union_art_DataContent(sb_unit2_saturationLogic_channel2, &sb_unit2_saturationLogic_channel2_seqNum);

  // initialise data structure for data port unit2_saturationLogic_channel3
  init_sp_union_art_DataContent(sb_unit2_saturationLogic_channel3, &sb_unit2_saturationLogic_channel3_seqNum);

  // initialise data structure for data port unit2_saturationLogic_channel4
  init_sp_union_art_DataContent(sb_unit2_saturationLogic_channel4, &sb_unit2_saturationLogic_channel4_seqNum);

  // initialise slang-embedded components/ports
  rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_adapter_initialiseArchitecture(SF_LAST);

  // call the component's initialise entrypoint
  rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_adapter_initialiseEntryPoint(SF_LAST);

  printf("Leaving pre-init of InstrumentationMockThread_instrumentationMock_instrumentationMockThread\n");
}

/************************************************************************
 * int run(void)
 * Main active thread function.
 ************************************************************************/
int run(void) {
  DeclNewStackFrame(NULL, "sb_InstrumentationMockThread.c", "", "run", 0);

  CALLBACKOP(sb_periodic_dispatch_notification_reg_callback(sb_periodic_dispatch_notification_callback, NULL));
  MUTEXOP(sb_dispatch_sem_wait())
  for(;;) {
    MUTEXOP(sb_dispatch_sem_wait())
    // call the component's compute entrypoint
    rts_Instrumentation_InstrumentationMockThread_instrumentationMock_instrumentationMockThread_adapter_computeEntryPoint(SF_LAST);
  }
  return 0;
}
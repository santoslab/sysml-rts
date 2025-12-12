#include <string.h>
#include <camkes.h>
#include <sb_types.h>

// prototypes for clock functions
void clock_init();
void clock_set_interval_in_ms(uint32_t interval);
void clock_start_timer(void);
void clock_irq_callback(void);
uint64_t clock_get_time();

// Declarations for managing periodic thread dispatch
const uint32_t aadl_tick_interval = 1;
uint32_t aadl_calendar_counter = 0;

void sb_thread_calendar() {
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit1_temperatureLogic_coincidenceLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit1_pressureLogic_coincidenceLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit1_saturationLogic_coincidenceLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit1_tempPressureTripOut_orLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit2_temperatureLogic_coincidenceLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit2_pressureLogic_coincidenceLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit2_saturationLogic_coincidenceLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_actuationUnit2_tempPressureTripOut_orLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_tempPressureActuatorUnit_actuateTempPressureActuator_orLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_tempPressureActuatorUnit_tempPressureActuator_actuator_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_saturationActuatorUnit_actuateSaturationActuator_orLogic_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuationSubsystem_saturationActuatorUnit_saturationActuator_actuator_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_instrumentationMock_instrumentationMockThread_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_eventControlMock_eventControlMockThread_periodic_dispatch_notification_emit();
  }
  if ((aadl_calendar_counter % (1000 / aadl_tick_interval)) == 0) {
    sb_actuatorsMock_actuatorsMockThread_periodic_dispatch_notification_emit();
  }

  aadl_calendar_counter++;
}

void timer_complete_callback() {
  sb_thread_calendar();
}

// no op under the new time server scheme.
void clock_init() { }

// Set interrupt interval, in mss.
void clock_set_interval_in_ms(uint32_t interval) {
  timer_periodic(0, ((uint64_t)interval) * NS_IN_MS);
}

// no op under the new time server scheme
void clock_start_timer(void) { }

// defer to time server
uint64_t clock_get_time() {
  return (timer_time() / NS_IN_MS);
}

int run(void) {
  clock_init();
  clock_set_interval_in_ms(1);
  clock_start_timer();
  return 0;
}

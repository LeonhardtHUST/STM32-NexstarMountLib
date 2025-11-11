#ifndef NEXSTAR_MOUNT_H
#define NEXSTAR_MOUNT_H

#include <stdint.h>
#include <stdbool.h>

// Structure for receiving messages from Nexstar mount
typedef struct {
    uint8_t device_id;
    uint8_t message_type;
    uint8_t payload_length;
    uint8_t payload[256]; // example max payload length
} nexstar_receiver_t;

// Structure for sending messages to Nexstar mount
typedef struct {
    uint8_t device_id;
    uint8_t message_type;
    uint8_t payload_length;
    uint8_t payload[256]; // example max payload length
} nexstar_sender_t;

// Function prototypes

// Message processing
bool nexstar_send_message(nexstar_sender_t *sender);
bool nexstar_receive_message(nexstar_receiver_t *receiver);

// GPS data handling
void nexstar_set_gps_coordinates(double latitude, double longitude);
void nexstar_get_gps_coordinates(double *latitude, double *longitude);

// RTS/CTS control
void nexstar_enable_rts();
void nexstar_disable_rts();

#endif // NEXSTAR_MOUNT_H

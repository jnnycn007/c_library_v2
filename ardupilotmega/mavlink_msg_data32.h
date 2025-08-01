#pragma once
// MESSAGE DATA32 PACKING

#define MAVLINK_MSG_ID_DATA32 170


typedef struct __mavlink_data32_t {
 uint8_t type; /*<  Data type.*/
 uint8_t len; /*< [bytes] Data length.*/
 uint8_t data[32]; /*<  Raw data.*/
} mavlink_data32_t;

#define MAVLINK_MSG_ID_DATA32_LEN 34
#define MAVLINK_MSG_ID_DATA32_MIN_LEN 34
#define MAVLINK_MSG_ID_170_LEN 34
#define MAVLINK_MSG_ID_170_MIN_LEN 34

#define MAVLINK_MSG_ID_DATA32_CRC 73
#define MAVLINK_MSG_ID_170_CRC 73

#define MAVLINK_MSG_DATA32_FIELD_DATA_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DATA32 { \
    170, \
    "DATA32", \
    3, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_data32_t, type) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_data32_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 32, 2, offsetof(mavlink_data32_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DATA32 { \
    "DATA32", \
    3, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_data32_t, type) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_data32_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 32, 2, offsetof(mavlink_data32_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a data32 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Data type.
 * @param len [bytes] Data length.
 * @param data  Raw data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data32_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DATA32_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA32_LEN);
#else
    mavlink_data32_t packet;
    packet.type = type;
    packet.len = len;
    mav_array_assign_uint8_t(packet.data, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA32_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DATA32;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
}

/**
 * @brief Pack a data32 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Data type.
 * @param len [bytes] Data length.
 * @param data  Raw data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data32_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DATA32_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA32_LEN);
#else
    mavlink_data32_t packet;
    packet.type = type;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA32_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DATA32;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN);
#endif
}

/**
 * @brief Pack a data32 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  Data type.
 * @param len [bytes] Data length.
 * @param data  Raw data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_data32_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t len,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DATA32_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DATA32_LEN);
#else
    mavlink_data32_t packet;
    packet.type = type;
    packet.len = len;
    mav_array_assign_uint8_t(packet.data, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DATA32_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DATA32;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
}

/**
 * @brief Encode a data32 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param data32 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data32_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_data32_t* data32)
{
    return mavlink_msg_data32_pack(system_id, component_id, msg, data32->type, data32->len, data32->data);
}

/**
 * @brief Encode a data32 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param data32 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data32_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_data32_t* data32)
{
    return mavlink_msg_data32_pack_chan(system_id, component_id, chan, msg, data32->type, data32->len, data32->data);
}

/**
 * @brief Encode a data32 struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param data32 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_data32_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_data32_t* data32)
{
    return mavlink_msg_data32_pack_status(system_id, component_id, _status, msg,  data32->type, data32->len, data32->data);
}

/**
 * @brief Send a data32 message
 * @param chan MAVLink channel to send the message
 *
 * @param type  Data type.
 * @param len [bytes] Data length.
 * @param data  Raw data.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_data32_send(mavlink_channel_t chan, uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DATA32_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA32, buf, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
#else
    mavlink_data32_t packet;
    packet.type = type;
    packet.len = len;
    mav_array_assign_uint8_t(packet.data, data, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA32, (const char *)&packet, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
#endif
}

/**
 * @brief Send a data32 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_data32_send_struct(mavlink_channel_t chan, const mavlink_data32_t* data32)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_data32_send(chan, data32->type, data32->len, data32->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA32, (const char *)data32, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
#endif
}

#if MAVLINK_MSG_ID_DATA32_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_data32_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA32, buf, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
#else
    mavlink_data32_t *packet = (mavlink_data32_t *)msgbuf;
    packet->type = type;
    packet->len = len;
    mav_array_assign_uint8_t(packet->data, data, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DATA32, (const char *)packet, MAVLINK_MSG_ID_DATA32_MIN_LEN, MAVLINK_MSG_ID_DATA32_LEN, MAVLINK_MSG_ID_DATA32_CRC);
#endif
}
#endif

#endif

// MESSAGE DATA32 UNPACKING


/**
 * @brief Get field type from data32 message
 *
 * @return  Data type.
 */
static inline uint8_t mavlink_msg_data32_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field len from data32 message
 *
 * @return [bytes] Data length.
 */
static inline uint8_t mavlink_msg_data32_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from data32 message
 *
 * @return  Raw data.
 */
static inline uint16_t mavlink_msg_data32_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 32,  2);
}

/**
 * @brief Decode a data32 message into a struct
 *
 * @param msg The message to decode
 * @param data32 C-struct to decode the message contents into
 */
static inline void mavlink_msg_data32_decode(const mavlink_message_t* msg, mavlink_data32_t* data32)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    data32->type = mavlink_msg_data32_get_type(msg);
    data32->len = mavlink_msg_data32_get_len(msg);
    mavlink_msg_data32_get_data(msg, data32->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DATA32_LEN? msg->len : MAVLINK_MSG_ID_DATA32_LEN;
        memset(data32, 0, MAVLINK_MSG_ID_DATA32_LEN);
    memcpy(data32, _MAV_PAYLOAD(msg), len);
#endif
}
